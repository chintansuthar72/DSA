#include <bits/stdc++.h>
using namespace std;

/*
==> depth first order
1.INORDER TRIVASAL(LEFT-ROOT-RIGHT)
2.PREORDER TRIVASAL(ROOT-LEFT-RIGHT)
3.OSTORDER TRIVASAL(LEFT-RIGHT-ROOT)
==> level order
1.using queue
*/

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int searchOfElement(const int ino[], int s, int e, int x)
{
    for (int i = s; i <= e; i++)
    {
        if (x == ino[i])
        {
            return i;
        }
    }
    return -1;
}

node *buildTreePreInorder(int preo[], int ino[], int s, int e)
{
    static int idx = 0;
    if (s > e)
    {
        return nullptr;
    }
    int curr = preo[idx];
    idx++;
    node *root = new node(curr);
    if (s == e)
    {
        return root;
    }
    int pos = searchOfElement(ino, s, e, curr);
    root->left = buildTreePreInorder(preo, ino, s, pos - 1);
    root->right = buildTreePreInorder(preo, ino, pos + 1, e);
    return root;
}

node* buildPrePostorder(int preo[],int post[],int s,int e)
{
    
}

node *buildTreePostInorder(int post[], int ino[], int s, int e)
{
    static int idx = 4;
    if (s > e)
        return nullptr;
    int curr = post[idx];
    idx--;
    node *root = new node(curr);
    if (s == e)
        return root;
    int pos = searchOfElement(ino, s, e, curr);
    root->right = buildTreePostInorder(post, ino, pos + 1, e);
    root->left = buildTreePostInorder(post, ino, s, pos - 1);
    return root;
}

void inorderDisplay(node *&root)
{
    if (root == nullptr)
        return;
    inorderDisplay(root->left);
    cout << root->data << " ";
    inorderDisplay(root->right);
}

void preorderDisplay(node *&root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderDisplay(root->left);
    preorderDisplay(root->right);
}

void postorderDisplay(node *&root)
{
    if (root == nullptr)
        return;
    postorderDisplay(root->left);
    postorderDisplay(root->right);
    cout << root->data << " ";
}

int heightOfTree(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return max(left, right) + 1;
}

int diameterOfTree(node *root) // O(n*n) -- n is numbers of nodes in tree
{
    if (root == NULL)
        return 0;

    int lHeight = heightOfTree(root->left);
    int rHeight = heightOfTree(root->right);
    int currentDiameter = lHeight + rHeight + 1;
    int rDiameter = diameterOfTree(root->right);
    int lDiameter = diameterOfTree(root->left);

    return max(currentDiameter, max(lDiameter, rDiameter));
}

int sumNodes(node *root)
{
    if (root == nullptr)
        return 0;
    return sumNodes(root->left) + sumNodes(root->right) + (root->data);
}

int countNodes(node *root)
{
    if (root == nullptr)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

void nodeReplaceWithSum(node *root)
{
    if (root == nullptr)
        return;
    nodeReplaceWithSum(root->left);
    nodeReplaceWithSum(root->right);

    // root->data = root->left->data + root->right->data + root->data;

    if (root->left != nullptr)
        root->data += root->left->data;
    if (root->right != nullptr)
        root->data += root->right->data;
}

bool childrenSumProperty(node *root)
{
    // bool check = true;
    int sum = 0;
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;
    if (root->left != nullptr)
        sum = sum + root->left->data;
    if (root->right != nullptr)
        sum = sum + root->right->data;
    if (root->data == sum && childrenSumProperty(root->left) && childrenSumProperty((root->right)))
        return true;
    else
        return false;
}

void printKlevelNodeData(node *root, int k)
{
    if (root == nullptr)
        return;
    if (k == 0)
        cout << root->data << " ";
    printKlevelNodeData(root->left, k - 1);
    printKlevelNodeData(root->right, k - 1);
}

int sumAtKNodes(node *root, int k)
{
    int sum = 0;
    if (root == nullptr)
    {
        return 0;
    }
    if (k == 0)
    {
        return root->data;
    }
    sum += sumAtKNodes(root->left, k - 1);
    sum += sumAtKNodes(root->right, k - 1);

    return sum;
}

void levelOrderUsingQueue(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        cout << n->data << " ";
        if (n->left != nullptr)
        {
            q.push(n->left);
        }
        if (n->right != nullptr)
        {
            q.push(n->right);
        }
    }
}

