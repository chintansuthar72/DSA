#include<iostream>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    explicit node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

struct information {
    int size;
    int maximum;
    int minimum;
    int ans;
    bool isBst;
};

information largestBSTinBinaryTree(node* root) {
    
    if(root == nullptr) {
        return { 0,INT_MIN,INT_MAX,0,true }; // default 
    }

    if(root->left == nullptr and root->right == nullptr) { // leaf node
        return { 1,root->data,root->data,1,true };
    }

    information leftInformation = largestBSTinBinaryTree(root->left);
    information rightInformation = largestBSTinBinaryTree(root->right);

    information currentInformation;
    currentInformation.size = 1+ leftInformation.size + rightInformation.size;
    if(leftInformation.isBst && rightInformation.isBst) {
        if(leftInformation.maximum < root->data && rightInformation.minimum > root->data) {
            currentInformation.isBst = true;
            currentInformation.minimum = min(rightInformation.minimum,min(root->data,leftInformation.minimum));
            currentInformation.maximum = max(rightInformation.maximum,max(root->data,leftInformation.maximum));
            currentInformation.ans = currentInformation.size;

            return currentInformation;
        }
    }
    
    currentInformation.ans = max(rightInformation.ans,leftInformation.ans);
    currentInformation.isBst = false;

    return currentInformation;
}

void printInformation(struct information x) {
    cout << x.size << endl;
    cout << x.maximum << endl;
    cout << x.minimum << endl;
    cout << x.size << endl;
    cout << x.isBst << endl;
}

int main() {

    // node* root = new node(5);
    // root->left = new node(3);
    // root->right = new node(6);
    // root->left->left = new node(2);
    // root->left->right = new node(4);

    node* root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    // information check = largestBSTinBinaryTree(root);
    // printInformation(check);
    cout << largestBSTinBinaryTree(root).ans << endl;
    return 0;
}