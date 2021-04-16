#include "Traversal.h"
#include "Tree.h"
#include "Node.h"

#include <iostream>
#include <queue>

void Traversal::preOrder(Node* start)
{
	if (!start)
	{
		return;
	}

	std::cout<< start->position<< ", ";
	preOrder(start->first);
	preOrder(start->second);
}

void Traversal::inOrder(Node* start)
{
	if (!start)
	{
		return;
	}

	inOrder(start->first);
	std::cout << start->position << ", ";
	inOrder(start->second);
}

void Traversal::postOrder(Node* start)
{
	if (!start)
	{
		return;
	}

	postOrder(start->first);
	postOrder(start->second);
	std::cout << start->position << ", ";
}

void Traversal::levelOrder(Node* start)
{
	if (!start)
	{
		return;
	}

	std::queue<Node*> q;
	q.push(start);

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			auto current = q.front();
			q.pop();

			std::cout << current->position << ", ";
			if (current->first)
			{
				q.push(current->first);
			}
			if (current->second)
			{
				q.push(current->second);
			}
		}

		std::cout << std::endl;
	}
}
