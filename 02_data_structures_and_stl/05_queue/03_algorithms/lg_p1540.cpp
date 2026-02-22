#include <iostream>
#include <queue>
#include <vector>

#define M_MAX ( 100 + 1)
#define N_MAX (1000 + 1)

std::vector<bool> saved(N_MAX, false);
std::queue<int> memory;

int main(void) {
    int m, n;
    std::cin >> m >> n;
    int times = 0; // 查询次数
    int word; // 单词

    while (n-- != 0) {
        std::cin >> word;

        if (saved[word]) { // 如果已经被存入内存中了，查询次数不变
            continue;
        } else { // 没有被放入内存
            if (memory.size() == m) { // 内存已经被放满了
                int frt = memory.front();
                memory.pop();
                saved[frt] = false;
            }
            
            memory.push(word);
            saved[word] = true;
            times++;
        }
    }

    std::cout << times << std::endl;

    return 0;
}
