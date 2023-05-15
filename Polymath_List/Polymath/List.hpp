#ifndef list_hpp
#define list_hpp

#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
    struct Node
    {
        T value;
        Node* nextNode;

        Node(const T& _value) : value(_value), nextNode(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;
public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    void push_front(const T& value)
    {
        Node* newNode = new Node(value);
        newNode->nextNode = head;
        head = newNode;
        if (tail == nullptr) { tail = head; }
        ++size;
    }

    void push_back(const T& value)
    {
        Node* newNode = new Node(value);
        if (tail == nullptr) { head = newNode; }
        else { tail->nextNode = newNode; }
        tail = newNode;
        ++size;
    }

    void pop_front()
    {
        if (head == nullptr) { throw std::out_of_range("List is empty"); }
        Node* temp = head;
        head = head->nextNode;
        delete temp;
        if (head == nullptr) { tail = nullptr; }
        --size;
    }

    void pop_back()
    {
        if (tail == nullptr) { throw std::out_of_range("List is empty"); }
        if (head == tail) { delete tail; head = tail = nullptr; }
        else
        {
            Node* temp = head;
            while (temp->nextNode != tail) { temp = temp->nextNode; }
            delete tail;
            tail = temp;
            tail->nextNode = nullptr;
        }
        --size;
    }

    T& front() const
    {
        if (head == nullptr) { throw std::out_of_range("List is empty"); }
        return head->value;
    }

    T& back() const
    {
        if (tail == nullptr) { throw std::out_of_range("List is empty"); }
        return tail->value;
    }

    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }
    
    ~List()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->nextNode;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    class Iterator
    {
    private:
        Node* node;

    public:
        Iterator(Node* _node = nullptr) : node(_node) {}
        Iterator(const Iterator& other) : node(other.node) {}

        Iterator& operator=(const Iterator& other)
        {
            if (this != &other) { node = other.node; }
            return *this;
        }

        bool operator==(const Iterator& other) const { return node == other.node; }
        bool operator!=(const Iterator& other) const { return node != other.node; }

        T& operator*() const { return node->value; }
        T* operator->() const { return &(node->value); }

        Iterator& operator++()
        {
            if (node != nullptr) { node = node->nextNode; }
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp(*this);
            ++(*this);
            return temp;
        }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }

    T& operator[](int index)
    {
        if (index < 0 || index >= size) { throw std::out_of_range("Index out of range"); }
        Node* temp = head;
        for (int i = 0; i < index; ++i) { temp = temp->nextNode; }
        return temp->value;
    }
};


#endif /* list_hpp */
