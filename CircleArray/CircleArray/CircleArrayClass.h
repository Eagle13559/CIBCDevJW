#ifndef CIRCLEARRAYCLASS_H
#define CIRCLEARRAYCLASS_H

#include <vector>

template <typename T>
struct Node {
	Node<T> *next;
	Node<T> *prev;
	T value;
};

template <typename T>
class CircleArrayClass 
{
public:
	// Constructor (will allocate memory)
	CircleArrayClass(std::vector<T> &_list);

	// Destructor
	~CircleArrayClass();

	// Move and copy constructors
	CircleArrayClass(const CircleArrayClass<T> &_right) = delete; // No move assignment is allowed
	CircleArrayClass(CircleArrayClass<T> &&_right);

	// Assignment operators
	CircleArrayClass<T>& operator=(const CircleArrayClass<T> &_right) = delete; // No copy assignment is allowed
	CircleArrayClass<T>& operator=(CircleArrayClass<T> &&_right);

	// Increments each index by 1, moving the last item to the first (in place)
	void rotateForward();

	// Decrements each index by 1, moving the first item to the back (in place)
	void rotateBack();

	// Prints the list, starting at listBegin_
	void printList();

private:
	CircleArrayClass(Node<T> *_newFirstNode);

	Node<T> *listBegin_;
	int listSize_;

};

#endif //CIRCLEARRAYCLASS_H