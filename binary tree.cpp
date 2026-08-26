#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    Node *root;

    // Helper method to recursively create nodes
    Node* createTree()
    {
        int value;
        cout << "\nEnter node value (-1 for No Node): ";
        cin >> value;

        // -1 represents an empty node/child
        if (value == -1)
            return nullptr;

        Node *newNode = new Node(value);

        cout << "Enter Left Child of " << value;
        newNode->left = createTree();

        cout << "Enter Right Child of " << value;
        newNode->right = createTree();

        return newNode;
    }

    // Postorder helper to delete nodes and prevent memory leaks
    void destroyTree(Node *temp)
    {
        if (temp == nullptr)
            return;

        destroyTree(temp->left);
        destroyTree(temp->right);
        delete temp;
    }

    // Inorder: Left -> Root -> Right
    void inorder(Node *temp)
    {
        if (temp == nullptr)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    // Preorder: Root -> Left -> Right
    void preorder(Node *temp)
    {
        if (temp == nullptr)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Postorder: Left -> Right -> Root
    void postorder(Node *temp)
    {
        if (temp == nullptr)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    // Leaf node count: nodes with no left or right child
    int countLeafNodes(Node *temp)
    {
        if (temp == nullptr)
            return 0;

        if (temp->left == nullptr && temp->right == nullptr)
            return 1;

        return countLeafNodes(temp->left) + countLeafNodes(temp->right);
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Destructor
    ~BinaryTree()
    {
        destroyTree(root);
    }

    void buildTree()
    {
        // Clean up previous tree if rebuilding
        if (root != nullptr)
        {
            destroyTree(root);
            root = nullptr;
        }

        cout << "\n--- Create Binary Tree ---";
        root = createTree();
    }

    void displayInorder()
    {
        cout << "\nInorder Traversal   : ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder()
    {
        cout << "\nPreorder Traversal  : ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder()
    {
        cout << "\nPostorder Traversal : ";
        postorder(root);
        cout << endl;
    }

    void displayLeafNodes()
    {
        cout << "\nNumber of Leaf Nodes: " << countLeafNodes(root) << endl;
    }
};

int main()
{
    BinaryTree tree;
    int choice;

    do
    {
        cout << "\n================================";
        cout << "\n        BINARY TREE MENU";
        cout << "\n================================";
        cout << "\n1. Create Binary Tree";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Count Leaf Nodes";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                tree.buildTree();
                break;
            case 2:
                tree.displayInorder();
                break;
            case 3:
                tree.displayPreorder();
                break;
            case 4:
                tree.displayPostorder();
                break;
            case 5:
                tree.displayLeafNodes();
                break;
            case 6:
                cout << "\nProgram Ended Successfully.\n";
                break;
            default:
                cout << "\nInvalid Choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}