#include<stdio.h>  
#include<iostream>  

using namespace std;  

int pin[10003][10003];  
int n,m,tempb,tempe,counter,perittoi=0,u=0,v=0;  
int main(){  
  scanf("%d%d",&n,&m);  
 // cin>>n>>m;  
  for(int i=0;i<m;i++){  
 //cin>>tempb>>tempe;  
    scanf("%d%d",&tempb,&tempe);  
    pin[tempb][tempe]+=1;  
    pin[tempe][tempb]+=1;  
  }  
  for(int i=0;i<n;i++){  
    counter=0;  
    for(int j=0;j<n;j++){  
      if(j!=i)  
        counter+=pin[i][j];  
    }  
    if(counter%2==1){  
      perittoi++;  
      if(u==0)  
        u=i;  
      else if(v==0)  
        v=i;  
    }  
  }  
  if (perittoi==0)  
    //cout<<"CYCLE\n";  
    printf("CYCLE\n");  
  else if(perittoi==2)  
    //cout<<"PATH "<<u<<" "<<v<<"\n";  
    printf("PATH %d %d\n",u,v);  
  else  
    //cout<<"IMPOSSIBLE\n";  
    printf("IMPOSSIBLE\n");  
  return 0;  
}
