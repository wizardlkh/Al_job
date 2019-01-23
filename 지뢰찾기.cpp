#include<iostream>
#include<algorithm>

using namespace std;

int map[100][100] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, X, Y, sum=0;
	cin >> N >> M >> X >> Y;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	// idx 
	X -= 1; Y -= 1;

	if (map[X][Y] == 1)
	{
		cout << "game over" << '\n';
		return 0;
	}
	else
		for (int i = X - 1; i <= X + 1; i++)
			for (int j = Y - 1; j <= Y + 1; j++)
				if(map[i][j] == 1)
					sum++;

	cout << sum << '\n';
	return 0;
}