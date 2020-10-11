/*
ID: kangzi1
LANG: C++
TASK: transform
*/

#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    char bimage[10][10];
    char aimage[10][10];bool tryed[8]={false,false,false,false,false,false,false,false};
    int n;
    int i;
    bool is_out=false;
    fin>>n;
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fin>>bimage[i][j];
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fin>>aimage[i][j];
    i=0;
    while(i<n){
        for(int j=0;j<n;j++){
            if(bimage[i][j]!=aimage[j][n-i-1] && tryed[0]==false)
                tryed[0]=true;
            if(bimage[i][j]!=aimage[n-i-1][n-j-1] && tryed[1]==false)                
                tryed[1]=true;
            if(bimage[i][j]!=aimage[j][i] && tryed[2]==false)            
                tryed[2]=true;
            if(bimage[i][j]!=aimage[i][n-j-1] && tryed[3]==false)                
                tryed[3]=true;
            if(bimage[i][j]!=aimage[n-j-1][n-i-1] && tryed[4]==false)
                tryed[4]=true;
            if(bimage[i][j]!=aimage[n-i-1][j] && tryed[5]==false)        
                tryed[5]=true;
            if(bimage[i][j]!=aimage[n-j-1][i] && tryed[6]==false)        
                tryed[6]=true;
            if(bimage[i][j]!=aimage[i][j] && tryed[7]==false)            
                tryed[7]=true;
        }
        i++;
    }
    for(int k=0;k<4;k++){
        if(!tryed[k]){
            is_out=true;
            fout<<k+1<<endl;
            break;
        }
    }
    if(!is_out){
        if(!tryed[4] || !tryed[5] || !tryed[6])
            fout<<5<<endl;
        else if(!tryed[7])
            fout<<6<<endl;
        else
            fout<<7<<endl;
    }
    return 0;
}