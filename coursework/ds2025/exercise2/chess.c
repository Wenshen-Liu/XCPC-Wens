#include<stdio.h>
#define Maxn 30

int a[Maxn][Maxn];

int check(int x,int y,int dx,int dy){
    int c=a[x][y];
    if(c==0){
        return 0;
    }
    for(int k=1;k<=3;++k){
        int nx=x+k*dx;
        int ny=y+k*dy;
        if(nx<1||nx>19||ny<1||ny>19||a[nx][ny]!=c){
            return 0;
        }
    }
    int ok=0;
    int px=x-dx;
    int py=y-dy;
    if(px>=1&&px<=19&&py>=1&&py<=19&&a[px][py]==0){
        ok=1;
    }
    int qx=x+4*dx;
    int qy=y+4*dy;
    if(qx>=1&&qx<=19&&qy>=1&&qy<=19&&a[qx][qy]==0){
        ok=1;
    }
    return ok;
}

int main(){
    for(int i=1;i<=19;++i){
        for(int j=1;j<=19;++j){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=1;i<=19;++i){
        for(int j=1;j<=19;++j){
            if(check(i,j,0,1)){
                printf("%d:%d,%d\n",a[i][j],i,j);
                return 0;
            }
            if(check(i,j,1,0)){
                printf("%d:%d,%d\n",a[i][j],i,j);
                return 0;
            }
            if(check(i,j,1,1)){
                printf("%d:%d,%d\n",a[i][j],i,j);
                return 0;
            }
            if(check(i,j,1,-1)){
                printf("%d:%d,%d\n",a[i][j],i,j);
                return 0;
            }
        }
    }

    printf("No\n");
    return 0;
}