#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

typedef struct
{
	unsigned int i_debut;
	unsigned int i_fin;
	unsigned int pas;
	unsigned int flag;
	pthread_cond_t* cond;
	pthread_mutex_t* mut;
	int flag
	int* A;
} paramThread;

void worker(paramThread* p)
{
	pthread_mutex_lock(p->mut);
	while(1){
	pthread_cond_wait(cond, mt);
	if(!p->flag){pthread_exit(0);}
void initialiserTableau(int* tab, unsigned int n)
{
	unsigned int i;
	for(i = 0; i < n; i++)
		tab[i] = 1;

	tab[0] = 0;
	tab[1] = 0;
}
}
}



void crible(int* A, int n, int nbThread)
{
	unsigned int i, j;
	unsigned int intervalle;

	pthread_t* threads = malloc(nbThread*sizeof(pthread_t));
	pthread_mutex_t* mutex = malloc(nbThread*sizeof(int));
	pthread_cond_t* condition;
	pthread_cond_init (&condition[i], NULL);

	paramThread* params = malloc(nbThread*sizeof(paramThread));

	for(i = 0; i < nbThread; i++)
	{

	 	pthread_mutex_init(&mutex[i], NULL);
		params[i].flag=1;
		params[i].mut=&mutex[i];
		params[i].cond=condition;

		pthread_create(&threads[i], NULL, (void*) worker, &params[i]);
	}

	for(i = 2; i*i < n; i++)  //i de 2 à sqrt(n)
		if(A[i])
		{
			for(j = 0; j < nbThread; j++)
			{
				intervalle = (n - i*i)/(i*nbThread);
				//TODO: initialiser params
				params[i].i_debut = i*i+j*intervalle;
				params[i].i_fin = i*i+(j+1)*intervalle;
				params[i].pas = i;
				params[i].A = A;
				if (i!=2)
				pthread_mutex_unlock(mutex[j]);

			}
			pthread_cond_broadcast(condition) ;
			for(j = 0; j < nbThread; j++)
			{
				pthread_mutex_lock(mutex[j]);

			}

		}
		for(j = 0; j < nbThread; j++)
		{
			params[i].flag=0;
			



	free(threads);
	free(params);
}

int main(int argc, char** argv)
{
	clock_t t1, t2;
	float duree;
	unsigned int i;

	if(argc == 3)
	{
		unsigned int n = atoi(argv[1]);
		unsigned int nbThread = atoi(argv[2]);

		int* A = malloc(sizeof(int) * n);
		initialiserTableau(A, n);

		t1 = clock();

		crible(A, n, nbThread);

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
