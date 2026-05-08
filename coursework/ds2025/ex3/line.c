#include <stdio.h>

struct Point{
    int x;
    int y;
};

struct Line{
    struct Point s;
    struct Point e;
};

int samePoint(struct Point a, struct Point b){
    return a.x==b.x && a.y==b.y;
}

int main(){
    int n;
    scanf("%d",&n);

    struct Line line[105];
    int i,j;

    for(i=0;i<n;i++){
        scanf("%d%d%d%d",
              &line[i].s.x,&line[i].s.y,
              &line[i].e.x,&line[i].e.y);
    }

    int maxcnt=0;
    int ansx=0,ansy=0;

    for(i=0;i<n;i++){
        int hasPrev=0;

        /* 判断第 i 条线段前面是否还有线段接到它 */
        for(j=0;j<n;j++){
            if(i!=j && samePoint(line[j].e,line[i].s)){
                hasPrev=1;
                break;
            }
        }

        /* 不是起点线段就跳过 */
        if(hasPrev) continue;

        /* 从第 i 条线段开始往后找整条链 */
        int cnt=1;
        int cur=i;

        while(1){
            int next=-1;
            for(j=0;j<n;j++){
                if(j!=cur && samePoint(line[cur].e,line[j].s)){
                    next=j;
                    break;
                }
            }
            if(next==-1) break;

            cnt++;
            cur=next;
        }

        if(cnt>maxcnt){
            maxcnt=cnt;
            ansx=line[i].s.x;
            ansy=line[i].s.y;
        }
    }

    printf("%d %d %d\n",maxcnt,ansx,ansy);

    return 0;
}