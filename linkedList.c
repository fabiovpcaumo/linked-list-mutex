#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "linkedList.h"
#include "node.h"
#include <locale.h>

struct lista{
	int length;
	struct node* head;
	
};

struct node{
	struct node* next;
	int data; 

};

LinkedList* createList(){
	printf("\nCriando uma nova LinkedList.");
	LinkedList* list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->length = 0;
	return list;
}

Node* createNode(int data){
	printf("\n\nCriando novo node.");
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	
	printf("\nPróximo node: %p", newNode->next);
	printf("\nValor do node: %d", newNode->data);
	
	return newNode;
}

LinkedList* insertNode(LinkedList* list, int data){
	
	Node* newNode = createNode(data);
	Node* temp = list->head;
	printf("\nTemp: %p", temp); //deve ser 00000000000
	list->head = newNode;
	newNode->next = temp;
	list->length++;
		
	return list;
}

LinkedList* insertEndNode(LinkedList* list, int data){
	
	Node* newNode = createNode(data);
	
	if(isEmpty(list) != true){
		printf("\nLista vazia!");
	}
}

LinkedList* deleteNode(LinkedList* list, int data){
	
	return NULL;
}

Node* find(LinkedList* list, int data){
	
}

bool isEmpty(LinkedList* list){
	
	if(list->head){
		return true;
	}
	return false;
}

void printList(LinkedList* list){


	printf("\nElementos na lista:\n");
	if(isEmpty(list) != false){
		Node* head = list->head;
		
		while(head){
			
			printf("%d| ", head->data);
			head = head->next;
		}
	}

	printf("\nTamanho da lista: %d", list->length);
}
