#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void print_poly(int d[], int size)
{
    for (int i=size; i>= 0; i--)
    {
        if (d[i] < 0)
        {
            printf("\b\b");
            printf("- %dx^(%d) + ", (-1 * d[i]), i);
        }
        else
            printf("%dx^(%d) + ", d[i],i);
    }
    printf("\b");
    printf("\b \n");
}
void multiplicaton(int a[], int b[], int c[], int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    printf("Multiplication Result : ");
    print_poly(c, m + n);
}

void subtraction(int a[], int b[], int m, int n)
{   
    printf("Subtraction Result : ");
    int min = MIN(m, n);
    if (min == n)
    {
        int *c = calloc((m), sizeof(int));
        for (int i = 0; i <= m; i++)
        {
            c[i] = a[i] ;
        }
        for (int i = 0; i <= min; i++)
        {
            c[i] -= b[i] ;
        }
        print_poly(c, m);
    }
    else
    {
        int *c = calloc((n), sizeof(int));
        for (int i = 0; i <= n; i++)
        {
            c[i] = b[i] ;
        }
        for (int i = 0; i <= min; i++)
        {
            b[i] -= a[i];
        }
        print_poly(b, n);
    }
}

void addition(int a[], int b[], int m, int n)
{   
    printf("Addition Result : ");
    int min = MIN(m, n);
    if (min == n)
    {
        int *c = calloc((m),sizeof(int));
        for (int i = 0; i <= m; i++)
        {
            c[i] = a[i] ;
        }

        for (int i = 0; i <= min; i++)
        {
            c[i] += b[i];
        }
        print_poly(c, m);
    }
    else
    {
        int *c = calloc((n), sizeof(int));
        for (int i = 0; i <= n; i++)
        {
            c[i] = b[i] ;
        }
        for (int i = 0; i <= min; i++)
        {
            c[i] += a[i];
        }
        print_poly(c, n);
    }
}

int main()
{
    int m, n;
    printf("Enter the degree of both the polynomials m n : ");
    scanf("%d%d", &m, &n);
    int *a = calloc(m, sizeof(int));
    int *b = calloc(n, sizeof(int));
    int *c = calloc((m + n), sizeof(int));

    printf("\nEnter the coefficients of polynomial with degree m : ");
    for (int i = 0; i <= m; i++)
    {
        scanf("%d", a + i);
    }

    printf("\nEnter the coefficients of polynomial with degree n : ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", b + i);
    }

    printf("\nPolynomial 1 : ");
    print_poly(a, m);
    printf("Polynomial 2 : ");
    print_poly(b, n);
    printf("\n");

    int k = 3 , choice;
    while (k --> 0)
    {   
        printf("Enter the choice of operation : \n1. Addition \n2. Subtraction \n3. Multiplicaton \n\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addition(a, b, m, n);
                break;
            case 2:
                subtraction(a, b, m, n);
                break;

            case 3:
                multiplicaton(a, b, c, m, n);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}


