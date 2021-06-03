#include "binary_tree.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<float> data = {5., 3., 6};
    auto const root_node = Trees::Binary_tree::from_array(data, 0);
    Trees::Binary_tree::order_print(root_node);
}
