#ifndef BINTREE_H
#define BINTREE_H

#include <memory>
#include <vector>
#include <functional>

#include "bin_tree_node.h"


namespace ads {

  
  template <typename T>
  class bin_tree {
    
    public:

      /* Default Constructor */
      bin_tree<T>() {}

      /* Takes in a vector of elements, and constructs a binary tree. */
      bin_tree<T>(std::vector<T> elements) {
        for (const T& element: elements) {
          insert(element);
        }
        balance();
      }

      /* Initialiser-List Constructor */
      bin_tree<T>(std::initializer_list<T> elements) {
        for (const T& element: elements) {
          insert(element);
        }
        balance();
      }

      /* Insert an Element. */
      void insert(const T& element) {
        if (root == nullptr)
          root = std::unique_ptr<bin_tree_node<T>>(new bin_tree_node<T>(element));
        root->insert(element);
      }

      /* Balance the Binary Tree */
      void balance() {
        root->balance();
      }

      std::vector<T> in_order() {
        std::vector<T> result = root->in_order();
        return result;
      }

    private:

      int height = 0;
      std::unique_ptr<bin_tree_node<T>> root;

  };

} // ads

#endif