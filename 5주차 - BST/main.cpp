#include "BST.h"
#include <iostream>

int main()
{
	BST* tree = new BST();

	tree->insert(12);
	tree->insert(10);
	tree->insert(20);
	tree->insert(8);
	tree->insert(11);
	tree->insert(15);
	tree->insert(28);
	tree->insert(4);
	tree->insert(2);

	// 중위순회 오름차순 출력
	std::cout << "<오름차순>"<<std::endl;
	tree->inorder();
	std::cout << std:: endl;

	// 내림차순 출력
	std::cout << "<내림차순>" << std::endl;
	tree->descending();
	std::cout << std:: endl;

	tree->deleteValue(12);
	std::cout << "노드 12를 삭제한 후 오름차순" << std:: endl;
	tree->inorder();
	std::cout << std::endl;

	std::cout << "노드 12를 삭제한 후 내림차순" << std::endl;
	tree->descending();
	std::cout << std::endl;

	if (tree->find(12))
	{
		std::cout<< "원소 12는 트리에 있습니다." << std::endl;
	}
	else
	{
		std::cout << "원소 12는 트리에 없습니다." << std::endl;
	}
}