#include <assert.h>

template < class StackElementType >
class Stack {
public:
	Stack();
	void push(StackElementType e);
	StackElementType pop();
	StackElementType top();
	bool isEmpty();

private:
	struct Node;
	typedef Node* Link;
	struct Node {
		StackElementType data;
		Link next;
	};
	Link head;
};


template < class StackElementType>
Stack < StackElementType >::Stack()
{
	head = 0;
}

template < class StackElementType >
void
Stack < StackElementType >::push(StackElementType e)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->data = e;
	addedNode->next = head;
	head = addedNode;
}

template < class StackElementType >
StackElementType
Stack < StackElementType >::pop()
{
	assert(head != 0);
	Link poppedNode = head;
	head = poppedNode->next;
	StackElementType poppedData = poppedNode->data;
	delete poppedNode;

	return poppedData;
}

template <class StackElementType>
StackElementType Stack<StackElementType>::top()
{
	assert(head != 0);
	return head->data;
}

template <class StackElementType>
bool Stack<StackElementType>::isEmpty()
{
	return head == 0;
}