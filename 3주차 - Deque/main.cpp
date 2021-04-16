#include "deque.h"

int main()
{

	deque<int,5> deq;

	deq.push_back(0);
	deq.push_front(5);
	deq.push_back(1);
	deq.push_back(9);
	deq.push_front(4);
	deq.push_front(2);

	deq.printElement();

	

	//245019

}