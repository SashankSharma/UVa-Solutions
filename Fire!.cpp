#include<iostream>
#include<queue>
#include<climits>
#define INF 1000000
using namespace std;
const int N=1000;

char maze[N][N];

struct Point{
  int x;
  int y;
  Point(int a,int b){
    x=a;
    y=b;
  }
  Point(){}
};

struct Node{
  Point pt;
  int k;
  Node(Point a,int b){
    pt=a;
    k=b;
  }
  Node(){}
};

int rowNum[]={-1,0,1,0};
int colNum[]={0,-1,0,1};

bool isValid(int row,int col,int r,int c){
  return (row>=0 && row<r && col>=0 && col<c);
}

int min(int a,int b){
  if(a<b) return a;
  return b;
}

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
      int r,c;
      cin>>r>>c;
      Point start,fstart;
      for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
          cin>>maze[i][j];
          if(maze[i][j]=='J') start=Point(i,j);
          if(maze[i][j]=='F') fstart=Point(i,j);
        }
      }
      queue <Node> q,qf;
      q.push(Node(start,0));
      qf.push(Node(fstart,0));
      int visit[N][N];
      int visitf[N][N];
      for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            visit[i][j]=visitf[i][j]=INF;
    }
      while(!q.empty()){
          Node curr=q.front();
          Point pt=curr.pt;
          q.pop();
          for(int i=0;i<4;i++){
            int row=pt.x+rowNum[i];
            int col=pt.y+colNum[i];
            if(isValid(row,col,r,c) && maze[row][col]!='#' && maze[row][col]!='F' && visit[row][col]==INF){
              visit[row][col]=curr.k+1;
              q.push(Node(Point(row,col),curr.k+1));
            }
          }
      }

      while(!qf.empty()){
          Node curr=qf.front();
          Point pt=curr.pt;
          qf.pop();
          for(int i=0;i<4;i++){
            int row=pt.x+rowNum[i];
            int col=pt.y+colNum[i];
            if(isValid(row,col,r,c) && maze[row][col]!='#' && visitf[row][col]>curr.k+1){
              visitf[row][col]=curr.k+1;
              qf.push(Node(Point(row,col),curr.k+1));
            }
          }
      }
      int k=INF;
      for(int i=0;i<c;i++){
        if(visit[0][i]<visitf[0][i]) k=min(k,visit[0][i]);
        if(visit[r-1][i]<visitf[r-1][i]) k=min(k,visit[r-1][i]);
      }
      for(int i=0;i<r;i++){
        if(visit[i][0]<visitf[i][0]) k=min(k,visit[i][0]);
        if(visit[i][c-1]<visitf[i][c-1]) k=min(k,visit[i][c-1]);
      }
      if(k==INF) cout<<"IMPOSSIBLE"<<endl;
      else cout<<k+1<<endl;
  }
}
