
struct MyStack
{
    int cap;
    int *arr;
    int top1, top2;

    MyStack(int n)
    {
        cap = n;
        arr = new int[n];
        top1 = -1;
        top2 = cap;
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
    }

    int pop2()
    {
        if (top2 < cap)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
    }
};