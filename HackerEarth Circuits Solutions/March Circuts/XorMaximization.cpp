#include<bits/stdc++.h>
#define re cin>>
#define pr cout<<
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;

// go till power of N in case of masks
const int MX=70,N=1<<19; // should be a pow of 2
const int mod=1e9+7;

int n,cnt[MX+1]; // mx +1 here, rest <=MX
// int dp[N][MX+1];
int dp[2][MX+1]; // better
int pw[N];

bool isprime[MX+1];
int cc;
map<int,int> mp;

int getBit(int x){
    int res=0;

    // finding the prime factors is like->
    int till=sqrt(x); // go till a fixed sqrt
    for(int i=2;i<=till;i++){ // not go till x as x will change now
        bool tmp=0;
        if(x%i==0){
            while(x%i==0) x/=i, tmp=!tmp;
        }
        // id is considered to start from 1 to easily find the non present numbers
        if(tmp) res|=(1<<mp[i]-1);
    }

    // in case x is a prime number
    if(x>1) res|=(1<<mp[x]-1);
    return res;
}

void seive(){
    // yes till MX, all primes will exists if there will be 
    for(int i=2;i<=MX;i++) isprime[i]=1;
    for(int i=2;i<=MX;i++) if(isprime[i]){
        for(int j=i+i;j<=MX;j+=i) isprime[j]=0;
        mp[i]=++cc;
    }
}

int main(){
    // go simple 
    seive();

    re n;
    pw[0]=1;

    rep1(i,n) {
        int x;
        re x;
        cnt[x]++;
        pw[i]=(pw[i-1]*2LL)%mod;
    }

    dp[0][0]=1; // including an empty set

    for(int i=1;i<=70;i++){
        int mask= getBit(i);
        bool state= (i%2)==1;
        long long ways= cnt[i]?pw[cnt[i]-1]:0;  
        for(int j=0;j<N;j++){
            dp[j][state]=dp[j][!state]; // first add the old values
            // then add the odd numbers in the set (it will never be empty in case cnt exists)
            dp[j][state]=(dp[j][state]+dp[mask^j][!state]*ways)%mod; 
            // adding the even number set, will include any empty set 
            if(ways) // for the empty set -1 
                dp[j][state]=(dp[j][i]+dp[j][!state]*(ways-1))%mod; 
        }
    }

    cout<<(dp[0][0]-1+mod)%mod; // removing the empty set!
    return 0;
}