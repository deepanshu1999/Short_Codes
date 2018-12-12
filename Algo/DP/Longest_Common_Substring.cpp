#include<iostream>
using namespace std;

int LongestCommonSubstring(char *s1,char *s2,int size1,int size2){
    int DP[1000][1000];
    int maximum;
    //Init 
    for(int i=0;i<size2;i++){
        if(s1[0]==s2[i]){
            DP[i][0]=1;
        }
        else{
            DP[i][0]=0;
        }
    }
    //Init
    for(int i=0;i<size1;i++){
        if(s2[0]==s1[i]){
            DP[0][i]=1;
        }
        else{
            DP[0][i]=0;
        }
    }
   /* for(int i=0;i<size2;i++){
        for(int j=0;j<size1;j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }*/
    //Work
    for(int i=1;i<size2;i++){
        for(int j=1;j<size1;j++){
            if(s2[i]==s1[j]){
                //cout<<"Here"<<i<<"l"<<j<<"K"<<DP[i-1][j-1]<<endl;
                DP[i][j]=DP[i-1][j-1]+1;
                //cout<<"POP"<<DP[i][j];
            }
            else{
                DP[i][j]=0;
            }
            if(DP[i][j]>maximum)
                maximum=DP[i][j];
        }
    }
    for(int i=0;i<size2;i++){
        for(int j=0;j<size1;j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    return maximum;
    
}

int main(){
    char s[]="IIITBAY";char p[]="IITBOMBAY";
    LongestCommonSubstring(s,p,4,4);
    return 0;
}
