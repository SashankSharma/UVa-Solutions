#include<iostream>
#include<queue>
using namespace std;
const int N=10000;

int Inc[]={0001,0010,0100,1000};

struct Node{
  int x;
  int y;
};

struct ArrNode{
    int arr[4];
};

int ArrToNum(ArrNode arr){
  return (arr.arr[0]*1000+arr.arr[1]*100+arr.arr[2]*10+arr.arr[3]);
}

ArrNode NumToArr(int num){
    ArrNode arr;
    for(int i=3;i>=0;i--){
      arr.arr[i]=num%10;
      num=num/10;
    }
    return arr;
}

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
     ArrNode s,f;
     cin>>s.arr[0]>>s.arr[1]>>s.arr[2]>>s.arr[3];
     cin>>f.arr[0]>>f.arr[1]>>f.arr[2]>>f.arr[3];
     int n;
     cin>>n;
     int visited[N]={0};
     for(int i=0;i<n;i++){
       ArrNode tmp;
       cin>>tmp.arr[0]>>tmp.arr[1]>>tmp.arr[2]>>tmp.arr[3];
       visited[ArrToNum(tmp)]=1;
     }
     int dest,flag=0;
     dest=ArrToNum(f);
     queue <Node> q;
     Node src={ArrToNum(s),0};
     q.push(src);
     int k=0;
     while(!q.empty()){
       Node curr=q.front();
       q.pop();
       if(curr.x==dest) {
         flag=1;
         k=curr.y;
         break;
       }
       for(int i=0;i<4;i++){
           ArrNode pp=NumToArr(curr.x);
           pp.arr[i]=(pp.arr[i]+1)%10;
           int p=ArrToNum(pp);
         if((p<10000 && p>=0000) && visited[p]==0){
          Node AdjCell={p,curr.y+1};
          //cout<<p<<endl;
         visited[p]=1;
         q.push(AdjCell);
        }
       }
       for(int i=0;i<4;i++){
         ArrNode pp=NumToArr(curr.x);
         pp.arr[i]=pp.arr[i]-1;
         if(pp.arr[i]<0) pp.arr[i]=10+pp.arr[i];
         int p=ArrToNum(pp);
         if((p<10000 && p>=0000) && visited[p]==0){
            Node AdjCell={p,curr.y+1};
            //cout<<p<<endl;
           visited[p]=1;
           q.push(AdjCell);
        }
       }
     }
     if(flag==1) cout<<k<<endl;
     else cout<<-1<<endl;
  }
}
