#include <stdio.h>

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};


void printCL(Node* head)
{
    if (head == NULL)
        return;

    Node* curr = head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    }while (curr != head);

    printf("\n");
}

// O(1) - time complexity
Node* insertatEnd(Node* head, int data)
{
    Node* temp = new Node(data);

    if (head == nullptr)
    {
        head = new Node(data);
        head->next = head;
        return head;
    }

    temp->next = head->next;
    head->next = temp;
    int tdata = temp->data;
    temp->data = head->data;
    head->data = tdata;

    return temp;
}


Node* delHead(Node* head)
{
    if (head == NULL)
        return NULL;
    
    Node* curr = head->next;

    int temp = curr->data;
    curr->data = head->data ;
    head->data = temp;

    head->next = curr->next;
    delete curr;
    return head;
}

Node* delatPos(Node* head, int pos)
{
    if (head == NULL )
        return nullptr;

    // deleting head
    if (pos == 1)
    {
        Node* curr = head->next;
        int temp = curr->data;
        curr->data = head->data;
        head->data = temp;
        head->next  = curr->next;
        delete curr;
        return head;
    }

    Node* curr = head;
    for (int i =0 ; i < pos-2; i++)
        curr = curr->next;
    
    if (curr == NULL)
        return head;

    Node* temp = curr->next->next;
    delete curr->next;
    curr->next = nullptr;
    curr->next = temp;
    return head;
}

int main()
{
    Node * head = nullptr;
   /* head = insertatBegin(head, 10);
    head = insertatBegin(head, 20);
    head = insertatBegin(head, 30);
    head = insertatBegin(head, 40);*/
    head = insertatEnd(head, 10);
    head = insertatEnd(head, 20);
    head = insertatEnd(head, 30);
    head = insertatEnd(head, 40);
    head = insertatEnd(head, 50);
    //delHead(head);
    head = delatPos(head,1);
    printCL(head);
    head = delatPos(head,2);
    printCL(head);
    head = delatPos(head,3);
    printCL(head);
}