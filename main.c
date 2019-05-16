#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"
#include <locale.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#define THREADS_AMMOUNT 120

pthread_t threads[THREADS_AMMOUNT];
pthread_mutex_t list_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t list_cond = PTHREAD_COND_INITIALIZER;
LinkedList *linkedList;

void *addOnList(void *lista)
{
	pthread_mutex_lock(&list_lock);

	srand(time(NULL));
	int value = rand();

	printf("\nInserindo valor na lista: %d\n", value);

	insertNode(lista, value);
	pthread_mutex_unlock(&list_lock);
}

void *readList(void *lista)
{
	pthread_mutex_lock(&list_lock);
	printf("Lendo a lista...");

	printList(lista);
	pthread_mutex_unlock(&list_lock);
}

void *deleteFromList(void *lista)
{
	pthread_mutex_lock(&list_lock);
	printf("Deletando da lista...");

	Node *node = findNode(lista, 5);
	if (node != NULL)
	{

		deleteNode(lista, getNodeData(node));
	}

	pthread_mutex_unlock(&list_lock);
}

int main()
{
	int err;
	setlocale(LC_ALL, "Portuguese");
	LinkedList *linkedList;
	linkedList = createList();

	for (int i = 0; i < THREADS_AMMOUNT; i += 3)
	{
		pthread_create(&threads[i], NULL, &addOnList, linkedList);
		pthread_create(&threads[i + 1], NULL, &readList, linkedList);
		pthread_create(&threads[i + 2], NULL, &deleteFromList, linkedList);
	}

	// // Libera o espaço de memória das threads
	for (int i = 0; i < THREADS_AMMOUNT; ++i)
		pthread_join(threads[i], NULL);

	pthread_mutex_destroy(&list_lock);
	printf("Tamanho da lista: %d", count(linkedList));
	readList(linkedList);
	getchar();
	return 0;
}
