# DSA: 
Data Structure and Algorithms are the building blocks for a software application. We need to figure out the efficient data structure tools depending on the program.

## Language used:
1. C++.
2. Python.

# Topics Covered:
1. Tree.
2. Linked List.
3. Array.
4. Graphs.
5. Hashing.

# Discussions:
### Hash Table:
We use a key, on which we apply the HASH function. The Hash Function returns us the address of 
the bucket(collection of all the data accumulated). Using that address, we can get the element.
This way we can get O(1) complexity.

### Big O Notation:
Used to measure the program's running time or space requirements as the input size grows. Big O Notation often shows the WORST CASE SCENARIO.
Types of complexities:
- Time Complexity.
- Space Complexity.
  
Rules to represent complexity:
1. Keeping the fastest growing term.
2. Drop the constant from the growing term.

### Array and List:
In Python, List is implemented as a dynamic array. Python doesn't have any static array. But in other, C++, Java, C, etc we have both static and dynamic arrays. 
- In the case of a static array, space is initialized (fixed) at the start. 
- In the case of a dynamic array, when we create an array object at first it initializes some capacity in the memory. When we say inserting a new element but the initial capacity is booked, then it again initializes a new memory just like the previous one. Then the previous elements are copied and merged with the new elements. And the cycle repeats.......

### Linked List:
There are some drawbacks in arrays and lists and those drawbacks are covered by the linked list.
In arrays and lists, the elements are stored in contiguous memory locations. However, in the linked list, the elements are stored in random places in the memory. And those locations are linked by pointers.

The first node stores a value and the location of the next node. And the process repeats.
Types of linked lists:
1. Singly Linked List.
2. Double Linked List. (Can traverse forward and backward both)
3. Circular Linked List.
4. Doubly Circular Linked List.
