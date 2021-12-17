#include <stdio.h>

struct edge { int from, to; };

void printArray(int n, int array[])
{
  for(int i = 0; i < n; i++)
    {
      printf("%i",array[i]);
    }
}

int find0(int n, int count[])
{
  for(int i = 0; i < n; i++)
  {
    if(count[i] == 0) return i;
  }
  return -1;
}

void topsort(int n, int e, struct edge edges[], int ord[]) 
{
    //Array der Elternanzahl
	int count[n];

    for(int i = 0; i < n; i++)
    {
      count[i] = 0;
    }

    for(int i = 0; i < e; i++)
    {
      count[edges[i].to]++;
    }
  
    //Sortieren
    int zero;

    for(int i = 0; i < n; i++)
    {
      zero = find0(n, count);

      count[zero] = -1;
      
      if(zero == -1)
      {
        printf("Es gibt keine topologische Sortierung");
        return;
      }

      ord[i] = zero;

      for(int i2 = 0; i2 < e; i2++)
      {
        if(edges[i2].from == zero) count[edges[i2].to]--;
      }
    }

    

}




// ============================================
// 					Helper
// ============================================
void printorder(int list[], int length){	
	for(int i = 0;	i < length; i++){
		if(list[i] == -1){
			printf("Keine gültige Sortierung!");
			return;		
		}	
	}
	printf("length=%i\n", length);
	for(int ordv = 1; ordv <= length; ordv++){	
		for(int i = 0;	i < length; i++){
			if(list[i] == ordv){
				printf("ord[%i]=%i\n", i,ordv);
				break;
			}
		}
	}
}

int main(){
	// Initialisierung der Knotenmenge, startend mit 0
	int n = 5; // 0,1,2,...,5

	// Initialisierung der Kantenmenge
	struct edge edges[] = {
		{.from= 0, .to= 1},
		{.from= 0, .to= 3},
		{.from= 1, .to= 2},
		{.from= 1, .to= 4},
		{.from= 3, .to= 2},
		{.from= 3, .to= 4}
	};

	// Berechnen der Menge von Kanten
	int e = sizeof(edges) / sizeof(struct edge);

	// Initialisieren von ord mit so vielen Einträgen wie Knoten; jeweils -1
	int ord[n];
	for(int i = 0; i<n; i++)
		ord[i] = -1;

	// Sortieren
	topsort(n, e, edges, ord);

    printArray(n, ord);

	// Ausgabe der Sortierung
	printorder(ord, n);
	return 0;
}
