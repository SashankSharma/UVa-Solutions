#include<iostream>
#include<iomanip>
#include<cstdio>
#include<queue>
using namespace std;
const int N = 101;

int arr[N][N];
int c[N];
int maxv;

struct Point
{
	int a, b;
};

void init(){
	for (int i = 0; i<N; i++){
		c[i] = 0;
		for (int j = 0; j<N; j++)
			arr[i][j] = 0;
	}
}

int maxVal()
{
	int maxv = 0;
	for (int i = 1; i<N; i++)
	{
		if (c[i] == 1 && i>maxv) maxv = i;
	}
	return maxv;
}

int numNodes(int c[N]){
	int ret = 0;
	for (int i = 1; i<N; i++){
		if (c[i] == 1) ret = ret + 1;
	}
	return ret;
}

int bfs(int i, int j)
{
	queue <Point> q;
	bool visit[N] = { false };
	Point src = { i, 0 };
	q.push(src);
	while (!q.empty())
	{
		Point curr = q.front();
		q.pop();
		if (curr.a == j) return curr.b;
		for (int k = 1; k<N; k++)
		{
			if (arr[curr.a][k] && !visit[k])
			{
				visit[k] = true;
				Point adj;
				adj = { k, curr.b + 1 };
				q.push(adj);
			}
		}
	}
}

int BFS(int i)
{
	int d = 0;
	for (int j = 1; j <= maxv; j++)
	{
		int p;
		if (c[j] == 0) continue;
		else
		{
			p = bfs(i, j);
		}
		d = d + p;
	}
	return d;
}

int main()
{
	int t = 0;
	while (1)
	{
		init();
		int a, b, cnt = 0, dist = 0;
		//cout<<1<<endl;
		while (1)
		{
			cin >> a >> b;
			if (a == 0 && b == 0)
			{
				break;
			}
			arr[a][b] = 1;
			c[a] = 1;
			c[b] = 1;
			cnt++;
			//cout<<a<<" "<<b<<endl;
		}
		if (cnt == 0) break;
		maxv = maxVal();
		//cout<<maxv<<endl;
		for (int i = 1; i<N; i++)
		{
			int p = 0, q = 1;
			if (c[i] == 0) continue;
			else
			{
				p = BFS(i);
				q++;
			}
			dist = dist + p;
		}
		float ave;
		int num = numNodes(c);
		int x = (num - 1)*(num);
		ave = float(dist) / float(x);
		printf("Case %d: average length between pages = %.3f clicks\n", ++t, ave);
	}
	return 0;
}
