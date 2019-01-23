#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int cnt = 0;
int cnt_20 = 20;

int Is_zero(list<char> &oper, int max)
{
	list<char> oper2 = oper;
	list<int> int_vec;

	int digit = 0, c_end=0 , result;
	// 숫자 초기화 1~7
	for (int i = 0; i < max + 1; i++)
		int_vec.push_back(i + 1);

	list<int>::iterator i_it, copy_i_it;

	while ( !c_end )
	{
		i_it = int_vec.begin();

		for (list<char>::iterator c_it = oper2.begin(); c_it != oper2.end(); c_it++)
		{
			copy_i_it = i_it;
			if (*c_it == '.')
			{
				digit = (int)log10(double(*(++copy_i_it)));
				*copy_i_it += (int)pow(10, digit + 1) * (*i_it);

				oper2.erase(c_it);
				int_vec.erase(i_it);
				break;
			}

			if (c_it == --oper2.end())
				c_end = 1;

			i_it++;
		}
	}

	i_it = int_vec.begin();
	result = *i_it;

	for (list<char>::iterator c_it = oper2.begin(); c_it != oper2.end(); c_it++)
	{
		copy_i_it = i_it;

		if (*c_it == '+')
			result += *(++copy_i_it);
		else if(*c_it == '-')
			result -= *(++copy_i_it);

		i_it++;
	}

	if( result == 0 )
		return 1;
	else
		return 0;
}

void number(list<char> &oper, int max)
{
	list<int> int_vec2;

	// 숫자 초기화 (1~7)
	for (int i = 0; i < max + 1; i++)
		int_vec2.push_back(i + 1);

	list<int>::iterator i_it;

	
	if(oper.size() >= max)
	{
		if (Is_zero(oper, max))
		{	
			if (cnt_20 != 0)
			{
				i_it = int_vec2.begin();

				for (list<char>::iterator c_it = oper.begin(); c_it != oper.end(); c_it++)
				{					
						cout << *(i_it ++) << ' ' << *c_it << ' ';					
				}
				cout << int_vec2.back() << '\n';

				cnt_20--;
			}		
			cnt++;
		}
		
		return ;
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

	list<char> oper;

	number(oper, n - 1);
	cout << cnt << '\n';

	return 0;
}