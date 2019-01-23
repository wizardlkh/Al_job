#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> num_set;
int cnt = 0;

void divi(int rem, int max)
{
	int m_num;

	if (rem == 0)
	{
		for (int i = 0; i < num_set.size(); i++)
		{
			if (i != 0)
				cout << '+';

			cout << num_set[i];
		}
		cout << '\n';
		cnt++;
		return;
	}

	m_num = min(rem, max);
	// (9,8) [8�߰�]-> (1,8) [1�߰�]-> (0,1) ->���
	// (9,8) [7�߰�](i==7) -> (2,7) [2�߰�]-> (0,2) -> ���
	for (int i = m_num; i > 0; i--)
	{
		num_set.push_back(i);
		divi(rem - i, i);
		num_set.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;

	divi(n, n - 1);
	cout << cnt << '\n';

	return 0;
}