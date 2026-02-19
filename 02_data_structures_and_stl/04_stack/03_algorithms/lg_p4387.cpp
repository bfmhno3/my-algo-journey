#include <iostream>
#include <vector>
#include <stack>

constexpr int N = 1000000 + 1;

int main(void) {
    std::vector<int> pushed(N);
    std::vector<int> popped(N);

    int q = 0;
    std::cin >> q;

    while (q--) {
        int n = 0;
        std::cin >> n;

        // 读取入栈序列
        for (int i = 0; i < n; i++) {
            std::cin >> pushed[i];
        }

        // 读取出栈序列
        for (int i = 0; i < n; i++) {
            std::cin >> popped[i];
        }

        // 模拟验证
        std::stack<int> stk;
        int popped_idx = 0;

        // 依次入栈
        for (int i = 0; i < n; i++) {
            stk.push(pushed[i]);

            while (popped_idx < n && !stk.empty() && stk.top() == popped[popped_idx]) {
                stk.pop();
                popped_idx++;
            }
        }

        // 判断
        if (stk.empty()) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }


    return 0;
}
