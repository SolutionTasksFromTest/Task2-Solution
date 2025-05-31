#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

size_t find_min_alphabet_prefix(const std::vector<int64_t>& values) {
    std::vector<bool> seen(27, false);
    size_t distinct_count = 0;

    for (size_t i = 0; i < values.size(); ++i) {
        int64_t x = values[i];
        if (x >= 1 && x <= 26 && !seen[x]) {
            seen[x] = true;
            ++distinct_count;
        }
        if (distinct_count == 26) {
            return i + 1;
        }
    }

    return 0;
}

int main() {
    size_t number_of_elements = 0;
    std::cin >> number_of_elements;

    std::vector<int64_t> values(number_of_elements);
    for (auto &val : values) {
        std::cin >> val;
    }

    int64_t min_prefix_length = find_min_alphabet_prefix(values);
    if (min_prefix_length > 0) {
        std::cout << min_prefix_length << std::endl;
    } else {
        std::cout << "NONE" << std::endl;
    }

    return 0;
}
