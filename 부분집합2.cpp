#include <stdio.h>
#include <string.h>

int data[] = { 100,2000,30000,400000 };
int flag[] = { 0,0,0,0 };


void powerset(int n, int depth)
{
	if (n == depth) 
	{
		int i;
		printf("{");

		for (i = 0; i<n; i++) 
			if (flag[i] == 1)
				printf("%d ", data[i]);
	
		printf("}\n");
		return;
	}
	flag[depth] = 1;
	powerset(n, depth + 1);
	flag[depth] = 0;
	powerset(n, depth + 1);
}

int main()
{
	powerset(sizeof(data) / sizeof(int), 0);
	return 0;
}