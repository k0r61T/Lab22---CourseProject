#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#define SCREENW 100
#define SCREENH 150

// Объявление типа указателя на функцию
typedef double (*TFunc) (double);

// Объявление прототипов функций
double Y(double);
double V(double);
void Funktsiya(TFunc, double, double, double);
void Znachenie(TFunc, double);
void Grafik(TFunc, double, double);
TFunc vybor_funktsii(int);

int main()
{
    double shag, nachalo, konec, x;
    int vybor, vybor_func;
    int flag_func = 0;

    setlocale(LC_ALL, "RUS");

    printf("**************************************************************************\n");
    printf("*                                                                        *\n");
    printf("*                           Курсовой проект                              *\n");
    printf("*            Разработка программы для табулирования функции              *\n");
    printf("*                       Выполнил: Еременко Я.С.                          *\n");
    printf("*                     Руководитель: Курипта О.В.                         *\n");
    printf("*                          Группа: 6ИПТ-251                              *\n");
    printf("*                                                                        *\n");
    printf("**************************************************************************\n");
    printf("\n");
    printf("**************************************************************************\n");
    printf("*                      Функции Y(x) и V(x):                              *\n");
    printf("*                                                                        *\n");
    printf("*  1. Функция Y(x):                                                      *\n");
    printf("*                                                                        *\n");
    printf("*           Y(x) = e^x + 5 + cos(0.001x)                                 *\n");
    printf("*                                                                        *\n");
    printf("**************************************************************************\n");
    printf("*                                                                        *\n");
    printf("*  2. Кусочная функция V(x):                                             *\n");
    printf("*                                                                        *\n");
    printf("*                  ----                                                  *\n");
    printf("*                 /                                                      *\n");
    printf("*                | sin(2.3x - 1)         при x > 2.5                     *\n");
    printf("*       V(x) = --| 1 - 3*ln|1 - x|       при 0 <= x <= 2.5               *\n");
    printf("*                | 2 - x                 при x < 0                       *\n");
    printf("*                 \\                                                      *\n");
    printf("*                  ----                                                  *\n");
    printf("*                                                                        *\n");
    printf("**************************************************************************\n");
    printf("\n");

    do
    {
        printf("\nМЕНЮ:\n");
        printf("1. Табулировать функцию\n");
        printf("2. Вычислить значение при заданном x\n");
        printf("3. Начертить график функции\n");
        printf("4. Выйти из программы\n\n");
        printf("Ваш выбор: ");
        scanf("%d", &vybor);

        switch (vybor)
        {
        case 1:
        {
            flag_func = 0;
            printf("Выберите функцию (1 или 2): ");
            scanf("%d", &vybor_func);

            if (vybor_func != 1 && vybor_func != 2)
            {
                printf("\nОшибка: неверный выбор функции! Доступны только 1 или 2.\n");
                break;
            }
            flag_func = 1;

            printf("\nВведите начальную точку интервала: ");
            if (scanf("%lf", &nachalo) != 1)
            {
                printf("\nОшибка: некорректный ввод начальной точки!\n");
                return 1;
            }

            printf("Введите конечную точку интервала: ");
            if (scanf("%lf", &konec) != 1)
            {
                printf("\nОшибка: некорректный ввод конечной точки!\n");
                return 1;
            }

            printf("Введите шаг табуляции: ");
            if (scanf("%lf", &shag) != 1)
            {
                printf("\nОшибка: некорректный ввод шага!\n");
                return 1;
            }

            if (nachalo >= konec)
            {
                printf("\nОшибка: начальная точка должна быть меньше конечной!\n");
                return 1;
            }

            if (shag <= 0 || shag > (konec - nachalo))
            {
                printf("\nОшибка: шаг должен быть положительным и меньше длины интервала!\n");
                return 1;
            }

            TFunc func = vybor_funktsii(vybor_func);
            Funktsiya(func, shag, nachalo, konec);
            break;
        }

        case 2:
        {
            flag_func = 0;
            printf("Выберите функцию (1 или 2): ");
            scanf("%d", &vybor_func);

            if (vybor_func != 1 && vybor_func != 2)
            {
                printf("\nОшибка: неверный выбор функции! Доступны только 1 или 2.\n");
                break;
            }
            flag_func = 1;

            printf("\nВведите x для вычисления значения функции: ");
            if (scanf("%lf", &x) != 1)
            {
                printf("\nОшибка: некорректный ввод значения x!\n");
                return 1;
            }

            TFunc func = vybor_funktsii(vybor_func);
            Znachenie(func, x);
            break;
        }

        case 3:
        {
            flag_func = 0;
            printf("Выберите функцию (1 или 2): ");
            scanf("%d", &vybor_func);

            if (vybor_func != 1 && vybor_func != 2)
            {
                printf("\nОшибка: неверный выбор функции! Доступны только 1 или 2.\n");
                break;
            }
            flag_func = 1;

            printf("\nВведите начальную точку интервала: ");
            if (scanf("%lf", &nachalo) != 1)
            {
                printf("\nОшибка: некорректный ввод начальной точки!\n");
                return 1;
            }

            printf("Введите конечную точку интервала: ");
            if (scanf("%lf", &konec) != 1)
            {
                printf("\nОшибка: некорректный ввод конечной точки!\n");
                return 1;
            }

            if (nachalo >= konec)
            {
                printf("\nОшибка: начальная точка должна быть меньше конечной!\n");
                return 1;
            }

            TFunc func = vybor_funktsii(vybor_func);
            printf("\n");
            Grafik(func, nachalo, konec);
            break;
        }

        case 4:
            printf("\nПодождите, происходит завершение программы...\n");
            break;

        default:
            printf("\nНеверный выбор операции!\n");
        }
    } 
    while (vybor != 4);

    printf("\n");
    getchar();
    system("pause");
    return 0;
}

