//Sudoku Solver
#include<iostream>
#include<vector>
using namespace std;
bool row[9][9]={0};
bool column[9][9]={0};
bool box[9][9]={0};
//first for pos second for no;
struct coord{
    int i,j;
};
int getBoxNo(int i,int j){
    if(i<=2 && j<=2)
        return 0;
    if(i<=2 && j<=5)
        return 1;
    if(i<=2)
        return 2;
    if(i<=5 && j<=2)
        return 3;
    if(i<=5 &&j<=5)
        return 4;
    if(i<=5)
        return 5;
    if(j<=2)
        return 6;
    if(j<=5)
        return 7;
    else
        return 8;
}
bool Solve();
vector<coord> emptypos;
int emptypositer=0;

int Suduko[9][9]={    {8, 0, 0,  0, 0, 0,  0, 0, 0}, 
                      {0, 0, 3,  6, 0, 0,  0, 0, 0}, 
                      {0, 7, 0,  0, 9, 0,  2, 0, 0}, 
                      
                      {0, 5, 0,  0, 0, 7,  0, 0, 0}, 
                      {0, 0, 0,  0, 4, 5,  7, 0, 0}, 
                      {0, 0, 0,  1, 0, 0,  0, 3, 0}, 
                      
                      {0, 0, 1,  0, 0, 0,  0, 6, 8}, 
                      {0, 0, 8,  5, 0, 0,  0, 1, 0}, 
                      {0, 9, 0,  0, 0, 0,  4, 0, 0}};
void PrintS(){
    for(int i=0;i<9;i++){
         for(int j=0;j<9;j++){
             cout<<Suduko[i][j]<<" ";
         }
         cout<<endl;
     }
}
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            //cin>>::Suduko[i][j];
            if(::Suduko[i][j]==0){
                coord o;
                o.i=i;
                o.j=j;
                emptypos.push_back(o);
            }
            else{
                row[i][::Suduko[i][j]]=true;
                column[j][::Suduko[i][j]]=true;
                box[getBoxNo(i,j)][::Suduko[i][j]]=true;
                }
        }
    }
   
   
   
   
   if(Solve()){
     for(int i=0;i<9;i++){
         for(int j=0;j<9;j++){
             cout<<Suduko[i][j]<<" ";
         }
         cout<<endl;
     }
     
    }else{
        cout<<"No Solution\n";
        for(int i=0;i<9;i++){
         for(int j=0;j<9;j++){
             cout<<Suduko[i][j]<<" ";
         }
         cout<<endl;
     }
    }}

bool Solve(){
    struct coord curr=::emptypos[::emptypositer++];
    
    if(emptypositer==emptypos.size()){
        //cout<<"POS"<<curr.i<<","<<curr.j;
        for(int value=1;value<=9;value++){
            bool rbool=row[curr.i][value];
            bool cbool=column[curr.j][value];
            bool bbool=box[getBoxNo(curr.i,curr.j)][value];
            if(!rbool && !cbool && !bbool){
                row[curr.i][value]=true;
                column[curr.j][value]=true;
                box[getBoxNo(curr.i,curr.j)][value]=true;
                Suduko[curr.i][curr.j]=value;
                return true;
            }
        }
        return false;
        
    }
    
    
    
    for(int value=1;value<=9;value++){
        
        bool rbool=row[curr.i][value];
        bool cbool=column[curr.j][value];
        bool bbool=box[getBoxNo(curr.i,curr.j)][value];
        
        if(!rbool && !cbool && !bbool){
            row[curr.i][value]=true;
            column[curr.j][value]=true;
            box[getBoxNo(curr.i,curr.j)][value]=true;
            Suduko[curr.i][curr.j]=value;
            bool rbb=Solve();
            if(rbb){
                return true;
            }
            
            Suduko[curr.i][curr.j]=0;
            row[curr.i][value]=false;
            column[curr.j][value]=false;
            box[getBoxNo(curr.i,curr.j)][value]=false;
            emptypositer--;
            
        }
        
    }
    return false;
}
