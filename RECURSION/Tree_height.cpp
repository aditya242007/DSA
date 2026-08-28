#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node (int val) : data(val), left(nullptr), right(nullptr){}
};

int height(Node* root){
    if(root == nullptr) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1+ max(left,right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout<< height(root) <<endl;
    return 0;
}