void iterativePreorderDisplay(node *root)
{
    if (root == nullptr)
        return;
    stack<node *> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty())
    {
        node *n = nodeStack.top();
        cout << n->data << " ";
        nodeStack.pop();
        if (n->right != nullptr)
            nodeStack.push(n->right);
        if (n->left != nullptr)
            nodeStack.push(n->left);
    }
}

void zigzagTravesal(node *root)
{
    if (root == nullptr)
        return;
    stack<node *> currLevel;
    stack<node *> nextLevel;
    bool leftToRight = true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        node *n = currLevel.top();
        currLevel.pop();
        if (n)
        {
            cout << n->data << " ";
            if (leftToRight)
            {
                if (n->left)
                    nextLevel.push(n->left);
                if (n->right)
                    nextLevel.push(n->right);
            }
            else
            {
                if (n->right)
                    nextLevel.push(n->right);
                if (n->left)
                    nextLevel.push(n->left);
            }
        }
        if (currLevel.empty())
        {
            leftToRight = not leftToRight; // changing direction
            swap(currLevel, nextLevel);    // stack swaping
        }
    }
}

void createInorderArray(node *root, vector<int> &v)
{
    if (root == nullptr)
        return;
    createInorderArray(root->left, v);
    v.push_back(root->data);
    createInorderArray(root->right, v);
}

bool isMirror(node *root1, node *root2)
{
    vector<int> v1, v2;
    createInorderArray(root1, v1);
    createInorderArray(root2, v2);
    if (v1[0] != v2[v2.size() - 1])
        return false;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[v2.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

void makeMirrorOfTree(node *root)
{
    if (root == nullptr)
        return;
    makeMirrorOfTree(root->left);
    makeMirrorOfTree(root->right);
    node *tmp = root->left;
    tmp->left = tmp->right;
    tmp->right = tmp;
}

bool isIdentical(node *root1, node *root2)
{

    if (root1 == nullptr and root2 == nullptr)
        return true;
    else if (root1 == nullptr and root2 != nullptr)
        return false;
    else
    {
        return (isIdentical(root1->right, root2->right)) and (isIdentical(root1->left, root2->left)) and (root1->data == root2->data);
    }
}

// O(n2)
// bool isHeightBalanced(node* root) {
//     // O(n*n)
//     // if(root == nullptr) return true;
//     // return isHeightBalanced(root->left) and isHeightBalanced(root->right) and (abs(heightOfTree(root->right)-heightOfTree(root->left))<=1);
// }

// O(n)
bool isHeightBalanced(node *root, int *height)
{

    if (root == nullptr)
        return true;

    int lh = 0, rh = 0;

    if (isHeightBalanced(root->left, &lh) != true)
        return false;
    if (isHeightBalanced(root->right, &rh) != true)
        return false;

    *height = max(lh, rh) + 1;

    return (abs(lh - rh) <= 1);
}

void rightView(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            node *tmp = q.front();
            q.pop();

            if (i == n)
            { // i==n for right view
                cout << tmp->data << " ";
            }
            if (tmp->left != nullptr)
            {
                q.push(tmp->left);
            }
            if (tmp->right != nullptr)
            {
                q.push(tmp->right);
            }
        }
    }
}

void leftView(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            node *tmp = q.front();
            q.pop();

            if (i == 1)
            { // i==n for right view
                cout << tmp->data << " ";
            }
            if (tmp->left != nullptr)
            {
                q.push(tmp->left);
            }
            if (tmp->right != nullptr)
            {
                q.push(tmp->right);
            }
        }

        // cout << q.front()->data << " ";
        // q.pop();
        // if(root->left != nullptr and root->right != nullptr) {
        //     leftView(root->left);
        // }
        // else if(root->left == nullptr and root->right != nullptr){
        //     leftView(root->right);
        // }
    }
}

void flattenTree(node *root)
{
    // construct linked list of binary tree in preorder (left is null)
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    if (root->left != nullptr)
    {
        flattenTree(root->left);

        node *tmp = root->right;
        root->right = root->left;
        root->left = nullptr;

        node *traverse = root->right;
        while (traverse->right != nullptr)
        {
            traverse = traverse->right;
        }

        traverse->right = tmp;
    }
    flattenTree(root->right);
    return;
}

