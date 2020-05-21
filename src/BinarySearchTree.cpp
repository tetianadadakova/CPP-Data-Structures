#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree() : root{nullptr}, tree_size{0} {}

BinarySearchTree::BinarySearchTree(int value) : root{std::make_unique<Node>(value)}, tree_size{1} {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other_tree) :
root(deep_copy(other_tree.root)), tree_size{other_tree.tree_size} {}

BinarySearchTree::BinarySearchTree(BinarySearchTree&& other_tree) :
root(std::move(other_tree.root)), tree_size(other_tree.tree_size) {}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& other_tree) {
    if (this != &other_tree) {
        tree_size = other_tree.tree_size;
        root = deep_copy(other_tree.root);
    }
    return *this;
}

BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree&& other_tree) {
    if (this != &other_tree) {
        tree_size = other_tree.tree_size;
        other_tree.tree_size = 0;
        root = std::move(other_tree.root);
    }
    return *this;
}

void BinarySearchTree::build_from_vector(std::vector<int>& values) {
    for (int value : values) {
        insert_node(value);
    }
}

void BinarySearchTree::build_from_vector_balanced(std::vector<int>& values) {
    std::sort(values.begin(), values.end());
    std::vector<int>::iterator it_b = values.begin();
    std::vector<int>::iterator it_e = values.end() - 1;
    build_from_vector_balanced(it_b, it_e);
}

void BinarySearchTree::insert_node(int value) {
    insert_node(value, root);
}

void BinarySearchTree::remove_node(int value) {
    remove_node(value, root);
}

void BinarySearchTree::clear() {
    root = nullptr;
    tree_size = 0;
}

int BinarySearchTree::min_val() const {
    return find_min_node(root)->val;
}

int BinarySearchTree::max_val() const {
    return find_max_node(root)->val;
}

bool BinarySearchTree::contains(int val) const {
    return contains(val, root);
}

int BinarySearchTree::max_depth() const {
    return max_depth(root);
}

bool BinarySearchTree::balanced() const {
    int height = 0;
    return balanced(root, height);
}

std::vector<int> BinarySearchTree::get_inorder_vals() const {
    std::vector<int> vals;
    get_inorder_vals(vals, root);
    return vals;
}

std::vector<int> BinarySearchTree::get_preorder_vals() const {
    std::vector<int> vals;
    get_preorder_vals(vals, root);
    return vals;
}

std::vector<int> BinarySearchTree::get_postorder_vals() const {
    std::vector<int> vals;
    get_postorder_vals(vals, root);
    return vals;
}

std::vector<int> BinarySearchTree::get_level_order_vals() const {
    std::vector<int> vals;
    get_level_order_vals(vals, root);
    return vals;
}

std::unique_ptr<BinarySearchTree::Node> BinarySearchTree::deep_copy(const std::unique_ptr<Node>& source_node) {
    if (!source_node) return nullptr;
    auto dest_node = std::make_unique<Node>(source_node->val);
    dest_node->left = deep_copy(source_node->left);
    dest_node->right = deep_copy(source_node->right);
    return dest_node;
}

void BinarySearchTree::build_from_vector_balanced(std::vector<int>::iterator it_b, std::vector<int>::iterator it_e) {
    if (it_b > it_e) return;
    
    int range = std::distance(it_b, it_e);
    std::vector<int>::iterator it_m = it_b + range / 2;
    
    insert_node(*it_m);
    
    build_from_vector_balanced(it_b, it_m - 1);
    build_from_vector_balanced(it_m + 1, it_e);
}

void BinarySearchTree::insert_node(int value, std::unique_ptr<Node>& curr_node) {
    if (!curr_node) {
        curr_node = std::make_unique<Node>(value);
        tree_size++;
        return;
    }
    
    if (value == curr_node->val) // handle duplicate vals - ignore?
        return;
    
    if (value < curr_node->val)
        insert_node(value, curr_node->left);
    else // (value > curr_node->val)
        insert_node(value, curr_node->right);
}

