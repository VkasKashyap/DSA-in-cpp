#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

Node* buildPreIn(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& inMap){
    if(preStart > preEnd || inStart > inEnd)    return NULL;

    Node* root = new Node(preorder[preStart]);
    int inRoot = inMap[root -> data];
    int numsLeft = inRoot - inStart;

    root -> left = buildPreIn(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap);

    root -> right = buildPreIn(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);
}

Node* buildTreePreIn(vector<int>& preorder, vector<int>& inorder){
    map<int,int> inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]] = i;
    }
    return buildPreIn(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
}

void printTree(Node* root){ 
    if(!root) return; 
    queue<Node*> q; 
    q.push(root); 
    while(!q.empty()){ 
        int size = q.size(); 
        while(size--){ 
            Node* curr = q.front(); 
            q.pop(); 
            if(curr){ 
                cout << curr->data << " "; 
                q.push(curr->left); 
                q.push(curr->right); 
            } 
            else { 
                cout << "null "; 
            } 
        } 
        cout << endl;  
    } 
}

int main(){ 
    vector<int> preorder = {3,9,20,15,7}; 
    vector<int> inorder = {9,3,15,20,7}; 
    Node* root = buildTreePreIn(preorder, inorder); 
    cout << "Tree structure (level by level):" << endl; 
    printTree(root); 
    return 0; 
}