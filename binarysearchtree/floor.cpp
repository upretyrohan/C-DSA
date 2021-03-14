#include <stdio.h>
#include <queue>
/*  10
    / \
   5  20
  /   / \ 
3    18 80
    /
    16
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
Node* floor (Node* root, int x)
{
    Node* res = nullptr; 
    while (root != nullptr)
    {
        if (x == root->data)
            return root;

        else if (x < root->data)
            root = root->left;    

        else if (x  > root->data)
        {
            res = root;
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
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 18);
    root = insert(root, 80);
    root = insert(root, 16);
    printBST(root);
    root = floor(root, 23);
    printf("%d", root->data);
    //root = floor(root, 10);
    //printBST(root);
}