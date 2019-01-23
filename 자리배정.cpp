#include <iostream>

using namespace std;

bool chk[1000][1000];

int main()
{
	int C, R, K, ** arr, ho=0, ver=0;
	cin >> C >> R >> K;

	arr = new int*[C];
	for (int i = 0; i < C; i++)
		arr[i] = new int[R];

	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			chk[i][j] = false;

	if (C*R < K)
		cout << 0;
	else
	{
		while (1)
		{
			while(1)
			{
				if ((0 <= ho && ho < C) && (0 <= ver && ver < R) && chk[ho][ver] == false)
				{
					//cout << "x:" << ho << ", y:" << ver << '\n';
					// 방문함
					chk[ho][ver++] = true;
					K--;
				}
				else
				{
					ver--;
					ho++;
					break;
				}

				if (K == 0)
				{
					ver--;
					break;
				}
			}
			if (K == 0)
				break;

			while(1)
			{
				if ((0 <= ho && ho < C) && (0 <= ver && ver < R) && chk[ho][ver] == false)
				{
					//cout << "x:" << ho << ", y:" << ver << '\n';
					// 방문함
					chk[ho++][ver] = true;
					K--;
				}
				else
				{
					ho--;
					ver--;
					break;
				}

				if (K == 0)
				{
					ho--;
					break;
				}
			}
			if (K == 0)
				break;

			while (1)
			{
				if ((0 <= ho && ho < C) && (0 <= ver && ver < R) && chk[ho][ver] == false)
				{
					//cout << "x:" << ho << ", y:" << ver << '\n';
					// 방문함
					chk[ho][ver--] = true;
					K--;
				}
				else
				{
					ver++;
					ho--;
					break;
				}

				if (K == 0)
				{
					ver++;
					break;
				}
			}
			if (K == 0)
				break;

			while (1)
			{
				if ((0 <= ho && ho < C) && (0 <= ver && ver < R) && chk[ho][ver] == false)
				{
					//cout << "x:" << ho << ", y:" << ver << '\n';
					// 방문함
					chk[ho--][ver] = true;
					K--;
				}
				else
				{
					ho++;
					ver++;
					break;
				}

				if (K == 0)
				{
					ho++;
					break;
				}
			}
			if (K == 0)
				break;
		}

		cout << ho + 1 << ' ' << ver + 1;
	}

	return 0;
}