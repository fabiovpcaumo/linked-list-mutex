#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	LinkedList* linkedList;
	linkedList = createList();
	printf("%s", isEmpty(linkedList) ? "true": "false");
	
	printList(linkedList);
	
	insertNode(linkedList, 3);
	printList(linkedList);
	
	insertNode(linkedList, 5);
	printList(linkedList);
	
	insertEndNode(linkedList, 99);
	insertNode(linkedList, 7);
	printList(linkedList);
	
	insertEndNode(linkedList, 9932);
	printList(linkedList);
	
	getNodePosition(linkedList, 99);
	insertAfterSpecificNode(linkedList, 84, 5);
	printList(linkedList);
	
	printf("%p", findNode(linkedList, 98));
	printf("\nQuantidade de elementos na lista: %d", count(linkedList));
	
	printList(linkedList);
	
}
