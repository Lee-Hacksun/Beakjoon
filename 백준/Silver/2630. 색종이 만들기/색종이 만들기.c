#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int x;
	int y;
	int size;
} TASK;

int countSquare(const int** square, int size, int* blue, int* white)
{
	int top = -1;
	TASK* stack = malloc(sizeof(TASK) * size * size * 2 + 4);

	stack[++top] = (TASK){ 0, 0, size };

	while (top != -1)
	{
		TASK task = stack[top--];

		int firstSquare = square[task.y][task.x];
		int isSame = 1;
		for (int i = task.y; i < task.y + task.size && isSame; i++)
		{
			for (int j = task.x; j < task.x + task.size; j++)
			{
				if (firstSquare != square[i][j])
				{
					isSame = 0;
					break;
				}
			}
		}

		if (isSame)
		{
			if (firstSquare == 0)
			{
				(*white)++;
			}
			else
			{
				(*blue)++;
			}
			continue;
		}

		if (!isSame)
		{
			stack[++top] = (TASK){ task.x, task.y, task.size / 2 };
			stack[++top] = (TASK){ task.x + (task.size / 2), task.y, task.size / 2};
			stack[++top] = (TASK){ task.x, task.y + (task.size / 2), task.size / 2 };
			stack[++top] = (TASK){ task.x + (task.size / 2), task.y + (task.size / 2), task.size / 2 };
		}
	}
	free(stack);
}

int main()
{
	int n;
	int** square;

	scanf("%d", &n);
	square = calloc(n, sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		square[i] = calloc(n, sizeof(int));
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &square[i][j]);
		}
	}

	int white = 0;
	int blue = 0;

	countSquare(square, n, &blue, &white);

	printf("%d\n%d", white, blue);

	return 0;
}