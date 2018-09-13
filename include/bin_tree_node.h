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
      printf("\nInserting Element\n");
      if (element < value) {
        printf("\nGoing Left\n");
        if (left != nullptr)
          left->insert(element);
        else
          left = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node(element));
      }
      else if (element > value) {
        printf("\nGoing Right\n");
        if (right != nullptr)
          right->insert(element);
        else
          right = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node(element));
      }
      else {
        printf("\nIM HERE\n");
        value = element;
      }
    }

    /* Balance the Binary Tree */
    void balance() {
      std::cout << "@TODO - Balance Tree" << std::endl;
    }

    std::vector<T> in_order() {
      std::vector<T> output       = {};
      
      std::cout << "Getting Left Order" << std::endl;
      if (left != NULL) {
        std::vector<T> leftOrder    = left->in_order();
        output.insert(output.end(), leftOrder.begin(), leftOrder.end());
      }

      std::cout << "Getting This Element" << std::endl;
      output.push_back(value);
      
      std::cout << "Getting Right Order" << std::endl;
      if (right != NULL) {
        std::vector<T> rightOrder   = right->in_order();
        output.insert(output.end(), rightOrder.begin(), rightOrder.end());
      }

      return output;
    }

  private:

    T value;
    std::unique_ptr<bin_tree_node<T>> left;
    std::unique_ptr<bin_tree_node<T>> right;

};

#endif