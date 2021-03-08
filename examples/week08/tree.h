#pragma once

#include <iostream>


// struct tree {
//   std::string value;
//   tree<std::string>* left = nullptr;
//   tree<std::string>* right = nullptr;
// };

template <class T>
struct tree {
  T value;
  tree<T>* left = nullptr;
  tree<T>* right = nullptr;
};

template <class T>
bool is_leaf(const tree<T>* node) {
  return node->left == nullptr && node->right == nullptr;
}

// make a tree, leaving the chld nodes == nullptr
template <class T>
tree<T>* make_tree(T value) {
  auto root = new tree<T>;
  root->value = value;
  return root;
}

// make a complete binary tree
template <class T>
tree<T>* make_tree(T value, tree<T>* left, tree<T>* right) {
  auto root = make_tree(value);
  root->left  = left;
  root->right = right;
  return root;
}

template <class T>
std::ostream& operator<< (std::ostream& os, const tree<T>* root) {
  if (root == nullptr) return os;
  if (is_leaf(root)) {
    return os << "A:" << root->value << '\n';
  }
  os << "Q:" << root->value << '\n';
  operator<< (os, root->left);  // same as os << root->left; 
  os << root->right;
  return os;
}
