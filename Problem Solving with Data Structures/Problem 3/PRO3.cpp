
using namespace std;
#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
class Queue {
public:
    Node* front;
    Node* rear;
    Queue() 
    {
        front = rear = NULL;

    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int item)
    {
        Node* new_node = new Node;
        new_node->data=item;
        if (isEmpty())
            front = rear = new_node;
        else
        {
            rear->next = new_node;
            rear = new_node;

        }

    }
   void dequeue()
   {
       if (isEmpty())
           cout << "stack is empty" << endl;
       else if(front==rear)
       {
           delete front;
           front = rear = NULL;

       }
       else {
           Node* delptr = front;
           front = front->next;
           delete delptr;
       }
       
   }
   int peek()
   { 
       if (front == NULL)
       {
           cout << "stack is empty";
           return-1;
       }
       else
           return front->data;
   }
   int count()
   {
       int counter = 0;
       Node* temp = front;
       while (temp!=NULL)
       {
           counter++;
           temp = temp->next;
       }
       return counter;
   }

};
class Stack
{   
private:
    Queue q;
public:
    void push(int x);
    void pop();
    int top();
  
};

// Push operation
void Stack::push(int x)
{
    //  Get previous size of queue
    int s = q.count();

    // Push current element
    q.enqueue(x);

    // Pop (or Dequeue) all previous
    // elements and put them after current
    // element
    for (int i = 0; i < s; i++)
    {
        // this will add front element into
        // rear of queue
        q.enqueue(q.peek());

        // this will delete front element
        q.dequeue();
    }
}

// Removes the top element
void Stack::pop()
{
    if (q.isEmpty())
        cout << "Stack is empty\n";
    else
        q.dequeue();
}

// Returns top of stack
int  Stack::top()
{
    if (q.isEmpty())
       return-1;
    else
      return q.peek();
}


// Driver code
int main()
{
    Stack s;
    s.pop();
    cout << s.top() << endl;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
   
}