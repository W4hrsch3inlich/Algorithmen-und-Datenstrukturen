#include <stdio.h>

int fakultaet (int n)
{
    int r = 1;
    while(n > 0)
    {
        r *= n--;
    }
    return r;
}

int main ()
{
    while(1)
    {
        int n; 
        scanf("%d",&n);
        printf("%d \n",fakultaet(n));
    }
}