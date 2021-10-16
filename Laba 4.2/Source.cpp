#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stack>
int num = 0, i, j, ** a, * vis, ran, Max, * parent;

using namespace std;
void Stack(int)
{
	stack <int> q;
	q.push(num);
	vis[num] = 1;
	while (!q.empty())
	{
		num = q.top();
		q.pop();
		for (i = 0; i < Max; i++)
		{
			if (vis[i] == 0 && a[num][i] == 1)
			{
				q.push(i);
				vis[i] = 1;
				printf("%d ", i);
				num = q.top();
				i = 0;
			}
		}
	}
}

void road(int num, int*)
{
	vis[num] = 1;
	for (i = 0; i < Max; i++)
	{
		if (a[num][i] == 1 && vis[i] == 0)
		{
			parent[i] = num;
			printf("%d ", i);
			road(i, parent);
		}
	}
	for (i = 0; i < Max; i++)
	{
		if (vis[i] == 0)
		{
			num = parent[num];
			road(num, parent);
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Введите размеры массива ");
	scanf_s("%d", &Max);
	printf("Матрица смежности:\n");
	a = (int**)malloc(Max * sizeof(int));
	vis = (int*)malloc(Max * sizeof(int));
	parent = (int*)malloc(Max * sizeof(int));
	srand(time(NULL));

	for (i = 0; i < Max; i++)
	{
		vis[i] = 0;
	}
	for (i = 0; i < Max; i++)
	{
		a[i] = (int*)malloc(Max * sizeof(int));
	}
	for (i = 0; i < Max; i++)
	{
		for (j = 0; j < Max; j++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 0; i < Max; i++)
	{
		for (j = 1 + i; j < Max; j++)
		{
			ran = rand() % 101;
			if (ran > 30) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	for (i = 0; i < Max; i++)
	{
		for (j = 0; j < Max; j++)
		{
			a[j][i] = a[i][j];
		}
	}
	for (i = 0; i < Max; i++)
	{
		for (j = 0; j < Max; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < Max; i++)
	{
		parent[i] = 0;
	}
	i = 0; j = 0;
	printf("Очерёдность посещения вершин с рекурсией: 0 ");
	road(num, parent);
	for (i = 0; i < Max; i++)
	{
		vis[i] = 0;
	}
	num = 0;
	printf("\n");
	printf("Очерёдность посещения вершин без рекурсии: 0 ");
	Stack(num);
}
