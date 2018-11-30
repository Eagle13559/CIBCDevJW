#include "CircleArrayClass.h"
#include <iostream>

template <typename T>
CircleArrayClass<T>::CircleArrayClass(std::vector<T> &_list)
{
	listBegin_ = new Node<T>;
	listBegin_->prev = nullptr;
	listBegin_->value = _list.at(0);
	Node<T> *prev = listBegin_;
	for (int i = 1; i < _list.size(); ++i)
	{
		Node<T> *n = new Node<T>;
		n->prev = prev;
		prev->next = n;
		n->value = _list.at(i);
		prev = n;
	}
	prev->next = listBegin_;
	listBegin_->prev = prev;
	listSize_ = _list.size();
}

template <typename T>
CircleArrayClass<T>::CircleArrayClass(Node<T> *_newFirstNode)
{
	listBegin_->next = _newFirstNode->next;
	listBegin_->prev = _newFirstNode->prev;
	listBegin_->value = _newFirstNode->value;

	delete(_newFirstNode);
}

template <typename T>
CircleArrayClass<T>::~CircleArrayClass<T>()
{
	Node<T> *current;
	Node<T> *next = listBegin_;
	for (int i = 0; i < listSize_; ++i)
	{
		current = next;
		next = current->next;
		delete(current);
	}
}

template <typename T>
CircleArrayClass<T>::CircleArrayClass(CircleArrayClass<T> &&_right)
{
	listBegin_->next = _right.listBegin_->next;
	listBegin_->prev = _right.listBegin_->prev;
	listBegin_->value = _right.listBegin_->value;

	listSize_ = _right.listSize_;

	delete(_right.listBegin_);
}

template <typename T>
CircleArrayClass<T>& CircleArrayClass<T>::operator=(CircleArrayClass<T> &&_right)
{
	int size = _right.listSize_;
	CircleArrayClass<T> newFriend(_right.listBegin_);
	newFriend.listSize_ = size;
	return newFriend;
}

template <typename T>
void CircleArrayClass<T>::rotateForward()
{
	listBegin_ = listBegin_->next;
}

template <typename T>
void CircleArrayClass<T>::rotateBack()
{
	listBegin_ = listBegin_->prev;
}

template <typename T>
void CircleArrayClass<T>::printList()
{
	Node<T> *current = listBegin_;
	for (int i = 0; i < listSize_; ++i)
	{
		std::cout << current->value << ", ";
		current = current->next;
	}
	std::cout << "\n";
}

// Why do this? To avoid linking errors
// http://www.cs.technion.ac.il/users/yechiel/c++-faq/separate-template-class-defn-from-decl.html
template class CircleArrayClass<int>;