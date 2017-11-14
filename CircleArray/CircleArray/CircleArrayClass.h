#ifndef CIRCLEARRAYCLASS_H
#define CIRCLEARRAYCLASS_H

#include <vector>

struct Node {
	Node *next;
	Node *prev;
	int value;
};

class CircleArrayClass 
{
public:
	// Constructor (will allocate memory)
	CircleArrayClass(std::vector<int> &_list);

	// Destructor
	~CircleArrayClass();

	// Move and copy constructors
	CircleArrayClass(const CircleArrayClass &_right) = delete; // No move assignment is allowed
	CircleArrayClass(CircleArrayClass &&_right);

	// Assignment operators
	CircleArrayClass& operator=(const CircleArrayClass &_right) = delete; // No copy assignment is allowed
	CircleArrayClass& operator=(CircleArrayClass &&_right);

	// Increments each index by 1, moving the last item to the first (in place)
	void rotateForward();

	// Decrements each index by 1, moving the first item to the back (in place)
	void rotateBack();

	// Prints the list, starting at listBegin_
	void printList();

private:
	CircleArrayClass(Node *_newFirstNode);

	Node *listBegin_;
	int listSize_;

};

#endif //CIRCLEARRAYCLASS_H