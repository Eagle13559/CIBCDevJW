#ifndef CIRCLEARRAYCLASS_H
#define CIRCLEARRAYCLASS_H

#include <vector>
#include <exception>

template <typename T>
struct Node {
	Node<T> *next;
	Node<T> *prev;
	T value;
};

template <typename T>
class CircleArrayClass;

// Range based for loop functions
template <typename T>
class CircleArrayIterator
{
public:
	CircleArrayIterator(CircleArrayClass<T> &c, unsigned idx = 0) :
		c_(c),
		idx_(idx)
	{}

	bool operator!=(CircleArrayIterator<T>& other)
	{
		return (idx_ != other.idx_);
	}

	const CircleArrayIterator<T>& operator++()
	{
		idx_++;
		return *this;
	}

	T& operator*() 
	{
		return c_.getItemAtIndex(idx_);
	}

private:
	CircleArrayClass<T> &c_;
	unsigned idx_;

};

template <typename T>
class CircleArrayClass
{
public:
	// Constructor (will allocate memory)
	CircleArrayClass(std::vector<T> &_list)
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

	// Destructor
	~CircleArrayClass()
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

	// Move and copy constructors
	CircleArrayClass(const CircleArrayClass<T> &_right) = delete; // No copy construction is allowed
	CircleArrayClass(CircleArrayClass<T> &&_right)
	{
		listBegin_->next = _right.listBegin_->next;
		listBegin_->prev = _right.listBegin_->prev;
		listBegin_->value = _right.listBegin_->value;

		listSize_ = _right.listSize_;

		delete(_right.listBegin_);
	}

	// Assignment operators
	CircleArrayClass<T>& operator=(const CircleArrayClass<T> &_right) = delete; // No copy assignment is allowed
	CircleArrayClass<T>& operator=(CircleArrayClass<T> &&_right)
	{
		int size = _right.listSize_;
		CircleArrayClass<T> newFriend(_right.listBegin_);
		newFriend.listSize_ = size;
		return newFriend;
	}

	// Increments each index by 1, moving the last item to the first (in place)
	void rotateForward()
	{
		listBegin_ = listBegin_->next;
	}

	// Decrements each index by 1, moving the first item to the back (in place)
	void rotateBack()
	{
		listBegin_ = listBegin_->prev;
	}

	// Prints the list, starting at listBegin_
	void printList()
	{
		Node<T> *current = listBegin_;
		for (int i = 0; i < listSize_; ++i)
		{
			std::cout << current->value << ", ";
			current = current->next;
		}
		std::cout << "\n";
	}

	CircleArrayIterator<T> begin()
	{
		return CircleArrayIterator<T>(*this, 0);
	}

	CircleArrayIterator<T> end()
	{
		return CircleArrayIterator<T>(*this, listSize_);
	}

	T& getItemAtIndex(unsigned idx)
	{
		if (idx >= listSize_)
			throw("CircleArrayClass::getItemAtIndex Out of range exception\n");
		Node<T> *current = listBegin_;
		for (int i = 1; i <= idx; ++i)
		{
			current = current->next;
		}
		return current->value;
	}

private:
	CircleArrayClass(Node<T> *_newFirstNode)
	{
		listBegin_->next = _newFirstNode->next;
		listBegin_->prev = _newFirstNode->prev;
		listBegin_->value = _newFirstNode->value;

		delete(_newFirstNode);
	}

	Node<T> *listBegin_;
	int listSize_;

};

#endif //CIRCLEARRAYCLASS_H