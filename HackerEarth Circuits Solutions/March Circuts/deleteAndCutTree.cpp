#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define re cin>>
#define pr cout<<
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)


const int N=2e6+5;
const int mod=1e9+7;


int n,m,u[N],v[N];
vector<pii> adj[N];

bool vis[N],is[N];
int curr,lo[N],hi[N];

void FindBridges(int x,int p){
    vis[x]=1;
    lo[x]=hi[x]=++curr;
    for(auto xx: adj[x]) if(xx.first!=p) {
        if(vis[xx.first]) lo[x]=min(lo[x],hi[xx.first]);
        else{ 
            FindBridges(xx.first,x);
            lo[x]=min(lo[x],lo[xx.first]);
            if(lo[xx.first]>hi[x]) is[xx.second]=1;
        }
    }
}

int sz[N];
void dfsSz(int x){
    sz[x]++;
    for(auto xx: adj[x]) if(!sz[xx.first]){
        dfsSz(xx.first);
        sz[x]+=sz[xx.first];
    }
}   

void EE(int aa, int bb, int& xx, int& yy){if(aa%bb == 0){xx=0,yy=1;return;}
EE(bb,aa%bb,xx,yy);int t = xx;xx = yy;yy = t - yy*(aa/bb);}
int mmi(int aa){int xx,yy;EE(aa,mod,xx,yy);xx = (xx+mod)%mod;return xx;}


int main(){
    re n>>m;
    rep1(i,m){
        re u[i]>>v[i];
        adj[u[i]].pb({v[i],i});
        adj[v[i]].pb({u[i],i});
    }

    FindBridges(1,0);
    dfsSz(1);

    if(sz[1]!=n){
        pr "0 0\n";
        return 0;
    }

    int eve=0,odd=0;
    rep1(i,m) if(is[i]){
        int mn= min(sz[u[i]],sz[v[i]]);
        if(mn%2==0 && n%2==0) eve++;
        else odd++;
    }

    int ans1= (1LL*eve*mmi(odd+eve))%mod;
    int ans2= (1LL*odd*mmi(eve+odd))%mod;    
    
    pr ans1<<" "<<ans2;
    return 0;
}