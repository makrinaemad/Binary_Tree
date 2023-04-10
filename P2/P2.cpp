#include <iostream>

using namespace std;

class Queue
{
private:
	struct node
	{
		int item;
		node* next;
	};
	int length;
	node* front, * rear;
public:
	Queue()
	{
		front = rear = NULL;
		length = 0;
	}

	bool isEmpty()
	{
		return length == 0;
	}

	void push(int value)
	{
		node* newnode = new node;
		newnode->item = value;
		newnode->next = NULL;
		if (length == 0)
			rear = front = newnode;
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
		length++;
	}

	void pop()
	{
		if (isEmpty())
			cout << "it's already empty" << endl;
		else if (length == 1)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
			node* temp = front;
			front = front->next;
			delete temp;
		}
		length--;
	}

	int top()
	{
		if (isEmpty())
			cout << "NULL" << endl;
		else
			return front->item;
	}

	int Qsize()
	{
		return length;
	}

};

class stack
{
	Queue q1;
public:

	void push(int value)
	{
		int s = q1.Qsize();
		q1.push(value);
		for (int i = 0; i < s; i++)
		{
			q1.push(q1.top());
			q1.pop();
		}
	}

	void pop()
	{
		if (q1.Qsize() == 0)
			cout << "empty stack..." << endl;
		else
			q1.pop();
	}

	int top()
	{
		return q1.top();
	}
};

int main()
{

	stack s1;
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(7);
	cout << s1.top() << endl;


}