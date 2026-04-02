#include <iostream>
#include <vector>
#include <cstdint>

int main(void) {
    int64_t n{}, value{}, curr{}, result{};

    std::cin >> n;

    std::vector<int64_t> sequence(n + 1);

    for (int64_t i = 1; i <= n; i++) {
        std::cin >> sequence[i];
    }

    for (int64_t i = 0; i <= n; i++) {
        curr = std::max(curr + sequence[i], sequence[i]);
        result = std::max(curr, result);
    }

    std::cout << result;

    return 0;
}
