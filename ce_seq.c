#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initialiserTableau(int* tab, unsigned int n)
{
	unsigned int i;
	for(i = 0; i < n; i++)
		tab[i] = 1;

	tab[0] = 0;
	tab[1] = 0;
}

void crible(int* A, int n)
{
	unsigned int i, j;
	for(i = 2; i*i < n; i++)  //i de 2 à sqrt(n)
		if(A[i])
			for(j = i*i; j < n; j+=i)
				A[j] = 0;
}

int main(int argc, char** argv)
{
	clock_t t1, t2;
	float duree;
	unsigned int i;

	if(argc == 2)
	{
		unsigned int n = atoi(argv[1]);
		int* A = malloc(sizeof(int) * n);
		initialiserTableau(A, n);

		t1 = clock();
		
		crible(A, n);
		
		t2 = clock();
		duree = (float) (t2-t1) / CLOCKS_PER_SEC;
		printf("Durée de l'algorithme: %f\n", duree);

		printf("Nombres premiers trouvés: \n");
		for(i = 0; i < n; i++) if(A[i]) printf("%d ", i);

		free(A);
	}
	else fprintf(stderr, "Nombre de paramètres incorrect");
	
	return 0;
}