//---------------------------------------------------------
TFunc vybor_funktsii(int vybor_func)
{
    switch (vybor_func)
    {
    case 1:
        return Y;
    case 2:
        return V;
    default:
        return Y;
    }
}

//---------------------------------------------------------
double Y(double x)
{
    return exp(x) + 5 + cos(0.001 * x);
}

//---------------------------------------------------------
double V(double x)
{
    if (x > 2.5)
    {
        return sin(2.3 * x - 1);
    }
    else if (x >= 0 && x <= 2.5)
    {
        if (fabs(1.0 - x) < 1e-12)
        {
            return INFINITY;
        }
        return 1 - 3 * log(fabs(1 - x));
    }
    else // x < 0
    {
        return 2 - x;
    }
}

//---------------------------------------------------------
void Funktsiya(TFunc f, double shag, double nachalo, double konec)
{
    printf("-------------------------\n");
    printf("|     x     |    F(x)   |\n");
    printf("-------------------------\n");

    for (double x = nachalo; x <= konec; x += shag)
    {
        double result = f(x);
        printf("| %9.2f | %9.2f |\n", x, result);
    }

    printf("-------------------------\n");
}

//---------------------------------------------------------
void Znachenie(TFunc f, double x)
{
    double result = f(x);

    if (isinf(result))
    {
        printf("\nОШИБКА! Функция не определена в точке x = %lf\n", x);
    }
    else
    {
        printf("\nЗначение функции при x = %lf равно %lf\n", x, result);
    }
}

//---------------------------------------------------------
void Grafik(TFunc f, double x0, double x1)
{
    char screen[SCREENW][SCREENH];
    double x, y[SCREENW];
    double ymin = 0, ymax = 0;
    double hx, hy;
    int i, j;
    int xz, yz;
    hx = (x1 - x0) / (SCREENW - 1);

    for (i = 0, x = x0; i < SCREENW; ++i, x += hx)
    {
        y[i] = f(x);
        if (y[i] < ymin)
            ymin = y[i];
        if (y[i] > ymax)
            ymax = y[i];
    }

    hy = (ymax - ymin) / (SCREENH - 1);
    yz = (int)floor(ymax / hy + 0.5);
    xz = (int)floor((0. - x0) / hx + 0.5);

    for (j = 0; j < SCREENH; ++j)
    {
        for (i = 0; i < SCREENW; ++i)
        {
            if (j == yz && i == xz)
                screen[i][j] = '+';
            else if (j == yz)
                screen[i][j] = '-';
            else if (i == xz)
                screen[i][j] = '|';
            else
                screen[i][j] = ' ';
        }
    }

    for (i = 0; i < SCREENW; ++i)
    {
        j = (int)floor((ymax - y[i]) / hy + 0.5);
        screen[i][j] = '*';
    }

    for (j = 0; j < SCREENH; ++j)
    {
        printf("                   ");
        for (i = 0; i < SCREENW; ++i)
            putchar(screen[i][j]);
        putchar('\n');
    }
}