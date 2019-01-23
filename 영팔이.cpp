#include<iostream>

using namespace std;
//	1 0 0 0 	0 0 0 1 
//	0 1 1 0		0 1 1 0
//	0 1 0 1		1 0 1 0 

int main()
{
	int n, m;
	cin >> n >> m;

	int ** arr = new int*[n];

	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j >= 0; j--)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}