#include<iostream>
#include<queue>
using namespace std;
const int N = 201;

int graph[N][N];

void init(){
	for (int i = 0; i<N; i++)
	for (int j = 0; j<N; j++)
		graph[i][j] = 0;
}

int main(){
	while (1){
		int n;
		cin >> n;
		if (n == 0) break;
		init();
		int l;
		cin >> l;
		for (int i = 0; i<l; i++){
			int a, b;
			cin >> a >> b;
			graph[a][b] = 1;
		}
		queue<int> q;
		int flg = 0;
		int visited[N] = { 0 };
		q.push(0);
		while (!q.empty()){
			int curr = q.front();
			q.pop();
			for (int i = 0; i<N; i++){
				if (graph[curr][i] == 1){
					if (visited[i] == 0){
						visited[i] = 3 - visited[curr];
						q.push(i);
					}
					if (visited[i] != 0){
						if (visited[curr] == visited[i]){
							//cout<<curr<<" "<<i<<endl;
							flg = 1;
							break;
						}
					}
				}
			}
		}
		if (flg == 1) cout << "NOT BICOLORABLE." << endl;
		else cout << "BICOLORABLE." << endl;
	}
	return 0;
}
