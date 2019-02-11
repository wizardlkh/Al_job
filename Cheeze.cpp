#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;
set<int> chee_num;
set< pair<int,int> > m_adj_0_s;
int map[101][101], x=0, y=0, N, M, v, time = 0;
int dx[4] = {1,-1,0, 0};
int dy[4] = {0, 0,1,-1};
// 0 -> hole, outside // out -> -1, hole -> 0
void c_bfs(int x, int y, int n_color , int c_color , vector< vector<int> >& vst)
{ 
	int nx, ny;

	queue< pair<int, int> > q;
	q.push({ x,y });
	vst[x][y] = 1;
	if (map[x][y] == n_color)
		map[x][y] = c_color;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if ( (0 <= nx && nx < N) && (0 <= ny && ny < M) && vst[nx][ny] == 0)
			{
				if (map[nx][ny] == n_color)
				{
					map[nx][ny] = c_color;
					vst[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}				
	}
}

void m_adj_1_bfs(int x, int y, vector< vector<int> >& vst)
{
	int nx, ny;

	queue< pair<int, int> > q;
	q.push({ x,y });
	vst[x][y] = 1;
	v++;
	
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (map[nx][ny] == -1 && vst[nx][ny] == 0)
				map[x][y] = -1; // 방문되지 않은 -1과 인접한 1은 제거

			if (map[nx][ny] == 1 && vst[nx][ny] == 0) // (0 <= nx && nx < N) && (0 <= ny && ny < M)				
			{			
				v++;
				vst[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void m_adj_0_find(int x, int y, vector< vector<int> >& vst)
{
	int nx, ny;

	queue< pair<int, int> > q;
	q.push({ x,y });
	vst[x][y] = 1;
	
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (map[nx][ny] == -1)
				m_adj_0_s.insert({x,y}); // -1과 인접한 0의 좌표 set에 추가

			if (map[nx][ny] == 0 && vst[nx][ny] == 0) // (0 <= nx && nx < N) && (0 <= ny && ny < M)				
			{			
				vst[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void cheeze(int t)
{
	v = 0; // cheeze num initial
	
	//// 출력
	//cout << '\n' << "t:" << t << '\n';
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//		printf("%3d", map[i][j]);
	//	cout << '\n';
	//}

	// 1 -> -1로
	vector< vector<int> > vst1(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if(map[i][j] == 1 && vst1[i][j] == 0 )
				m_adj_1_bfs(i, j, vst1);
	vst1.clear();

	chee_num.insert(v);

	// 구멍0이 오픈0되면 -> -1로 변경
	vector< vector<int> > vst2(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0 && vst2[i][j] == 0)
				m_adj_0_find(i, j, vst2);
	vst2.clear();
	vst2.assign(N, vector<int>(M, 0));

	// 오픈된 0들 -1로 만들기
	for (set< pair<int, int> >::iterator it = m_adj_0_s.begin(); it != m_adj_0_s.end(); it++)
		c_bfs(it->first, it->second, 0, -1, vst2);
	vst2.clear();
	m_adj_0_s.clear();

	//// 출력
	//cout << '\n' << "t:" << t << '\n';
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//		printf("%3d", map[i][j]);
	//	cout << '\n';
	//}

	if (v != 0)
		cheeze(t + 1);
	else if (v == 0)
	{
		time = t;
		return;
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> v ;
			map[i][j] = v;
		}

	vector< vector<int> > vst0(N, vector<int>(M, 0));
	c_bfs(0, 0, 0, -1, vst0); // 구멍0을 제외한 외부0을 모두 -1로 치환
	
	cheeze(0);

	cout << time << '\n';
	cout << *(++chee_num.begin()) << '\n';
	return 0;
}