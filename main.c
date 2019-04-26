#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	LinkedList* linkedList;
	linkedList = createList();
	printList(linkedList);
	
	insertEndNode(linkedList, 3);
	insertNode(linkedList, 3);
	printList(linkedList);
	
	insertNode(linkedList, 5);
	printList(linkedList);
	
	insertEndNode(linkedList, 3);
	insertNode(linkedList, 7);
	printList(linkedList);
	
}
