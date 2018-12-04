#include "SinglyLinkedList.hpp"
#include <list>

void print(const SinglyLinkedList& currList) {
    auto tempNode = currList.head();
    
    while (tempNode) {
        std::cout << tempNode->value << " ";
        tempNode = tempNode->next.get();
    }
    std::cout << "\n";
}

int main() {
    
    // List init
    SinglyLinkedList myList;
    
    std::cout << "List size: " << myList.size() << "\n";

    // Add nodes to the back of the list
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    std::cout << "Print list after adding nodes to the back: \n";
    print(myList);
    std::cout << "List size: " << myList.size() << "\n";
    
    // To test destructor: add 1000000 nodes
    // With default destructor the nodes are deleted recursively
    // And this latge list will cause stack overflow
    /*
    for (int i = 0; i < 1000000; ++i) {
        myList.push_back(i);
    }
    std::cout << "List size: " << myList.size() << "\n";
    */

    // Add nodes to the front of the list
    myList.push_front(8);
    myList.push_front(9);
    myList.push_front(7);
    std::cout << "Print list after adding nodes to the front: \n";
    print(myList);
    std::cout << "List size: " << myList.size() << "\n";

    
    // Pop nodes from the front of the list
    myList.pop_front();
    std::cout << "Print list after popping nodes from the front: \n";
    print(myList);
    std::cout << "List size: " << myList.size() << "\n";

 
    // Front node value
    std::cout << "List front value: " << myList.front() << "\n";
    // Back node value
    std::cout << "List back value: " << myList.back() << "\n";
    // Head node pointer
    std::cout << "List head value: " << myList.head()->value << "\n";
    // Tail node pointer
    std::cout << "List tail value: " << myList.tail()->value << "\n";
 
    // Find value in the list - returns pointer
    int val = 3;
    auto foundNode = myList.find(val, myList.head(), myList.tail());
    if (foundNode) {
        std::cout << "Find " << val << ": " << foundNode->value << "\n";
    } else {
        std::cout << "Node not found\n";
    }
    
    
    // Remove value from the list
    myList.remove(myList.find(val, myList.head(), myList.tail()));
    std::cout << "Print list after the value " << val << " was removed \n";
    print(myList);
    std::cout << "List size: " << myList.size() << "\n";
    
    // Remove head
    myList.remove(myList.head());
    std::cout << "Print list after head node is removed: \n";
    print(myList);
    std::cout << "List size: " << myList.size() << "\n";

    // Remove tail
    myList.remove(myList.tail());
    std::cout << "Print list after tail node is removed: \n";
    print(myList);
    std::cout << "List size: " << myList.size() << "\n";

}
