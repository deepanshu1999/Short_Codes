#include <iostream>
#include<cmath>
using namespace std;
/*Longest Palindromic Subsequence
abab=3
*/
int LongestPalindrome(char *seq,int size){
    int DP[100][100];
    for(int i=0;i<=size;i++){
        DP[i][i]=1;
    }
    //Initialization done
    
    for(int i=1;i<=size;i++){
        for(int j=0;j<=size-i;j++){
            if(seq[j+i]==seq[j])
            {
                DP[j][j+i]=2+DP[j+1][j+i-1];
            }
            else
            {
                DP[j][j+i]=max(DP[j+1][j+i],DP[j][j+i-1]);
            }
        }
    }
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*   {
F(n)=|2+F(n-last-first) if(last==first)
     |max(F(n-last),F(n-first)); if(last!=first)
     {
*/
int main(){
    char sc[]="AAAAAA";
    LongestPalindrome(sc,6);
    return 0;
}

