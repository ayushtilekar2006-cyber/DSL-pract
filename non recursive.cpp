#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    // Recursive helper to insert a node into BST
    void insertHelper(Node *&temp, int value)
    {
        if (temp == nullptr)
        {
            temp = new Node(value);
            return;
        }

        if (value < temp->data)
            insertHelper(temp->left, value);
        else if (value > temp->data)
            insertHelper(temp->right, value);
        // Duplicate values are ignored
    }

    // Postorder deletion helper for destructor
    void clear(Node *temp)
    {
        if (temp == nullptr)
            return;
        clear(temp->left);
        clear(temp->right);
        delete temp;
    }

public:
    BST() : root(nullptr) {}

    ~BST()
    {
        clear(root);
    }

    // Public insert method
    void insert(int value)
    {
        if (value == -1)
            return;
        insertHelper(root, value);
    }

    // Non-recursive Inorder Traversal (Left -> Root -> Right)
    void inorder()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty.";
            return;
        }

        stack<Node *> s;
        Node *temp = root;

        while (temp != nullptr || !s.empty())
        {
            while (temp != nullptr)
            {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top();
            s.pop();

            cout << temp->data << " ";
            temp = temp->right;
        }
    }

    // Non-recursive Preorder Traversal (Root -> Left -> Right)
    void preorder()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty.";
            return;
        }

        stack<Node *> s;
        s.push(root);

        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();

            cout << temp->data << " ";

            // Push right first so that left is popped and processed first
            if (temp->right != nullptr)
                s.push(temp->right);

            if (temp->left != nullptr)
                s.push(temp->left);
        }
    }

    // Non-recursive Postorder Traversal using two stacks (Left -> Right -> Root)
    void postorder()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty.";
            return;
        }

        stack<Node *> s1, s2;
        s1.push(root);

        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            s2.push(temp);

            if (temp->left != nullptr)
                s1.push(temp->left);

            if (temp->right != nullptr)
                s1.push(temp->right);
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
        }
    }
};

int main()
{
    BST tree;
    int choice, value;

    do
    {
        cout << "\n===== Binary Search Tree Menu =====";
        cout << "\n1. Insert Node";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value (-1 to cancel): ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Inorder traversal: ";
            tree.inorder();
            cout << "\n";
            break;

        case 3:
            cout << "Preorder traversal: ";
            tree.preorder();
            cout << "\n";
            break;

        case 4:
            cout << "Postorder traversal: ";
            tree.postorder();
            cout << "\n";
            break;

        case 5:
            cout << "Program Exited.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}