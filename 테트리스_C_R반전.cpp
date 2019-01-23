#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

// ��ȯ���� ���ִ� ���� ���� (0�� ��� ����0�� or ���ӿ���)
int each_col(int ** arr , int cur_col, int C, int R )
{
	int seat=0, cnt=1, sum=0; // �� ����� �ٴ� idx, ���� ���� ����, ���� ���� ����

	for (int i = 0; i < C; i++)
	{
		if (arr[i][cur_col] == 1)
		{
			// ���ӿ��� ���̽�
			if (i < 4)
				return 0;
			else if(i >= 4)
			{
				seat = i - 1;
				break;
			}
		}
		
		if(i == C-1)
		{
			seat = C - 1;
			break;
		}
	}

	for (int i = seat - 3; i <= seat; i++)
		arr[i][cur_col] = 1;

	for (int i = seat-3; i <= seat; i++)
	{
		cnt = 1;
		for (int j = 0; j < R; j++)
		{
			if (arr[i][j] == 0)
			{
				cnt = 0;
				break;
			}
		}
		sum += cnt;
	}

	for (int i = seat - 3; i <= seat; i++)
		arr[i][cur_col] = 0;

	return sum;
}

int main()
{
	int C, R, **arr, rst=0;
	cin >> C >> R;

	arr = new int*[C];
	for (int i = 0; i < C; i++)
		arr[i] = new int[R];

	for (int i = 0; i < C; i++)
		for (int j = 0; j < R; j++)
			cin >> arr[i][j];

	// each_col ����� ���� �迭
	vector<int> result;

	for (int i = 0; i < R; i++)
		result.push_back(each_col(arr, i, C, R));

	vector<int> result2(result);
	sort(result2.begin(), result2.end());

	vector<int>::iterator iter = result.begin();

	if (result2.front() == 0 && result2.back() == 0)
		cout << 0 << ' ' << 0;
	else 
	{
		while ( find(iter, result.end(), result2.back()) != result.end() )
		{
			iter = find(iter, result.end(), result2.back());
			cout << iter - result.begin() + 1 << ' ' << result2.back() << '\n';
			iter++;
		}
	}

	return 0;
}