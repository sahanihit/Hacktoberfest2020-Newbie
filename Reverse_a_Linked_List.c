/*The problem statement is simple "Reverse a linked list".

Example
Input
2
4
1 2 3 4
5
10 20 30 40 50

Output
4 3 2 1
50 40 30 20 10 */

#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node*next;
};
void append(struct Node** head_ref, int new_data) { 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node *last = *head_ref;  
  
  
    new_node->data  = new_data; 
  
   
    new_node->next = NULL; 
  
    
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
  
    while (last->next != NULL) 
        last = last->next; 
  
    
    last->next = new_node; 
    return; 
}
void reverse(struct Node** head_ref) { 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next = NULL; 
    while (current != NULL) { 
        // Store next 
        next = current->next; 
  
        // Reverse current node's pointer 
        current->next = prev; 
  
        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
void printList(struct Node *node) { 
  while (node != NULL) 
  { 
     printf("%d ", node->data); 
     node = node->next; 
  } 
} 
  int main()
  {
    int t;
    scanf("%d",&t);
    while(t--){
     int n,k,add;
      struct Node *head=NULL;
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
       scanf("%d",&k);
       append(&head,k);
     }
     reverse(&head);
     printList(head);
     printf("\n");
    }
    return 0;
  }
