#include<iostream>
#include<algorithm>

using namespace std;

int sum_until(int n)
{
	return n * (n + 1) / 2;
}

int main()
{
	// 3 -> 1,1,1  // 4 -> 1,2,1 //  5 -> 1,2,1,1 (1,1,2,1)  // 6-> 1,2,  2,1
	// 12 -> 1,2,3,  3,2,1
	// 50 -> 1, 2, 3, 4, 5, 6(21) ,     7 (7)     , 6, 5, 4, 3, 2, 1(21), 1  -> 6*2 + 2 ȸ?

	// 9500 -> 1, 2, ...  (94) ,94 ,95 ,96(4656)        96, 95, 94, (94) ,93 ....1 (4656)   ///  9312 (188 ���ڶ�)  ->  96*2 + 2ȸ 
	// ���ڶ����� 0�̸� +0ȸ, [1 ~ N+1(97)] �̸� +1ȸ, [N+2(98) ~ (N+1)*2(194)) �̸� 2ȸ 
	// 9505 -> 1~96 (4656) ,    ,  1~96 (4656)	 -> 9312(193 ���ڶ�) 
	// 1~97 �� : 4753     - > 9506 
	int n1, n2, dist, i = 1, result=0;
	cin >> n1 >> n2;
	dist = n2 - n1; 

	while (1)
	{
		if (dist < sum_until(i) * 2)
		{
			i -= 1;
			dist -= sum_until(i) * 2;
			break;
		}
		i++;
	}

	if (dist == 0)
		result = 0;
	else if (1 <= dist && dist <= i + 1)
		result = 1;
	else if(i+2 <= dist && dist <= 2*i + 1)
		result = 2;

	cout << sum_until(i) * 2 + result;
	return 0;
}