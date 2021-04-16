#include "Tree.h"
#include "Node.h"

#include <iostream>
#include <string.h>

Tree::Tree(const std::string& pos)
{
	root = new Node(pos, nullptr, nullptr);

}

Tree::~Tree()
{
    
}

Node* Tree::find(Node* root, const std::string& value)
{
    if (nullptr == root)
    {
        return nullptr;
    }
    if (value == root->position)
    {
        return root;
    }

    auto firstFound = Tree::find(root->first, value);

    if (nullptr != firstFound)
    {
        return firstFound;
    }

    return Tree::find(root->second,value);

}

bool Tree::addChildNode(const std::string& manager, const std::string& child)
{
    auto managerNode = Tree::find(root,manager);

    if (!managerNode)
    {
        std::cout << manager << "을(를) 찾을 수 없습니다." << std::endl;

        return false;
    }

    if (managerNode->first && managerNode->second)
    {
        std::cout << manager << "아래에 " << child << "를 추가할 수 없습니다." << std::endl;

        return false;
    }

    if(!managerNode->first)
    {
        managerNode->first = new Node(child, nullptr, nullptr);
    }
    else
    {
        managerNode->second = new Node(child, nullptr, nullptr);
    }
    std::cout << manager << "아래에" << child << "를 추가했습니다." << std::endl;

    return true;

}