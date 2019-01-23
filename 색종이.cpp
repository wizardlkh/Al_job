#include<iostream>

using namespace std;

int arr[101][101];

int main()
{
	int N;
	int * color;
	int ** paper;
	cin >> N;
	paper = new int*[N];
	for (int i = 0; i < N; i++)
		paper[i] = new int[4];

	color = new int[N+1];
	
	for (int i = 0; i <= N; i++)
		color[i] = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++)
			cin >> paper[i][j];

	// 색종이마다
	for (int i = 0; i < N; i++)
	{	
		// 색종이 영역만큼 번호로 채우기
		for (int j = paper[i][1]; j < paper[i][1] + paper[i][3]; j++)
			for (int k = paper[i][0]; k < paper[i][0] + paper[i][2]; k++)
				arr[j][k] = i + 1;
	}
	
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			color[arr[i][j]] ++;

	for (int i = 1; i <= N; i++)
		cout << color[i] << '\n';

	return 0;
}