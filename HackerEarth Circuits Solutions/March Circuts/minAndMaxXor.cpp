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


const int N=1e5+5;
const int mod=1e9+7;

int t,n,ar[N];

int main(){
    
    cin.tie(NULL); 
    cout.tie(NULL); 
    ios_base::sync_with_stdio(false);
    
    re t;
    
    while(t--){
        re n;
        rep1(i,n) re ar[i];
        sort(ar+1,ar+1+n);
        int mx=INT_MAX;
        rep1(i,n-1){
            // mx=min(mx,(ar[i]&ar[i+1])^(ar[i]|ar[i+1]));
            mx=min(mx,(ar[i]^ar[i+1]));
        }
        pr mx<<"\n";
    }
    return 0;
}