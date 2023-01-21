#ifndef C_DOUBLY_LINKED_LIST_H
#define C_DOUBLY_LINKED_LIST_H

typedef struct node{
    int data;
    struct node * prev;
    struct node *next;
}Node;

Node * createNode(int data);
void traverseAndPrint(Node *head);
int nodeCount(Node *head);
void insertAtEnd(Node **head, int data);
void insertAtBeginning(Node **head, int data);
void insertBefore(Node **head, int data, int index);
void insertAfter(Node **head, int data, int index);
void deleteFirst(Node **head);
void deleteLast(Node **head);
void deleteIndex(Node ** head, int index);
Node * createList(int length);
Node * deleteList(Node *head);
Node * reverseList(Node *head);
Node * lastNode(Node *head);
void copyList(Node **source, Node **destination);
Node * concat(Node *list1, Node *list2);

//void insertAtEnd(Node **tail, int data);

Node * createNode(int data){
    Node *newNode = (Node*) malloc(sizeof (Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void traverseAndPrint(Node *head){
    Node *temp = head;
    if (temp == NULL){
        printf("The list is empty.\n");
        return;
    }
    while (1){
        printf("%d  ", temp->data);
        if (temp->next != NULL) temp = temp->next;
        else break;
    }
}


int nodeCount(Node *head){
    int i = 0;
    Node *temp = head;
    while (1){
        if (temp != NULL && ++i){
            temp = temp->next;
        } else break;
    }
    return i;
}

void insertAtEnd(Node **head, int data){
    Node *temp = *head, *newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtBeginning(Node **head, int data){
    Node *newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}

void insertBefore(Node **head, int data, int index){
    Node *newNode = createNode(data), *temp = *head;
    if (index == 0){
        insertAtBeginning(head, data);
    } else {
        if (index > nodeCount(*head)-1){
            printf("Error : Index not available. The index of last node => %d\n", nodeCount(*head)-1);
            return;
        }
        for (int i = 0; i < index-1; ++i) temp = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(Node **head, int data, int index) {
    Node *newNode = createNode(data), *temp = *head;
    if (index > nodeCount(*head) - 1) {
        printf("Error : Index not available. The index of last node => %d\n", nodeCount(*head) - 1);
        return;
    }
    for (int i = 0; i < index; ++i) temp = temp->next;
    if(temp->next != NULL) temp->next->prev = newNode;
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst(Node **head){
    if (*head==NULL){
        printf("The list is empty.\n");
        return;
    }
    Node * temp = *head;
    *head = temp->next;
    free(temp);
    if (*head != NULL) (*head)->prev = NULL;
}

void deleteLast(Node **head){
    Node * temp = *head, * temp2 = *head;
    if (*head == NULL) printf("The list is empty.\n");
    else if (temp->next == NULL){
        free(*head);
        *head = NULL;
    } else{
        while (temp->next != NULL){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
    }
}

void deleteIndex(Node **head, int index){
    Node *temp1 = *head, *temp2 = NULL;
    if (*head == NULL) printf("List is empty.\n");
    else if (index == 0){
        deleteFirst(head);
    } else{
        if (index > nodeCount(*head)-1){
            printf("Error : Index not available. The index of last node => %d\n", nodeCount(*head) - 1);
            return;
        }
        for (int i = 0; i < index-1; ++i) temp1 = temp1->next;
        temp2 = temp1->next->next;
        free(temp1->next);
        temp1->next = temp2;
        if (temp2 != NULL) temp2->prev = temp1;
    }
}

Node * createList(int length){
    if (length <= 0) return NULL;
    int n = 0;
    scanf("%d",&n);
    Node * newList = createNode(n);
    for (int i = 0; i < length-1; ++i) {
        scanf("%d",&n);
        insertAtEnd(&newList, n);
    }
    return newList;
}

Node * deleteList(Node *head){
    Node * temp = head;
    while (temp != NULL){
        temp = temp->next;
        free(head);
        head = temp;
    }
    return head;
}

Node * reverseList(Node *head){
    Node * temp1 = NULL, * temp2 = NULL;
    if (head == NULL || head->next == NULL) return head;
    while (head != NULL){
        temp2 = head->next;
        head->next = temp1;
        temp1 = head;
        head = temp2;
        temp1->prev = head;
    }
    head = temp1;
    return head;
}

Node * lastNode(Node *head){
    Node *temp = head;
    if (temp == NULL) return NULL;
    while (1){
        if (temp->next != NULL) temp = temp->next;
        else break;
    }
    return temp;
}

// The destination has to be empty list.
// Copy only data, not the address
// Time complexity -> O(n)
void copyList(Node **source, Node **destination){
    Node *temp = *source;
    if (temp == NULL) {
        *destination = NULL;
        return;
    }
    *destination = createNode(temp->data);
    while (temp->next != NULL){
        temp = temp->next;
        insertAtEnd(destination, temp->data);
    }
}

// Concatenate the lists and return the concatenated list
// Time complexity -> O(n)
Node * concat(Node *list1, Node *list2){
    if (list1 == NULL) return list2;
    Node *tailOfList1 = lastNode(list1);
    tailOfList1->next = list2;
    list2->prev = tailOfList1;
    return list1;
}


/*
If the address of the last node is known.
Time complexity -> O(1)
*/
//void insertAtEnd(Node **tail, int data){
//    if (*tail == NULL){
//        *tail = createNode(data);
//        return;
//    }
//    Node *newNode = createNode(data);
//    (*tail)->next = newNode;
//}

#endif
