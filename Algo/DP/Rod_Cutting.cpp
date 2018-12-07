#include<iostream>
#include<climits>
using namespace std;
///TYPICAL DP QUESTION
//Cormen Rod cutting Problem solved by TWO DP strategies and Greedy Algo
//TOP DOWN APPROACH
int DP[1000];
int s[1000];
int CostTable[1000];
int ShowWhere(int n){
if(n==0)
    return 0;
if(DP[n]>=0)
    return DP[n];
else{
    int q=INT_MIN;
    for(int i=1;i<=n;i++){
    if(q<CostTable[i]+ShowWhere(n-i)){
    q=CostTable[i]+ShowWhere(n-i);
    s[n]=i;
    }
    }
    DP[n]=q;
    return DP[n];
}
}
//BOTTOM UP APPROACH
int CUTTER(int n){
    DP[0]=0;
    //Solving Problem for increasing j
    for(int j=1;j<=n;j++){
        int q=INT_MIN;
        for(int i=1;i<=j;i++){

            if(q<CostTable[i]+DP[j-i]){
                q=CostTable[i]+DP[j-i];
                s[j]=i;

            }
        }
        DP[j]=q;

    }
    return DP[n];

}
void PrintDP(int n){
cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<DP[i]<<",";
    }
}
void Display(int n){
cout<<"CUT THE ROD AT:"<<endl;

while(n>0){
cout<<s[n]<<",";
n-=s[n];
}
}
//A Greedy Algo
int Greedy(int n){
    float Density[1000][2];
    Density[0][0]=0;
    Density[0][1]=0;
    for(int i=1;i<=n;i++){
        Density[i][0]=(float)CostTable[i]/i;
        //cout<<"D"<<Density[i][0];
        Density[i][1]=i;
    }
   // for(int i=1;i<=n;i++){
     //   cout<<Density[i][1]<<",";
    //}
    //cout<<"Done";
    //Sorting Can use any method now using Bubble Sorting

    for(int j=1;j<=n;j++){
        for(int i=1;i<=n-1;i++){
            if(Density[i+1][0]>Density[i][0]){
                float temp1=Density[i+1][0];
                float temp2=Density[i+1][1];
                Density[i+1][0]=Density[i][0];
                Density[i+1][1]=Density[i][1];
                Density[i][0]=temp1;
                Density[i][1]=temp2;
            }
        }
    }
   // for(int i=1;i<=n;i++){
   //     cout<<Density[i][0]<<",";
   // }
   // cout<<"Done";
    //Sorting Done now time for real work
    int s[20];
    int iter=0;
    int diter=1;
    while(n>0){
        if(Density[diter][1]>n)
            diter++;
        else{
            n=n-Density[diter][1];
            s[iter++]=Density[diter][1];
        }
    }
    for(int j=0;j<iter;j++){
        cout<<s[j]<<",";
    }
    return 1;
}
int main(){

    for(int i=0;i<1000;i++)
        DP[i]=-2;
CostTable[0]=0;
CostTable[1]=1;
CostTable[2]=5;
CostTable[3]=8;
CostTable[4]=9;
CostTable[5]=10;
CostTable[6]=17;
CostTable[7]=17;
CostTable[8]=20;
CostTable[9]=24;
CostTable[10]=30;
Greedy(9);
//cout<<"OPTIMUM PRICE\n"<<(9)<<endl;
//PrintDP(9);
//Display(9);
return 1;
}
