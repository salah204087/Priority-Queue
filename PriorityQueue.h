#pragma once
template<class T>
struct Node {
	T item;
	int prio;
	Node<T>* next;
};

template<class T>
class PriorityQueue
{
private:
	Node<T>* top;
	int length;

public:
	PriorityQueue();
	void push(T item);
	void pop();
	Node<T>* getTop();
	int getSize();
	bool isEmpty();
	void swap(PriorityQueue<T> *q);
	void emplace(T item);
	void print();

};

