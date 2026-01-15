#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node (int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTreeFromInput(){
    int data;
    cout<<"Enter root data (-1 for NULL) : ";
    cin>>data;
    if(data == -1)  return NULL;

    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        int leftData, rightData;
        cout<<"Enter left child of "<<curr->data<<": ";
        cin>>leftData;
        if(leftData != -1){
            curr -> left = new Node(leftData);
            q.push(curr->left);
        }

        cout<<"Enter the right child of "<<curr->data<<": ";
        cin>>rightData;
        if(rightData != -1){
            curr -> right = new Node(rightData);
            q.push(curr->right);
        }
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (!root) return; 
    inorderTraversal(root->left); 
    cout << root->data << " "; 
    inorderTraversal(root->right); 
} 

int main() { 
    Node* root = buildTreeFromInput(); 
    cout << "\nInorder Traversal of the tree: "; 
    inorderTraversal(root); 
    cout << endl; 
    return 0; 
}