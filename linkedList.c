#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

LinkedList* insertAfterSpecificNode(LinkedList* list, int data, int specificNode){
	
	return NULL;
}

LinkedList* insertEndNode(LinkedList* list, int data){
	Node* newNode = createNode(data);
	Node* head = list->head;
	Node* lastNode = NULL;
	
	if(isEmpty(list) == false){
		Node* head = list->head;
		
		while(head->next){
			head = head->next;
		}
		
		head->next = newNode;
		list->length++;
	}
		
	printf("\nElemento %d inserido no fim da lista\n", newNode->data);
	return list;
}

LinkedList* deleteNode(LinkedList* list, int data){
	
	return NULL;
}

Node* findNode(LinkedList* list, int data){
	Node* head = list->head;
	int posicao = 0;
	
	while(head){
		if(head->data == data){
//			printf("\n\nEncontrado o node de valor [%d] na posição [%d] da lista.\n\n", head->data, posicao);
			return head;
		}else{
			head = head->next;
		}
		posicao++;
	}
//	printf("O node não foi encontrado na lista.");
	return NULL;
}

int getNodePosition(LinkedList* list, int data){
	Node* head = list->head;
	int posicao = 0;

	while(head){
		if(head->data == data){
			printf("\n\nEncontrado o node na posição [%d] da lista.\n\n", posicao);
			return posicao;
		}else{
			head = head->next;
		}
		
		posicao++;
		}
	
	printf("\nO node não foi encontrado na lista.\n");
	return -1;
}


bool isEmpty(LinkedList* list){
	
	if(list->head){
		return false;
	}
	return true;
}

void printList(LinkedList* list){

	printf("\nElementos na lista:\n");
	if(isEmpty(list) == false){
		Node* head = list->head;
		
		while(head){
			
			printf("%d| ", head->data);
			head = head->next;
		}
	}

	printf("\nElementos na lista: %d\n", list->length);
}
