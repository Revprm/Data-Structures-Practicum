#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

typedef struct bstnode_t {
    int key;
    struct bstnode_t* left, * right;
} BSTNode;

typedef struct bst_t {
    BSTNode* _root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode* root, int value) {
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}

BSTNode* __bst__search(BSTNode* root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode* node) {
    BSTNode* currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode* __bst__remove(BSTNode* root, int value) {
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else {

        if (root->left == NULL) {
            BSTNode* rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode* leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode* temp = __bst__findMinNode(root->right);
        root->key = temp->key;
        root->right = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode* root) {
    if (root) {
        __bst__inorder(root->left);
        cout << root->key << " ";
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode* root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        cout << root->key << " ";
    }
}

void __bst__preorder(BSTNode* root) {
    if (root) {
        cout << root->key << " ";
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

void bst_init(BST* bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST* bst) {
    return bst->_root == NULL;
}

bool bst_find(BST* bst, int value) {
    BSTNode* temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST* bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST* bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

void bst_inorder(BST* bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST* bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST* bst) {
    __bst__preorder(bst->_root);
}

int getLevel(BSTNode* root, int value, int level = 1) {
    if (root == NULL) return -1;
    if (root->key == value) return level;
    if (value < root->key) return getLevel(root->left, value, level + 1);

    return getLevel(root->right, value, level + 1);
}

int getCount(BSTNode* root) {
    if (root == NULL)
        return 0;
    return 1 + getCount(root->left) + getCount(root->right);
}

BSTNode* getRank(BSTNode* root, int x) {
    if (root == NULL)
        return NULL;

    int leftCount = getCount(root->left);

    if (x <= leftCount)
        return getRank(root->left, x);
    else if (x == leftCount + 1)
        return root;
    else
        return getRank(root->right, x - leftCount - 1);
}

string getPath(BSTNode* root, int value) {
    if (root == nullptr) return "";
    if (root->key == value) return "S";
    if (value < root->key) {
        string leftPath = getPath(root->left, value);
        if (leftPath != "") return "L" + leftPath;
    }
    else {
        string rightPath = getPath(root->right, value);
        if (rightPath != "") return "R" + rightPath;
    }
    return "";
}

int main() {
    BST set;
    bst_init(&set);
    int x;
    string cmd;
    cin >> cmd;
    while (cmd != "STOP") {
        if (cmd == "IN") {
            cin >> x;
            bst_insert(&set, x);
        }
        else if (cmd == "RK") {
            cin >> x;
            BSTNode* rank = getRank(set._root, x);
            if (rank != NULL) cout << rank->key << endl;
            else cout << "-1" << endl;
        }
        else if (cmd == "FD") {
            cin >> x;
            int level = getLevel(set._root, x);
            if (level != -1) cout << "on level " << level << endl;
            else cout << "no " << x << endl;
        }
        else if (cmd == "PH") {
            cin >> x;
            string path = getPath(set._root, x);
            if (path != "") cout << path << endl;
            else cout << "no " << x << endl;
        }
        cin >> cmd;
    }

    cout << "done" << endl;
    return 0;
}
