#include <iostream>
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
    BSTNode* newNode = new BSTNode;
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode* root, int value) {
    if (root == NULL) {
        BSTNode* newNode = __bst__createNode(value);
        return newNode;
    }

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
        return 0;

    return temp->key == value;
}

void bst_insert(BST* bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void minato(BSTNode* root, int parentKey, vector<int>& aqutan) {
    if (root && (root->left || root->right)) {
        minato(root->left, root->key, aqutan);
        minato(root->right, root->key, aqutan);
        
        if (root->left && root->right) {
            aqutan.push_back(root->left->key + root->key + root->right->key);
        }
        else if (root->right) {
            aqutan.push_back(root->key + parentKey + root->right->key);
        }
        else if (root->left) {
            aqutan.push_back(root->key + parentKey + root->left->key);
        }
        
    }
}

bool aqua(BST* bst, int tg) {
    vector<int> aqutan;
    minato(bst->_root, 0, aqutan);

    for (int sum : aqutan) {
        if (sum == tg) {
            return 1;
        }
    }
    return 0;
}


int main() {
    int N, K, fnd;
    cin >> N;

    BST set;
    bst_init(&set);

    for (int i = 0; i < N; i++) {
        cin >> fnd;
        bst_insert(&set, fnd);
    }

    cin >> K;
    if (aqua(&set, K))
        cout << K << " Selamat! Kalian menemukan harta karunnya" << '\n';
    else
        cout << K << " Tidak ada kombinasi yang tepat! Bikin ulang." << '\n';

    return 0;
}
