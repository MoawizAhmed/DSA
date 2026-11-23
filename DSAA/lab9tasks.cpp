#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Create Node
Node* createNode(int value) {

    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

// Get Height
int getHeight(Node* root) {

    if (root == NULL)
        return 0;

    return root->height;
}

// Update Height
void updateHeight(Node* root) {

    root->height = 1 + max(
        getHeight(root->left),
        getHeight(root->right)
    );
}

// Get Balance Factor
int getBalance(Node* root) {

    if (root == NULL)
        return 0;

    return getHeight(root->left) -
           getHeight(root->right);
}

// Right Rotation
Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left Rotation
Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insertion
Node* insert(Node* root, int value) {

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        return root;

    updateHeight(root);

    int balance = getBalance(root);

    // LL
    if (balance > 1 &&
        value < root->left->data)
        return rightRotate(root);

    // RR
    if (balance < -1 &&
        value > root->right->data)
        return leftRotate(root);

    // LR
    if (balance > 1 &&
        value > root->left->data) {

        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 &&
        value < root->right->data) {

        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find Minimum
Node* findMin(Node* root) {

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Deletion
Node* deleteNode(Node* root, int value) {

    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else {

        if (root->left == NULL ||
            root->right == NULL) {

            Node* temp = root->left ?
                         root->left : root->right;

            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right =
            deleteNode(root->right, temp->data);
    }

    if (root == NULL)
        return root;

    updateHeight(root);

    int balance = getBalance(root);

    // LL
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 &&
        getBalance(root->left) < 0) {

        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 &&
        getBalance(root->right) > 0) {

        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Search
bool search(Node* root, int value) {

    if (root == NULL)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

// Find Maximum
Node* findMax(Node* root) {

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Inorder
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder
void preorder(Node* root) {

    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder
void postorder(Node* root) {

    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {

    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nSearching 40: ";

    if (search(root, 40))
        cout << "Found";
    else
        cout << "Not Found";

    cout << "\nMinimum: " << findMin(root)->data;
    cout << "\nMaximum: " << findMax(root)->data;

    root = deleteNode(root, 20);

    cout << "\nAfter Deletion: ";
    inorder(root);

    return 0;
}
