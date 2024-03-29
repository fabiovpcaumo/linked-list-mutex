#include <stdbool.h>
#include "node.h"

typedef struct lista LinkedList;

//Cria uma lista vazia
LinkedList *createList();

//Insere um node no começo da lista
LinkedList *insertNode(LinkedList *list, int data);

//Insere um node após o node especificado
LinkedList *insertAfterSpecificNode(LinkedList *list, int data, int specificNode);

//Insere um node no final da lista
LinkedList *insertEndNode(LinkedList *list, int data);

//Remove um elemento da lista
LinkedList *deleteNode(LinkedList *list, int data);

//Remove um elemento de uma posição específica da lista
LinkedList *deleteNodeFromSpecificPosition(LinkedList *list, int position);

//Encontra a posição de um Node da lista
int getNodePosition(LinkedList *list, int data);

//Retorna o próximo Node de uma lista
Node *getNextNode(LinkedList *list);

//Retorna o head da lista
Node *getHead(LinkedList *list);

//Retorna o valor dentro de um node da lista
int getNodeData(Node *node);

//Encontra um node na lista
Node *findNode(LinkedList *list, int data);

//Printa o conteúdo da lista
void printList(LinkedList *list);

//Verifica se a lista está vazia
bool isEmpty(LinkedList *list);

//Conta o número de elementos na lista
int count(LinkedList *list);

//Função para deletar a lista
void deleteList(LinkedList *list);
