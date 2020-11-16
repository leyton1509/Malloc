#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#define _XOPEN_SOURCE 500
#define _DEFAULT_SOURCE
#include <unistd.h>

typedef struct node {
	int used;
	struct node* next;
	size_t size;
	struct node* prev;
} node;

node * initiateList(int size) {
	struct node* head = NULL;
	head->size = size;
	head->next = NULL;
	head->used = 0;
	head->next = NULL;
	return head;
}

int removeEndNode(node * head) {

	if (head->next == NULL) {
		return 1;
	}

	node* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	free(current->next);
	current->next = NULL;

	return 1;
}

void addNodeEnd(node * head, int size) {
	node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	struct node*  new_node;
	new_node = sbrk(0);
	new_node->size = size;
	new_node->next = NULL;
	new_node->used = 0;
	current->next = &new_node;
	current->next->next = NULL;
}

void printNodes(node * head) {
	node* current = head;
	while (current != NULL) {
		printf("%d ",current->used);
		current = current->next;
	}
}

void push(node* head) {
	struct node * new_node;
	new_node = head;

	new_node->next = head;
	head = new_node;
}

int pop(node** head) {
	node* next_node = NULL;

	if (*head == NULL) {
		return -1;
	}

	next_node = (*head)->next;
	*head = next_node;

	return 1;
}

/*
int remove_by_index(node** head, int n) {
	int i = 0;
	int retval = -1;
	node* current = *head;
	node* temp_node = NULL;

	if (n == 0) {
		return pop(head);
	}

	for (i = 0; i < n - 1; i++) {
		if (current->next == NULL) {
			return -1;
		}
		current = current->next;
	}

	temp_node = current->next;
	retval = temp_node->value;
	current->next = temp_node->next;
	free(temp_node);

	return retval;

}
*/


int main(int argc, char* argv[]) {

	node* head = initiateList(6);
	addNodeEnd(head, 4);
	addNodeEnd(head, 7);
	addNodeEnd(head, 9);
	addNodeEnd(head, 10);
	addNodeEnd(head, 20);
	addNodeEnd(head, 2);
	addNodeEnd(head, 10);
	printNodes(head);



}