#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Cn = (1/(n+1))*2nCn = sum(Ci*C(n-i)) , i=0 to n-1
// C0 = C1 = 1 , C2 = 2 , C3 = 5

// void file_i_o(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// }

class node{

    public:

    int data;
    node* left;
    node* right;
    
    node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

long long int catalanNth(int n){
    if(n <= 1) return 1;
    long long int result = 0;
    for(int i=0;i<n;i++){
        result += catalanNth(i)*catalanNth(n-i-1);
    }
    return result;
}

// making BSTs using concept of catalan number
vector<node*> constructBSTrees(int s,int e){
    vector<node*> trees;

    if(s>e){
        trees.push_back(nullptr);
        return trees;
    }

    for(int i=s;i<=e;i++){
        vector<node*> leftSubTrees = constructBSTrees(s,i-1);
        vector<node*> rightSubTrees = constructBSTrees(i+1,e);

        for(unsigned int j=0;j<leftSubTrees.size();j++){
            for(unsigned int k=0;k<rightSubTrees.size();k++){
                node* newNode = new node(i);
                newNode->left = leftSubTrees[j];
                newNode->right = rightSubTrees[k];
                trees.push_back(newNode);
            }
        }
    }
    return trees;
}

void printInorder(node* root){
    if(root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){
    // int n=5,a,b,c;
    // cin >> n >>a>>b;
    // cout << n;
    // cout << catalanNth(n) << endl;
    // for(int i=0;i<n;i++) cout << catalanNth(i) << " ";
    // cout << endl;

    vector<node*> trees = constructBSTrees(1,3);
    for (unsigned int i = 0; i < trees.size(); i++)
    {
        printInorder(trees[i]);
        cout << endl;
    }
    
    return 0;
}
