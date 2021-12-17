#include <stdio.h>
#include <math.h>

int main ()
{
    while(1)
    {
        int n; 
        scanf("%d",&n);
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = i+1;
        }
        int c = 1;
        
        while(c < n)
        {
            if(arr[c] == 0)
            {
                c++;
                continue;
            }
            
            printf("%d ", arr[c]);
            
            for(int i = 2; i*arr[c]-1 < n; i++)
            {
                arr[arr[c]*i-1] = 0;
            }
            
            c++;
        }
        
        printf("\n");
    }
}