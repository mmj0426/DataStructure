#include <iostream>
#include "Heap.h"
#include "Median.h"

int main()
{
	Median* med = new Median();

	med->insert(1);
	std::cout << "1 ���� �� �߾Ӱ� : " << med->get() << std::endl;

	med->insert(5);
	std::cout << "5 ���� �� �߾Ӱ�: " << med->get() << std::endl;

	med->insert(2);
	std::cout << "2 ���� �� �߾Ӱ�: " << med->get() << std::endl;

	med->insert(10);
	std::cout << "10 ���� �� �߾Ӱ�: " << med->get() << std::endl;

	med->insert(40);
	std::cout << "40 ���� �� �߾Ӱ�: " << med->get() << std::endl;
}