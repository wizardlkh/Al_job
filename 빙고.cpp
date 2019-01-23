#include <iostream>
#include <vector>
#include <map>

using namespace std;

int bing[5][5], input[5][5], cnt = 0, cmp=0;
map<int, pair<int, int> > mp;
bool chk[5][5];

bool chk_bing(bool(*chk)[5])
{
	int count = 0, l_dia=1, r_dia=1, ho, ver;

	for (int i = 0; i < 5; i++)
	{
		if (chk[i][i] == 0)
			l_dia = 0;

		if (chk[4-i][i] == 0)
			r_dia = 0;
	}
	count += (l_dia + r_dia);

	for (int i = 0; i < 5; i++)
	{
		ho = 1, ver = 1;
		// i가 행, // i가 열
		for (int j = 0; j < 5; j++)
		{
			if (chk[i][j] == 0)
				ho = 0;
			if (chk[j][i] == 0)
				ver = 0;
		}
		count += (ho + ver);
	}

	if (count >= 3)
		return true;
	else
		return false;
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> bing[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> input[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			mp[ bing[i][j] ] = make_pair(i,j);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			chk[i][j] = false;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cnt++;
			chk[mp[input[i][j]].first][mp[input[i][j]].second] = true;

			if (chk_bing(chk))
			{
				cmp = 1;
				cout << cnt;
				break;
			}
		}
		if (cmp == 1)
			break;
	}

	return 0;
}