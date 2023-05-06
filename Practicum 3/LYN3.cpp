#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#define fast ios_base::sync_with_stdio(false);
#define ull unsigned long long
using namespace std;
typedef struct AVLNode_t{
    ull data;
    struct AVLNode_t *left, *right, *parent;
    int height;
} AVLNode;

typedef struct AVL_t{
    AVLNode *_root;
    unsigned int _size;
} AVL;

AVLNode *_avl_createNode(AVLNode *root, int value)
{
    AVLNode *NewRootNode = new AVLNode;
    NewRootNode->data = value;
    NewRootNode->height = 1;
    NewRootNode->parent = NULL;
    NewRootNode->left = NewRootNode->right = NULL;
    return NewRootNode;
}

AVLNode *_search(AVLNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

AVLNode *_rightRotate(AVLNode *pivotNode)
{

    AVLNode *NewRootParrent = pivotNode->left;
    pivotNode->left = NewRootParrent->right;
    NewRootParrent->right = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left),
                             _getHeight(pivotNode->right)) +
                        1;
    NewRootParrent->height = _max(_getHeight(NewRootParrent->left),
                              _getHeight(NewRootParrent->right)) +
                         1;

    return NewRootParrent;
}

AVLNode *_leftRotate(AVLNode *pivotNode)
{

    AVLNode *NewRootParrent = pivotNode->right;
    pivotNode->right = NewRootParrent->left;
    NewRootParrent->left = pivotNode;

    pivotNode->height = _max(_getHeight(pivotNode->left),
                             _getHeight(pivotNode->right)) +
                        1;
    NewRootParrent->height = _max(_getHeight(NewRootParrent->left),
                              _getHeight(NewRootParrent->right)) +
                         1;

    return NewRootParrent;
}

AVLNode *_leftCaseRotate(AVLNode *node)
{
    return _rightRotate(node);
}

AVLNode *_rightCaseRotate(AVLNode *node)
{
    return _leftRotate(node);
}

AVLNode *_leftRightCaseRotate(AVLNode *node)
{
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode *_rightLeftCaseRotate(AVLNode *node)
{
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, int value)
{

    if (node == NULL) // udah mencapai leaf
        return _avl_createNode(node, value);
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && value > node->left->data) //
        return _leftRightCaseRotate(node);
    if (balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);

    return node;
}

AVLNode *_findMinNode(AVLNode *node)
{
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode *_remove_AVL(AVLNode *node, int value)
{
    if (node == NULL)
        return node;
    if (value > node->data)
        node->right = _remove_AVL(node->right, value);
    else if (value < node->data)
        node->left = _remove_AVL(node->left, value);
    else
    {
        AVLNode *temp;
        if ((node->left == NULL) || (node->right == NULL))
        {
            temp = NULL;
            if (node->left == NULL)
                temp = node->right;
            else if (node->right == NULL)
                temp = node->left;

            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;

            free(temp);
        }
        else
        {
            temp = _findMinNode(node->right);
            node->data = temp->data;
            node->right = _remove_AVL(node->right, temp->data);
        }
    }

    if (node == NULL)
        return node;

    node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
        return _leftCaseRotate(node);

    if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
        return _leftRightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
        return _rightCaseRotate(node);

    if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
        return _rightLeftCaseRotate(node);

    return node;
}

void avl_init(AVL *avl)
{
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl)
{
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value)
{
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, int value)
{
    if (!avl_find(avl, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value);
        avl->_size++;
    }
}

void avl_remove(AVL *avl, int value)
{
    if (avl_find(avl, value))
    {
        avl->_root = _remove_AVL(avl->_root, value);
        avl->_size--;
    }
}

void preorder(AVLNode *root)
{
    if (root)
    {
        preorder(root->left);
        printf("%d ", root->data);
        preorder(root->right);
    }
}

void getparent(AVLNode *node)
{
    if (node->left)
    {
        node->left->parent = node;
        getparent(node->left);
    }
    if (node->right)
    {
        node->right->parent = node;
        getparent(node->right);
    }
}

typedef struct bstBSTnode_t
{
    int data;
    struct bstBSTnode_t *left, *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;


void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}


BSTNode *__bst__createBSTNode(int value)
{
    BSTNode *NewRootBSTNode = (BSTNode *)malloc(sizeof(BSTNode));
    NewRootBSTNode->data = value;
    NewRootBSTNode->left = NewRootBSTNode->right = NULL;
    return NewRootBSTNode;
}

BSTNode *__bst__insert(BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createBSTNode(value);

    if (value < root->data)
        root->left = __bst__insert(root->left, value);
    else if (value > root->data)
        root->right = __bst__insert(root->right, value);

    return root;
}

BSTNode *__bst__findMinBSTNode(BSTNode *BSTnode)
{
    BSTNode *currBSTNode = BSTnode;
    while (currBSTNode && currBSTNode->left != NULL)
        currBSTNode = currBSTNode->left;

    return currBSTNode;
}

BSTNode *__bst__remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->data)
        root->right = __bst__remove(root->right, value);
    else if (value < root->data)
        root->left = __bst__remove(root->left, value);
    else
    {

        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinBSTNode(root->right);
        root->data = temp->data;
        root->right = __bst__remove(root->right, temp->data);
    }
    return root;
}

