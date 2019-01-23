#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, car[5];
	cin >> N ;

	for (int i = 0; i < 5; i++)
		cin >> car[i];

	vector<int> v;

	for (int i = 0; i < 5; i++)
		if (car[i] % 10 == N)
			v.push_back(car[i]);

	cout << v.size();
}