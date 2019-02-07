#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> adj[1001];

bool vst[1001] = {false};
bool vst2[1001] = {false};

void dfs(int node)
{
	vst[node] = true;
	cout << node << ' ';

	for (int i = 0; i < adj[node].size(); i++)
	{
		if (vst[adj[node][i]] == false)
			dfs(adj[node][i]);
	}
}

void bfs(int node)
{
	int now;

	queue<int> q;
	q.push(node);
	vst2[node] = true;

	while (!q.empty())
	{
		now = q.front();
		cout << now << ' ';
		q.pop();

		for (int i = 0; i < adj[now].size(); i++)
		{
			if (vst2[adj[now][i]] == false)
			{
				vst2[adj[now][i]] = true;
				q.push(adj[now][i]);				
			}
		}
	}
}

int main()
{
	int N,M,  v1, v2;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;

		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	for (int i = 0; i < N; i++)
		sort(adj[i].begin(), adj[i].end());

	dfs(0);
	cout << '\n';
	bfs(0);
	cout << '\n';
	return 0;
}