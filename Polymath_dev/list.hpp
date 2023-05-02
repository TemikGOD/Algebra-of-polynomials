#ifndef list_hpp
#define list_hpp

#include <list>
#include <iostream>
#include "monom.hpp"

using namespace std;

template <class Type> class Node;
template <class Type> class List;

template <class T>
class Node
{
    Node* another; T value;
public:
    Node(T _value) { value = _value; another = nullptr; }
    friend class List<T>;
};

template <class T>
class List
{
    Node<T>* head; Node<T>* tail;
public:
    size_t size;
    
    List() : head(nullptr), tail(nullptr), size(0) { }
    
    bool isEmpty() { if (head == nullptr) return true; else return false;}
    
    void control() { while (head != nullptr) pop_front(); }
    
    Monom& getFront()
    {
        if(isEmpty())
            throw runtime_error("List is empty");
        return head->value;
    }
    
    void copy(const List& item)
    {
        control(); Node<T>* stuff = item.head;
        for (int i = 0; i < item.size && stuff->another != nullptr; i++)
        { push_back(stuff->value); stuff = stuff->another; }
        if (item.size != 0 && stuff == item.tail) { push_back(stuff->value); }
        size = item.size;
    }
    
    void push_back(T _value)
    {
        Node<T>* stuff = new Node<T>(_value);
        if (head == nullptr) { head = stuff; tail = stuff; }
        else { tail->another = stuff; tail = stuff; } size++;
    }
    
    void push_front(T _value)
    {
        Node<T>* stuff = new Node<T>(_value);
        if (head == nullptr) { head = stuff; tail = stuff; }
        else { stuff->another = head; head = stuff; } size++;
    }
    
    T pop_back()
    {
        Node<T>* back = tail; T stuff = back->value;
        if (head != tail)
        {
            Node<T>* remove = head;
            while (remove->another != tail) { remove = remove->another; }
            delete tail; tail = remove;
            return stuff;
        }
        else { tail = nullptr; head = nullptr; return stuff; } size--;
    }
    
    T pop_front()
    {
        Node<T>* back = head; T stuff = back->value;
        if (!(head == nullptr)) { Node<T>* remove = head; head = head->another;
            delete remove; return stuff; }
        if (head == nullptr) { tail = nullptr; // return stuff;
        } size--; return stuff;
    }
    
    T remove(int _item)
    {
        size_t length = 0; length = this->size;
        if (_item < 0 || _item > length - 1) throw("can't remove");
        if (_item == 0) { size--; return this->pop_back(); }
        else if (_item == size - 1) { size--; return this->pop_front(); }
        else
        {
            Node<T>* place = head; Node<T>* place2 = head;
            for (int i = 0; i < _item-1; i++) { place2 = place2->another; }
            for (int i = 0; i < _item; i++) { place = place->another; }
            place2->another = place->another;
            Node<T>* back = place; T stuff = back->value;
            delete place; size--; return stuff;
        }
    }
};

#endif /* list_hpp */
