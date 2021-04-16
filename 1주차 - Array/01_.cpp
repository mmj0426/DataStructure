#include <iostream>
#include "Array.h"


int main()
{

	Array<int,3>myarray;

	//데이터 추가
	myarray[0] = 5;
	myarray[1] = 6;
	myarray[2] = 7;

	std::cout << "Begin : " << myarray.GetBegin() <<std::endl;
	std::cout << "End : " << myarray.GetEnd() << std::endl;
	std::cout << "Size : " << myarray.GetSize()<<std::endl;
}

