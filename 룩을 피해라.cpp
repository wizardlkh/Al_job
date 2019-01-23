#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	int arr[8][8], k_x , k_y, result = 0, big_y, sm_y, big_x, sm_x, sum=0;
	vector<pair<int, int> > rook;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 1)
			{
				k_x = i;
				k_y = j;
			}

			if (arr[i][j] == 2)
			{
				rook.push_back({ i,j });
			}
		}

	for (int i = 0; i < rook.size(); i++)
	{
		if(k_x != rook[i].first && k_y != rook[i].second)
			result += 0;
		else if (k_x == rook[i].first)
		{
			// 기물인 3이 하나도 없으면 만날 가능성 있음(1)
			sum = 1;
			big_y = max(k_y, rook[i].second);
			sm_y = min(k_y, rook[i].second);

			for (int j = sm_y + 1; j < big_y; j++)
				if (arr[k_x][j] == 3)
					sum = 0;
				
			result += sum;
		}
		else if (k_y == rook[i].second)
		{
			// 기물인 3이 하나도 없으면 만날 가능성 있음(1)
			sum = 1;
			big_x = max(k_x, rook[i].first);
			sm_x = min(k_x, rook[i].first);

			for (int j = sm_x + 1; j < big_x; j++)
				if (arr[j][k_y] == 3)
					sum = 0;

			result += sum;
		}	
	}

	if (result >= 1)
		cout << 1;
	else
		cout << 0;

	return 0;
}