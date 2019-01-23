#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> int_vec;

/*
int Is_zero(vector<char> &oper, int max)
{
	// 숫자 초기화
	for (int i = 0; i < max + 1; i++)
		int_vec.push_back(i + 1);

	// 
	for (int i = 0; i < max; i++)
		if (oper[i] == '.')
		{
			oper.erase(oper.begin() + i);





		}




}
*/



void number(vector<char> &oper, int max)
{
	if (oper.size() == max)
	{
		for (int i = 0; i < max; i++)
			cout << oper[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			oper.push_back('+');
			number(oper, max);
			oper.pop_back();
		}
		else if (i == 1)
		{
			oper.push_back('-');
			number(oper, max);
			oper.pop_back();
		}
		else if (i == 2)
		{
			oper.push_back('.');
			number(oper, max);
			oper.pop_back();
		}
	}
}

int main()
{
	int n;
	cin >> n;

	vector<char> oper;

	// 111111, 111112 ~333333;
	number(oper, n - 1);


	return 0;
}