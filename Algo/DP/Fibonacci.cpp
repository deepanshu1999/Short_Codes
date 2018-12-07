#include<iostream>
using namespace std;
//Top Down Approach
///Always Have Memory penalty
int Fib(int n,int DP[]){
if(n==1)
return 1;
if(n==2)
return 1;
else{
    if(DP[n]<=0)
        DP[n]=Fib(n-2,DP)+Fib(n-1,DP);
    return DP[n];
    }
}
//Bottom up Approach
///No Memory Penalty
int Fibonacci(int n){
int last=1,s_last=1;
if(n==1) return 1;
if(n==2) return 1;
else{
for(int i=3;i<=n;i++){
    int current=last+s_last;
    s_last=last;
    last=current;}
return last;
}
}

int main(){
cout<<"TEST1\n";

for(int i=0;i<10;i++){
int c;
cin>>c;
int *p=new int[c+1];
for(int i=0;i<=c;i++){
p[i]=-1;}
cout<<"RES "<<Fib(c,p)<<endl;
}
cout<<"TEST2\n";
for(int j=0;j<10;j++){
int c;
cin>>c;
cout<<"RES "<<Fibonacci(c)<<endl;
}
return 0;
}
