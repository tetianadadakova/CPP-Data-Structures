#include "SinglyLinkedList.hpp"
#include "Stack.hpp"
#include "BinarySearchTree.hpp"
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
    
    /* === LINKED LIST === */
    std::cout << "=== LINKED LIST ===\n";
    
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

    std::cout << "\n";
    std::cout << "\n";
    
    
    /* === STACK === */
    std::cout << "=== STACK ===\n";
    
    // Stack init
    Stack myStack;
    
    std::cout << "Empty? " << myStack.empty() << "\n";
    std::cout << "Size: " << myStack.size() << "\n";
    
    try {
        std::cout << "Top: " << myStack.top() << "\n";
        std::cout << "Min: " << myStack.min() << "\n";
        std::cout << "Max: " << myStack.max() << "\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Out of range error. " << e.what() << "\n";
    }
    
    std::cout << "Push some integers: \n";
    myStack.push(5);
    myStack.push(3);
    myStack.push(7);
    
    std::cout << "Empty? " << myStack.empty() << "\n";
    std::cout << "Size: " << myStack.size() << "\n";
    
    try {
        std::cout << "Top: " << myStack.top() << "\n";
        std::cout << "Min: " << myStack.min() << "\n";
        std::cout << "Max: " << myStack.max() << "\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Out of range error. " << e.what() << "\n";
    }
    
    std::cout << "Pop some integers: \n";
    myStack.pop();
    
    std::cout << "Empty? " << myStack.empty() << "\n";
    std::cout << "Size: " << myStack.size() << "\n";
        
    try {
        std::cout << "Top: " << myStack.top() << "\n";
        std::cout << "Min: " << myStack.min() << "\n";
        std::cout << "Max: " << myStack.max() << "\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Out of range error. " << e.what() << "\n";
    }
    
    std::cout << "\n";
    std::cout << "\n";
    
    
    /* === BINARY SEARCH TREE === */
    std::cout << "=== BINARY SEARCH TREE ===\n";
    
    std::cout << "--------------------------\n";
    std::cout << "Build unbalanced vs balanced" << std::endl;
    BinarySearchTree myBST_unb;
    BinarySearchTree myBST_b;
    std::vector<int> values_sorted_back {9, 8, 7, 6, 5, 4, 3, 2, 1};
    myBST_unb.build_from_vector(values_sorted_back);
    myBST_b.build_from_vector_balanced(values_sorted_back);
    
    std::cout << "Is balanced myBST_unb: " << myBST_unb.balanced() << std::endl;
    std::cout << "Is balanced myBST_b: " << myBST_b.balanced() << std::endl;
    std::cout << "Max depth myBST_unb: " << myBST_unb.max_depth() << std::endl;
    std::cout << "Max depth myBST_b: " << myBST_b.max_depth() << std::endl;
    
    std::cout << "myBST_unb size: " << myBST_unb.size() << std::endl;
    std::cout << "myBST_unb empty? " << myBST_unb.empty() << std::endl;
    std::cout << "myBST_b size: " << myBST_b.size() << std::endl;
    std::cout << "myBST_b empty? " << myBST_b.empty() << std::endl;
    
    // Traversals:
    std::vector<int> vals_inorder_unb = myBST_unb.get_inorder_vals();
    std::vector<int> vals_preorder_unb = myBST_unb.get_preorder_vals();
    std::vector<int> vals_postorder_unb = myBST_unb.get_postorder_vals();
    std::vector<int> vals_level_order_unb = myBST_unb.get_level_order_vals();
    
    std::vector<int> vals_inorder_b = myBST_b.get_inorder_vals();
    std::vector<int> vals_preorder_b = myBST_b.get_preorder_vals();
    std::vector<int> vals_postorder_b = myBST_b.get_postorder_vals();
    std::vector<int> vals_level_order_b = myBST_b.get_level_order_vals();
    
    std::cout << "Inorder values myBST_unb: " << std::endl;
    for (auto& val : vals_inorder_unb)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Preorder values myBST_unb: " << std::endl;
    for (auto& val : vals_preorder_unb)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Postorder values myBST_unb: " << std::endl;
    for (auto& val : vals_postorder_unb)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Level order values myBST_unb: " << std::endl;
    for (auto& val : vals_level_order_unb)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Inorder values myBST_b: " << std::endl;
    for (auto& val : vals_inorder_b)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Preorder values myBST_b: " << std::endl;
    for (auto& val : vals_preorder_b)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Postorder values myBST_b: " << std::endl;
    for (auto& val : vals_postorder_b)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Level order values myBST_b: " << std::endl;
    for (auto& val : vals_level_order_b)
        std::cout << val << " ";
    std::cout << std::endl;
    
    
    // ---------------------------------------
    std::cout << "--------------------------\n";
    std::cout << "Remove nodes" << std::endl;
    
    BinarySearchTree myBST;
    std::vector<int> values {1, 2, 3, 4, 5, 6, 7, 8, 9};
    myBST.build_from_vector_balanced(values);
    
    std::cout << "Max value: " << myBST.max_val() << std::endl;
    std::cout << "Min value: " << myBST.min_val() << std::endl;
    std::cout << "Contains 5: " << myBST.contains(5) << std::endl;
    std::cout << "Contains 15: " << myBST.contains(15) << std::endl;
    
    std::cout << "Before removing nodes" << std::endl;
    std::cout << "myBST size: " << myBST.size() << std::endl;
    std::cout << "myBST empty? " << myBST.empty() << std::endl;
    std::vector<int> vals_inorder = myBST.get_inorder_vals();
    std::cout << "Inorder values: " << std::endl;
    for (auto& val : vals_inorder)
        std::cout << val << " ";
    std::cout << std::endl;
    
    myBST.remove_node(9);
    myBST.remove_node(5);
    myBST.remove_node(2);
    myBST.remove_node(1);
    myBST.remove_node(1);
    
    std::cout << "Removed 9, 5, 2, 1, 1" << std::endl;
    std::cout << "myBST size: " << myBST.size() << std::endl;
    std::cout << "myBST empty? " << myBST.empty() << std::endl;
    vals_inorder = myBST.get_inorder_vals();
    std::cout << "Inorder values: " << std::endl;
    for (auto& val : vals_inorder)
        std::cout << val << " ";
    std::cout << std::endl;

    myBST.remove_node(80);
    myBST.remove_node(2);
    myBST.remove_node(3);
    myBST.remove_node(4);
    myBST.remove_node(6);
    myBST.remove_node(7);
    myBST.remove_node(8);
    
    std::cout << "Removed 80, 2, 3, 4, 6, 7, 8" << std::endl;
    std::cout << "myBST size: " << myBST.size() << std::endl;
    std::cout << "myBST empty? " << myBST.empty() << std::endl;

    
    // ---------------------------------------
    std::cout << "--------------------------\n";
    std::cout << "Insert nodes" << std::endl;
    myBST.insert_node(10);
    myBST.insert_node(50);
    myBST.insert_node(20);
    myBST.insert_node(5);
    
    std::cout << "Inserted 10, 50, 20, 5" << std::endl;
    std::cout << "myBST size: " << myBST.size() << std::endl;
    std::cout << "myBST empty? " << myBST.empty() << std::endl;
    vals_inorder = myBST.get_inorder_vals();
    std::cout << "Inorder values: " << std::endl;
    for (auto& val : vals_inorder)
        std::cout << val << " ";
    std::cout << std::endl;
    
    
    
    // ---------------------------------------
    std::cout << "--------------------------\n";
    std::cout << "Copy constructor" << std::endl;
    BinarySearchTree myBST_orig;
    
    myBST_orig.build_from_vector_balanced(values);
    BinarySearchTree myBST_copy = myBST_orig;
    
    myBST_orig.insert_node(15);
    myBST_copy.insert_node(12);
    
    std::vector<int> vals_inorder_orig = myBST_orig.get_inorder_vals();
    std::vector<int> vals_inorder_copy = myBST_copy.get_inorder_vals();
    
    std::cout << "Inorder values myBST_orig: " << std::endl;
    for (auto& val : vals_inorder_orig)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Inorder values myBST_copy: " << std::endl;
    for (auto& val : vals_inorder_copy)
        std::cout << val << " ";
    std::cout << std::endl;
    
    
    // ---------------------------------------
    std::cout << "--------------------------\n";
    std::cout << "Copy assignment operator" << std::endl;
    // Not really sure how to test this
    
    BinarySearchTree myBST_orig_assign;
    std::vector<int> values1 {1, 2, 3, 4, 5};
    myBST_orig_assign.build_from_vector_balanced(values1);
    BinarySearchTree myBST_copy_assign;
    std::vector<int> values2 {6, 7, 8, 9};
    myBST_copy_assign.build_from_vector_balanced(values2);

    std::vector<int> vals_inorder_orig_assign = myBST_orig_assign.get_inorder_vals();
    std::vector<int> vals_inorder_copy_assign = myBST_copy_assign.get_inorder_vals();
    
    std::cout << "Inorder values before assign: myBST_orig_assign: " << std::endl;
    for (auto& val : vals_inorder_orig_assign)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Inorder values before assign: myBST_copy_assign: " << std::endl;
    for (auto& val : vals_inorder_copy_assign)
        std::cout << val << " ";
    std::cout << std::endl;
    myBST_orig_assign = myBST_copy_assign;
    
    vals_inorder_orig_assign = myBST_orig_assign.get_inorder_vals();
    vals_inorder_copy_assign = myBST_copy_assign.get_inorder_vals();
    
    std::cout << "Inorder values after assign: myBST_orig_assign: " << std::endl;
    for (auto& val : vals_inorder_orig_assign)
        std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Inorder values after assign: myBST_copy_assign: " << std::endl;
    for (auto& val : vals_inorder_copy_assign)
        std::cout << val << " ";
    std::cout << std::endl;
    
    
    // ---------------------------------------
    std::cout << "--------------------------\n";
    std::cout << "Move constructor" << std::endl;
    
    BinarySearchTree myBST_orig_move;
    myBST_orig_move.build_from_vector_balanced(values);
    std::cout << "myBST_orig_move before move: empty? " << myBST_orig_move.empty() << "\n";
    BinarySearchTree myBST_target_move(std::move(myBST_orig_move));

    std::cout << "myBST_orig_move after move: empty? " << myBST_orig_move.empty() << "\n";
    std::cout << "myBST_target_move after move: empty? " << myBST_target_move.empty() << "\n";

    
    // ---------------------------------------
    std::cout << "--------------------------\n";
    std::cout << "Move assignment operator" << std::endl;
    
    BinarySearchTree myBST_orig_move_assign;
    myBST_orig_move_assign.build_from_vector_balanced(values1);
    BinarySearchTree myBST_target_move_assign;
    myBST_target_move_assign.build_from_vector_balanced(values2);
    
    std::cout << "myBST_orig_move_assign before move: empty? " << myBST_orig_move_assign.empty() << "\n";
    std::cout << "myBST_target_move_assign before move: empty? " << myBST_target_move_assign.empty() << "\n";

    myBST_target_move_assign = std::move(myBST_orig_move_assign);
    
    std::cout << "myBST_orig_move_assign after move: empty? " << myBST_orig_move_assign.empty() << "\n";
    std::cout << "myBST_target_move_assign after move: empty? " << myBST_target_move_assign.empty() << "\n";
    

}
