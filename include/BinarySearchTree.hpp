#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

//#include <iostream>
#include <vector>
#include <queue>

class BinarySearchTree {
    
public:
    BinarySearchTree();
    BinarySearchTree(int value);
    BinarySearchTree(const BinarySearchTree& other_tree);
    BinarySearchTree(BinarySearchTree&& other_tree);
    friend void swap(BinarySearchTree& left_tree, BinarySearchTree& right_tree);
    BinarySearchTree& operator=(BinarySearchTree other_tree);
    ~BinarySearchTree() = default;

    void build_from_vector(std::vector<int>& values);
    void build_from_vector_balanced(std::vector<int>& values);
    void insert_node(int value);
    void remove_node(int value);
    void clear();
    
    int min_val() const;
    int max_val() const;
    bool contains(int val) const;
    
    int max_depth() const;
    bool balanced() const;
    
    std::vector<int> get_inorder_vals() const;
    std::vector<int> get_preorder_vals() const;
    std::vector<int> get_postorder_vals() const;
    std::vector<int> get_level_order_vals() const;
    
    inline int size() const {
        return tree_size;
    }
    inline bool empty() const {
        return tree_size == 0;
    }
    
private:
    struct Node {
        int val;
        std::unique_ptr<Node> left = nullptr;
        std::unique_ptr<Node> right = nullptr;
        
        Node(const int value) :
        val{value},
        left{nullptr},
        right{nullptr}
        {}
    };
        
    std::unique_ptr<Node> root;
    int tree_size;
    
    std::unique_ptr<Node> deep_copy(const std::unique_ptr<Node>& source_node);

    void build_from_vector_balanced(std::vector<int>::iterator it_b, std::vector<int>::iterator it_e);
    void insert_node(int value, std::unique_ptr<Node>& curr_node);
    void remove_node(int value, std::unique_ptr<Node>& curr_node);
    
    const Node* find_min_node(const std::unique_ptr<Node>& curr_node) const;
    const Node* find_max_node(const std::unique_ptr<Node>& curr_node) const;
    bool contains(int value, const std::unique_ptr<Node>& curr_node) const;
    
    bool balanced(const std::unique_ptr<Node>& curr_node, int height) const;
    int max_depth(const std::unique_ptr<Node>& curr_node) const;
    
    void get_inorder_vals(std::vector<int>& vals, const std::unique_ptr<Node>& curr_node) const;
    void get_preorder_vals(std::vector<int>& vals, const std::unique_ptr<Node>& curr_node) const;
    void get_postorder_vals(std::vector<int>& vals, const std::unique_ptr<Node>& curr_node) const;
    void get_level_order_vals(std::vector<int>& vals, const std::unique_ptr<Node>& curr_node) const;

};

#endif /* BINARYSEARCHTREE_H */
