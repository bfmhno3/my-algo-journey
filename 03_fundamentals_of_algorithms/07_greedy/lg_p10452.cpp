#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>

int main(void) {
    int64_t n{}, x{}, result{};
    std::cin >> n;
    std::vector<int64_t> pos(n + 1);

    for (int64_t i = 1; i <= n; i++) {
        std::cin >> x;
        pos[i] = x;
    }

    std::sort(pos.begin(), pos.end());

    for (int64_t i = 1; i <= n / 2; i++) {
        result += pos[n + 1 - i] - pos[i];
    }

    std::cout << result;

    return 0;
}
