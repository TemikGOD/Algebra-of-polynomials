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
    Node* another;
    T value;
public:
    Node(T _value)
    {
        value = _value; another = nullptr;
    }
    
    Node* getAnother()
    {
        return another;
    }
    
    void setValue(T _value)
    {
        value = _value;
    }
    
    T getValue()
    {
        return value;
    }
    
    friend class List<T>;
};

template <class T>
class List
{
    Node<T>* head;
    Node<T>* tail;
    size_t size;
public:
    List() : head(nullptr), tail(nullptr), size(0) { }
    
    List(const List& other) : head(nullptr), tail(nullptr), size(0) { copy(other); }
    
    bool isEmpty() const
    {
        return head == nullptr;
    }
    
    void control()
    {
        while (!isEmpty()) pop_front();
    }

    List& operator=(const List& other)
    {
        if (this != &other) { control(); copy(other); }
        
        return *this;
    }
    
    int find(const T& value) const
    {
        int index = 0;
        
        for (Node<T>* current = head; current != nullptr; current = current->another)
        {
            if (current->value == value) { return index; } index++;
        }
        
        return -1;  // not found
    }
    
    void reverse()
    {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        
        while (current != nullptr)
        {
            Node<T>* next = current->another;
            current->another = prev;
            prev = current;
            current = next;
        }
        
        swap(head, tail);
    }
    
    void copy(const List& item)
    {
        control();
        Node<T>* stuff = item.head;
        
        for (int i = 0; i < item.size && stuff->another != nullptr; i++)
        {
            push_back(stuff->value);
            stuff = stuff->another;
        }
        
        if (item.size != 0 && stuff == item.tail) { push_back(stuff->value); }
        size = item.size;
    }
    
    void push_back(T _value)
    {
        Node<T>* stuff = new Node<T>(_value);
        
        if (isEmpty()) { head = stuff; }
        else { tail->another = stuff; }
        tail = stuff;
        size++;
    }
    
    void push_front(T _value)
    {
        Node<T>* stuff = new Node<T>(_value);
        if (isEmpty()) { tail = stuff; }
        else { stuff->another = head; }
        head = stuff;
        size++;
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
        else { tail = nullptr; head = nullptr; } size--;
        
        return stuff;
    }
    
    T pop_front()
    {
        Node<T>* back = head; T stuff = back->value;
        
        if (!(head == nullptr)) { Node<T>* remove = head; head = head->another; delete remove; return stuff; }
        if (head == nullptr) { tail = nullptr; }
        size--;
        
        return stuff;
    }
    
    T remove(int _item)
    {
        if (isEmpty()) throw runtime_error("List is empty");
        
        size_t length = size;
        if (_item < 0 || _item >= length) throw runtime_error("Can't remove item");
        
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        
        for (int i = 0; i < _item; i++) { prev = current; current = current->another; }
        
        T value = current->value;
        if (current == head) { head = current->another; }
        else if (current == tail) { tail = prev; tail->another = nullptr; }
        else { prev->another = current->another; }
        delete current;
        size--;
        return value;
    }
        
    size_t getSize() const
    {
        return size;
    }
    
    Node<T>* getHead() const
    {
        return head;
    }
    
    T& back() const
    {
        if(isEmpty()) throw runtime_error("List is empty"); return head->value;
    }
    
    Node<T>* begin() const
    {
        return head;
    }
    
    Node<T>* end() const
    {
        return nullptr;
    }
    
    /*
    ~List()
     {
        while (!isEmpty())
     {
            pop_front();
        }
    }
    */

};

#endif /* list_hpp */
