// I FORGOT THAT HLD CANT BE HANDLE UPDATES IN LOGN|LOGN2
// NsqrtN->X Since no updates will be handeled then

// Eulers Simple tour cant be simply used because-> since a node has two ends in and out,
// ans always in is not + and out is not -! Ex if only out is included in the range

// Two other types of eulers tour are there->

// Eulers Tree Tour MOS-> Include the first occ of vertices and exclude its second occurence always simple euler tour traversal [April Long Factor Tree]
// Eulers Tree Tour-> beg=end=++cur and each time a child is visited end[i]=end[child]. 
// UPD (1,beg,+v) and UPD(1,end+1,-v)
// SEE: https://www.hackerearth.com/submission/41069729/

// Tip: We can use bit instead of stree. Since it is much faster and
// easy to implement 


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
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)


const int N=5e5+5;
const int mod=1e9+7;

int n,val[N];
vector<pii> adj[N];

int d[N],heavy[N],sz[N],par[N];
void dfs(int x){
      int mx=0;
      sz[x]++;
      for(auto xx: adj[x]) if(xx.first!=par[x]){
            par[xx.first]=x;   
            val[xx.first]=xx.second;
            d[xx.first]=d[x]+1;
            dfs(xx.first);
            sz[x]+=sz[xx.first];
            if(sz[xx.first]>mx) {
                  mx=sz[xx.first];
                  heavy[x]=xx.first;
            }
      }
}

int head[N],at[N],where[N],ptr;
void HeavyLightDecomposition(){
      rep(i,n) heavy[i]=-1;
      par[0]=-1;
      dfs(0);
      rep(i,n) if(par[i]==-1 || heavy[par[i]]!=i){
            for(int j=i;j!=-1;j=heavy[j]){
                  head[j]=i;
                  at[j]=++ptr; // still from 1 to n
                  where[ptr]=j;
            }
      }
}

int ql, qr,by,st[N*4];
int Combine(int a, int b){return (a+b)%mod;}	 
void Build(int v, int tl, int tr){
      if(tl==tr){
            st[v]=val[where[tl]];
            return ;
      }
      int tm=(tl+tr)/2;
      Build(v<<1,tl,tm);
      Build(v<<1|1,tm+1,tr);
      st[v]=Combine(st[v<<1],st[v<<1|1]);
}

int Query(int v, int tl, int tr){
      if(tl>qr || tr<ql) return 0;
      if(tl>=ql && tr<=qr) return st[v];
      int tm= (tl+tr)>>1;
      return Combine(Query(v<<1,tl,tm),Query(v<<1|1,tm+1,tr));
}

void Update(int v, int tl, int tr){
      if(tl>qr || tr<ql) return;
      if(tl==tr) {
            st[v]=by;  
            return ;
      }
      int tm=(tl+tr)>>1;
      Update(v<<1,tl,tm);Update(v<<1|1,tm+1,tr);
      st[v]=Combine(st[v<<1],st[v<<1|1]);
}

void pUp(int i, int z){ ql=qr=i,by=z; Update(1,1,n);}
int get(int l, int r){ ql=l,qr=r; return Query(1,1,n);}


int getQuery(){
      int u,v,ans=0;
      re u>>v;
      while(head[u]!=head[v]){
            if(d[head[u]]<d[head[v]]) swap(u,v);
            ans=Combine(ans,get(at[head[u]],at[u]));
            u=par[head[u]];
      }
      if(d[u]>d[v]) swap(u,v);
      ans=Combine(ans,get(at[u]+1,at[v]));
      return ans;
}

void pushUpdate(){
      int u;re u;
      for(auto x: adj[u]) {
            if(x.first==par[u]) {
                  val[u]=(val[u]*2)%mod;
                  pUp(at[u],val[u]);
            }else {
                  val[x.first]=(val[x.first]*2)%mod;
                  pUp(at[x.first],val[x.first]);
            }
      }
}

int main(){
      cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
      int q,t,u,v;
      re n>>q;
      rep(i,n-1){
            re u>>v>>t;
            adj[u].pb({v,t});
            adj[v].pb({u,t});
      }
      HeavyLightDecomposition();
      Build(1,1,n);
      
      // rep(i,n) cerr<<heavy[i]<<" "; cerr<<"\n";
      // rep(i,n) cerr<<head[i]<<" "; cerr<<"\n";

      while(q--){
            re t;
            if(t) pr getQuery()<<"\n";
            else pushUpdate();
      }
      return 0;
}