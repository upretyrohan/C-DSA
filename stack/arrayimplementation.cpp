#include <stdio.h>

struct MyStack
{
    int capacity;
    int *arr;
    int top;

    MyStack(int c)
    {
        capacity = c;
        arr = new int[capacity];
        top = -1;
    }

    void push(int data)
    {
        if (top == capacity - 1)
        {
            printf("Stack Overflow\n");
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop()
    {
        if (top == -1)
        {
            printf("Stack Underflow\n");
            return -1;
        }

        int res = arr[top];
        top--;
        return res;
    }

    int peek()
    {
        if (top == -1)
        {
            printf("Stack Underflow\n");
            return -1;
        }

        return arr[top];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    int size()
    {
        return top + 1;
    }
};

int main()
{
    MyStack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    printf("%d\n", s.pop());
    printf("%d\n", s.size());
    printf("%d\n", s.peek());
    printf("%d\n", s.isEmpty());
    return 0;
}