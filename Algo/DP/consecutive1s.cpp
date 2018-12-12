#include<iostream>
using namespace std;
//No consequetive 1s
int binaryString(int n){
    int parent[1000][2];
    parent[0][0]=1;
    parent[0][1]=1;
    
    for(int i=1;i<n;i++){
        parent[i][0]=parent[i-1][0]+parent[i-1][1];
        parent[i][1]=parent[i-1][0];
    }
    return parent[n-1][0]+parent[n-1][1];
}

int main(){
    cout<<binaryString(5);
    return 0;
}
