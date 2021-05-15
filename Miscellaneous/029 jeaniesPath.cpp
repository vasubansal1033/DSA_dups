#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MA(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int N=500002;
const int inf=1000000000;
int n,K,s[N],SUM,M;
bool f[N];
vector <int> v[N],d[N];

int input(){
    scanf("%d%d",&n,&K);
    for (int i=0,x;i<K;i++){
        scanf("%d",&x);
        s[x]=1;
        f[x]=1;
    }
    for (int i=1,x,y,z;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        v[x].pb(y);
        v[y].pb(x);
        d[x].pb(z);
        d[y].pb(z);
    }
    return 0;
}

int go(int x,int from){
    int D1=-inf;
    int D2=-inf;

    for (int i=0;i<v[x].size();i++)
    if (v[x][i]!=from){
        D1=max(D1,go(v[x][i],x)+d[x][i]);
        if (D1>D2) swap(D1,D2);
        s[x]+=s[v[x][i]];
        if (0<s[v[x][i]] && s[v[x][i]]<K) SUM+=d[x][i];
    }

    if (D1>0) M=max(M,D1+D2);

    if (D2>0 && f[x]) M=max(M,D2);

    if (f[x]) D2=max(D2,0);

    return D2;
}

int sol(){
    go(1,1);
    printf("%d\n",SUM*2-M);
    return 0;
}

int main() {
    input();
    sol();
    return 0;
}
