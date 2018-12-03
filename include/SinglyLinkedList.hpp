//#pragma once
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <memory>
#include <cstddef>

class SinglyLinkedList {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> next = nullptr;
        Node(int val) : value(val) {}
    };
    
    std::unique_ptr<Node> head_ = nullptr;
    Node* tail_ = nullptr;
    
    std::size_t listSize = 0;

    
public:
    SinglyLinkedList() = default;
    
    std::size_t size() const;
    void push_back(int val);
    void push_front(int val);
    void pop_front();
    int front() const;
    int back() const;
    Node* head() const;
    Node* tail() const;
    Node* find(int val, Node* begin, Node* end) const;
    void remove(Node* nodeToRemove);
    
    ~SinglyLinkedList();
    
};

#endif /* SINGLYLINKEDLIST_H */
