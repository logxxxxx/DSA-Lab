#include <iostream>
#define MAX 5

using namespace std;
struct Stack
{
    int TOS;
    int DATA[MAX];
};
bool IsFull(struct Stack *S)
{
   return S->TOS == MAX-1;
}
bool IsEmpty(struct Stack *S)
{
   return S->TOS == -1;
}
void Push(struct Stack *S, int Element)
{
    if(S->TOS == MAX-1)
    {
        cout<<"Stack Overflow!!"<<endl;
    }
    else
    {
        S->TOS += 1;
        S->DATA[S->TOS] = Element;
        cout<<Element<<" WAS PUSHED!!"<<endl;
    }
}
int pop(struct Stack *S)
{
    int element;
    if(S->TOS == -1)
    {
        cout<<"Stack Underflow!!"<<endl;
        return -1;
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
    int data, choice;
    struct Stack S = {-1};
    do
    {
        cout<<"1.PUSH\n2.POP\n3.EXIT"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        cout<<endl;
        switch (choice)
        {
        case 1:
            cout<<"Enter the element to PUSH"<<endl;
            cin>>data;
            Push(&S, data);
            break;

        case 2:
            data = pop(&S);
            if(data != -1)
            {
                cout<<data<<" WAS POPPED!!"<<endl;
            }
            break;

        case 3:
            printf("Byeee!!\n");
            break;
        
        default:
            printf("Please enter 1,2 or 3 only!\n");
            break;
        }
    } while (choice!=3);
    
}