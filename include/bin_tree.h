#ifndef BINTREE_H
#define BINTREE_H

#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

#include "bin_tree_node.h"

namespace ads {

template <typename T> class bin_tree {

public:
  /* Default Constructor */
  bin_tree<T>() {}

  /* Takes in a vector of elements, and constructs a binary tree. */
  bin_tree<T>(std::vector<T> elements) {
    std::sort(elements.begin(), elements.end());
    root = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(elements));
  }

  /* Initialiser-List Constructor */
  bin_tree<T>(const std::initializer_list<T> &elements) {
    std::vector<T> elems = elements;
    std::sort(elems.begin(), elems.end());
    root = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(elems));
  }

  /* Copy Constructor */
  bin_tree<T>(const bin_tree<T> &copy) {
    std::vector<T> elements = copy.in_order();
    root = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(elements));
  }

  /* Assignment Operator */
  bin_tree<T> &operator=(const bin_tree<T> &rhs) {
    if (&rhs == this) {
      return *this;
    }
    std::vector<T> elements = rhs.in_order();
    root = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(elements));
    return *this;
  }

  /* Insert an Element. */
  void insert(const T &element) {
    if (root == nullptr)
      root = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(element));
    root->insert(element);
  }

  /* Returns if an Element Exists in the Tree */
  bool find(const T &element) const {
    if (root == nullptr)
      return false;
    return root->find(element);
  }

  /* Balance the Binary Tree */
  void balance() {
    std::vector<T> order = in_order();
    clear();
    root = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(order));
  }

  std::vector<T> in_order() const {
    if (root == nullptr)
      return {};

    return root->in_order();
  }

  std::vector<T> pre_order() const {
    if (root == nullptr)
      return {};

    return root->pre_order();
  }

  std::vector<T> post_order() const {
    if (root == nullptr)
      return {};

    return root->post_order();
  }

  /* Clears all Elements of the Binary Tree */
  void clear() { root.reset(); }

private:
  std::unique_ptr<bin_tree_node<T>> root;
};

} // namespace ads

#endif