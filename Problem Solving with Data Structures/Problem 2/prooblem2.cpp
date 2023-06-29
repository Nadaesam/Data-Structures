#include<iostream>

using namespace std;
template<typename ItemType>
class Node {
public:
	ItemType data;
	Node* next;
};

template<class ItemType>
class QueueTypeLinked {
public:
	QueueTypeLinked();
	//	~QueueTypeLinked();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType);
	void Dequeue(ItemType&);
	Node<int>* p2();
	int Length();
private:
	Node<ItemType>* qFront;
	Node<ItemType>* qRear;
};

template<class ItemType>
QueueTypeLinked<ItemType>::QueueTypeLinked()
{
	qFront = NULL;
	qRear = NULL;
}

template<class ItemType>
void QueueTypeLinked<ItemType>::MakeEmpty()
{
	Node<ItemType>* tempPtr;

	while (qFront != NULL) {
		tempPtr = qFront;
		qFront = qFront->next;
		delete tempPtr;
	}
	qRear = NULL;
}

/*template<class ItemType>
QueueTypeLinked<ItemType>::~QueueTypeLinked()
{
	MakeEmpty();
}*/

template<class ItemType>
bool QueueTypeLinked<ItemType>::IsEmpty() const
{
	return(qFront == NULL);
}

template<class ItemType>
bool QueueTypeLinked<ItemType>::IsFull() const
{
	Node<ItemType>* ptr;


	ptr = new Node<ItemType>;
	if (ptr == NULL)
		return true;
	else {
		delete ptr;
		return false;
	}
}

template<class ItemType>
void QueueTypeLinked<ItemType>::Enqueue(ItemType newItem)
{
	Node<ItemType>* newNode;

	newNode = new Node<ItemType>;
	newNode->data = newItem;
	newNode->next = NULL;
	if (qRear == NULL)
		qFront = newNode;
	else
		qRear->next = newNode;
	qRear = newNode;
}

template<class ItemType>
void QueueTypeLinked<ItemType>::Dequeue(ItemType& item)
{
	Node<ItemType>* tempPtr;

	tempPtr = qFront;
	item = qFront->data;
	qFront = qFront->next;
	if (qFront == NULL)
		qRear = NULL;
	delete tempPtr;
}

template<class ItemType>
int QueueTypeLinked<ItemType>::Length()
{
	QueueTypeLinked<ItemType> tempQ;
	ItemType item;
	int length = 0;

	while (!IsEmpty())
	{
		Dequeue(item);
		tempQ.Enqueue(item);
		length++;
	}

	while (!tempQ.IsEmpty())
	{
		tempQ.Dequeue(item);
		Enqueue(item);
	}


	return length;
}
template<class ItemType>
Node<int>* QueueTypeLinked<ItemType>::p2()
{
	Node<int>* ter = qFront;

	return ter;
}
int solaution_p2(QueueTypeLinked<int> q1, int k) {
	int counter = -1, num;
	int len = q1.Length();
	Node<int>* ter = new Node<int>;


	while (len--) {
		counter++;
		if (k == counter)
			ter = q1.p2();
		q1.Dequeue(num);
		q1.Enqueue(num);
	}
	counter = 0;
	while (ter->data > 0) {



		q1.Dequeue(num);
		num--;
		q1.Enqueue(num);


		if (num >= 0) {
			counter++;
		}

	}
	return counter;
}





int main() {
	QueueTypeLinked<int> p;
	p.Enqueue(5);
	p.Enqueue(1);
	p.Enqueue(1);
	p.Enqueue(1);
	QueueTypeLinked<int> v;
	v.Enqueue(2);
	v.Enqueue(3);
	v.Enqueue(2);


	cout << solaution_p2(p, 0) << endl;

	cout << solaution_p2(v, 2);



}