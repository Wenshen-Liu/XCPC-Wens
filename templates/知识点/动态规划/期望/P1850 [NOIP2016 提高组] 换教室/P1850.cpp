#include<bits/stdc++.h>
#define N 2010
#define V 310
#define BIG 1020060805
using namespace std;

inline int read(){
  int x=0,w=0;char ch=0;
  while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
  while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
  return w?-x:x;
}

double Min(double a,double b){return a<b?a:b;}

int n,m,v,e;
int class1[N],class2[N],dis[N][N];
double k[N],f1[N][N],f2[N][N],ans;

int main(){
  //freopen("1.in","r",stdin);
  n=read(),m=read(),v=read(),e=read();
  for(int i=1;i<=v;++i){
    for(int j=1;j<=v;++j){
      dis[i][j]=BIG;
    }
  }
  for(int i=1;i<=n;++i)class1[i]=read();
  for(int i=1;i<=n;++i)class2[i]=read();
  for(int i=1;i<=n;++i)scanf("%lf",&k[i]);
  for(int i=1;i<=e;++i){
    int x=read(),y=read(),z=read();
    dis[y][x]=dis[x][y]=Min(dis[x][y],z);
  }
  for(int i=1;i<=v;++i){
    for(int j=1;j<=v;++j){
      for(int l=1;l<=v;++l){
	dis[l][j]=dis[j][l]=Min(dis[j][l],dis[j][i]+dis[i][l]);
      }
    }
  }
  for(int i=1;i<=v;++i)dis[i][i]=dis[i][0]=dis[0][i]=0;
  for(int i=0;i<=n;++i){
    for(int j=0;j<=m;++j){
      f1[i][j]=f2[i][j]=BIG;
    }
  }
  f1[1][0]=f2[1][1]=0;
  for(int i=2;i<=n;++i){
    int C1=class1[i-1],C2=class2[i-1],C3=class1[i],C4=class2[i];
    f1[i][0]=f1[i-1][0]+dis[C1][C3];
    for(int j=1;j<=min(i,m);++j){
      f1[i][j]=Min(f1[i][j],Min(f1[i-1][j]+dis[C1][C3],f2[i-1][j]+dis[C1][C3]*(1.0-k[i-1])+dis[C2][C3]*k[i-1]));
      f2[i][j]=Min(f2[i][j],Min(f1[i-1][j-1]+dis[C1][C3]*(1-k[i])+dis[C1][C4]*k[i],f2[i-1][j-1]+dis[C1][C3]*(1.0-k[i-1])*(1.0-k[i])+dis[C2][C3]*k[i-1]*(1.0-k[i])+dis[C1][C4]*(1.0-k[i-1])*k[i]+dis[C2][C4]*k[i-1]*k[i]));
      //	printf("%d %d %lf %lf\n",i,j,f1[i][j],f2[i][j]);
    }
  }
  double ans=BIG;
  for(int i=0;i<=m;++i){
    ans=Min(ans,Min(f1[n][i],f2[n][i]));
  }
  printf("%.2lf",ans);
  return 0;
}
