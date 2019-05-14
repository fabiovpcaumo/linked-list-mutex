#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"
#include <locale.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#define THREADS_AMMOUNT 200

pthread_t threads[THREADS_AMMOUNT];
pthread_mutex_t lock;
LinkedList *linkedList;

void *addOnList(void *lista)
{
	pthread_mutex_lock(&lock);

	srand(time(NULL));
	int value = rand();

	printf("\nInserindo valor na lista: %d\n", value);

	insertNode(lista, value);
	pthread_mutex_unlock(&lock);
}

void *readList(void *lista)
{
	pthread_mutex_lock(&lock);
	printf("Lendo a lista...");

	readList(lista);
	pthread_mutex_unlock(&lock);
}

void *deleteFromList(void *lista)
{
	pthread_mutex_lock(&lock);
	printf("Deletando da lista...");

	Node *node = findNode(lista, 5);
	if (node != NULL)
	{

		deleteNode(lista, getNodeData(node));
	}

	pthread_mutex_unlock(&lock);
}

int main()
{
	int err;
	setlocale(LC_ALL, "Portuguese");
	LinkedList *linkedList;
	linkedList = createList();

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\nOcorreu um erro ao inicializar o Mutex.");
		return 1;
	}

	for (int i = 0; i < THREADS_AMMOUNT; i += 4)
	{
		pthread_create(&threads[i], NULL, &addOnList, linkedList);
		pthread_create(&threads[i + 1], NULL, &readList, linkedList);
		pthread_create(&threads[i + 2], NULL, &deleteFromList, linkedList);
		pthread_create(&threads[i + 3], NULL, &readList, linkedList);
	}

	// // Libera o espaço de memória das threads
	// for (int i = 0; i < THREADS_AMMOUNT; i++)
	// 	pthread_join(threads[i], NULL);

	pthread_mutex_destroy(&lock);
	getchar();
	return 0;
}
