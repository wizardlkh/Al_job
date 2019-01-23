#include<iostream>

using namespace std;

int main()
{
	int N, X, Y, R, arr[101][101] = {0}, st_y , end_y, st_x, end_x, dst;
	char c_arr[101][101];

	cin >> N >> X >> Y >> R; // idx -> X-1, Y-1

	// 문자 0 으로 채우기
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)		
			c_arr[i][j] = 48;

	// 사거리 입력할 범위 설정
	X - 1 - R >= 0 ? (st_y = X - 1 - R) : (st_y = 0);
	X - 1 + R < N ? (end_y = X - 1 + R) : (end_y = N-1);

	Y - 1 - R >= 0 ? (st_x = Y - 1 - R) : (st_x = 0);
	Y - 1 + R < N ? (end_x = Y - 1 + R) : (end_x = N-1);

	// 사거리 입력
	for (int i = st_y ; i <= end_y; i++)
		for (int j = st_x; j <= end_x; j++)
		{
			dst = abs(i - (X - 1)) + abs(j - (Y - 1));

			if (dst <= R)
				c_arr[i][j] += dst;
		}			

	// 유닛위치에 문자 x
	c_arr[X - 1][Y - 1] += 72;

	// 결과출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << c_arr[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
