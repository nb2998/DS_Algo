#include<fstream>
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
int dijkstra(bool*done,int *Dist,int V){
  int minv=-1;
  for(int i=0;i<V;i++){
    if(done[i] == false && (minv==-1||Dist[i] < Dist[minv])){
      minv=i;
    }
  }
  return minv;
}
void matrixfunc(int AdjMatrx[100][100],int vert,int E,bool*done,int *before,int start,int *Dist){

  for(int i=0;i<vert;i++)
  {
    Dist[i]=9999;
      done[i]=false;
  }
Dist[0]=0;
  for(int i=0;i<vert;i++)
  { int minv=dijkstra(done,Dist,vert);
   done[minv]=true;
   for(int k=0;k<vert;k++)
   {
     if(AdjMatrx[minv][k]!=0&&done[k]==false){
       int newDist=Dist[minv]+AdjMatrx[minv][k];
         if(newDist<Dist[k]){
             before[k]=minv;
           Dist[k]=newDist;
         }
   }
  }
  }

}






int main(int argc,char *argv[]){
ofstream f2;
f2.open(argv[2]);
ifstream f1;
f1.open(argv[1]);
int e=0;
int start;
string str1="";
string str2="";
f1>>str2;
int vert=str2[0]-48;
f1>>str2;
int AdjMatrx[100][100];
for(int i=0;i<vert;i++){
    for(int j=0;j<vert;j++){
        AdjMatrx[i][j]=0;
    }
}
while(!f1.eof()){
    string str;
    f1>>str;
    int size=str.size();
    if(size>1){
    int start=str[0]-97;
    int destination=str[2]-97;
     int i=4;
    int x=str[i]-48;
   i++;
    while(str[i]!='\0'){
        x=x*10+(str[i]-48);
        i++;
    }
   AdjMatrx[start][destination]=x;
    e++;
    }
    else if(str[0]!=0){
    start=str[0]-97;
    }
}
bool*done=new bool[vert];
int *Dist=new int[vert];
int *before=new int[vert];
  for(int i=0;i<vert;i++)
    done[i]=false;
    for(int i=0;i<vert;i++) {
        before[i]=i;
    }
  matrixfunc(AdjMatrx,vert,e,done,before,start,Dist);


    for(int i=1;i<vert;i++)
    {vector<int>v1;
     int j=i;
     v1.push_back(i);
     j=before[j];
       while(before[j]!=j){
           v1.push_back(j);
           j=before[j];
       }
     v1.push_back(j);  //putting into the vector
     f2<<char(start+97)<<"-"<<char(i+97)<<":";
        for(int k=v1.size()-1;k>=0;k--){
            if(k!=0)
            f2<<char(v1[k]+97)<<",";
            else if(k==0)
                f2<<char(v1[k]+97);
        }
        f2<<":"<<Dist[i]<<endl;

    }
 }





