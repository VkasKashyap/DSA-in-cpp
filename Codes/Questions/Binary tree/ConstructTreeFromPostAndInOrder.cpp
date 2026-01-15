#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

Node* buildPostIn(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& inMap){

    if(postStart > postEnd || inStart > inEnd)  return NULL;

    Node* root = new Node(postorder[postEnd]);
    int inRoot = inMap[root -> data];
    int numsLeft = inRoot - inStart;

    root -> left = buildPostIn(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, inMap);

    root -> right = buildPostIn(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, inMap);

    return root;
}

Node* buildTreePostIn(vector<int>& postorder, vector<int>& inorder){
    map<int,int> inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]] = i;
    }

    return buildPostIn(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
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
    vector<int> postorder = {3,9,20,15,7}; 
    vector<int> inorder = {9,3,15,20,7}; 
    Node* root = buildTreePostIn(postorder, inorder); 
    cout << "Tree structure (level by level):" << endl; 
    printTree(root); 
    return 0; 
}