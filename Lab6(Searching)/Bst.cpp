#include "iostream"
using namespace std;

struct Bst
{
	int data;
	struct  Bst* left;
	struct Bst* right;

	public:
	Bst(int Element): data(Element),left(nullptr), right(nullptr)
	{

	}
};

void inorder(struct Bst* root)
{
	if(root != nullptr)
	{
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}
}

void Preorder(struct Bst* root)
{
	if(root != nullptr)
	{
		cout<<root->data<<endl;
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Postorder(struct Bst* root)
{
	if(root != nullptr)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout<<root->data<<endl;
	}
}

struct Bst* Search(struct Bst* root,int key)
{
	if(root == nullptr || key == root->data)
	{
		return root;
	}
	else if(key< root->data)
	{
		return Search(root->left,key);
	}
	else
	{
		return Search(root->right,key);
	}
}

struct Bst* FindMax(struct Bst* root)
{
	while(root->right != nullptr)
	{
		root = root->right;
	}
	return root;
}

struct Bst* FindMin(struct Bst* root)
{
	while(root->left != nullptr)
	{
		root = root->left;
	}
	return root;
}

struct  Bst* Insert(struct Bst* root, int element)
{
	if(root == nullptr)
	{
		return root = new Bst(element);
		/*
		root->left = nullptr;
		root->right = nullptr;
		root->data = element;
		*/
	}
	else if(element <root->data)
	{
		root->left = Insert(root->left,element);
	}
	else
	{
		root->right = Insert(root->right,element);
	}
	return root;
}

struct Bst* DeleteNode(struct Bst* root, int element)
{
	if(root == nullptr)
	{
		return root;
	}
	else if( element < root->data)
	{
		root->left = DeleteNode(root->left,element);
	}
	else if(element > root ->data)
	{
		root -> right = DeleteNode(root->right , element);
	
	}
	else
	{
		if(root ->left == nullptr)
		{
			struct Bst* temp = root ->right;
			free(root);
			return temp;
		}
		else if(root->right == nullptr)
		{
			struct Bst* temp = root->left;
			free(root);
			return temp;
		}

		else
		{
			struct Bst* temp = FindMin(root->right);


			root->data = temp->data;
			root->right = DeleteNode(root->right,element);
		}
	}
	return root;
}

struct Bst* root = nullptr, *temp = nullptr;
int main ()
{
	int Choice , element;

	do
	{
		cout << "1.Insert" << endl; 
		cout << "2. Delete" << endl; 
		cout << "3. Search" << endl; 
		cout << "4. FindMax" << endl; 
		cout << "5. FindMin" << endl; 
		cout << "6. Inorder" << endl; 
		cout << "7. PreOrder" << endl; 
		cout << "8. PostOrder" << endl; 
		cout << "9. Exit" << endl; 
		cin >> Choice;
		switch(Choice)
		{
			case 1: 
				{

				cout << "\nEnter value to be inserted: "; 
				cin >> element; 
				Insert(root,element); 
				break; 

				}

			case 2: 
				{
				cout << "\nEnter Element to be Deleted: "; 
				cin >> element; 
				temp = DeleteNode(root, element); 
				if(temp)
				{
					cout<<temp->data<<" Was Deleted!"<<endl;
				}
				break; 
				}

			case 3: 
			{
				cout << "Enter the Key to be search: "<<endl; 
				cin >> element; 
				temp = Search(root,element);

				if(temp)
				{
					cout<<temp->data<<" is founded!"<<endl;
				}
				else
				{
					cout<<"not founded!"<<endl;
				}
				break; 
			}

			case 4: 
			{
				temp = FindMax(root);
				if(temp)
				{
					cout<<temp->data<<" is Max element!"<<endl;
				}
				break;
			}
				
			case 5: 
			{
				temp = FindMin(root);
				if(temp)
				{
					cout<<temp->data<<" is Min element!"<<endl;
				}
			}	
			case 6: 
				{
					inorder(root);
					break;
				}
			case 7: 
				{
				Preorder(root);
				break; 
				}

			case 8: 

				{
				Postorder(root);
				break; 
				}
				
			case 9: 
				{	
				cout << "\nExiting Program." << endl; 
				exit(0); 
				break; 
				}

			default: 
				cout << "\nInvalid choice. Please enter number again between 1 and 9." << endl; 
				break; 

		}


	} while (Choice != 9);
	
	return 0;
	
}