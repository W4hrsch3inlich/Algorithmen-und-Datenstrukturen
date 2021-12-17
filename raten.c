#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    while(1)
    {
        int n;
        printf("Geben Sie n an: ");
        scanf("%d", &n);
        
        srand(time(NULL));
        int r = rand() % n;
        
        while(1)
        {
            int g;
            printf("Raten Sie was die zufällige Zahl ist: ");
            scanf("%d", &g);
            
            if(g == r)
            {
                printf("Richtig!!!\n");
                break;
            }
            else if(g < r)
            {
                printf("größer\n");
            }
            else
            {
                printf("kleiner\n");
            }
        }
    }
}