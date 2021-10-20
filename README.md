# Build-The-Bag

Implement a high level shopping simulator by creating an ArrayBag. For this project you will use separate compilation with g++ to link 
multiple classes into one executable, and, in order to successfully complete this project, you must understand the bag abstract data type 
and the concept and implementation of overloading operators.


## Implementation
Work incrementally! Work through the tasks sequentially (implement and test). Only move on to a task when you are positive that the previous 
one has been completed correctly. Remember that the names of function prototypes and member variables must exactly match those declared in the 
respective header file when implementing a class.

___
Task 1: The Bag
___

*Your parents were not happy that you forgot to bring the bread last time; so they have decided to come with you to buy groceries this time. They 
leave you alone to do some shopping on your own. There was no cart available so they gave you a bag instead.*

Create an ArrayBag template class from scratch. This will require you to create two files: **ArrayBag.hpp** for the interface and **ArrayBag.cpp** 
for the implementation. The purpose of the ArrayBag class is to serve as the base class of the ShoppingCart class that has been provided to you in 
the given code; essentially, ArrayBag is meant to replace the DynamicArray of the previous project. Thus, you can test the final output of this 
project in the same way that you tested that of your previous project. The ArrayBag class must contain the following protected members:

```
static const int DEFAULT_CAPACITY = 200;  // max size of items_ 
ItemType items_[DEFAULT_CAPACITY];        // items in the array bag
int item_count_;                   // Current count of items in bag

/**
   @param target to be found in items_
   @return either the index target in the array items_ or -1,
   if the array does not containthe target.
**/
int getIndexOf(const ItemType &target) const;
```

Your ArrayBag class must contain the following public members:

```
/** 
   Default Constructor
   item_count_  <- 0
**/
ArrayBag();

/**
   @return item_count_ : the current size of the bag
**/
int getCurrentSize() const;

/**
   @return true if item_count_ == 0, false otherwise
**/
bool isEmpty() const;

/**
   @return true if new_entry was successfully added to items_, false otherwise
**/
bool add(const ItemType &new_entry);

/**
   @return true if an_entry was successfully removed from items_, false otherwise
**/
bool remove(const ItemType &an_entry);

/**
   @post item_count_ == 0
**/
void clear();

/**
   @return true if an_entry is found in items_, false otherwise
   -> THIS METHOD MUST CALL getIndexOf() <-
**/
bool contains(const ItemType &an_entry) const;

/**
   @return the number of times an_entry appears in items_
**/
int getFrequencyOf(const ItemType &an_entry) const;
```

*Hint*: This is a template class. Do not forget to place ```template <typename ItemType>``` before each function when you are implementing them. 
Also do not forget to ```#include the .cpp``` file at the end of your class definition.

___
Task 2: To Compare Or Not To Compare… And Other Operations
___




