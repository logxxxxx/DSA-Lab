#include <iostream>
#define Max 5

using namespace std;
struct Queue
{
    int  FRONT;
    int REAR;
    int DATA[Max];
};

void Enqueue(struct Queue *Q, int element)
{
    if(Q->REAR==Max-1)
    {
        cout <<"Queue is full "<<endl;
    }
    else
    {
        Q->REAR++;
        Q->DATA[Q->REAR]= element;
    }
}

int Dequeue(struct Queue *Q)
{
    if(Q->REAR <Q->FRONT)
    {
        cout <<"Queue is full "<<endl;
    }
    else
    {
        int element = Q->DATA[Q->FRONT];
        Q->FRONT ++;
        return element;
        
    }
}
void Print(struct Queue *Q)
{
        for (int i = 0; i <= Max-1; ++i)
        {
            cout << Q->DATA[i] << " ";
        }
        cout << endl;
}
int main()
{
    struct Queue Q = {0,-1};
    int choice;
    int data;
    do
    {
        cout << "1.Enque\n2.Dequeue\n3.Print\n4.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout <<"Element to Enque? "<<endl;
            cin >> data;
            Enqueue(&Q,data);
            break;

        case 2:
            data = Dequeue(&Q);
            cout <<data<<"Element is Dequeue!!"<<endl;
            break;

        case 3:
            cout<<"Result";
            Print(&Q);
            break;

        case 4:
            cout<<"Bye..."<<endl;
            break;
            
        default:
            cout <<"Please enter 1,2 ,3 and 4 only!"<<endl;
            break;
        }
    } while (choice!=4);
    
}