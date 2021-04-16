#include "BST.h"
#include "Node.h"

#include <iostream>

BST::BST()
{
	root = nullptr;
}

Node* BST::find_impl(Node* current, int value)
{
	if (!current)
	{
		std::cout << std:: endl;
		return nullptr;
	}

	if (value == current->data)
	{
		std::cout << value << "��(��) ã�ҽ��ϴ�." << std::endl;
		return current;
	}

	// value ���� ���ʿ� �ִ� ���
	if (value < current->data)
	{
		std::cout << current->data << "���� �������� �̵� -> ";
		return find_impl(current->left, value);
	}
	// value ���� �����ʿ� �ִ� ���
	else
	{
		std::cout << current->data << "���� ���������� �̵� -> ";
		return find_impl(current->right, value);
	}
}

Node* BST::find(int value)
{
	return find_impl(root, value);
}

void BST::insert_impl(Node* current, int value)
{
	if (value < current->data)
	{
		if (!current->left)
		{
			current->left = new Node {value, nullptr, nullptr};
		}
		else
		{
			insert_impl(current->left,value);
		}
	}
	else
	{
		if (!current->right)
		{
			current->right = new Node{value, nullptr, nullptr};
		}
		else
		{
			insert_impl(current->right, value);
		}
	}
}

void BST::insert(int value)
{
	if (!root)
	{
		root = new Node{value, nullptr, nullptr};
	}
	else
	{
		insert_impl(root,value);
	}

}


// �������� 
void BST::inorder_impl(Node* start)
{
	if (!start)
	{
		return;
	}

	inorder_impl(start->left);
	std::cout<<"[ "<<start->data << " ]  ";
	inorder_impl(start->right);
}

void BST::inorder()
{
	inorder_impl(root);
}

void BST::decending_impl(Node* start)
{
	if (!start)
	{
		return;
	}

	decending_impl(start->right);
	std::cout << "[ " << start->data << " ]  ";
	decending_impl(start->left);
}

void BST::descending()
{
	decending_impl(root);
}


Node* BST::successor(Node* start)
{
	auto current = start->right;
	while (current && current->left)
	{
		current = current->left;
	}

	return current;
}

Node* BST::delete_impl(Node* start, int value)
{
	if (!start)
	{
		return nullptr;
	}

	// �ļ� ��� ã��
	if (value < start->data)
	{
		start->left = delete_impl(start->left, value);
	}
	else if (value > start->data)
	{
		start->right = delete_impl(start->right,value);
	}
	else
	{	
		// �ڽ� ��尡 ���� ���ų�, ���� �ڽ� ��常 ���� ���
		if (!start->left)
		{
			auto tmp = start->right;
			delete start;
			return tmp;
		}

		// ������ �ڽ� ��常 ���� ���
		if (!start->right)
		{
			auto tmp = start->left;
			delete start;
			return tmp;
		}

		// �ڽ� ��尡 �� �� �ִ� ���
		auto succNode = successor(start);
		start->data = succNode->data;

		start->right = delete_impl(start->right, succNode->data);
	}

	return start;
}

void BST::deleteValue(int value)
{
	root = delete_impl(root,value);
}
