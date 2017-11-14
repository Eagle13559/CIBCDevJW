// CircleArray.cpp : Defines the entry point for the console application.
//

#include "CircleArrayClass.h"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> list{1,2,3,4,5};
	CircleArrayClass c(list);
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
    return 0;
}

