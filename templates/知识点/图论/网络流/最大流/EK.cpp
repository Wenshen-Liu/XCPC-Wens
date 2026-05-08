#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int MAXN=2*1e6+10;
const int INF=1e8+10;
inline char nc(){
    static char buf[MAXN],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXN,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    char c=nc();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=nc();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=nc();}
    return x*f;
}
struct node{
    int u,v,flow,nxt;
}edge[MAXN];
int head[MAXN];
int num=0;
inline void add_edge(int x,int y,int z){
    edge[num].u=x;
    edge[num].v=y;
    edge[num].flow=z;
    edge[num].nxt=head[x];
    head[x]=num++;
}
inline void AddEdge(int x,int y,int z)
{
    add_edge(x,y,z);
    add_edge(y,x,0);
}
int N,M,S,T;
int path[MAXN];
int A[MAXN];
inline int EK()
{
    int ans=0;
    while(true)
    {
        memset(A,0,sizeof(A)); 
        queue<int>q;
        q.push(S);
        A[S]=INF;
        while(q.size()!=0)
        {
            int p=q.front();q.pop();
            for(int i=head[p];i!=-1;i=edge[i].nxt)
            {
                if(!A[edge[i].v]&&edge[i].flow)
                {
                    path[ edge[i].v ]=i;
                    A[edge[i].v]=min(A[p],edge[i].flow);
                    q.push(edge[i].v);
                }
            }
            if(A[T]) break; 
        }
        if(!A[T]) break;
        for(int i=T;i!=S;i=edge[path[i]].u)
        {
            edge[path[i]].flow-=A[T];
            edge[path[i]^1].flow+=A[T];
        }
        ans+=A[T]; 
    }
    return ans;
}
int main()
{
    #ifdef WIN32
    freopen("a.in","r",stdin);
    #else
    #endif 
    memset(head,-1,sizeof(head));
    N=read(),M=read(),S=read(),T=read();
    for(int i=1;i<=M;i++)
    {
        int x=read(),y=read(),z=read();
        AddEdge(x,y,z); 
    } 
    printf("%d", EK() ); 
    return 0;
}
