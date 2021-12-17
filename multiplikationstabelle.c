#include <stdio.h>
#include <math.h>

int main ()
{
    while(1)
    {
        int n; 
        scanf("%d",&n);
        
        for(int i1 = 0; i1 < n; ++i1)
        {
            for(int i2 = 0; i2 < n; ++i2)
            {
                printf("%d ",(i1+1) * (i2+1));
                
                for(int i = 0; i < + (3 - log10((i1+1) * (i2+1))); i++)
                {
                    printf(" ");
                }
            }
            
            printf("\n");
        }
    }
}