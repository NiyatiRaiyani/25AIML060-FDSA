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
Node* buildTree(vector<int> &preorder, int &index)
{
    if(index >= preorder.size() || preorder[index] == -1)
    {
        index++;
        return NULL;
    }
    Node* root = new Node(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}

int main()
{
    vector<int> preorder = {1, 2, -1,-1, 3, 4, -1, -1, 5, -1, -1};
    int index = 0;
    Node* root = buildTree(preorder, index);
}