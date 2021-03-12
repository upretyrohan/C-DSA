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
}

// O(1) - time complexity
Node* insertatBegin(Node *head, int data)
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

    return head;
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
    printCL(head);
}