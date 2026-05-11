#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int arrive_time;
    int duration;
    int wait_time;
} Customer;

Customer queue[1000];
int head = 0, tail = 0;
int windows[5] = {0, 0, 0, 0, 0}; // 0-2对私, 3-4临时
int current_window_count = 3;

void adjust_windows_increase() {
    int waiting_count = tail - head;
    while (current_window_count < 5 && waiting_count >= 7 * current_window_count) {
        current_window_count++;
    }
}

void adjust_windows_decrease() {
    int waiting_count = tail - head;
    while (current_window_count > 3) {
        if (waiting_count < 7 * (current_window_count - 1)) {
            current_window_count--;
        } else {
            break;
        }
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    int *new_customer_counts = (int *)malloc(T * sizeof(int));
    for (int i = 0; i < T; i++) scanf("%d", &new_customer_counts[i]);

    int customer_id_counter = 1;
    Customer finished[1000];
    int finished_count = 0;

    for (int t = 0; t < T || head < tail; t++) {
        // 1. 新客户到达
        if (t < T) {
            for (int j = 0; j < new_customer_counts[t]; j++) {
                queue[tail].id = customer_id_counter++;
                queue[tail].arrive_time = t;
                scanf("%d", &queue[tail].duration);
                tail++;
            }
            // 只有在获取新客户时（包括0人）调增窗口
            adjust_windows_increase();
        }

        // 2. 窗口尝试处理客户
        for (int i = 0; i < current_window_count; i++) {
            if (windows[i] == 0 && head < tail) {
                Customer *c = &queue[head++];
                c->wait_time = t - c->arrive_time;
                windows[i] = c->duration;
                finished[finished_count++] = *c;
                
                // 每当有人去接受服务，等待人数减少，立刻尝试减少窗口
                adjust_windows_decrease();
            }
        }

        // 3. 时间流逝，窗口服务时间减1
        for (int i = 0; i < 5; i++) {
            if (windows[i] > 0) windows[i]--;
        }
    }

    for (int i = 0; i < finished_count; i++) {
        printf("%d : %d\n", finished[i].id, finished[i].wait_time);
    }

    free(new_customer_counts);
    return 0;
}