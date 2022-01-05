#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define loop(a,b,inc) for(int i=a;i<=b;i+=inc)
//#define oset tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
//using namespace __gnu_pbds;

// tree height n = 2^h - 1 => h=log(1+n) => O(log(n))
// inorder is sorted in BST
void file_i_o(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

class node{
    public:
    int data;
    node *left,*right;

    explicit node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node* insertBST(node* root,int val){
    if(root == nullptr) return new node(val);
    if(val > root->data){
        root->right = insertBST(root->right,val);
    }
    if(val<root->data){
        root->left = insertBST(root->left,val);
    }
    return root;
}

bool searchBST(node* root,int x){
    if(root == nullptr)
        return false;
    if(root->data == x) return true;
    if(root->data > x){
        return searchBST(root->left,x);
    }
    if(root->data < x){
        return searchBST(root->right,x);
    }
    return false;
}

node* inorder_succoser(node* root){
    node* tmp=root;
    while (tmp && tmp->left!=nullptr)
    {
        tmp=tmp->left;
    }
    return tmp;
}

node* deleteInBST(node* root,int x){
    if(root->data == x){
        if(root->left == nullptr){
            node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->right == nullptr){
            node* tmp = root->left;
            delete root;
            return tmp;
        }
        node* tmp = inorder_succoser(root);
        root->data = tmp->data;
        root->right = deleteInBST(root->right,tmp->data);
    }
    else if(root->data > x){
        root->left = deleteInBST(root->left,x);
    }
    else{
        root->right = deleteInBST(root->right,x);
    }
    return root;
}

int searchOfElement(vector<int> ino,int s,int e,int x){
    for(int i=s;i<e;i++){
        if(x == ino[i]){
            return i;
        }
    }
    return -1;
}

node* preorderToBST(int preo[],const vector<int>& ino,int s,int e){
    static int idx=0;
    if(s>e){
        return nullptr;
    }
    node* root = new node(preo[idx]);
    idx++;
    if(s==e) return root;
    int pos = searchOfElement(ino,s,e,preo[idx]);
    root->right = preorderToBST(preo,ino,pos+1,e);
    root->left = preorderToBST(preo,ino,s,pos-1);
    return root;
}

void inorderDisplay(node* root){
    if(root== nullptr) return;
    inorderDisplay(root->left);
    cout<<root->data<<" ";
    inorderDisplay(root->right);
}

void preorderDisplay(node* root){
    if(root == nullptr) return ;
    cout<<root->data<<" ";
    preorderDisplay(root->left);
    preorderDisplay(root->right);
}

int maxOfTree(node* root){
    if(root == nullptr) return INT_MIN;
    if(root->left == nullptr && root->right == nullptr) return root->data;
    return max(maxOfTree(root->right),maxOfTree(root->left));
}

int minOfTree(node* root){
    if(root == nullptr) return INT_MAX;
    if(root->left == nullptr && root->right == nullptr) return root->data;
    return min(minOfTree(root->right),minOfTree(root->left));
}

bool isBST(node* root){
    if(root == nullptr) return true;
    if(root->data > maxOfTree(root->left) && root->data < minOfTree(root->right)){
        return isBST(root->left) && isBST(root->right);
    }
    else{
        return false;
    }
}

node* createBSTfromSortedArray(int sorted[],int l,int r){
    if(l>r) return nullptr;
    int mid = (l+r)/2;
    node* root = new node(sorted[mid]);
    root->left = createBSTfromSortedArray(sorted,l,mid-1);
    root->right = createBSTfromSortedArray(sorted,mid+1,r);
    return root;
}

void swap(int *a,int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void getpointersvalues(node* root,node** first,node** last,node** prv,node** mid) {

    if(root == nullptr) return;

    getpointersvalues(root->left,first,last,prv,mid);

    if(*prv && root->data < (*prv)->data) {
        if(*first == nullptr) {
            *first = *prv;
            *mid = root;
        }
        else {
            *last = root;
        }
    }
    *prv = root;
    getpointersvalues(root->right,first,last,prv,mid);

}

void restoreBST(node* root) {

    node* first = nullptr;
    node* last = nullptr;
    node* prv = nullptr;
    node* mid = nullptr;

    getpointersvalues(root,&first,&last,&prv,&mid);

    if(first && last) {
        swap(&(first->data),&(last->data));
    }
    else if(first && mid) {
        swap(&(first->data),&(mid->data));
    }
}

int main(){
    // file_i_o();
    // node* root = nullptr;
    // root=insertBST(root,2);
    // insertBST(root,1);
    // insertBST(root,5);
    // insertBST(root,3);
    // insertBST(root,8);
    // insertBST(root,6);
    // insertBST(root,4);
    // insertBST(root,7);
    // insertBST(root,9);
    // inorderDisplay(root);
    // printf("\n");
    // cout << minOfTree(root) << endl;
    // cout << maxOfTree(root) << endl;

    // node* newroot = new node(1);
    // newroot->left = new node(-1);
    // newroot->right = new node(3);
    // cout << isBST(newroot) << endl;
    // preorderDisplay(root);
    // printf("\n");
    // root = deleteInBST(root,4);
    // inorderDisplay(root);
    // printf("\n");
    // cout<<searchBST(root,6)<<endl;

    // int ino[] = {1 ,2 ,3, 5, 6, 7, 8, 9};
    // int preo[] = {2, 1 ,5 ,3 ,4, 8 ,6,7 ,9 };
    // vector<int> ino(preo,preo+9);
    // sort(ino.begin(),ino.end());
    // node* newroot = preorderToBST(preo,ino,0,8);
    // inorderDisplay(newroot);

    // int n;
    // cin >> n;
    // int sorted[n];
    // for (int i=0;i<n;i++) cin >> sorted[i];
    // node* root = nullptr;
    // root = createBSTfromSortedArray(sorted,0,n-1);
    // preorderDisplay(root);

    node* root = new node(6);
    root->left = new node(9); 
    root->right = new node(3); 
    root->left->left = new node(1); 
    root->left->right = new node(4); 
    root->right->right = new node(13);
    inorderDisplay(root); 
    cout << endl;
    restoreBST(root);
    inorderDisplay(root); 
    cout << endl;
    return 0;
}