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
	// 97 +0 ~ 97 +n-1 까지 알파벳 n개

	// n개 알파벳 담을 벡터
	vector<char> c_vec;

	vector<char> c_line;
	vector<vector<char> > comb;
	vector<vector<char> > comb_to_perm;

	// a부터해서 n개의 알파벳 생성
	for (int i = 0; i < n; i++) 
		c_vec.push_back( 97+ i );

	// 0과1을 저장 할 벡터 생성
	vector<int> ind;

	// r개의 1 추가
	for (int i = 0; i<r; i++)	
		ind.push_back(1);	

	// n-r개의 0 추가
	for (int i = 0; i< c_vec.size() - r; i++) 
		ind.push_back(0);

	// 조합 만들기 위한 정렬
	sort(ind.begin(), ind.end());
	reverse(ind.begin(), ind.end());

	// 조합 뽑아내기 ( comb에 조합결과 저장 )
	do {
		// 출력
		for (int i = 0; i < ind.size(); i++) 
		{
			if (ind[i] == 1)
				c_line.push_back( c_vec[i] );			
		}
		comb.push_back(c_line);
		c_line.clear();
	} while (prev_permutation(ind.begin(), ind.end()));

	
	// 조합을 순열로 만들기 4C2 = 6개 -> 4P2 = 12개 (각 조합결과의 순열) 
	for (int i = 0; i < comb.size(); i++) 
	{
		do {
			c_line.clear();
			c_line = comb[i]; // 벡터 복사 가능?
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