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

Required test #2:

What to expect:

This is even simpler than the first test. Run the script and give it two valid paths to two different (or even the same!) images.
It will use scipy to calculate the manhattan norm and spit out a value. The larger the value, the less they are correlated.
If you give it the same image twice, the error image will be all zeros, and give a perfect registration.

Bonus Task #1:

What to expect:

As of 11/13, I have successfully written the DFS algorithm for sorting the tree. The downside is I need to figure out how to hand nodes not connected to any other node. Will Resolve soon.

11/14: Pivoted technique. Realized DFS alone is not enough to detect cycles. Implemented a cycle detection algorithm, followed by a topological sort if the cycle detection comes back as negative.

Bonus Task #2:

Haven't done. Was pushed out of the sprint and put on the backlog.

Bonus Task #3:

Tried several times to download. The QT servers were having a seizure. :(

Update: Tried again, successfully installed QT, Cmake, and built the project. :)
