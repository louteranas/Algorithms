#pragma once
/*!
@file
Anary_tree structure.
 */
#include <iostream>

namespace Trees
{

    namespace Binary_tree
    {
        struct Node
        {
            Trees::Binary_tree::Node* right = nullptr;
            Trees::Binary_tree::Node* left = nullptr;
            double data = -1;
        };

        template < class Scalar >
        auto create_node(Scalar const value)
        {
          auto root_node = new Node{};
          root_node->data = value;
          return root_node;
        }

        template < class Node, class Scalar >
        void add_node(Node& node, Scalar const value)
        {
            if(node == nullptr)
                node = create_node(value);
            else
            {
                if(node->data > value)
                    if(node->left == nullptr)
                        node->left = create_node(value);
                    else
                        add_node(node->left, value);
                if(node->data <= value)
                    if(node->right == nullptr)
                        node->right = create_node(value);
                    else
                        add_node(node->right, value);
            }
        }

        template < class Container, class Index>
        auto const from_array(Container in_array, Index const in_rootIndex)
        {
            if(in_array.size() == 0)
              return new Node{};
            auto root_node = create_node(in_array[in_rootIndex]);
            for( std::size_t i = 0; i < in_array.size(); ++i)
                if(i != in_rootIndex)
                    add_node(root_node, in_array[i]);
            return root_node;
        }

        template < class Node >
        auto order_print(Node const& root_node)
        {
            if(root_node == nullptr)
                return;
            order_print(root_node->left);
            std::cout << root_node->data << " ";
            order_print(root_node->right);
        }
    }

}
