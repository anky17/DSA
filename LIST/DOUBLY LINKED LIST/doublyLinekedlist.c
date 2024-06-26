#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

void listTraversal(struct Node* head) {
  printf("Linked list: NULL<->");
  while (head != NULL) {
    printf("%d<->", head->data);
    head = head->next;
  }
  if (head == NULL) printf("NULL\n");
}

// Function to insert a node at the front of a doubly linked list
struct Node* insertAtFront(struct Node* head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = head;
  // previous of head is newNode
  head->prev = newNode;
  head = newNode;
  return head;
}

// Function to insert a node at given index of a doubly linked list
void insertAtIndex(struct Node* head, int data, int index) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  struct Node* p = head;
  newNode->data = data;
  int i = 0;
  while (i != index - 1) {
    p = p->next;
    i++;
  }
  newNode->next = p->next;
  p->next->prev = newNode;
  p->next = newNode;
  newNode->prev = p;
}

// Function to insert a node at the end of a doubly linked list
void insertAtEnd(struct Node* head, int data) {
  struct Node* ptr = head;
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = newNode;
  newNode->prev = ptr;
  newNode->next = NULL;
}

// Function to delete a node from the front of a doubly linked list
struct Node* deletefromFront(struct Node* head) {
  struct Node* p = head;
  head = head->next;
  head->prev = NULL;
  free(p);
  return head;
}

// Function to delete a node at given index of a doubly linked list
void deleteAtIndex(struct Node* head, int index) {
  struct Node* p = head;
  struct Node* q = head->next;
  int i = 0;
  for (i = 0; i < index - 1; i++) {
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  q->next->prev = p;
  free(q);
}

// Function to delete a node from the end of a doubly linked list
void deleteFromEnd(struct Node* head) {
  struct Node* p = head;
  struct Node* q = head->next;
  while (q->next != NULL) {
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
}

int main() {
  // initialize an empty node
  struct Node* head = NULL;
  struct Node* first = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  first = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));

  first->data = 7;
  second->data = 8;
  third->data = 9;

  first->prev = NULL;
  first->next = second;

  second->prev = first;
  second->next = third;

  third->prev = second;
  third->next = NULL;

  head = first;
  head = insertAtFront(head, 6);
  insertAtIndex(head, 11, 1);
  insertAtEnd(head, 9);

  printf("\nAfter insertion:\n");
  listTraversal(head);

  head = deletefromFront(head);
  deleteAtIndex(head, 1);
  deleteFromEnd(head);

  printf("\nAfter deletion:\n");
  listTraversal(head);
}