int maxOfTree(node *root)
{
    if (root == nullptr)
        return INT_MIN;
    if (root->left == nullptr && root->right == nullptr)
        return root->data;
    return max(maxOfTree(root->right), maxOfTree(root->left));
}

int minOfTree(node *root)
{
    if (root == nullptr)
        return INT_MAX;
    if (root->left == nullptr && root->right == nullptr)
        return root->data;
    return min(minOfTree(root->right), minOfTree(root->left));
}

bool isBST(node *root)
{
    if (root == nullptr)
        return true;
    if (root->data > maxOfTree(root->left) && root->data < minOfTree(root->right))
    {
        return isBST(root->left) && isBST(root->right);
    }
    else
    {
        return false;
    }
}

void verticalOrderUsingHashingPrintHelper(node *root, map<int, vector<int>> &mp, int hdis)
{
    if (root == nullptr)
        return;
    mp[hdis].push_back(root->data);
    verticalOrderUsingHashingPrintHelper(root->left, mp, hdis - 1);
    verticalOrderUsingHashingPrintHelper(root->right, mp, hdis + 1);
}

void verticalOrderUsingHashingPrint(node *root)
{
    if (root == nullptr)
        return;
    map<int, vector<int>> mp;
    int hdis = 0;
    verticalOrderUsingHashingPrintHelper(root, mp, hdis);
    for (auto x = mp.begin(); x != mp.end(); x++)
    {
        for (int i = 0; i < (x->second).size(); i++)
        {
            cout << (x->second)[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    node *root = new node(10);
    // root->left = new node(6);
    // root->right = new node(3);
    // cout<<"inorderDisplay"<<endl;
    // inorderDisplay(root);
    // cout<<endl;
    // cout<<"preorderDisplay"<<endl;
    // preorderDisplay(root);
    // cout<<endl;
    // cout<<"postorderDisplay"<<endl;
    // postorderDisplay(root);
    // cout<<endl;
    // cout<<"levelOrderUsingQueue"<<endl;
    // levelOrderUsingQueue(root);
    // cout<<endl;
    // cout<<"height of tree is "<<heightOfTree(root)<<endl;
    // cout<<childrenSumProperty(root)<<endl;
    // cout<<isBalanced(root)<<endl;
    // printKlevelNodeData(root,0);

    // int preo[] = {1,2,4,3,5};
    // int ino[] = {4,2,1,5,3};
    // int posto[] = {4,2,5,3,1};
    // node* newroot = buildTreePreInorder(preo,ino,0,4);
    // preorderDisplay(newroot);
    // nodeReplaceWithSum(newroot);
    // preorderDisplay(newroot);
    // cout<<sumNodes(newroot)<<endl;
    // cout<<countNodes(newroot)<<endl;
    // cout<<sumAtKNodes(newroot,2)<<endl;
    // levelOrderUsingQueue(newroot);
    // inorderDisplay(newroot);
    // printf("\n");
    // postorderDisplay(newroot);
    // printf("\n");
    // preorderDisplay(newroot);
    // printf("\n");
    // node* newroot = buildTreePostInorder(posto,ino,0,4);
    // inorderDisplay(newroot);

    /*
        2
       1  3
     7 5  9  4
    */
    node *root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(3);
    root1->right->right = new node(4);
    root1->left->right = new node(5);
    root1->left->left = new node(7);
    root1->right->left = new node(9);
    // verticalOrderUsingHashingPrint(root1);
    cout << diameterOfTree(root1) << endl;
    // rightView(root1);
    // flattenTree(root1);
    levelOrderUsingQueue(root1);
    // cout << endl;
    // preorderDisplay(root1);
    // node* root2 = new node(5);
    // root2->left = new node(6);
    // root2->right = new node(7);

    // inorderDisplay(root1);
    // cout << endl;
    // zigzagTravesal(root1);
    // cout << endl;
    // int height = 0;
    // cout << isHeightBalanced(root1,&height) << endl;
    // cout << isIdentical(root1,root1) << endl;
    // cout<< isMirror(root1,root2) <<endl;
    // iterativeInorderDisplay(root1);
    // iterativeInorderDisplay(root2);
    return 0;
}