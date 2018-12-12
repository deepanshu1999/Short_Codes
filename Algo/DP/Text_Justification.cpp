#include <iostream>
#include<cmath>
#include<climits>
#define CHARLIMIT 100
using namespace std;
int DP[10000];
double badness(int n){
    if(n>CHARLIMIT)
    return INT_MAX;
    return pow(CHARLIMIT-n,3);
}
int summation(int start,int ending,char A[]){
    int summ=0;
    for(int i=start;i<ending;i++){
        summ+=A[i];
    }
    return summ;
}
void JustifyText(){
    //Assuming no word>n
    char text[10000];
    gets(text);
    char wordlength[5000];
    int worditer=0;
    int j=0;
    for(int i=0;text[i]!='\0';){
        if(text[i]==' ' || text[i]=='.'){
            wordlength[worditer++]=(i-j>0)?i-j:0;
            j=i+1;
        }

    }
    //Just Checking
    for(int i=0;i<worditer;i++){
        cout<<wordlength[i]<<",";
    }
    for(int i=1;i<worditer;i++){
    wordlength[i]=wordlength[i-1]+wordlength[i];}

    for(int i=0;i<1000;DP[i++]=-2);

    DP[0]=0;

    cout<<DP_Do(wordlength,0,n,n);
}
int s[1000];
int siter=0;
    //Now Time for DP
double DP_Do(char wordlength[],int start,int ending,int n){
    if(DP[n]>=0)
        return DP[n];
    else{
        q=INT_MAX;
        for(int i=start;i<=ending;i++){
            double pi=badness(wordlength[i-1]);
            double ri=DP_Do(wordlength,i,ending,n-i);
            if(q>pi+ri)
                {
                q=pi+ri;
                s[n]=i;
                }
        }
        DP[n]=q;
        return DP[n];
    }
}
int main() {

}
