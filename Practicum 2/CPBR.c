#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t *left, *right, *parent;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(BSTNode *proot ,int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    newNode->parent = proot;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, BSTNode *proot, int value) {
    if (root == NULL) return __bst__createNode(proot,value);
    if (value < root->key) root->left = __bst__insert(root->left, root, value);
    else if (value > root->key) root->right = __bst__insert(root->right, root, value);
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key) root = root->left;
        else if (value > root->key) root = root->right;
        else return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL) currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;
    if (value > root->key) root->right = __bst__remove(root->right, value);
    else if (value < root->key) root->left = __bst__remove(root->left, value);
    else {
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }
        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

int bst_distance(BSTNode* root, int node1, int node2) {
    BSTNode* lca = root;
    while (lca) {
        if (lca->key > node1 && lca->key > node2) lca = lca->left;
        else if (lca->key < node1 && lca->key < node2) lca = lca->right;
        else break;
    }

    int dist1 = 0;
    BSTNode* curr = lca;
    while (curr->key != node1) {
        if (node1 < curr->key) curr = curr->left;
        else curr = curr->right;
        dist1++;
    }

    // Calculate distance of node2 from LCA
    int dist2 = 0;
    curr = lca;
    while (curr->key != node2) {
        if (node2 < curr->key) curr = curr->left;
        else curr = curr->right;
        dist2++;
    }

    // Return sum of distances
    return dist1 + dist2;
}



int bst_find_2(BST *bst, int node1, int node2) {
    BSTNode *temp1 = __bst__search(bst->_root, node1);
    BSTNode *temp2 = __bst__search(bst->_root, node2);
    if (temp1 == NULL || temp2 == NULL) return 0;
    if (temp1->key == node1 && temp2->key == node2) {
        int dist = bst_distance(bst->_root, node1, node2);
        printf("%d\n", dist);
    }

}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL) return false;
    if (temp->key == value){
        return true;
    }
    else return false;
}


void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}
 
int main(){
    BST set;
    bst_init(&set);
    int n, x, T, a, b;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &x);
        bst_insert(&set, x);
    }
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &a, &b);
        bst_find_2(&set, a, b);
    }
    return 0;
}