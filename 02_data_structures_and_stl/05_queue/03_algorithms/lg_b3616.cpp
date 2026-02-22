#include <iostream>
#include <cstdint>

#define QUEUE_MAX_SIZE (10000 + 1)

enum Operation {
    kPUSH  = 1,
    kPOP   = 2,
    kQUERY = 3,
    kSIZE  = 4,
};

void push(int64_t x);
void pop();
int size();
void query();
bool empty();

int64_t queue[QUEUE_MAX_SIZE];

// 队列范围（左开右闭区间）：(head, tail]
int head = 0; // 队首指针
int tail = 0; // 队尾指针


int main(void) {
    int n = 0; // 操作的次数
    std::cin >> n;

    while (n-- != 0) {
        int op = 0;
        std::cin >> op;

        switch (op) {
            case kPUSH: {
                int x = 0;
                std::cin >> x;
                push(x);
                break;
            }
            case kPOP:
                pop();
                break;
            case kQUERY:
                query();
                break;
            case kSIZE: {
                int sz = size();
                std::cout << sz << std::endl;
            }
        }
    }

    return 0;
}

void push(int64_t x) {
    queue[++tail] = x;
}

void pop() {
    if (empty()) {
        std::cout << "ERR_CANNOT_POP" << std::endl;
    } else {
        head++;
    }
}

void query() {
    if (empty()) {
        std::cout << "ERR_CANNOT_QUERY" << std::endl;
    } else {
        std::cout << queue[head + 1] << std::endl;;
    }
}

int size() {
    return tail - head;
}

bool empty() {
    return size() == 0;
}
