#include "PriorityQueue.h"
#include<iostream>
using namespace std;


template<class T>
PriorityQueue<T>::PriorityQueue()
{
	top = NULL;
	length = 0;
}

template<class T>
void PriorityQueue<T>::push(T item)
{
	Node<T>* newnode = new Node<T>();
	newnode->item = item;
	newnode->prio = 0;
	if (isEmpty()) {
		top = newnode;
	}
	else {
		
		if (newnode->item > top->item) {
			for (int i = 0; i < length; i++)
			{
				newnode->prio++;
			}
			newnode->next = top;
			top = newnode;
		}
		else {
			top->prio++;
			int count = 0;
			Node<T>* curr = top->next;
			Node<T>* prev = top;
			while (curr != NULL) {
				count++;
				if (curr->item < newnode->item) {
					prev->next = newnode;
					newnode->next = curr;
					break;
				}
				else {
					curr->prio++;
				}
				prev = curr;
				curr = curr->next;
			}
			if (curr == NULL) {
				prev->next = newnode;
				newnode->next = NULL;
			}
			else {
				newnode->prio += length - count;
			}
		}
		}
	length++;
	}

template<class T>
void PriorityQueue<T>::pop()
{
	Node<T>* curr;
	curr = top;
	top = top->next;
	delete curr;
	length--;
}

template<class T>
Node<T>* PriorityQueue<T>::getTop()
{
	return top;
}

template<class T>
int PriorityQueue<T>::getSize()
{
	return length;
}



template<class T>
bool PriorityQueue<T>::isEmpty()
{
	return (length==0);
}

template<class T>
void PriorityQueue<T>::swap(PriorityQueue<T> *q)
{
	if (q->getSize() != length)
		cout << "Cannot swap not the same size!" << endl;
	else {
		Node<T>* curr = top, *curr2 = q->getTop();
		T temp;
		while (curr != NULL) {
			temp = curr->item;
			curr->item = curr2->item;
			curr2->item = temp;
			curr = curr->next;
			curr2 = curr2->next;
		}
		
		
	}
}

template<class T>
void PriorityQueue<T>::emplace(T item)
{
	Node<T>* newnode = new Node<T>();
	newnode->item = item;
	newnode->next = top;
	top = newnode;
	length++;

}

template<class T>
void PriorityQueue<T>::print()
{
	Node<T>* curr = top;
	while (curr != NULL) {
		cout << curr->item << " ";
		curr = curr->next;
	}
}
