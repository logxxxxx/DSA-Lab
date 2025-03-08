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
    if(Q->FRONT ==(Q->REAR+1)%Max)
    {
        cout <<"Queue is full "<<endl;
    }
    else
    {
        Q->DATA[Q->REAR]=element;
        Q->REAR =(Q->REAR+1)%Max;
    }
}

int Dequeue(struct Queue *Q)
{
    if(Q->FRONT == Q->REAR)
    {
        cout <<"Queue is full "<<endl;
        return 0;
    }
    else
    {
        int element = Q->DATA[Q->FRONT];

        Q->FRONT = (Q->FRONT+1)%Max;
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
            cout<<"Result:";
            Print(&Q);
            break;

        case 4:
            cout <<data<<"Bye..."<<endl;
            break;
               
        default:
            cout <<"Please enter 1,2 ,3 and 4 only!"<<endl;
            break;

        }
    } while (choice!=4);
    
}