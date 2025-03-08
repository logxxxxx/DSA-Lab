#include <iostream>
using namespace std;
struct SLL 
{
    int data; // Data stored in the node
    SLL* next = nullptr; // Pointer to the next node in the list
};

//function to initialize the NewNode with given data
SLL* InitializeNewNode(int data)
{
    struct SLL* newNode = new SLL(); 
	/* 
		In c 
		NewNode = (struct SLL*)malloc(sizeof(SLL)); 
	*/
	newNode->data = data;
    newNode->next = nullptr;

    return newNode; 
} 




void InsertionAtbeginning(SLL*& fist, SLL*& last, int value)
{
	struct SLL* NewNode = InitializeNewNode(value);
	if(NewNode == nullptr)
	{
		cout << "Memory allocation failed" << endl;
		return;
	}
	NewNode->data = value; 
	NewNode->next = nullptr; 
	if(fist == nullptr) // i.e List is empty
	{
		fist = last = NewNode; 

	}
	else
	{
		NewNode->next = fist; 
		fist = NewNode; 
	}
	cout << fist->data <<" is inserted at beginning" << endl;
}

void InsertionAtend(SLL*& first, SLL*& last, int value)
{
	struct SLL* NewNode = InitializeNewNode(value);

	if(NewNode == nullptr)
	{
		cout << "Memory allocation failed" << endl;
		return;
	}

	if(first == nullptr) // i.e List is empty
	{
		first = last = NewNode; 
	}
	else
	{
		last->next = NewNode; 
		last = NewNode; 
	}

	cout << last->data <<" is inserted at end" << endl; 	

}

void InsertionAtSpecificPosition(SLL*& first, SLL*& last, int pos, int value)
{
	if(pos == 1) // i.e List is empty means insertion should be done in the beginning
	{
		InsertionAtbeginning(first, last, value); 
	}
	else //insertion at specific position using for loop
	{
		struct SLL* NewNode = InitializeNewNode(value);

		if(NewNode == nullptr)
		{
			cout << "Memory allocation failed" << endl;
			return;
		}

		SLL* temp = first; 
		for(int i=1;i<pos-1;i++) 
		{
			temp = temp->next;
		}
		NewNode->next = temp->next; 
		temp->next = NewNode; 
		cout << value <<" is inserted at position " << pos << endl; 	
	}

}

void DelationAtbeginning(SLL*& first, SLL*& last)
{
	SLL* temp;
	if(first == nullptr) // i.e List is empty
	{
		cout << "List is empty" << endl; 
	}
	else if (first == last) // i.e List has single element
	{
		temp = first;
		first = last = nullptr; 
		cout << temp->data <<" is deleted from list" << endl; 
		free(temp); 	
	}
	else //i.e List has more than one element
	{
		temp = first;
		first = first->next; 
		cout << temp->data <<" is deleted from list" << endl; 
		free(temp); 	
	}
}

void DelationAtend(SLL*& first, SLL*& last)
{
	SLL* temp;
	if(first == nullptr) // i.e List is empty
	{
		cout << "List is empty" << endl; 
	}
	else if (first == last) // i.e List has single element
	{
		temp = first;
		first = last = nullptr; 
		cout << temp->data <<" is deleted from list" << endl; 
		free(temp); 	
	}
	else //i.e List has more than one element
	{
		temp = first;
		while (temp->next != last)
		{
			temp = temp->next;

		}
		last = temp;
		temp = last->next;
		last->next = nullptr;
		cout << temp->data <<" is deleted from list" << endl; 
		free(temp); 	
	}
}

void DelationAtSpecificPosition(SLL*& first, SLL*& last , int pos)
{
	SLL* temp; 
	if(pos == 1) // i.e Position is first
	{
		DelationAtbeginning(first, last);
	}
	else
	{
		temp = first;
		for(int i=1;i<pos-1;i++) // loop to reach the previous node of the desired position

		{
			temp = temp->next;
		}
		if(temp->next == last) // i.e Position is last
		{
			DelationAtend(first, last);
		}
		else // i.e Position is in between two nodes
		{
			SLL* tempp;
			tempp = temp->next;
			temp->next = tempp->next;
			cout << tempp->data <<" is deleted from list" << endl; 
			free(tempp); 	

		}

	}
}

void DisplayList(SLL* first)
{
	//SLL* temp = first;
	if(first == nullptr) // if list is empty
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "List elements: ";
    while (first) {
        cout << first->data << " ";
        first = first->next;
    }
    cout << endl;
	
}

void SearchInList(SLL* first, SLL* last , int value)
{
	if(first == nullptr) // if list is empty
	{
		cout << "List is empty" << endl;
		return;
	}
	else
	{
		SLL* temp = first;
		int flag = 0;

		do
		{
			if(temp->data == value) // if element is found
			{
				flag = 1;
				cout << "Element found" << endl;
			}
			temp = temp->next;

		} while (temp != nullptr);

		if(flag == 0) // if element is not found
		{
			cout << "Element not found" << endl;
		}
	}
}


int main() 
{
	struct SLL* First = nullptr;
	struct SLL* Last = nullptr;
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
				InsertionAtbeginning(First, Last, value); 
				break; 

				}

			case 2: 
				{
				cout << "\nEnter value to be inserted at end: "; 
				cin >> value; 
				InsertionAtend(First, Last, value); 
				break; 
				}

			case 3: 
				{
				cout << "\nEnter position and value to be inserted at specific position: "<<endl; 
				cout<<"Enter Postion:";
				cin >> pos; 
				cout<<"Enter Value:";
				cin >> value; 
				InsertionAtSpecificPosition(First, Last, pos, value); 
				break; 
				}

			case 4: 
				{
				DelationAtbeginning(First, Last); 
				break; 
				}
				
			case 5: 
				{
				DelationAtend(First, Last); 
				break; 
				}
				
			case 6: 
				{
				cout << "\nEnter position of value to be deleted: "; 
				cin >> pos; 
				DelationAtSpecificPosition(First, Last, pos); 
				break; 
				}
			case 7: 
				{
				cout << "\nDisplaying List:" << endl; 
				DisplayList(First); 
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

