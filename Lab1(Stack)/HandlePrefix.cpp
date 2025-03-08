#include <iostream>
#define MAX 5
using namespace std;

struct Stack
{
    int TOS;
    char DATA[MAX];
};
bool isFull(struct Stack *S)
{
   return S->TOS == MAX-1;

}
bool isEmpty(struct Stack *S)
{
   return S->TOS == -1;

}
void push(struct Stack *S, char element)
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
char pop(struct Stack *S)
{
    char element;
    if(S->TOS == -1)
    {
        cout <<"Stack Underflow!!"<<endl;
        return '1';
    }
    else
    {
        element = S->DATA[S->TOS];
        S->TOS -= 1;
        cout<<element<<" is popped"<<endl;
        return element;

    }
}
bool IsOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int ScanStack(Stack* S)
{
    Stack s1 = {-1};
    int result = 0;
    for(int i = 0; i <= S->TOS; i++)
    {
        if(IsOperator(S->DATA[i]))
        {
            int first = pop(&s1)-'0';
            int second = pop(&s1)-'0';
            cout<<first<<endl;
            cout<<second<<endl;
            
            switch (S->DATA[i])
            {
                case '+':
                    result = first + second;
                    cout<<"Addition is done"<<endl;
                    ;
                    break;
                case '-':
                    result = first - second;
                    cout<<"subtraction is done"<<endl;
                    break;
                case '*':
                    result = first * second;
                    cout<<"Multiplication is done";
                    break;
                case '/':
                    result = first / second;
                    cout<<"division is done";
                    break;
                default:
                    cout << "Unknown operator!" << endl;
                    return -1;
            }
            push(&s1,result + '0');   
        }
        else
        {
            push(&s1,S->DATA[i]);
        }
    }
    return result;
}
int main()
{
    int choice;
    char data;
    struct Stack S = {-1};
    do
    {
        cout << "1.PUSH\n2.POP\n3.Result\n4.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout <<"Element to PUSH? "<<endl;
            cin >> data;
            push(&S, data);
            break;

        case 2:
            data = pop(&S);
            cout <<data<<"WAS POPPED!!"<<endl;
            break;

        case 3:
            cout<<"Result: "<<ScanStack(&S)<<endl;
            break;
         
        case 4:
            cout <<"Bye..."<<endl;
            break;

        default:
            cout <<"Please enter 1,2,3 and 4 only!"<<endl;
            break;

        }
    } while (choice!=4);
    return 0;
}