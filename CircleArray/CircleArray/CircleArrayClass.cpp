#include "CircleArrayClass.h"
#include <iostream>

CircleArrayClass::CircleArrayClass(std::vector<int> &_list)
{
	listBegin_ = new Node;
	listBegin_->prev = nullptr;
	listBegin_->value = _list.at(0);
	Node *prev = listBegin_;
	for (int i = 1; i < _list.size(); ++i)
	{
		Node *n = new Node;
		n->prev = prev;
		prev->next = n;
		n->value = _list.at(i);
		prev = n;
	}
	prev->next = listBegin_;
	listBegin_->prev = prev;
	listSize_ = _list.size();
}

CircleArrayClass::CircleArrayClass(Node *_newFirstNode)
{
	listBegin_->next = _newFirstNode->next;
	listBegin_->prev = _newFirstNode->prev;
	listBegin_->value = _newFirstNode->value;

	delete(_newFirstNode);
}

CircleArrayClass::~CircleArrayClass()
{
	Node *current;
	Node *next = listBegin_;
	for (int i = 0; i < listSize_; ++i)
	{
		current = next;
		next = current->next;
		delete(current);
	}
}

CircleArrayClass::CircleArrayClass(CircleArrayClass &&_right)
{
	listBegin_->next = _right.listBegin_->next;
	listBegin_->prev = _right.listBegin_->prev;
	listBegin_->value = _right.listBegin_->value;

	listSize_ = _right.listSize_;

	delete(_right.listBegin_);
}

CircleArrayClass& CircleArrayClass::operator=(CircleArrayClass &&_right)
{
	int size = _right.listSize_;
	CircleArrayClass newFriend(_right.listBegin_);
	newFriend.listSize_ = size;
	return newFriend;
}

void CircleArrayClass::rotateForward()
{
	listBegin_ = listBegin_->next;
}

void CircleArrayClass::rotateBack()
{
	listBegin_ = listBegin_->prev;
}

void CircleArrayClass::printList() 
{
	Node *current = listBegin_;
	for (int i = 0; i < listSize_; ++i)
	{
		std::cout << current->value << ", ";
		current = current->next;
	}
	std::cout << "\n";
}