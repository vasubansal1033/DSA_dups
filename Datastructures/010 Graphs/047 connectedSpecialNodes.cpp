#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(int i=a;i<b;i++)
#define pb(a) push_back(a);
#define mp(a,b) make_pair(a,b)
#define ll long long
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>

const ll mod=1e9+7;
const int N=1e5+5;

int dsu[100005];
ll sz[100005];

int find(int u){
    if(dsu[u]==u)
        return u;

    int res=find(dsu[u]);
    dsu[u]=res;
    return res;
}

void uni(int u,int v){

    int val1=find(u);
    int val2=find(v);

    if(val1==val2) return;

    if(sz[val1]>sz[val2]){
        dsu[val2]=val1;
        sz[val1]+=sz[val2];
    }
    else{
        dsu[val1]=val2;
        sz[val2]+=sz[val1];
    }
}

multiset<ll> s;
bool visited[N]={false};
void solve(){

    int n,m,k;
    cin>>n>>m>>k;

    f(i,0,N){
        dsu[i]=i;
        sz[i]=1;
    }

    f(i,0,m){
        int u,v;
        cin>>u>>v;
        uni(u,v);
    }

    while(k--){
        int var;
        cin>>var;

        int x = find(var);
        visited[x]=true;
    }

    ll mx=0;

    ll total=0;

    f(i,1,n+1){
        if(dsu[i]==i){
            total=total+((sz[i]*(sz[i]-1))/2);

            if(visited[i])
                mx=max(mx,sz[i]);
            else
                s.insert(sz[i]);
        }
    }

    total=total-m;

    ll var=0;

    while(s.size()>1){

        ll tp1=*(s.begin());
        s.erase(s.begin());
        ll tp2=*(s.begin());
        s.erase(s.begin());
        s.insert(tp1+tp2);

        var = var+(tp1*tp2);
    }

    ll tp=*(s.begin());
    var=var+(mx*tp);
    cout<<var+total<<" "<<var;
}

int main(){
    solve();
    return 0;
}
