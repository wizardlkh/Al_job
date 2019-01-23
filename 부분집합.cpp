#include <iostream> 
using namespace std;

#define NUM 8

class Set
{
private:
	int set[NUM];
	void subset(int s[], int k);
public:
	void PrintSet();
	void PrintSubSet();
	void InputSet();
	int GetElement(int idx);
};

void Set::subset(int s[], int k)
{
	if (k == NUM)
	{
		cout << "{ ";

		for (int i = 0; i < k; i++) 
			if (s[i] == 1) 
				cout << set[i] << " ";

		cout << "}" << endl;
	}
	else
	{
		s[k] = 1;
		subset(s, k + 1);
		s[k] = 0;
		subset(s, k + 1);
	}
}

void Set::InputSet()
{
	for (int i = 0; i<NUM; i++)
		cin >> set[i];
}

void Set::PrintSubSet()
{
	int s[NUM];
	subset(s, 0);
}



void Set::PrintSet()
{
	cout << "{ ";
	for (int i = 0; i<NUM; i++)
		cout << set[i] << " ";
	cout << "}" << endl;
}

int Set::GetElement(int idx)
{
	return set[idx];
}

int main()
{
	cout << "집합 입력 : ";
	Set a;
	a.InputSet();

	//cout << "입력된 집합 출력 : " << endl;
	//a.PrintSet();
	cout << '\n';

	cout << "부분집합 출력 : " << endl;
	a.PrintSubSet();
	return 0;
}