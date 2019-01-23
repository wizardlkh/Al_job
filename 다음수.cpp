#include<iostream>
#include<algorithm>

using namespace std;

int input[10000][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i = 0;

	do {
		for (int j = 0; j < 3; j++)
			cin >> input[i][j];
		i++;
	} while (input[i-1][0] != 0 || input[i - 1][1] != 0 || input[i - 1][2] != 0);
	
	for (int j = 0; j < i-1; j++)
	{
		if (input[j][2] - input[j][1] == input[j][1] - input[j][0])
			cout << "AP " << input[j][2] + (input[j][1] - input[j][0]) << '\n';

		if((double)input[j][2]/input[j][1] == (double)input[j][1] / input[j][0])
			cout << "GP " << input[j][2] * (input[j][1] / input[j][0]) << '\n';
	}

	return 0;
}