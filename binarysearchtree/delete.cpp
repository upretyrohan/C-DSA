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

Node* getsuccessor(Node* root)
{
    Node* curr = curr->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}
// O(H)
// O(H)
Node* deleteNode(Node* root, int x)
{
    if (root == nullptr)
        return root;
    
    if (root->data > x)
        root->left = deleteNode(root->left, x);

    else if (root->data < x)
        root->right = deleteNode(root->right, x);
    
    else
     {
         if (root->left == nullptr)
         {
             Node* temp = root->right;
             delete root;
             return temp;
         }

        else if (root->right == nullptr)
         {
             Node* temp = root->left;
             delete root;
             return temp;
         }
        else
        {
             Node * succ = getsuccessor(root);
            root->data= succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
     }
     return root;
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
    root = deleteNode(root, 16);
    printBST(root);
    root = deleteNode(root, 10);
    printBST(root);
}