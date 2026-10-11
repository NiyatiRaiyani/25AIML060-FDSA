#include<iostream>
#include<vector>
using namespace std;
class Node
{   
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

static int index = -1;
Node* buildTree(vector<int> preorder)
{
    index++;
    if(preorder[index] == -1)
    {
        return NULL;
    }
    Node* root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;
    Node* root = buildTree(preorder);
    cout << "Root Node: " << root->data << endl;
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;
    cout << "Left Child of Right Child: " << root->right->left->data << endl;
    cout << "Right Child of Right Child: " << root->right->right->data << endl;
    cout << "Left Child of Left Child: " << (root->left->left ? to_string(root->left->left->data) : "NULL") << endl;
    cout << "Right Child of Left Child: " << (root->left->right ? to_string(root->left->right->data) : "NULL") << endl; 
    return 0;
}