#include <iostream>
#define MAX 5
using namespace std;

struct Stack
{
    int TOS;
    int Value;
    Stack* DATA[MAX];
};
int isFull(struct Stack *S)
{

   return S->TOS == MAX-1;
}
int isEmpty(struct Stack *S)
{
   return S->TOS == -1;
}
void push(struct Stack *S, Stack* element)
{
    if(S->TOS == MAX-1)
    {
        cout <<"Stack Overflow!!"<<endl;
    }    
    else
    {
        S->TOS += 1;
        S->DATA[S->TOS] = element;
        cout<<element<<"WAS PUSHED!!"<<endl;
    }
}
Stack* pop(struct Stack *S)
{
    Stack* element;
    if(S->TOS == -1)
    {
        cout <<"Stack Underflow!!"<<endl;
        return nullptr;
    }
    else
    {
        element = S->DATA[S->TOS];
        S->TOS -= 1;
        return element;
    }
}
int main()
{
    int choice;
    Stack* data = nullptr;
    struct Stack S = {-1};
    do
    {
        cout << "1.PUSH\n2.POP\n3.EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Stack* NewStack = new Stack{-1};
            cout <<"Enter the Struct Value:";
            cin>>NewStack->Value;
            push(&S, NewStack);
            break;
        }
        case 2:
        {
            data = pop(&S);
            if(data == nullptr)
            {
                cout<<"Stack might be empty"<<endl;
                break;
            }
            cout <<endl<<"Struct having Value = "<<data->Value<<" Was Poped!!"<<endl;
            break;
        }
        case 3:
            cout <<"Bye..."<<endl;
            break;
        default:
            cout <<"Please enter 1,2 or 3 only!"<<endl;
            break;
        }
    } while (choice!=3);
    return 0;
}