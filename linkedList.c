#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "linkedList.h"
#include "node.h"

#define run_test(function_name)      \
	printf("%s \n", #function_name); \
	function_name()

#ifdef TESTING
void test_create_list_should_return_empty_list()
{
	printf("rodando testes");
}
run_test(test_create_list_should_return_empty_list);
#endif

struct lista
{
	struct node *head;
	int length;
};

struct node
{
	struct node *next;
	int data;
};

LinkedList *createList()
{
	printf("\nCriando uma nova LinkedList.");
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	return list;
}

Node *createNode(int data)
{
	printf("\n\nCriando novo node.");
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	printf("\nValor do node: %d", newNode->data);

	return newNode;
}

void deleteList(LinkedList *list)
{
	Node *head = list->head;
	Node *temporaryNode = NULL;

	while (head->next)
	{
		temporaryNode = head->next->next;
		free(head->next);
		head->next = temporaryNode;
	}

	list->head = NULL;
	free(list);

	printList(list);
	printf("\nLista apagada.\n");
}

LinkedList *deleteNode(LinkedList *list, int data)
{

	Node *head = list->head;
	Node *wantedNode = findNode(list, data);
	Node *temporaryNode = NULL;

	if (wantedNode != NULL && !isEmpty(list))
	{
		if (head == wantedNode)
		{
			temporaryNode = head->next;
			free(head);
			head = temporaryNode;
		}
		else
		{
			while (head)
			{
				if (head->next == wantedNode)
				{
					temporaryNode = wantedNode->next;
					free(wantedNode);
					head->next = temporaryNode;
				}
				head = head->next;
			}
		}
	}
}

LinkedList *deleteNodeFromSpecificPosition(LinkedList *list, int position)
{
	Node *head = list->head;
	Node *temporaryNode = NULL;
	int iter = 0;
	if (count(list) >= position && !isEmpty(list))
	{
		if (position == 0) //No começo da lista
		{
			temporaryNode = head->next;
			free(head);
			head = temporaryNode;
			return NULL;
		}

		if (position == count(list)) //No fim da lista
		{
			while (head->next->next)
			{
				head = head->next;
			}
			free(head->next);
			head->next = NULL;
			return NULL;
		}

		while (head)
		{
			if (iter + 1 == position)
			{
				temporaryNode = head->next->next;
				free(head->next);
				head->next = temporaryNode;
				return NULL;
			}
			else
			{
				head = head->next;
			}
		}
	}
}

LinkedList *insertNode(LinkedList *list, int data)
{
	Node *newNode = createNode(data);
	Node *temp = list->head;
	printf("\nTemp: %p", temp); //deve ser NULL

	list->head = newNode;
	newNode->next = temp;

	return list;
}

LinkedList *insertAfterSpecificNode(LinkedList *list, int data, int specificNode)
{
	Node *wantedNode = findNode(list, specificNode);
	Node *newNode = createNode(data);
	Node *tempNode = wantedNode->next;

	wantedNode->next = newNode;
	newNode->next = tempNode;

	return list;
}

LinkedList *insertEndNode(LinkedList *list, int data)
{
	Node *newNode = createNode(data);

	if (isEmpty(list) == false)
	{
		Node *head = list->head;

		while (head->next)
		{
			head = head->next;
		}

		head->next = newNode;
	}

	printf("\nElemento %d inserido no fim da lista\n", newNode->data);
	return list;
}

Node *findNode(LinkedList *list, int data)
{
	Node *head = list->head;
	int posicao = 0;

	while (head)
	{
		if (head->data == data)
		{
			return head;
		}
		else
		{
			head = head->next;
		}
		posicao++;
	}
	return NULL;
}

void printList(LinkedList *list)
{

	printf("\nElementos na lista:\n");
	if (!isEmpty(list))
	{
		Node *head = list->head;

		for (int i = 0; i < count(list); i++)
		{
			printf("[%d] %d| ", i, head->data);
			head = head->next;
		}
	}
	else
	{
		printf("Lista vazia.");
	}

	list->length = count(list);
	printf("\nQuantidade de elementos na lista: %d", list->length);
}

int getNodePosition(LinkedList *list, int data)
{
	Node *head = list->head;
	int posicao = 0;

	while (head)
	{
		if (head->data == data)
		{
			printf("\n\nEncontrado o node na posição [%d] da lista.\n\n", posicao);
			return posicao;
		}
		else
		{
			head = head->next;
		}

		posicao++;
	}

	printf("\nO node não foi encontrado na lista.\n");
	return -1;
}

Node *getHead(LinkedList *list)
{
	Node *head = list->head;
	return head;
}

Node *getNextNode(LinkedList *list)
{
	Node *next = list->head->next;
	return next;
}

int getNodeData(Node *node)
{
	return node->data;
}

bool isEmpty(LinkedList *list)
{
	if (!list->head)
	{
		return true;
	}
	return false;
}

int count(LinkedList *list)
{
	Node *cursor = list->head;
	int length_ = 0;

	while (cursor)
	{
		cursor = cursor->next;
		length_++;
	}

	return (length_);
}
