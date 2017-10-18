#include<iostream>
#include<cstdio>
using namespace std;

int count;
int row[8],visit[8][8];

void init(){
  count=0;
  for(int i=0;i<8;i++){
    row[i]=0;
    for(int j=0;j<8;j++)
      visit[i][j]=0;
  }
}

bool isValid(int r,int c){
  return (r>=0 && r<8 && c>=0 && c<8);
}

bool Row(int r){
  for(int i=0;i<8;i++){
    if(visit[r][i]==1) return true;
  }
  return false;
}

bool Diag(int r,int c){
 int R,C;
 R=r;C=c;
 while(isValid(R+1,C+1)){
   R=R+1;C=C+1;
 }
 R=r;C=c;
 while(isValid(R-1,C+1)){
   if(visit[R-1][C+1]==1) return true;
   R=R-1;C=C+1;
 }
 R=r;C=c;
 while(isValid(R+1,C-1)){
   if(visit[R+1][C-1]==1) return true;
   R=R+1;C=C-1;
 }
 R=r;C=c;
 if(visit[R+1][C+1]==1) return true;
 while(isValid(R-1,C-1)){
   if(visit[R-1][C-1]==1) return true;
   R=R-1;C=C-1;
 }
 return false;
}

void BackTrack(int c,int C){
  bool ok=true;
  if(c==8){
    ++count;
    printf("%2d      ",count);
    for(int i=0;i<8;i++){
      cout<<row[i]+1<<" ";
    }
    cout<<endl;
  }
  if(c==C) BackTrack(c+1,C);
  else{
    for(int i=0;i<8;i++){
      if(Row(i) || Diag(i,c))continue;
      visit[i][c]=1;
      row[c]=i;
      BackTrack(c+1,C);
      visit[i][c]=0;
      }
    }
}

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int r,c;
    cin>>r>>c;
    init();
    visit[r-1][c-1]=1;
    row[c-1]=r-1;
    if(i!=0) cout<<endl;
    cout<<"SOLN       COLUMN"<<endl;
    cout<<" #      1 2 3 4 5 6 7 8"<<endl;
    cout<<endl;
    BackTrack(0,c-1);
  }
}
