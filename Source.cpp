#include <iostream>
#include "PriorityQueue.cpp"
using namespace std;

int main() {

	PriorityQueue<int>* q = new PriorityQueue<int>();
	PriorityQueue<int>* p = new PriorityQueue<int>();
	int n,s;
	do {
		cout << "************ Priority Queue ************ \n \n" << endl;
		cout << " 1- Push \n 2- Pop \n 3- Get top \n 4- swap \n 5- Emplace \n 6- Get size \n 7- print \n 8- Exit " << endl;
		cin >> s;
		switch (s) {
		case 1:
			cout << "Enter the number you want to push: \t \t (Enter -1 to stop)" << endl;
			do {
				cin >> n;
				if (n == -1)
					break;
				q->push(n);
			  } while (true);
			
			cout << "Is pushed!" << endl;
			break;
		case 2:
			q->pop();
			cout << "Is poped!" << endl;
			break;
		case 3:
			cout << "The top is " << q->getTop()->item << endl;
			break;
		case 4:
			cout << "Enter the number you want to push for the another priority queue: \t \t (Enter -1 to stop)" << endl;
			do {
				cin >> n;
				if (n == -1)
					break;	
				p->push(n);
			  } while (true);
			cout << "Is pushed! \n" << endl;
			cout << "Is swapped! \n" << endl;
			q->swap(p);
			cout << "Q is \t" << endl;
			q->print();
			cout << "\n P is \t" << endl;
			p->print();
			cout << endl;
			break;
		case 5:
			cout << "Enter the number you want to emplace: " << endl;
			cin >> n;
			q->emplace(n);
			cout << "Is emplaced!" << endl;
			break;
		case 6:
			cout << "The size is " << q->getSize() << endl;
			break;
		case 7:
			cout << "The queue is [ ";
			q->print();
			cout << " ]" << endl;
			break;
		case 8:
			cout << "Is leaving.......!" << endl;
			break;
		default:
			cout << " You entered invalid input! \n Please enter valid input: " << endl;
		}
	} while (s!=8);
	return 0;
}