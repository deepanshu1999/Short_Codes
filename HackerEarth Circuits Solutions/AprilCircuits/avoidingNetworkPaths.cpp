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


const int N=2e6+5;
const int m9=1e9+7;
const int m8=1e8+7;

int n,m,k,fact[N],w;
int ways[N][4];
struct node{int i,j, val=0;} ar[N];


void EE(int aa, int bb, int& xx, int& yy){if(aa%bb == 0){xx=0,yy=1;return;}
EE(bb,aa%bb,xx,yy);int t = xx;xx = yy;yy = t - yy*(aa/bb);}
int mmi(int aa){int xx,yy;EE(aa,m9,xx,yy);xx = (xx+m9)%m9;return xx;}

int compute(int nn,int mm){
      int ans = (1LL*fact[nn+mm-2]*mmi(fact[nn-1]))%m9;
      ans=(1LL*ans*mmi(fact[mm-1]))%m9;
      return ans;
}

void solve(){
      ways[1][ar[1].val]++; // {0,0,0,1} depending upon val
      rep1(i,k){
            int mx=ar[i].j-1;
            for(int j=i+1;j<=k;j++) if(ar[j].j>mx){
                  mx=ar[j].j;
                  ll temp = compute(ar[j].i-ar[i].i+1,ar[j].j-ar[i].j+1);
                  if(!ar[j].val) {
                        ways[j][0]=(ways[j][0]+temp*ways[i][0])%m9;
                        ways[j][1]=(ways[j][1]+temp*ways[i][1])%m9;
                        ways[j][2]=(ways[j][2]+temp*ways[i][2])%m9;
                        ways[j][3]=(ways[j][3]+temp*ways[i][3])%m9;
                  }else if(ar[j].val==1){
                        ways[j][1]=(ways[j][1]+temp*ways[i][0])%m9;
                        ways[j][1]=(ways[j][1]+temp*ways[i][1])%m9;
                        ways[j][3]=(ways[j][3]+temp*ways[i][2])%m9;
                        ways[j][3]=(ways[j][3]+temp*ways[i][3])%m9;
                  }else if(ar[j].val==2){
                        ways[j][2]=(ways[j][2]+temp*ways[i][0])%m9;
                        ways[j][2]=(ways[j][2]+temp*ways[i][2])%m9;
                        ways[j][3]=(ways[j][3]+temp*ways[i][1])%m9;
                        ways[j][3]=(ways[j][3]+temp*ways[i][3])%m9;
                  }else {
                        ways[j][3]=(ways[j][3]+temp*ways[i][0])%m9;
                        ways[j][3]=(ways[j][3]+temp*ways[i][1])%m9;
                        ways[j][3]=(ways[j][3]+temp*ways[i][2])%m9;
                        ways[j][3]=(ways[j][3]+temp*ways[i][3])%m9;
                  }
            }
      }
}

int main(){
      fact[0]=1; rep1(i,N-1) fact[i]=(1LL*fact[i-1]*i)%m9;

      re n>>m>>k>>w;
      bool oo=0,nm=0;

      rep1(i,k) {
            ll x;
            re ar[i].i>>ar[i].j>>x;
            if(ar[i].i==1 && ar[i].j==1) oo=1;
            if(ar[i].i==n && ar[i].j==m) nm=1;
            if(x%m9==0 && x%m8==0) ar[i].val=3;
            else if(x%m8==0) ar[i].val=1;
            else if(x%m9==0) ar[i].val=2;
            else ar[i].val=0;
      }

      if(!oo){
            k++;
            ar[k].i=1,ar[k].j=1,ar[k].val=0;
            if(ar[k].i==n && ar[k].j==m) nm=1;
      }

      if(!nm){
            k++;
            ar[k].i=n,ar[k].j=m,ar[k].val=0;
      }

      sort(ar+1,ar+1+k,[&](node&n1, node&n2){
            if(n1.i==n2.i) return n1.j<n2.j;
            return n1.i<n2.i;
      });

      solve();

      int tot=compute(n,m);
      pr (tot+m9-ways[k][3])%m9;
      return 0;
}