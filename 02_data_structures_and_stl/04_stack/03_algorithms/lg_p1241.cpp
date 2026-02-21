#include <iostream>
#include <string>
#include <stack>
#include <vector>

bool is_match(char left, char right) {
    return ('(' == left && ')' == right) || ('[' == left && ']' == right);
}

int main(void) {
    std::string expression;
    std::cin >> expression;

    std::stack<int> stk;
    std::vector<bool> matched(expression.size(), false);

    for (int i = 0; i < static_cast<int>(expression.size()); ++i) {
        char ch = expression[i];
        if ('(' == ch || '[' == ch) {
            stk.push(i);
            continue;
        }

        if (!stk.empty() && is_match(expression[stk.top()], ch)) {
            matched[stk.top()] = true;
            matched[i] = true;
            stk.pop();
        }
    }

    for (int i = 0; i < static_cast<int>(expression.size()); ++i) {
        if (matched[i]) {
            std::cout << expression[i];
            continue;
        }

        if ('(' == expression[i] || ')' == expression[i]) {
            std::cout << "()";
        } else {
            std::cout << "[]";
        }
    }
    std::cout << std::endl;
    
    return 0;
}
