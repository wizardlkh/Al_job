#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	// 1, 6, 12, 18, 24... 
	// 1(1ĭ), 2~7(2ĭ), 8 ~ 19(3ĭ), 20 ~ 37(4ĭ), 38 ~ 61(5ĭ)
	
	int N, Arith = 1, m_6 = 6, cnt=2;
	cin >> N;

	if (N == 1)
	{
		cout << 1 << '\n';
		return 0;
	}

	// 7, 19, 37 ...
	while (1)
	{
		Arith += m_6; // 7
		m_6 += 6; // 12

		if (N <= Arith) // 
			break;

		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}