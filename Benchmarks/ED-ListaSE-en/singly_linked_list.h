#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <cstddef>
#include <memory>

#include <iostream>

#include "contract.h"

template<class T>
class Node;

template<class T>
class Node : protected contract::Invariant
{
public:
    typedef std::shared_ptr<Node<T>> NodePtr;
    T value;
    NodePtr next;
    Node(T p_value) {
        #ifdef INVARIANT_MACRO
            add_invariant(INVARIANT(
                next != this));
        #elif defined(INVARIANT_LAMBDA)
            add_invariant([&](){
                return next != this;
            });
        #endif

        value = p_value;
        next = NULL;

        check_invariant();
    }
    ~Node() {}
};

template<class T> class SLList;

template<class T>
class ListIterator : protected contract::Invariant {
public:
    typedef std::shared_ptr<Node<T>> NodePtr;
    ListIterator<T>() : pointer(NULL) {}
    ListIterator<T>(NodePtr ptr_to_node) : pointer(ptr_to_node) {}
    ListIterator<T>& operator++() {
        pointer = pointer->next;
        return *this;
    }
    bool operator!=(const ListIterator<T>& iter) {
        return pointer != iter.pointer;
    }
    T operator*() {
        return pointer->value;
    }
private:
    NodePtr pointer;
    friend class SLList<T>;
};

template<class T>
class SLList {
public:
    SLList();
    /**
     * @brief insert Insert at the end of the list.
     * @param p_value Value to be inserted.
     */
    void insert(T p_value);

    /**
     * @brief insert Insert a value to specific position.
     * @param p_value Value to be inserted
     * @param p_iter Iterator indicating position inside the list. Can not be null.
     */
    void insert(T p_value, ListIterator<T> p_iter);

    bool find(T p_val);

    ListIterator<T> find2(T p_val);

    /**
     * @brief remove Remove a present value, otherwise raise exception.
     * @param p_val The value to be removed.
     */
    void remove(T p_val);

    ListIterator<T> begin();

    ListIterator<T> end();
private:
    typedef std::shared_ptr<Node<T>> NodePtr;

    NodePtr ptr_start_node;

    NodePtr ptr_end_node;   // for more efficient insert(T) call.
};

template<class T>
SLList<T>::SLList()
{
    ptr_start_node = NULL;

    ptr_end_node = NULL;
}

template<class T>
void SLList<T>::insert(T p_value)
{
    // Case 1: there is no node in the list
    if (ptr_start_node == NULL) {
        ptr_start_node = NodePtr(new Node<T>(p_value));
        ptr_end_node = ptr_start_node;
    }
    else {
        // back inserting efficient with ptr_end_node
        ptr_end_node->next = NodePtr(new Node<T>(p_value));
        ptr_end_node = ptr_end_node->next;
    }
}

template<class T>
void SLList<T>::insert(T p_value, ListIterator<T> p_iter) {
    // Case 1: the list is not empty and the iterator is null
    if (p_iter.pointer == NULL and ptr_start_node != NULL) {
        throw std::invalid_argument("Iterator can't be null in a non empty list.");
    }
    // Case 2: the list is empty and the iterator is null. Fall into insert with no iterator.
    if (p_iter.pointer == NULL and ptr_start_node == NULL) {
        insert(p_value);
    }
    // Case 3: the list is not empty and the iterator points to the begining
    else if (p_iter.pointer == ptr_start_node) {
        NodePtr ptr_aux = NodePtr(new Node<T>(p_value));
        ptr_aux->next = ptr_start_node;
        ptr_start_node = ptr_aux;
    }
    // Case 4: the list is not empty and the iterator points in the middle
    else { // p_iter != ptr_start_node
        // TODO: Remove while cicle
        NodePtr ptr_prev = NULL;
        NodePtr ptr_aux = ptr_start_node;
        while (ptr_aux != NULL && ptr_aux != p_iter.pointer) {
            ptr_prev = ptr_aux;
            ptr_aux = ptr_aux->next;
        }
        //NodePtr ptr_aux = p_iter.pointer; // NOTE: valid, but don't check if the iterator correspond to actual list.

        if (p_iter.pointer == ptr_aux) {
            NodePtr ptr_aux_2 = NodePtr(new Node<T>(p_value));
            assert(ptr_aux != NULL); // NOTE: the hypothesis
            ptr_aux_2->next = ptr_aux->next;
            ptr_aux->next = ptr_aux_2;
            // Case 5: The inserted node is the last one.
            if (p_iter.pointer == ptr_end_node) {
                ptr_end_node = ptr_aux_2->next; // Equivalent to: ptr_end_node = ptr_aux->next->next;
            }
        }
        else { // here the condition (ptr_aux == NULL) is always true.
            //if (ptr_aux == NULL)
            throw std::invalid_argument("Invalid iterator position. The iterator don't correspond to the list.");
        }
    }
}

template<class T>
bool SLList<T>::find(T p_val)
{
    NodePtr ptr_aux = ptr_start_node;
    while (ptr_aux != NULL) {
        if (ptr_aux->value == p_val)
            return true;
        ptr_aux = ptr_aux->next;
    }
    return false;
}

template<class T>
ListIterator<T> SLList<T>::find2(T p_val)
{
    NodePtr ptr_aux = ptr_start_node;
    while (ptr_aux != NULL) {
        if (ptr_aux->value == p_val)
            return ListIterator<T>(ptr_aux);
        ptr_aux = ptr_aux->next;
    }
    return ListIterator<T>();
}

template<class T>
void SLList<T>::remove(T p_val)
{
    if (ptr_start_node == NULL) {
        throw std::invalid_argument("The value is not present.");
    }
    NodePtr ptr_actual = ptr_start_node;
    NodePtr ptr_prev = NULL;

    while (ptr_actual->value != p_val) {
        ptr_prev = ptr_actual;
        ptr_actual = ptr_actual->next;
        if (ptr_actual == NULL)
            throw std::invalid_argument("The value is not present.");

    }

    // Case 1: remove first node
    if (ptr_prev == NULL)
        ptr_start_node = ptr_start_node->next; // smart_pointer will call destructor then.
    // Case 2: remove other node, not the first one
    else
        ptr_prev->next = ptr_actual->next; // smart_pointer will call destructor then.
}

template<class T>
ListIterator<T> SLList<T>::begin()
{
    return ListIterator<T>(ptr_start_node);
}

template<class T>
ListIterator<T> SLList<T>::end()
{
    return ListIterator<T>(NULL);
}

#endif // SINGLY_LINKED_LIST_H
