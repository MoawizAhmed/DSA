
#include <iostream>
#include <queue>
using namespace std;

class AVLTree
{
private:

    struct Node
    {
        int data;
        int height;
        Node *left;
        Node *right;

        Node(int value)
        {
            data = value;
            height = 1;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *root;

    // Calculate height
    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return node->height;
    }

    // Calculate balance factor
    int getBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return height(node->left) - height(node->right);
    }

    // Find minimum value node
    Node* findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }

        return node;
    }

    // Find maximum value node
    Node* findMax(Node *node)
    {
        while (node->right != nullptr)
        {
            node = node->right;
        }

        return node;
    }

    // Right Rotation (LL Case)
    Node* rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    // Left Rotation (RR Case)
    Node* leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    // Balance the tree
    Node* balance(Node *node)
    {
        if (node == nullptr)
        {
            return node;
        }

        int bf = getBalance(node);

        // LL Case
        if (bf > 1 && getBalance(node->left) >= 0)
        {
            return rightRotate(node);
        }

        // RR Case
        if (bf < -1 && getBalance(node->right) <= 0)
        {
            return leftRotate(node);
        }

        // LR Case
        if (bf > 1 && getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);

            return rightRotate(node);
        }

        // RL Case
        if (bf < -1 && getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);

            return leftRotate(node);
        }

        return node;
    }

    // Recursive insertion
    Node* insert(Node *node, int value)
    {
        // Normal BST insertion
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
        else
        {
            return node;
        }

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        // Balance the tree
        return balance(node);
    }

    // Recursive deletion
    Node* deleteNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        // Search for the node
        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // Node with no child or one child
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp;

                if (node->left != nullptr)
                {
                    temp = node->left;
                }
                else
                {
                    temp = node->right;
                }

                // No child
                if (temp == nullptr)
                {
                    delete node;
                    return nullptr;
                }
                // One child
                else
                {
                    Node *old = node;
                    node = temp;
                    delete old;
                }
            }

            // Node with two children
            else
            {
                Node *temp = findMin(node->right);

                node->data = temp->data;

                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr)
        {
            return node;
        }

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        // Balance after deletion
        return balance(node);
    }

    // Recursive searching
    bool search(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->data == value)
        {
            return true;
        }

        if (value < node->data)
        {
            return search(node->left, value);
        }

        return search(node->right, value);
    }

    // Inorder traversal
    void inorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        inorder(node->left);

        cout << node->data << " ";

        inorder(node->right);
    }

    // Preorder traversal
    void preorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        cout << node->data << " ";

        preorder(node->left);
        preorder(node->right);
    }

    // Postorder traversal
    void postorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        postorder(node->left);
        postorder(node->right);

        cout << node->data << " ";
    }

    // Level order traversal using queue
    void levelOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        queue<Node*> q;

        q.push(node);

        while (!q.empty())
        {
            Node *current = q.front();

            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
            {
                q.push(current->left);
            }

            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }

    // Delete entire tree
    void clear(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        clear(node->left);
        clear(node->right);

        delete node;
    }

public:

    AVLTree()
    {
        root = nullptr;
    }

    ~AVLTree()
    {
        clear(root);
        root = nullptr;
    }

    // Public insertion
    void insert(int value)
    {
        root = insert(root, value);
    }

    // Public deletion
    void deleteValue(int value)
    {
        root = deleteNode(root, value);
    }

    // Public searching
    bool search(int value)
    {
        return search(root, value);
    }

    // Get minimum value
    int getMin()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty!" << endl;
            return -1;
        }

        return findMin(root)->data;
    }

    // Get maximum value
    int getMax()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty!" << endl;
            return -1;
        }

        return findMax(root)->data;
    }

    // Display inorder
    void inorder()
    {
        inorder(root);
        cout << endl;
    }

    // Display preorder
    void preorder()
    {
        preorder(root);
        cout << endl;
    }

    // Display postorder
    void postorder()
    {
        postorder(root);
        cout << endl;
    }

    // Display level order
    void levelOrder()
    {
        levelOrder(root);
        cout << endl;
    }

    // Get tree height
    int getHeight()
    {
        return height(root);
    }
};