void BinarySearchTree::remove_node(const int value, std::unique_ptr<Node>& curr_node) {
    
    if (!curr_node) return;
    
    if (value < curr_node->val) {
        remove_node(value, curr_node->left);
    } else if (value > curr_node->val) {
        remove_node(value, curr_node->right);
    } else { // (value == curr_node->val)
        // remove it
        if (!curr_node->left && !curr_node->right) { // leaf
            tree_size--;
            curr_node = nullptr;
        } else if (curr_node->left && !curr_node->right) { // only left child
            tree_size--;
            curr_node = std::move(curr_node->left);
        } else if (!curr_node->left && curr_node->right) { // only right child
            tree_size--;
            curr_node = std::move(curr_node->right);
        } else {
            // both right and left children: replace val by left subtree's max value
            const Node* temp = find_max_node(curr_node->left);
            curr_node->val = temp->val;
            // then remove left subtree's max node
            remove_node(temp->val, curr_node->left);
        }
    }
}

const BinarySearchTree::Node* BinarySearchTree::find_min_node(const std::unique_ptr<Node>& curr_node) const {
    if (!curr_node) return nullptr;
    if (!curr_node->left) return curr_node.get();
    return find_min_node(curr_node->left);
}

const BinarySearchTree::Node* BinarySearchTree::find_max_node(const std::unique_ptr<Node>& curr_node) const {
    if (!curr_node) return nullptr;
    if (!curr_node->right) return curr_node.get();
    return find_max_node(curr_node->right);
}

bool BinarySearchTree::contains(int value, const std::unique_ptr<Node>& curr_node) const {
    if (!curr_node) return false;
    if (value == curr_node->val) return true;
    if (value < curr_node->val) return contains(value, curr_node->left);
    return contains(value, curr_node->right);
}

bool BinarySearchTree::balanced(const std::unique_ptr<Node>& curr_node, int height) const {
    if (!curr_node) {
        height = -1;
        return true;
    }
    int left = 0;
    int right = 0;
    if (balanced(curr_node->left, left)
        && balanced(curr_node->right, right)
        && std::abs(left - right) < 2) {
        height = std::max(left, right) + 1;
        return true;
    }
    return false;
}

int BinarySearchTree::max_depth(const std::unique_ptr<Node>& curr_node) const {
    if (!curr_node) return -1;
    return std::max(max_depth(curr_node->left), max_depth(curr_node->right)) + 1;
}

void BinarySearchTree::get_inorder_vals(std::vector<int>& vals,
                                        const std::unique_ptr<Node>& curr_node) const {
    if (!curr_node) return;
    get_inorder_vals(vals, curr_node->left);
    vals.push_back(curr_node->val);
    get_inorder_vals(vals, curr_node->right);
}

void BinarySearchTree::get_preorder_vals(std::vector<int>& vals,
                                         const std::unique_ptr<Node>& curr_node) const {
    if (!curr_node) return;
    vals.push_back(curr_node->val);
    get_preorder_vals(vals, curr_node->left);
    get_preorder_vals(vals, curr_node->right);
}

void BinarySearchTree::get_postorder_vals(std::vector<int>& vals,
                                          const std::unique_ptr<Node>& curr_node) const {
    if (!curr_node) return;
    get_postorder_vals(vals, curr_node->left);
    get_postorder_vals(vals, curr_node->right);
    vals.push_back(curr_node->val);
}

void BinarySearchTree::get_level_order_vals(std::vector<int>& vals,
                                            const std::unique_ptr<Node>& curr_node) const {
    if (!curr_node) return;
    
    std::queue<Node*> nodes_by_level;
    nodes_by_level.push(curr_node.get());
    while (!nodes_by_level.empty()) {
        Node* temp_node = nodes_by_level.front();
        nodes_by_level.pop();
        
        if (temp_node->left) nodes_by_level.push(temp_node->left.get());
        if (temp_node->right) nodes_by_level.push(temp_node->right.get());
        
        vals.push_back(temp_node->val);
    }
}
