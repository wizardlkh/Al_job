#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r;
	cin >> n >> r;
	// 97 +0 ~ 97 +n-1 ���� ���ĺ� n��

	// n�� ���ĺ� ���� ����
	vector<char> c_vec;

	vector<char> c_line;
	vector<vector<char> > comb;
	vector<vector<char> > comb_to_perm;

	// a�����ؼ� n���� ���ĺ� ����
	for (int i = 0; i < n; i++) 
		c_vec.push_back( 97+ i );

	// 0��1�� ���� �� ���� ����
	vector<int> ind;

	// r���� 1 �߰�
	for (int i = 0; i<r; i++)	
		ind.push_back(1);	

	// n-r���� 0 �߰�
	for (int i = 0; i< c_vec.size() - r; i++) 
		ind.push_back(0);

	// ���� ����� ���� ����
	sort(ind.begin(), ind.end());
	reverse(ind.begin(), ind.end());

	// ���� �̾Ƴ��� ( comb�� ���հ�� ���� )
	do {
		// ���
		for (int i = 0; i < ind.size(); i++) 
		{
			if (ind[i] == 1)
				c_line.push_back( c_vec[i] );			
		}
		comb.push_back(c_line);
		c_line.clear();
	} while (prev_permutation(ind.begin(), ind.end()));

	
	// ������ ������ ����� 4C2 = 6�� -> 4P2 = 12�� (�� ���հ���� ����) 
	for (int i = 0; i < comb.size(); i++) 
	{
		do {
			c_line.clear();
			c_line = comb[i]; // ���� ���� ����?
			comb_to_perm.push_back(c_line);
		} while (next_permutation(comb[i].begin(), comb[i].end()));
	}

	sort(comb_to_perm.begin(), comb_to_perm.end());

	for (vector<vector<char> >::iterator it1 = comb_to_perm.begin(); it1 != comb_to_perm.end(); it1++)
	{
		for (vector<char>::iterator it2 = it1->begin(); it2 != it1->end(); it2++)
			cout << *it2 << ' ';
		cout << '\n';
	}

	return 0;
}