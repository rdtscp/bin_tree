#ifndef BIN_TREE_NODE_H
#define BIN_TREE_NODE_H

#include <iostream>
#include <memory>
#include <vector>

#include "bin_tree.h"

template <typename T> class bin_tree_node {

public:
  /* Construct a Node of this Element */
  bin_tree_node<T>(const T &element) : value(element) {}

  /* Construct a List of Elements */
  bin_tree_node<T>(std::vector<T> elements) {
    T midElem = getMiddle(elements);
    std::vector<T> lhs = getLHS(elements);
    std::vector<T> rhs = getRHS(elements);

    value = midElem;

    if (lhs.size() > 0)
      left = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(lhs));

    if (rhs.size() > 0)
      right = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(rhs));
  }

  /* Insert an Element. */
  void insert(const T &element) {
    if (element < value) {
      if (left != nullptr)
        left->insert(element);
      else
        left = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(element));
    } else if (element > value) {
      if (right != nullptr)
        right->insert(element);
      else
        right =
            std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(element));
    } else {
      value = element;
    }
  }

  /* Returns if an Element Exists in the Tree */
  bool find(const T &element) {
    if (element < value) {
      if (left != nullptr)
        return left->find(element);
      else
        return false;
    } else if (element > value) {
      if (right != nullptr)
        return right->find(element);
      else
        return false;
    } else {
      return value == element;
    }
  }

  /* Balance the Binary Tree */
  void balance() {
    // @TODO
  }

  /* Return a vector of the In-Order Traversal. */
  std::vector<T> in_order() {
    std::vector<T> output = {};

    if (left != NULL) {
      std::vector<T> leftOrder = left->in_order();
      output.insert(output.end(), leftOrder.begin(), leftOrder.end());
    }

    output.push_back(value);

    if (right != NULL) {
      std::vector<T> rightOrder = right->in_order();
      output.insert(output.end(), rightOrder.begin(), rightOrder.end());
    }

    return output;
  }

  /* Return a vector of the Pre-Order Traversal. */
  std::vector<T> pre_order() {
    std::vector<T> output = {};

    output.push_back(value);

    if (left != NULL) {
      std::vector<T> leftOrder = left->pre_order();
      output.insert(output.end(), leftOrder.begin(), leftOrder.end());
    }

    if (right != NULL) {
      std::vector<T> rightOrder = right->pre_order();
      output.insert(output.end(), rightOrder.begin(), rightOrder.end());
    }

    return output;
  }

  /* Return a vector of the Post-Order Traversal. */
  std::vector<T> post_order() {
    std::vector<T> output = {};

    if (left != nullptr) {
      std::vector<T> leftOrder = left->post_order();
      output.insert(output.end(), leftOrder.begin(), leftOrder.end());
    }

    if (right != nullptr) {
      std::vector<T> rightOrder = right->post_order();
      output.insert(output.end(), rightOrder.begin(), rightOrder.end());
    }

    output.push_back(value);

    return output;
  }

private:
  T value;
  std::unique_ptr<bin_tree_node<T>> left;
  std::unique_ptr<bin_tree_node<T>> right;

  T getMiddle(const std::vector<T> &list) {
    int middleIdx = (list.size() - 1) / 2;
    return list[middleIdx];
  }

  std::vector<T> getLHS(std::vector<T> list) {
    if (list.size() == 0) {
      return {};
    }
    if (list.size() == 1) {
      return {};
    }
    if (list.size() == 2) {
      return {};
    }
    int middleIdx = (list.size() - 1) / 2;
    if (middleIdx > 0 && middleIdx < list.size()) {
      std::vector<T> output =
          std::vector<T>(list.begin(), list.begin() + middleIdx);
      return output;
    } else {
      return {};
    }
  }

  std::vector<T> getRHS(std::vector<T> list) {
    if (list.size() == 0) {
      return {};
    }
    if (list.size() == 1) {
      return {};
    }
    if (list.size() == 2) {
      return {list[1]};
    }
    int middleIdx = (list.size() - 1) / 2;
    if (middleIdx > 0 && middleIdx < list.size()) {
      std::vector<T> output =
          std::vector<T>(list.begin() + (middleIdx + 1), list.end());
      return output;
    } else {
      return {};
    }
  }
};

#endif