BSTNode *__bst__search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

void Node_avl(AVL* avl, BSTNode *root, int data) {
    if (root) {
        Node_avl(avl, root->left,data);
        if (root->data != data){
            if (root->left != NULL || root->right != NULL)avl_insert(avl, root->data);
            
        }
        Node_avl(avl, root->right,data);
    }
}

void Leaf(AVLNode* root, AVL* NewRoot){
    if (root){
        if (root->left == NULL && root->right == NULL)avl_insert(NewRoot, root->data);
        if (root->left != NULL) Leaf(root->left, NewRoot);
        if (root->right != NULL) Leaf(root->right, NewRoot);
    }
}

void FindEvenodd(AVLNode *root, bool *odd, bool *even) {
    if (root){
        FindEvenodd(root->left, odd, even);
        if (root->data % 2 == 0) *even = 1;
        else *odd = 1;
        FindEvenodd(root->right, odd, even);
    }
}

void avl_inorder(AVLNode *root) {
    if (root) {
        avl_inorder(root->left);
        printf("%d", root->data);
        avl_inorder(root->right);
    }
}

int main(){
    bool even = 0, odd = 0;
    BST BSTtree;
    AVL NodeTengah, final;
    bst_init(&BSTtree);
    avl_init(&NodeTengah); avl_init(&final);
    
    int P, L; cin >> P >> L;

    for (int i = 0; i < P; i++){
        string str; cin >> str;
        string str2;
        int p = 0;
        for (char ch : str){
            if (isdigit(ch)) p = ch - '0';
            else str2 += ch;
        }
        int sum = 0;
        for (char ch : str2){
            if (ch != 'X'){
                sum += (ch - 'A' + 1);
                bst_insert(&BSTtree, sum * p);
            }
        }
    }
    if (BSTtree._root == NULL){
        cout << "HADEHHH GADA PASSWORDNYA TERNYATA! >:(";
        return 0;
    }
    
    Node_avl(&NodeTengah, BSTtree._root, BSTtree._root->data);

    if (NodeTengah._root == NULL){
        cout << "HADEHHH GADA PASSWORDNYA TERNYATA! >:(";
        return 0;
    }
    else{
        Leaf(NodeTengah._root, &final);
        
        FindEvenodd(final._root, &odd, &even);
        if (even && odd){
            cout << "DONTO";
            avl_inorder(final._root);
            cout << ".lrc";
        }
        else if (!even && odd){
            cout << "BabaiCila";
            avl_inorder(final._root);
            cout << ".lrc";
        }
        else{
            cout << "SeeULyn";
            avl_inorder(final._root);
            cout << ".lrc";
        }
        
    }
    
    return 0;
}