/*Aplicația 8.2: Să se scrie o funcție float *allocVec(int n,...) care primește pe prima poziție un număr de elemente
iar apoi n elemente reale. Funcția va aloca dinamic un vector de tip float în care va depune toate elementele. */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float *allocVec(int n,...)
{
    va_list *va;
    va_start(va, n);
    float *v = NULL;
    int i = 0;
    while (i < n)
    {
        i++;
        v = realloc(v, sizeof(float) * i);
        if (!v)
        {
            free(v);
            printf("eroare");
            exit(EXIT_FAILURE);
        }
        v[i - 1] = (float)va_arg(va, double);
    }
    va_end(va);
    return v;
}


int main()
{
    float *v = allocVec(3, 7.2, (float) - 1, (float)0);
    for (int i = 0; i < 3; i++)
        printf("%g ", v[i]);
    free(v);
    return 0;
}