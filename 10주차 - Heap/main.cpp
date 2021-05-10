#include <iostream>
#include "Heap.h"
#include "Median.h"

int main()
{
	Median* med = new Median();

	med->insert(1);
	std::cout << "1 »ğÀÔ ÈÄ Áß¾Ó°ª : " << med->get() << std::endl;

	med->insert(5);
	std::cout << "5 »ğÀÔ ÈÄ Áß¾Ó°ª: " << med->get() << std::endl;

	med->insert(2);
	std::cout << "2 »ğÀÔ ÈÄ Áß¾Ó°ª: " << med->get() << std::endl;

	med->insert(10);
	std::cout << "10 »ğÀÔ ÈÄ Áß¾Ó°ª: " << med->get() << std::endl;

	med->insert(40);
	std::cout << "40 »ğÀÔ ÈÄ Áß¾Ó°ª: " << med->get() << std::endl;
}