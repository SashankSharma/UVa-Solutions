#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 301;
struct Point
{
	int x;
	int y;
};
struct node
{
	Point pt;
	int k;
};

int rowNum[] = { -1, 0, 1, 0 };
int colNum[] = { 0, -1, 0, 1 };
bool isValid(int row, int col,int R,int C)
{
	return (row >= 0) && (row < R) && (col >= 0) && (col < C);
}
bool isNotWall(char ch) {
	if (ch == '#') return false;
	return true;
}

int BFS_E(char vec[N][N], Point src, Point dest,int R,int C){
	queue <node> q;
	node s = { src, 0 };
	q.push(s);
	bool visited[N][N][4] = { 0 };
	int k = 0;
	while (!q.empty()){
		node curr = q.front();
		q.pop();
		Point pt = curr.pt;
		//cout << "("<<pt.x << "," <<pt.y<< ")" << " "<<curr.k<<endl;
		if (pt.x == dest.x && pt.y == dest.y) return curr.k;
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < curr.k+1; j++){
				int row = pt.x + (j+1)*rowNum[i];
				int col = pt.y + (j+1)*colNum[i];
				if (isValid(row, col,R,C) && !visited[row][col][(curr.k+1)%3] && isNotWall(vec[row][col])){
					if (j == curr.k){
						visited[row][col][(curr.k + 1) % 3] = true;
						Point adj = { row, col };
						node AdjCell = { adj,  curr.k + 1};
						q.push(AdjCell);
					}
				}
				else break;
			}
		}
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int R, C;
		cin >> R >> C;
		char vec[N][N];
		Point src, dest;
		for (int i = 0; i<R; i++) {
			for (int j = 0; j<C; j++) {
				char ch;
				cin >> ch;
				vec[i][j] = ch;
				if (vec[i][j] == 'S') {
					src.x = i;
					src.y = j;
				}
				if (vec[i][j] == 'E') {
					dest.x = i;
					dest.y = j;
				}
			}
		}
		int dist = BFS_E(vec, src, dest,R,C);
		if (dist == -1) cout << "NO" << endl;
		else cout << dist << endl;
	}
	return 0;
}
