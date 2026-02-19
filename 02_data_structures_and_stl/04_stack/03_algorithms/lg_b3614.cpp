#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

const uint64_t N = 10e6 + 1;
uint64_t stk[N] = {0};
uint64_t top_idx = 0; // 栈顶指针，指向栈顶元素的下一个位置

int main(void) {
    uint64_t t = 0;
    cin >> t; // 数据组数

    while (t--) {
        top_idx = 0; // 每组数据都清空栈
        uint64_t n = 0; // 操作的次数
        cin >> n;

        while (n--) {
            string operation;
            uint64_t x = 0;
            cin >> operation;

            if ("push" == operation) {
                cin >> x;
                stk[top_idx++] = x;
            } else if ("pop" == operation) {
                if (0 == top_idx) {
                    cout << "Empty" << endl;
                } else {
                    --top_idx;
                }
            } else if ("query" == operation) {
                if (0 == top_idx) {
                    cout << "Anguei!" << endl;
                } else {
                    cout << stk[top_idx - 1] << endl;
                }
            } else if ("size" == operation) {
                cout << top_idx << endl;
            } else {
                continue;
            }
        }
    }

    return 0;
}
