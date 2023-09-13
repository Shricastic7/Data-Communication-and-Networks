#include <stdio.h>
#include <stdlib.h>
void calculate(int);
int main()
{
    int ch;
    do
    {
        printf("\n1.Encode\n2.Decode\n3.Exit\nYour choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            calculate(0);
            break;
        case 2:
            calculate(1);
            break;
        default:
            printf("wrong choice/Exit");
        }
    }
    while (ch != 3);
    return 0;
}
void calculate(int op)
{
    int i, j, k = 0;
    int flag = 1, a[16], gen[16], r[20], div[16], n, m, ch;
    printf("Enter Data in only 0 and 1 \n");
    printf("Enter total no. of bits of generator : ");
    scanf("%d", &n);
    printf("\nEnter the generator bit by bit : ");
    n = n - 1;
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &gen[i]);
    }
    printf("\nEnter total no. of bits of data : ");
    scanf("%d", &m);
    m = m - 1;
    printf("Enter the data bit by bit : ");
    for (i = 0; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }
    if (m < n || (gen[0] && gen[n]) == 0)
    {
        printf("Not a proper generator \n");
        exit(0);
    }
    for (i = m + 1; i <= m + n; i++)
    {
        a[i] = 0;
    }
    for (j = 0; j <= n; j++)
    {
        r[j] = a[j];
    }
    for (i = n; i <= m + n; i++)
    {
        if (i > n)
        {
            for (j = 0; j < n; j++)
            {
                r[j] = r[j + 1];
            }
            r[j] = a[i];
        }
        if (r[0])
        {
            div[k++] = 1;
        }
        else
        {
            div[k++] = 0;
            continue;
        }
        for (j = 0; j <= n; j++)
        {
            r[j] = r[j] ^ gen[j];
        }
    }
    printf("\n\tQuotient : ");
    for (j = 0; j < k; j++)
    {
        printf("%d ", div[j]);
    }
    printf("\n\tRemainder : ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", r[i]);
    }
    if (op == 0)
    {
        printf("\n\tTransmitted frame is : ");
        for (i = m + 1, j = 1; i <= m + n; i++, j++)
        {
            a[i] = r[j];
        }
        for (i = 0; i <= m + n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    if (op == 1)
    {
        for (i = 1; i <= n; i++)
        {
            if (r[i])
                flag = 0;
        }
        if (flag)
            printf("\n\tNo Error\n");
        else
            printf("\n\tError");
    }
}
