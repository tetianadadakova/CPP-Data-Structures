#include "SinglyLinkedList.hpp"

std::size_t SinglyLinkedList::size() const {
    // O(1)
    return listSize;
}

void SinglyLinkedList::push_back(int val) {
    // O(1)
    if (head_) {
        tail_->next = std::make_unique<Node>(val);
        tail_ = tail_->next.get();
    } else {
        head_ = std::make_unique<Node>(val);
        tail_ = head_.get();
    }
    ++listSize;
}

void SinglyLinkedList::push_front(int val) {
    // O(1)
    std::unique_ptr<Node> tempNode = std::make_unique<Node>(val);
    tempNode->next = std::move(head_);
    head_ = std::move(tempNode);
    ++listSize;
}

void SinglyLinkedList::pop_front() {
    // O(1)
    if (head_) {
        head_ = std::move(head_->next);
        --listSize;
    }
}

int SinglyLinkedList::front() const {
    if (head_) {
        return head_->value;
    } else {
        return -1;
    }
}

int SinglyLinkedList::back() const {
    if (head_) {
        return tail_->value;
    } else {
        return -1;
    }
}

SinglyLinkedList::Node* SinglyLinkedList::head() const {
    return head_.get();
}

SinglyLinkedList::Node* SinglyLinkedList::tail() const {
    return tail_;
}

SinglyLinkedList::Node* SinglyLinkedList::find(int val, Node* begin, Node* end) const {
    // O(n)
    Node* currNode = begin;
    while (currNode != end->next.get()) {
        if (currNode->value == val) {
            return currNode;
        }
        currNode = currNode->next.get();
    }
    return nullptr;
}

void SinglyLinkedList::remove(Node* nodeToRemove) {
    if (nodeToRemove == head_.get()) {
        pop_front();
        return;
    }
    
    Node* currNode = head_.get();
    while (currNode->next.get() != nodeToRemove) {
        currNode = currNode->next.get();
    }
    if (currNode) {
        if (currNode->next.get() == tail_) {
            tail_ = currNode;
        }
        currNode->next = std::move(nodeToRemove->next);
        --listSize;
    }
}

SinglyLinkedList::~SinglyLinkedList () {
    
    std::unique_ptr<Node> currNode = std::move(head_->next);
    while (currNode) {
        currNode = std::move(currNode->next);
    }
}
