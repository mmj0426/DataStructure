#include "Tree.h"
#include "Traversal.h"

int main()
{
	Tree* tree = new Tree("CEO");
		
	tree->addChildNode("CEO", "부사장");
	tree->addChildNode("부사장", "IT부장");
	tree->addChildNode("부사장", "마케팅부장");
	tree->addChildNode("IT부장", "보안팀장");
	tree->addChildNode("IT부장", "앱개발팀장");
	tree->addChildNode("마케팅부장", "물류팀장");
	tree->addChildNode("마케팅부장", "홍보팀장");
	tree->addChildNode("부사장", "재무부장");

	Traversal* traversal = new Traversal();

	//traversal->preOrder(tree->GetRoot());
	//traversal->inOrder(tree->GetRoot());
	//traversal->postOrder(tree->GetRoot());
	traversal->levelOrder(tree->GetRoot()); 
}