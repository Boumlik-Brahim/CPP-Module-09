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

### Reverse Polish Notation:

Reverse Polish notation (RPN) is a method for conveying mathematical expressions without the use of separators such as brackets and parentheses. In this notation, the operators follow their operands, hence removing the need for brackets to define evaluation priority. The operation is read from left to right but execution is done every time an operator is reached, and always using the last two numbers as the operands. This notation is suited for computers and calculators since there are fewer characters to track and fewer operations to execute.

### stack:

In C++, a stack is a container adapter that provides a LIFO (Last-In-First-Out) data structure. It can be thought of as a stack of plates where the last plate added to the stack is the first one to be removed.

Elements are pushed onto the stack using the push() function, and the top element is accessed using the top() function. Elements are popped from the stack using the pop() function. 