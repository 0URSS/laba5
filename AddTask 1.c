#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 8

int main()
{
    setlocale(LC_ALL, "Russian");

    int A[N][N];
    int i, j;
    int edges = 0;

    srand((unsigned)time(NULL));

    // Задание 1.1. Матрица смежности неориентированного графа
    for (i = 0; i < N; i++)
    {
        A[i][i] = 0;
    }

    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            A[i][j] = rand() % 2;

            A[j][i] = A[i][j];
        }
    }

    // Вывод матрицы смежности на экран
    printf("Матрица смежности графа:\n\n");

    printf("    ");
    for (i = 0; i < N; i++)
    {
        printf("%3d", i + 1);
    }
    printf("\n");

    for (i = 0; i < N; i++)
    {
        printf("%3d ", i + 1);

        for (j = 0; j < N; j++)
        {
            printf("%3d", A[i][j]);
        }

        printf("\n");
    }

    // Задание 1.2. Размер графа - количество рёбер
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (A[i][j] == 1)
            {
                edges++;
            }
        }
    }

    printf("\nРазмер графа |E| = %d\n", edges);

    // Степени вершин
    printf("\nСтепени вершин:\n");

    for (i = 0; i < N; i++)
    {
        int degree = 0;

        for (j = 0; j < N; j++)
        {
            degree += A[i][j];
        }

        printf("deg(v%d) = %d\n", i + 1, degree);
    }

    // Задание 1.3. Изолированные вершины
    printf("\nИзолированные вершины (степень 0): ");

    int found = 0;

    for (i = 0; i < N; i++)
    {
        int degree = 0;

        for (j = 0; j < N; j++)
        {
            degree += A[i][j];
        }

        if (degree == 0)
        {
            printf("v%d ", i + 1);
            found = 1;
        }
    }

    if (!found)
    {
        printf("нет");
    }

    // Концевые вершины
    printf("\nКонцевые вершины (степень 1): ");

    found = 0;

    for (i = 0; i < N; i++)
    {
        int degree = 0;

        for (j = 0; j < N; j++)
        {
            degree += A[i][j];
        }

        if (degree == 1)
        {
            printf("v%d ", i + 1);
            found = 1;
        }
    }

    if (!found)
    {
        printf("нет");
    }

    // Доминирующие вершины
    printf("\nДоминирующие вершины: ");

    found = 0;

    for (i = 0; i < N; i++)
    {
        int degree = 0;

        for (j = 0; j < N; j++)
        {
            degree += A[i][j];
        }

        if (degree == N - 1)
        {
            printf("v%d ", i + 1);
            found = 1;
        }
    }

    if (!found)
    {
        printf("нет");
    }

    printf("\n");

    return 0;
}
