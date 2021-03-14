#include <stdio.h>
#include <queue>
/*  10
    / \
   5  15
     / \ 
    12 30

*/

struct Node
{
    int data;
    Node *left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void printBST(Node* root)
{
    if (root == nullptr)
        return;
    
    std::queue<Node*> q;
    q.push(root);
    while(q.empty() == false)
    {
        Node* curr = q.front();
        q.pop();
        printf("%d ", curr->data);
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }

    printf("\n");
}

Node* insert(Node* root, int x)
{
    Node* temp  = new Node(x);
    Node* parent = NULL, *curr = root;
    while ( curr != nullptr)
    {
        parent = curr;
        if (x < curr->data)
            curr = curr->left;
        else if (x > curr->data)
            curr = curr->right;
        else if ( x == curr->data)
            return root;
    }

    if (parent == nullptr)
        return temp;
    else if (parent->data > x)
        parent->left = temp;
    else if (parent->data < x)
        parent->right = temp;

    return root;
}

// O(H)
// O(1)
Node* ceil (Node* root, int x)
{
    Node* res = nullptr; 
    while (root != nullptr)
    {
        if (x == root->data)
            return root;

        else if (x < root->data)
        {   
            res = root;
            root = root->left;
        }    

        else if (x  > root->data)
        {
            root = root->right;
        }  
    }

    return res;
}

int main()
{
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 12);
    root = insert(root, 30);
    printBST(root);
    //root = ceil(root, 14);
    //printf("%d", root->data);
    //root = ceil(root, 5);
    //printf("%d", root->data);
    root = ceil(root, 40);
    if (root)
        printf("%d", root->data);
    else 
      printf("empty");
}