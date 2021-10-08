#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int num = 0, i, j, ** a, *vis, max, *parent, ran;

void road(int num, int*)
{
	vis[num] = 1;
	for (i = 0; i < max; i++)
	{
		if (a[num][i] == 1 && vis[i] == 0)
		{
			parent[i] = num;
			printf("%d ", i);
			road(i, parent);
		}
	}
	for (i = 0; i < max; i++)
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
	scanf_s("%d", &max);
	printf("Матрица смежности:\n");
	a = (int**)malloc(max * sizeof(int));
	vis = (int*)malloc(max * sizeof(int));
	parent = (int*)malloc(max * sizeof(int));
	srand(time(NULL));

	for (i = 0; i < max; i++)
	{
		vis[i] = 0;
	}
	for (i = 0; i < max; i++)
	{
		a[i] = (int*)malloc(max * sizeof(int));
	}
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 0; i < max; i++)
	{
		for (j = 1 + i; j < max; j++)
		{
			ran = rand() % 101;
			if (ran > 30) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			a[j][i] = a[i][j];
		}
	}
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < max; i++)
	{
		parent[i] = 0;
	}
	i = 0; j = 0;
	printf("Очерёдность посещения вершин: 0 ");
	road(num, parent);
}