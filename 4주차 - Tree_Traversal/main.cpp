#include "Tree.h"
#include "Traversal.h"

int main()
{
	Tree* tree = new Tree("CEO");
		
	tree->addChildNode("CEO", "�λ���");
	tree->addChildNode("�λ���", "IT����");
	tree->addChildNode("�λ���", "�����ú���");
	tree->addChildNode("IT����", "��������");
	tree->addChildNode("IT����", "�۰�������");
	tree->addChildNode("�����ú���", "��������");
	tree->addChildNode("�����ú���", "ȫ������");
	tree->addChildNode("�λ���", "�繫����");

	Traversal* traversal = new Traversal();

	//traversal->preOrder(tree->GetRoot());
	//traversal->inOrder(tree->GetRoot());
	//traversal->postOrder(tree->GetRoot());
	traversal->levelOrder(tree->GetRoot()); 
}