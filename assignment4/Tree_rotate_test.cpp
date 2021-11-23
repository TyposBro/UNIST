#include <iostream>

#include "Tree.h"

int main() {
    Tree_t<int, int> t;

    t.insert_internal(10, 10);
    auto pivot = t.insert_internal(20, 20);
    t.insert_internal(30, 30);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    t.rotate(pivot);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    t.insert(5, 5);
    t.insert(15, 15);
    t.insert(25, 25);
    auto leaf = t.insert_internal(35, 35);

    pivot = t.insert_internal(10, 11);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    t.rotate(pivot);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    // rotate on head: do nothing
    t.rotate(pivot);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    // rotate on leaf: be sure to handle grandparent
    t.rotate(leaf);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    // These tests are by no means exhaustive
    // Try to think of your own edge cases!

    return 0;
}
