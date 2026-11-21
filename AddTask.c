#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    int N;
    int i, j;
    int edges = 0;

    printf("Введите количество вершин N: ");
    scanf("%d", &N);

    // Матрица смежности в динамической памяти: N * N чисел
    int *A = (int *)malloc(N * N * sizeof(int));

    srand((unsigned)time(NULL));

    // Задание 1.1. Сначала петли на диагонали
    for (i = 0; i < N; i++)
    {
        A[i * N + i] = rand() % 2;
    }

    // Затем числа над диагональю
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            A[i * N + j] = rand() % 2;
        }
    }

    // И их отражение под диагональ
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            A[j * N + i] = A[i * N + j];
        }
    }

    // Вывод матрицы смежности на экран
    printf("\nМатрица смежности графа:\n\n");

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
            printf("%3d", A[i * N + j]);
        }

        printf("\n");
    }

    // Задание 1.2. Размер графа - рёбра и петли
    for (i = 0; i < N; i++)
    {
        if (A[i * N + i] == 1)
        {
            edges++;
        }

        for (j = i + 1; j < N; j++)
        {
            if (A[i * N + j] == 1)
            {
                edges++;
            }
        }
    }

    printf("\nРазмер графа |E| = %d\n", edges);

    // Степени вершин: петля даёт 2
    printf("\nСтепени вершин:\n");

    for (i = 0; i < N; i++)
    {
        int degree = A[i * N + i] * 2;

        for (j = 0; j < N; j++)
        {
            if (j != i)
            {
                degree += A[i * N + j];
            }
        }

        printf("deg(v%d) = %d\n", i + 1, degree);
    }

    // Задание 1.3. Изолированные вершины
    printf("\nИзолированные вершины (нет связей): ");

    int found = 0;

    for (i = 0; i < N; i++)
    {
        int links = 0;

        for (j = 0; j < N; j++)
        {
            if (j != i)
            {
                links += A[i * N + j];
            }
        }

        int degree = links + 2 * A[i * N + i];

        if (links == 0)
        {
            printf("v%d(deg=%d) ", i + 1, degree);
            found = 1;
        }
    }

    if (!found)
    {
        printf("нет");
    }

    // Концевые вершины
    printf("\nКонцевые вершины (одна связь): ");

    found = 0;

    for (i = 0; i < N; i++)
    {
        int links = 0;

        for (j = 0; j < N; j++)
        {
            if (j != i)
            {
                links += A[i * N + j];
            }
        }

        int degree = links + 2 * A[i * N + i];

        if (links == 1&& A[i * N + i] == 0)
        {
            printf("v%d(deg=%d) ", i + 1, degree);
            found = 1;
        }
    }

    if (!found)
    {
        printf("нет");
    }

    // Доминирующие вершины
    printf("\nДоминирующие вершины (связь со всеми): ");

    found = 0;

    for (i = 0; i < N; i++)
    {
        int links = 0;

        for (j = 0; j < N; j++)
        {
            if (j != i)
            {
                links += A[i * N + j];
            }
        }

        int degree = links + 2 * A[i * N + i];

        if (links == N - 1)
        {
            printf("v%d(deg=%d) ", i + 1, degree);
            found = 1;
        }
    }

    if (!found)
    {
        printf("нет");
    }

    printf("\n");

    // Освобождение памяти
    free(A);

    return 0;
}
