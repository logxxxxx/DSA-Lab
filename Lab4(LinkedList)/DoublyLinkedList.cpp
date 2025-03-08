#include <iostream>
using namespace std;

struct DLL
{
	int data;
	DLL *next, *prev;
};

DLL* createNode(int data)
{
	DLL *newNode = new DLL();
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void InsertionAtBeginning(DLL *&first, DLL *&last, int data)
{
	DLL *newNode = createNode(data);
	if (first == NULL && last == NULL) // List is empty
	{
		first = last = newNode;
	}
	else
	{
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}
}

void InsertionAtEnd(DLL *&first, DLL *&last, int data)
{
	DLL *newNode = createNode(data);
	if (first == NULL && last == NULL) // List is empty
	{
		first = last = newNode;
	}
	else
	{
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
	}
}

void InsertionAtSpecificPosition(DLL *&first, DLL *&last, int data, int position)
{
	DLL *newNode = createNode(data);
	if (position == 1) // Insert at the beginning
	{
		InsertionAtBeginning(first, last, data);
	}
	else
	{
		DLL *current = first;
		for (int i = 1; i < position - 1; i++)
		{
			current = current->next;
		}

		if(current->next == last)
		{
			InsertionAtEnd(first, last, data); // Insert at the end
		}
		else
		{
			newNode->next = current->next;
			current->next->prev = newNode;
			newNode->prev = current;
			current->next = newNode;
		}
	}
}

void DeletionAtBeginning(DLL *&first, DLL *&last)
{
	if (first == NULL && last == NULL) // List is empty
	{
		cout << "List is empty" << endl;
		return;
	}
	else if (first->next == NULL) // Only one node in the list
	{
		delete first;
		first = last = NULL;
	}
	else
	{
		DLL *temp = first;
		first = first->next;
		first->prev = NULL;
		delete temp;
	}
}
void DeletionAtEnd(DLL *&first, DLL *&last)
{
	if (first == NULL && last == NULL) // List is empty
	{
		cout << "List is empty" << endl;
		return;
	}
	else if (first->next == NULL) // Only one node in the list
	{
		delete first;
		first = last = NULL;
	}
	else
	{
		DLL *temp = last;
		last = last->prev;
		last->next = NULL;
		delete temp;
	}

}

void DeletionAtPosition(DLL *&first, DLL *&last, int position)
{
	if (first == NULL && last == NULL) // List is empty
	{
		cout << "List is empty" << endl;
		return;
	}
	else if (position == 1) // Delete the first node
	{	
		DeletionAtBeginning(first, last);
	}
	else
	{
		DLL *temp = first;
		int count = 1;
		while (count < position - 1)
		{
			temp = temp->next;
			count++;
		}

		if(temp->next == last)	
		{
			DeletionAtEnd(first, last); // Deletation of the last node
		}
		else
		{

			DLL *delNode = temp->next;
			temp->next = delNode->next;
			delNode->prev = temp;
			delete delNode;
		}
	}
}

void Display(DLL *&first, DLL *&last)
{
	if (first == NULL && last == NULL) // List is empty
	{
		cout << "List is empty" << endl;
		return;
	}
	else
	{
		DLL *temp = first;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void SearchInList(DLL *&first, DLL *&last, int key)
{
	if (first == NULL && last == NULL) // List is empty
	{
		cout << "List is empty" << endl;
		return;
	}
	else
	{
		DLL *temp = first;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				cout <<temp->data << " Value is present in the list " <<endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Vlaue not found in the list" << endl;
	}
}

int main()
{
	DLL *First = NULL, *Last = NULL;
		int choice, value, pos; 
	do
	{
		cout << "\n1. Insertion at beginning" << endl; 
		cout << "2. Insertion at end" << endl; 
		cout << "3. Insertion at specific position" << endl; 
		cout << "4. Delation at beginning" << endl; 
		cout << "5. Delation  at end" << endl; 
		cout << "6. Delation at specific position" << endl; 
		cout << "7. Display List" << endl; 
		cout << "8. Search Element in List" << endl; 
		cout << "9. Exit" << endl; 
		cin >> choice;
		switch(choice)
		{
			case 1: 
				{

				cout << "\nEnter value to be inserted at beginning: "; 
				cin >> value; 
				InsertionAtBeginning(First, Last, value); 
				break; 

				}

			case 2: 
				{
				cout << "\nEnter value to be inserted at end: "; 
				cin >> value; 
				InsertionAtEnd(First, Last, value); 
				break; 
				}

			case 3: 
				{
				cout << "\nEnter position and value to be inserted at specific position: "<<endl; 
				cout<<"Enter Postion:";
				cin >> pos; 
				cout<<"Enter Value:";
				cin >> value; 
				InsertionAtSpecificPosition(First, Last, value, pos); 
				break; 
				}

			case 4: 
				{
				DeletionAtBeginning(First, Last); 
				break; 
				}
				
			case 5: 
				{
				DeletionAtEnd(First, Last); 
				break; 
				}
				
			case 6: 
				{
				cout << "\nEnter position of value to be deleted: "; 
				cin >> pos; 
				DeletionAtPosition(First, Last, pos); 
				break; 
				}
			case 7: 
				{
				cout << "\nDisplaying List:" << endl; 
				Display(First, Last); 
				break; 
				}

			case 8: 

				{
				cout << "\nEnter value to be searched in list: "; 
				cin >> value; 
				SearchInList(First, Last, value); 
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


	} while (choice != 9);
	
	return 0;
	
}






















