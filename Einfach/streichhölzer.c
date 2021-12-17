#include <stdio.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int move(int *matches, int n)
{
    if(!(0 < n && n <= MIN(3,*matches)))
    {
        printf("Illegaler Zug.\n");
        return 0;
    }
    
    *matches -= n;
    
    printf("%d Streichhölzer wurden entfernt, %d verbleiben.\n", n, *matches);

    return 1;
}

int main ()
{
    int matches, turn;
    scanf("%d", &matches);
    turn = 1;
    
    while (matches > 0)
    {
        if (turn == 1)
        {
            //Zug des Computers
            printf("Der Computer macht seinen Zug.\n");
            if(matches <= 4)
            {
                move(&matches, MAX(1,matches-1));
            }
            else
            {
                move(&matches, 2);
            }
            turn = 0;
        }
        else
        {
            int input;
            char term;
            //Zug des Menschen
            while(1)
            {
                printf("Wie viele Streichhölzer wollen Sie nehmen?: ");
                scanf("%d%c", &input, &term);
                if(term != '\n')
                {
                    getchar();
                    printf("Invalide Eingabe.\n");
                }
                else
                {
                    if(move(&matches, input))
                    {
                        break;
                    }
                }
            }
            
            turn = 1;
        }
    }
    //Bekanntgabe des Gewinners
    if(turn == 0)
    {
        printf("Sie haben gewonnen!!!");
    }
    else
    {
        printf("Der Computer hat gewonnen!!!");
    }
    return 0;
}