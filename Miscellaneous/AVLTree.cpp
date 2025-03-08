#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

int getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* deleteNodeHelper(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNodeHelper(root->left, key);
    else if (key > root->data)
        root->right = deleteNodeHelper(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                delete root;
                return nullptr;
            } else {
                Node* toDelete = root;
                root = temp;
                delete toDelete;
                return root;
            }
        } else {
            Node* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNodeHelper(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node* node)
{
    if (node != nullptr)
	{
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

class AVLTree {
private:
    Node* Root;

public:
    AVLTree() : Root(nullptr) {}

    void InsertNode(int key) {
		Root = insert(Root, key);
    }

    void DeleteNode(int key) {
        Root = deleteNodeHelper(Root, key);
    }

    void PreOrderNode() {
        preOrder(Root);
    }
};

int main()
{
	class AVLTree* Tree = new AVLTree();
	int Choice , element;

	do
	{
		cout << "1. Insert Element" << endl; 
		cout << "2. Delete Element" << endl; 
		cout << "3. Print Tree" << endl; 
		cout << "4. Exit" << endl; 
		cin >> Choice;
		switch(Choice)
		{
			case 1: 
				{
					cout << "Enter Element to be inserted: "; 
					cin >> element; 
					if(Tree)
					{
						Tree->InsertNode(element);
					}
					break; 
				}

			case 2: 
				{
					cout << "\nEnter Element to be Deleted: "; 
					cin >> element; 
					if(Tree)
					{
						Tree->DeleteNode(element);
					}
					break; 
				}

			case 3: 
			{
				if(Tree) 
				{
					cout << "Tree in Preorder Traversal: ";
					Tree->PreOrderNode(); 
					cout << endl;
				}
				break; 
			}	
			case 4: 
				{	
					cout << "\nExiting Program." << endl; 
					exit(0); 
					break; 
				}

			default: 
				cout << "\nInvalid choice. Please enter number again between 1 and 4." << endl; 
				break; 

		}


	} while (Choice != 4);
	
	return 0;
	
}
