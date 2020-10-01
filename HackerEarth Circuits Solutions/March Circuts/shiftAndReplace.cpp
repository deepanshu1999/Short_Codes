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


const int N=2e5+5;
const int mod=1e9+7;

int n,q,ar[N];
int pos[N], neg[N];

struct Stree{
    int ql, qr;
    vector<int> st;
    Stree():st(n<<2,0){}    

    void Build(int v, int tl, int tr){
        if(tl==tr){
            st[v]=tl-1+n-pos[tl-1]-neg[n-tl+1]; 
            return ;
        }
        int tm=(tl+tr)/2;
        Build(v<<1,tl,tm);
        Build(v<<1|1,tm+1,tr);
        st[v]=min(st[v<<1],st[v<<1|1]);
    }
   
    int Query(int v, int tl, int tr){
        if(tl>qr || tr<ql) return INT_MAX;
        if(tl>=ql && tr<=qr) return st[v];
        int tm= (tl+tr)>>1;
        return min(Query(v<<1,tl,tm),Query(v<<1|1,tm+1,tr));
    }

    void Update(int v, int tl, int tr){
        if(tl>qr || tr<ql) return;
        if(tl==tr) {
            st[v]=tl-1+n-pos[tl-1]-neg[n-tl+1]; 
            return ;
        }
        int tm=(tl+tr)>>1;
        Update(v<<1,tl,tm);
        Update(v<<1|1,tm+1,tr);
        st[v]=min(st[v<<1],st[v<<1|1]);
    }

    void pUp(int i){ ql=qr=i; Update(1,1,n);}
    int get(int l, int r){ ql=l,qr=r; return Query(1,1,n);}
};


int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    re n;
    rep1(i,n) {
        re ar[i];
        if(ar[i]>n) continue;
        int temp=i-ar[i];
        if(temp<0) neg[-temp]++;
        else pos[temp]++;
    }
    
    Stree tree;
    tree.Build(1,1,n);

    // rep1(i,n) pr pos[i-1]<<" "; pr "\n";
    // rep1(i,n) pr neg[n-i+1]<<" "; pr "\n";
    // rep1(i,n) pr tree.get(i,i)<<" "; pr "\n";
    
    
    re q;
    while(q--){
        int x,b;
        re x>>b;

        if(ar[x]<=n){
            int temp=x-ar[x];
            // though here the changes are done at x
            // but updates are done at the i's that are deriving 
            // the values from this pos[del]/neg[del]
            // inverse of above function 

            if(temp<0) {
                temp*=-1;
                neg[temp]--;
                tree.pUp(n-temp+1);
            }else {
                pos[temp]--;
                tree.pUp(temp+1);
            }
        }

        ar[x]=b;
        if(ar[x]<=n){
            int temp=x-ar[x];
            if(temp<0) {
                temp=-temp;
                neg[temp]++;
                tree.pUp(n-temp+1);
            }else {
                pos[temp]++;
                tree.pUp(temp+1);
            }
        }

        pr tree.get(1,n)<<"\n";
    }
    return 0;
}