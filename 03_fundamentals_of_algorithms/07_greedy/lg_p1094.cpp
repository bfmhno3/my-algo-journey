#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

int main(void) {
    int64_t w{}, n{}, result{};
    std::cin >> w >> n;

    std::vector<int64_t> prices(n + 1);

    for (int64_t i = 1; i <= n; i++) {
        std::cin >> prices[i];
    }

    std::sort(prices.begin() + 1, prices.end());

    int front{1}, rear{n};

    while (front <= rear) {
        if (prices[front] + prices[rear] <= w) {
            front++;
        }

        rear--;
        result++;
    }

    std::cout << result;

    return 0;
}
