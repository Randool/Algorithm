#include <cstdio>
#include <string.h>
#include <queue>
#include<cstring>
using namespace std;

const int INF = 0x7fffffff;
const int MAX = 205;

int c[MAX][MAX];
int step[MAX];
int n,m;

bool BFS(int st,int ed) {
    memset(step,-1,sizeof(step));
    queue<int> que;
    step[st]=0;
    que.push(st);
    while(!que.empty()) {
        int curr=que.front();
        que.pop();
        for(int i=1; i<=n; i++) {
            if(c[curr][i]>0&&(step[i]==-1)) { //i没访问过
                step[i]=step[curr]+1;
                if(i==ed) return true;
                que.push(i);
            }
        }
    }
    return step[ed]!=-1;
}

int DFS(int st,int ed,int f) {
    if(st==ed||f==0) return f;
    int flow=0,d;
    for(int i=1; i<=n; i++) {
        if((step[i]==step[st]+1)&&c[st][i]>0&&(d=DFS(i,ed,min(c[st][i],f)))) {
            c[st][i]-=d;
            c[i][st]+=d;
            flow+=d;         //累加当前节点的某条路径的合适流量
            f-=d;            //当前节点的容量减去某条路径的合适流量
            if(f==0) break;  //如果当前节点的容量用完,说明无法再通过任何流量
        }
    }
    if(flow==0) step[st]=INF;//如果当前节点无任何流量通过,取消标记
    return flow;
}

int Dinic(int st,int ed) {
    int flow=0;
    while(BFS(st,ed)) {
        flow+=DFS(st,ed,INF);
    }
    return flow;
}

int main() {
    int a,b,flow;
    while(scanf("%d%d",&m,&n)!=EOF) {
        memset(c,0,sizeof(c));
        while(m--) {
            scanf("%d%d%d",&a,&b,&flow);
            c[a][b]+=flow;
        }
        printf("%d\n",Dinic(1,n));
    }
    return 0;
}
