# CIBCDevJW

Developed using visual studios. 

Required test #1:
What to expect:
main() is located in CircleArray.cpp. There you can see a standard vector of ints is declared, in ascending order. 
It's then passed to CircleArrayClass, where a doubly linked list allocated on the heap is constructed. This made
rotation very simple, as I only had to move the starting node. An infinite chain is made when the array class is constructed.
For fun I declared the basic six, (move/copy constructors, move/copy assign operators, constructor, and destructor,)
however I deleted the copy constructors, only allowing for movement. There are three other public functions,
rotateForward, rotateBack, and printList. These are utulized in main. You can see there I perform various transformations and
print the results to the console. Testing is as simple as compiling and running the application.
