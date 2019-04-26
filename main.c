#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	LinkedList* linkedList;
	linkedList = createList();
	printList(linkedList);
	
	insertNode(linkedList, 3);
	printList(linkedList);
	
	insertNode(linkedList, 5);
	printList(linkedList);
	
	insertNode(linkedList, 7);
	printList(linkedList);
	
}
