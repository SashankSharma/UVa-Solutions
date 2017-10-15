#include<iostream>
#include<queue>
#include<map>
using namespace std;

int graph[100][100];
int inc;

struct Point {
	int a;
	int b;
};

void init() {
	inc = 1;
	for (int i = 0; i<100; i++)
	for (int j = 0; j<100; j++)
		graph[i][j] = 0;
}

int main() {
	int k = 1;
	while (1) {
		int t;
		cin >> t;
		if (t == 0) break;
		init();
		map<int, int> c;
		for (int i = 0; i<t; i++) {
			int a, b;
			cin >> a >> b;
			if (!c[a]) c[a] = inc++;
			if (!c[b]) c[b] = inc++;
			graph[c[a]][c[b]] = 1;
			graph[c[b]][c[a]] = 1;

		}
		while (1) {
			int a, b, dist = 1;
			cin >> a >> b;
			if (a == 0 && b == 0) break;
			queue <Point> q;
			Point src = { c[a], b };
			//cout<<b<<endl;
			bool visited[100 + 10] = { false };
			visited[c[a]] = 1;
			q.push(src);
			while (!q.empty()) {
				Point curr = q.front();
				q.pop();
				if (curr.b>0){
					//cout<<"Hi"<<endl;
					for (int i = 1; i<100; i++) {
						if (!visited[i] && graph[curr.a][i] == 1) {
							//cout<<curr.a<<" = "<<curr.b<<endl;
							visited[i] = true;
							//cout<<"1"<<endl;
							dist = dist + 1;
							//cout<<i<<" , "<<curr.b-1<<" ";
							Point adj = { i, curr.b - 1 };
							q.push(adj);
						}
					}
				}
			}
			cout << "Case " << k << ": " << inc - 1 - dist << " nodes not reachable from node " << a << " with TTL = " << b << "." << endl;
			k++;
		}
	}
	return 0;
}
