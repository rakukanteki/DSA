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

### Hashing:
Say we have data or a list of data, if we apply a hash function on that data then the function returns an integer value called 'token' or 'index'.  
This index or token is later used in a HASH TABLE. After that when we want to search for a value from a humungous dataset, then we get that data with a complexity of O(1).

#### Working of Hash Function:
Say we have a value 'march 6', now we will find the ASCII value for each of the characters in the value. 'm'=109, 'a'=97, 'r'=114, 'c'=99,'h'=104, ' '=32, '6'=54. Then we add the values, we get 'SUM = 609'.
Now, to get an index from 609 from 0-9. We use the 'mod' operation. 609 mod 10 = 9. Hence, the index of 'March 6' == 9.

#### Collision in Hash Function:
Collision occurs when we get the same index for different values. For handling the collision,
1. we can do separate chaining. This means, instead of storing the value as usual.
we store a linked list or Python list at every location. We keep appending the values. Hence, multiple keys can share the same hash value. Big O Notation might go O(n).

2. The second approach we can do is "Linear Probing". When we find an index that has already a value stored in it, we go to the next available location. Say,
'march 6' has index 9 and when 'march 17' has also index 9 comes in, 'march 17' sees that there is already 'march 6' in that place. So, 'march 17' goes to the next index means the 10th index.

If 'march 17' doesn't find any 10th location then it goes to the beginning means 0th index and keeps on looking for the next empty index.
