/*Aplicația 8.3: Să se scrie o funcție absN(int n,...) care primește un număr n de adrese de tip float și setează
la fiecare dintre aceste adrese valoarea absolută de la acea locație.*/

#include <stdio.h>
#include <stdarg.h>

void absN(int n, ...)
{
    float *x;
    va_list va;
    va_start(va, n);
    while (n--)
    {
        x = (float *)va_arg(va, double *);
        *x = *x < 0 ? -(*x) : *x;
    }
}

int main()
{

    float x = 1, y = -2;
    absN(2, &x, &y);
    printf("%g %g", x, y);
}
