#include <stdio.h>

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

struct MyStack
{
    Node *head;
    int capacity;

    MyStack()
    {
        head = nullptr;
        capacity = 0;
    }

    void push(int d)
    {
        Node *temp = new Node(d);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        capacity++;
    }

    int pop()
    {
        if (head == nullptr)
            return -1;
        Node *temp = head->next;
        delete head;
        capacity--;
        head = nullptr;
        head = temp;
        return head->data;
    }

    int peek()
    {
        if (head == nullptr)
            return -1;

        return head->data;
    }

    bool isEmpty()
    {
        if (head == nullptr)
            return true;
        else
            return false;
    }

    int size()
    {
        return capacity;
    }
};

int main()
{
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    printf("%d\n", s.pop());
    printf("%d\n", s.size());
    printf("%d\n", s.peek());
    printf("%d\n", s.isEmpty());
    return 0;
}
