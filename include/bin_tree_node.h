#ifndef BIN_TREE_NODE_H
#define BIN_TREE_NODE_H

#include <memory>
#include <vector>
#include <iostream>

#include "bin_tree.h"

template <typename T>
class bin_tree_node {

  public:

    /* Default Constructor */
    bin_tree_node<T>() {}

    /* Construct with a Value */
    bin_tree_node<T>(const T& element) : value(element) {}

    /* Insert an Element. */
    void insert(const T& element) {
      if (element < value) {
        if (left != nullptr)
          left->insert(element);
        else
          left = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node(element));
      }
      else if (element > value) {
        if (right != nullptr)
          right->insert(element);
        else
          right = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node(element));
      }
      else {
        value = element;
      }
    }

    /* Returns if an Element Exists in the Tree */
    bool find(const T& element) {
      if (element < value) {
        if (left != nullptr)
          return left->find(element);
        else
          return false;
      }
      else if (element > value) {
        if (right != nullptr)
          return right->find(element);
        else
          return false;
      }
      else {
        return value == element;
      }
    }

    /* Balance the Binary Tree */
    void balance() {
      // @TODO
    }

    std::vector<T> in_order() {
      std::vector<T> output       = {};
      
      if (left != NULL) {
        std::vector<T> leftOrder    = left->in_order();
        output.insert(output.end(), leftOrder.begin(), leftOrder.end());
      }

      output.push_back(value);
      
      if (right != NULL) {
        std::vector<T> rightOrder   = right->in_order();
        output.insert(output.end(), rightOrder.begin(), rightOrder.end());
      }

      return output;
    }

    std::vector<T> pre_order() {
      std::vector<T> output;

      /* Temporary */
      return in_order();

      return output;
    }

  private:

    T value;
    std::unique_ptr<bin_tree_node<T>> left;
    std::unique_ptr<bin_tree_node<T>> right;

};

#endif