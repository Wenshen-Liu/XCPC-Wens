#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int service_time;
    int arrival_time;
} Customer;

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    int* arrivals = (int*)malloc(T * sizeof(int));
    int total_customers = 0;
    for (int i = 0; i < T; i++) {
        scanf("%d", &arrivals[i]);
        total_customers += arrivals[i];
    }

    Customer* all_customers = (Customer*)malloc(total_customers * sizeof(Customer));
    int idx = 0;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < arrivals[i]; j++) {
            all_customers[idx].id = idx + 1;
            scanf("%d", &all_customers[idx].service_time);
            all_customers[idx].arrival_time = i + 1;
            idx++;
        }
    }

    int windows[5] = {0};
    int active = 3;
    int head = 0;
    int tail = 0;
    int time = 1;

    while (head < total_customers || windows[0] > 0 || windows[1] > 0 || 
           windows[2] > 0 || windows[3] > 0 || windows[4] > 0) {
        
        for (int i = 0; i < 5; i++) {
            if (windows[i] > 0) {
                windows[i]--;
            }
        }

        if (time <= T) {
            int arr_count = arrivals[time - 1];
            tail += arr_count; 
            
            int queue_len = tail - head;
            while (active < 5 && (double)queue_len / active >= 7.0) {
                active++;
            }
        }

        int queue_len = tail - head;
        int assigned_this_cycle = 0;
        for (int i = 0; i < active; i++) {
            if (windows[i] == 0 && queue_len > 0) {
                Customer c = all_customers[head];
                windows[i] = c.service_time;
                printf("%d : %d\n", c.id, time - c.arrival_time);
                head++;
                queue_len--;
                assigned_this_cycle = 1;
            }
        }

        if (assigned_this_cycle) {
            while (active > 3 && (double)queue_len / active < 7.0) {
                active--;
            }
        }

        time++;
    }

    free(arrivals);
    free(all_customers);
    return 0;
}