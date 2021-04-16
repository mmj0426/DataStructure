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

	// ������ȸ �������� ���
	std::cout << "<��������>"<<std::endl;
	tree->inorder();
	std::cout << std:: endl;

	// �������� ���
	std::cout << "<��������>" << std::endl;
	tree->descending();
	std::cout << std:: endl;

	tree->deleteValue(12);
	std::cout << "��� 12�� ������ �� ��������" << std:: endl;
	tree->inorder();
	std::cout << std::endl;

	std::cout << "��� 12�� ������ �� ��������" << std::endl;
	tree->descending();
	std::cout << std::endl;

	if (tree->find(12))
	{
		std::cout<< "���� 12�� Ʈ���� �ֽ��ϴ�." << std::endl;
	}
	else
	{
		std::cout << "���� 12�� Ʈ���� �����ϴ�." << std::endl;
	}
}