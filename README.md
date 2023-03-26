# CPP-Module-09

## STL:

STL stands for the Standard Template Library, which is a collection of C++ templates that provide common data structures and algorithms. The STL was first standardized in the C++98 standard, and it has been an integral part of the C++ Standard Library ever since.

### The STL includes several components, including:

-   Containers: These are data structures such as vectors, lists, maps, and sets that store collections of objects.

-   Iterators: These are objects that provide a way to iterate over the elements in a container.

-   Algorithms: These are generic functions that operate on containers and perform operations such as sorting, searching, and transforming the elements.

The STL provides a way to write efficient and generic code by providing a set of common data structures and algorithms. The templates used in the STL allow for type-safe and parameterized programming, which can help to reduce the amount of boilerplate code needed to implement data structures and algorithms.

## Containers:

### map:

​Maps are a part of the C++ STL. Maps are associative containers that store elements in a combination of key values and mapped values that follow a specific order. No two mapped values can have the same key values.

In C++, maps store the key values in ascending order by default.
Maps can store the key values in descending order (i.e., from highest to lowest) using the std::greater<std::string> comparison function object.

-   `std::greater<std::string>` 

is a function object in C++ that is used for comparing two std::string objects. It is defined in the <functional> header file and is used in combination with various STL algorithms, such as std::sort and std::nth_element, to perform sorting and searching operations.

The std::greater function object returns true if the first argument is greater than the second argument, and false otherwise. When used with std::string objects, the comparison is performed lexicographically, meaning that it compares the strings character by character according to their ASCII values.

![screenshot](/assets/map.png)

The basic syntax to initialize a C++ STL map is as follows:

![screenshot](/assets/mapinit.png)

### stack:

In C++, a stack is a container adapter that provides a LIFO (Last-In-First-Out) data structure. It can be thought of as a stack of plates where the last plate added to the stack is the first one to be removed.

Elements are pushed onto the stack using the push() function, and the top element is accessed using the top() function. Elements are popped from the stack using the pop() function.

### Reverse Polish Notation:

Reverse Polish notation (RPN) is a method for conveying mathematical expressions without the use of separators such as brackets and parentheses. In this notation, the operators follow their operands, hence removing the need for brackets to define evaluation priority. The operation is read from left to right but execution is done every time an operator is reached, and always using the last two numbers as the operands. This notation is suited for computers and calculators since there are fewer characters to track and fewer operations to execute.

### vector:

Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes the array may need to be extended. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

### deque:

Double-ended queues are sequence containers with the feature of expansion and contraction on both ends. They are similar to vectors, but are more efficient in case of insertion and deletion of elements. Unlike vectors, contiguous storage allocation may not be guaranteed. 
Double Ended Queues are basically an implementation of the data structure double-ended queue. A queue data structure allows insertion only at the end and deletion from the front. This is like a queue in real life, wherein people are removed from the front and added at the back. Double-ended queues are a special case of queues where insertion and deletion operations are possible at both the ends. The functions for deque are same as vector, with an addition of push and pop operations for both front and back.

### Insertion Sort Algorithm:

![screenshot](/assets/array.png)
![screenshot](/assets/step1IS.png)
![screenshot](/assets/step2IS.png)
![screenshot](/assets/step3IS.png)
![screenshot](/assets/step4IS.png)

### Merge Sort Algorithm:

![screenshot](/assets/step1MS.png)
![screenshot](/assets/step2MS.png)
![screenshot](/assets/step3MS.png)
![screenshot](/assets/step4MS.png)
![screenshot](/assets/step5MS.png)
![screenshot](/assets/step6MS.png)