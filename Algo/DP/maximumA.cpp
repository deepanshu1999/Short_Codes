#include<iostream>
using namespace std;
#define Test 100
/* Say a keyboard has 4 keys
key 1: Print A to buffer
key 2: CTRL A
key 3: CTRL C
key 4: CTRL V
 We have to print maximum A's with given keystrokes
 N=1: A
 N=2: AA
 N=3: AAA
 N=4: AAAA
 N=5: AAAAA
 N=6: AAAAAA
 These are base case as no key2,3,4 required for them
 */
 
 
 int MaximumA(int keystrokes){
     int DP[1000];
     for(int i=0;i<=3;i++){
         DP[i]=i;
     }
     if(keystrokes>=4){
     for(int i=4;i<=keystrokes;i++){
         int q=-1;
         for(int j=2;j<=i-2;j++){
            if(q<(i-j)*DP[j-1])
                q=(i-j)*DP[j-1];
         }
         if(q>i)
            DP[i]=q;
        else
            DP[i]=i;
     }}
     for(int i=0;i<=keystrokes;i++){
         cout<<DP[i]<<" ";
     }
     return 0;
 }
 int main(){
     MaximumA(Test);
     return 0;
 }
