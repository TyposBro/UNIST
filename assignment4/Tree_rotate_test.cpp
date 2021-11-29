#include <iostream>

#include "Tree.h"

int main() {
    Tree_t<int, int> t;

    auto a_pivot = t.insert_internal(10, 10);
    auto b_pivot = t.insert_internal(20, 20);
    auto c_pivot = t.insert_internal(30, 30);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    t.rotate(a_pivot, false);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    t.insert(5, 5);
    t.insert(15, 15);
    t.insert(25, 25);
    t.insert_internal(35, 35);

    t.insert_internal(10, 11);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    t.rotate(b_pivot, true);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    t.rotate(c_pivot, false);
    std::cout << t.to_string_pre_order() << '\n';
    std::cout << t.to_string_level_order() << '\n';

    // These tests are by no means exhaustive
    // Try to think of your own edge cases!

    return 0;
}
