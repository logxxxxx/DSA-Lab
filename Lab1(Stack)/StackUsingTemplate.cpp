#include <iostream>
#define DefaultSize 5
#define TOP 0

using namespace std;

template <typename T>
struct  Stack
{
    int Top;
    int StackSize;
    T* Array;

    Stack():Top(TOP),StackSize(DefaultSize)
    {
        Array = new T[StackSize];
    }
    Stack(int LocalSize):Top(TOP), StackSize(LocalSize)
    {
        Array = new T[StackSize];
    }    

    bool IsEmpty()
    {
        return Top == TOP;
    }

    bool IsFull()
    {
        return Top == StackSize-1;
        
    }

    void Push(T Value)
    {
        Array[++Top] = Value;
    }

    template <typename...Values>

    void Push(Values...LocalValues)
    {
        if(IsFull()||StackSize == Top +  sizeof...(LocalValues))
        {
            printf("Stack is Overflow, Please increase the size of stack or decrease argument....\n ");
        }
        else
        {
            (Push(LocalValues), ...);
        }
    }

    void Print()
    {
        for (int i = 0; i <= Top; ++i)
        {
            cout << Array[i] << " ";
        }
        cout << endl;
    }

};  

int main()
{
    Stack<int> s1; 
    s1.Push(100, 200, 35); 
    s1.Print(); 

}
