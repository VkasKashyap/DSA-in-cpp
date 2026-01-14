#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);

    cout<<"Root : "<<root -> data<<endl;
    cout<<"Left child of root : "<<root -> left -> data<<endl;
    cout<<"Right child of root : "<<root -> right -> data<<endl;
    cout<<"Left child of node 2 : "<<root -> left -> left -> data<<endl;

    return 0;
}