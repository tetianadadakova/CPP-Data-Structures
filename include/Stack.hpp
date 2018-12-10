#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

class Stack {

private:
    struct Node {
        int val;
        // To get min and max value of stack in O(1):
        int maxVal = std::numeric_limits<int>::min();
        int minVal = std::numeric_limits<int>::max();
    };
    
    std::vector<Node> currStack;
        
public:
    
    int size() const { return currStack.size(); }
    bool empty() const { return currStack.empty(); }
    void pop() { currStack.pop_back(); }
    
    void push(int val);
    int top() const; // O(1)
    int min() const; // O(1)
    int max() const; // O(1)
    
};

#endif /* STACK_H */
