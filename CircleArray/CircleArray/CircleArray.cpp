// CircleArray.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include "CircleArrayClass.h"

int main()
{
	std::vector<int> list{1,2,3,4,5};
	CircleArrayClass<int> c(list);
	c.printList();

	std::cout << "Rotating backward!\n";
	c.rotateBack();
	c.printList();
	std::cout << "Rotating forward 2x!\n";
	c.rotateForward();
	c.rotateForward();
	std::cout << "Rotating forward again!\n";
	c.rotateForward();
	c.printList();

	// Demonstrate the use of range based for loops
	std::cout << "Using range based for loop to print!\n";
	for (auto myNode : c)
	{
		std::cout << myNode << '\t';
	}
	std::cout << '\n';

    return 0;
}

