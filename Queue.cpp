#include <iostream>
using namespace std;

//--------------------------------------------------
// Step 1: Define Queue Class
//--------------------------------------------------
class Queue
{
private:
    int queue[5];      // Array to store queue elements
    int front;         // Points to the first element
    int rear;          // Points to the last element
    int size;          // Maximum size of queue

public:

    //--------------------------------------------------
    // Constructor: Initialize Queue
    //--------------------------------------------------
    Queue()
    {
        size = 5;
        front = -1;
        rear = -1;
    }

    //--------------------------------------------------
    // Function to Insert an Element
    //--------------------------------------------------
    void enqueue(int value)
    {
        // Check whether queue is full
        if(rear == size - 1)
        {
            cout << "\nQueue Overflow! Queue is Full.\n";
            return;
        }

        // Insert first element
        if(front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        cout << "\nElement Inserted Successfully.\n";
    }

    //--------------------------------------------------
    // Function to Delete an Element
    //--------------------------------------------------
    void dequeue()
    {
        // Check whether queue is empty
        if(front == -1 || front > rear)
        {
            cout << "\nQueue Underflow! Queue is Empty.\n";

            // Reset queue
            front = rear = -1;
            return;
        }

        cout << "\nDeleted Element : " << queue[front];

        front++;

        // Reset queue when all elements are deleted
        if(front > rear)
        {
            front = rear = -1;
        }
    }

    //--------------------------------------------------
    // Function to Display Queue
    //--------------------------------------------------
    void display()
    {
        // Check whether queue is empty
        if(front == -1)
        {
            cout << "\nQueue is Empty.\n";
            return;
        }

        cout << "\nQueue Elements : ";

        for(int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }

    //--------------------------------------------------
    // Function to View Front Element
    //--------------------------------------------------
    void peek()
    {
        if(front == -1)
        {
            cout << "\nQueue is Empty.\n";
            return;
        }

        cout << "\nFront Element : " << queue[front] << endl;
    }
};

//--------------------------------------------------
// Main Function
//--------------------------------------------------
int main()
{
    Queue q;

    int choice, value;

    do
    {
        cout << "\n=================================";
        cout << "\n         QUEUE MENU";
        cout << "\n=================================";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Peek";
        cout << "\n5. Exit";

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter Element : ";
                cin >> value;

                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                q.peek();
                break;

            case 5:
                cout << "\nProgram Terminated Successfully.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}

