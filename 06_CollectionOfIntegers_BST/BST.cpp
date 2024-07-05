#include<iostream>
using namespace std;

//node class -> each node in the BST
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor to initialize the node with the data
    Node(int val) : data(val), left(nullptr), right(nullptr)
    {

    }

};

//BST class to represent the Binary Search Tree
class BST{
private:
Node* root;

//helper function to insert a new node in the BST
Node* insert(Node* node, int val)
{
    if(node == nullptr)
    {
        return new Node(val);
    }
    if(val < node ->data)
    {
        node -> left = insert(node->left, val);
    }else if(val > node->data){
      node->right = insert(node->right, val);
    }
    return node;

}

//helper function to serach for a value in the BST
bool search(Node* node, int val)
{
    if(node == nullptr)
    {
        return false;
    }
    if(val < node-> data)
    {
        return true;
    }
    if(val < node->data)
    {
        return search(node->left, val);
    }else{
        return search(node->right, val);
    }
}


void inOrderTraversal(Node* node)
{
    if(node != nullptr)
    {
        inOrderTraversal(node->left);
        cout<<node->data<<"";
        inOrderTraversal(node->right);
    }
}

public:
BST() : root(nullptr) {}

//function to insert a valur in the BST
void insert(int val)
{
    root = insert(root, val);

}

bool search(int val)
{
    return search(root, val);
}

//function for in order travesrsal of the BST
void inOrderTraversal(){
    inOrderTraversal(root);
    cout<<endl;
}

};

int main() {
    BST tree;
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. In-Order Traversal\n4. Exit\nEnter your choice: ";
        cin >> choice;

        // Clear the input buffer to handle invalid input and avoid infinite loops
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number.\n";
                } else {
                    tree.insert(value);
                }
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number.\n";
                } else {
                    if (tree.search(value)) {
                        cout << "Value found in the tree.\n";
                    } else {
                        cout << "Value not found in the tree.\n";
                    }
                }
                break;
            case 3:
                cout << "In-Order Traversal: ";
                tree.inOrderTraversal();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}