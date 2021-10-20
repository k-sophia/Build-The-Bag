/****************************************************************************************************************************
Title        : ArrayBag.hpp
Auhors       : Kelly Camacho
Description  : implementation file of a template class
Dependencies : ArrayBag.hpp
****************************************************************************************************************************/

#include "ArrayBag.hpp"

/* Constructor */
template<typename ItyemType>
ArrayBag<ItyemType>::ArrayBag(): item_count_(0)
{

}   //end default constructor

template<typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
    return item_count_;
}   // end getCurrentSize

template<typename ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
    return item_count_ == 0;
}   // end isEmpty

template<typename ItemType>
bool ArrayBag<ItemType>::add(const ItemType& new_entry) {
    bool has_room_to_add = (item_count_ < DEFAULT_CAPACITY);

    if (has_room_to_add) {
        items_[item_count_] = new_entry;
        item_count_++;
    }   //endif 

    return has_room_to_add;
}   // end add

template<typename ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& an_entry) {
    int located_index = getIndexOf(an_entry);

    bool can_remove_item = !isEmpty() && (located_index > -1);
    if (can_remove_item) {
        item_count_--;
        items_[located_index] = items_[item_count_]; //copy
    }   //end if

    return can_remove_item;
}   //end remove

template<typename ItemType>
void ArrayBag<ItemType>::clear() {
    item_count_ = 0;
}   // end clear

template<typename ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& an_entry) const {
    return getIndexOf(an_entry) > -1;
}   // end contains

template<typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& an_entry) const {
    int frequency = 0;
    int current_index = 0;

    while(current_index < item_count_) {
        if(items_[current_index] == an_entry) {
            frequency++;
        }   //end if

        current_index++; //increment to next entry
    }

    return frequency;
}   //end getFrequencyOf

template<typename ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const {
    bool found = false;
    int result = -1;
    int search_index = 0;

    //if bag is empty item_count_ is zero loop is skipped
    while(!found && (search_index < item_count_)) {
        if(items_[search_index] == target) {
            found = true;
            result = search_index;
        }
        else {
            search_index++;
        }   //end if
    }   //end while

    return result;
}   //end getIndexOf

template<typename ItemType>
void ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType> &a_bag) {
    int remaining_space_ = DEFAULT_CAPACITY - getCurrentSize();

    for(int i = 0; i < remaining_space_; i++) {
        if (i < a_bag.getCurrentSize()) {
            if(!contains(a_bag.items_[i])) { //if not have item then add
                add(a_bag.items_[i]);
            }
        } 
    }

}   //end operator+=

template<typename ItemType>
void ArrayBag<ItemType>::operator-=(const ArrayBag<ItemType> &a_bag) {

    for(int i = 0; i < getCurrentSize(); i++) {
        if(a_bag.contains(items_[i])) {
            remove(items_[i]);
        }
    }
}   //end operator-=

template<typename ItemType>
void ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType> &a_bag) {

    for(int i = 0; i < a_bag.getCurrentSize(); i++) {
        if(!a_bag.contains(items_[i])) {
            remove(items_[i]);
        }
    }
    
}   //end operator/=

template<typename ItemType>
bool ArrayBag<ItemType>::operator==(const ArrayBag<ItemType> &a_bag) {
    bool equal_bags_ = true;

    if(getCurrentSize() != a_bag.getCurrentSize()) {
        return false;
    }

    for(int i = 0; i < getCurrentSize(); i++) {
        if(!a_bag.contains(items_[i])) {
            equal_bags_ = false;
        }
    }

    return equal_bags_;
}   //end operator==

template<typename ItemType>
bool ArrayBag<ItemType>::operator!=(const ArrayBag<ItemType> &a_bag) {
    bool equal_bags_ = true;

    if(operator==(a_bag)) {
        equal_bags_ = false;
    }

    return equal_bags_;
}   //end operator==