#include "Stack.hpp"

void Stack::push(int val) {
    
    Node tempNode;
    tempNode.val = val;
    if (this->empty()) {
        tempNode.minVal = val;
        tempNode.maxVal = val;
    } else {
        tempNode.minVal = std::min(currStack.back().minVal, val);
        tempNode.maxVal = std::max(currStack.back().maxVal, val);
    }
    
    currStack.push_back(tempNode);
}

int Stack::top() const {
    if (currStack.empty()) {
        throw std::out_of_range ("Stack is empty");
    }
    return currStack.back().val;
}

int Stack::min() const {
    if (currStack.empty()) {
        throw std::out_of_range ("Stack is empty");
    }
    return currStack.back().minVal;
}

int Stack::max() const {
    if (currStack.empty()) {
        throw std::out_of_range ("Stack is empty");
    }
    return currStack.back().maxVal;
}


