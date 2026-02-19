class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        
        for (const char& c : s) {
            if ('(' == c || '[' == c || '{' == c) {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }

                char top = stk.top();

                if (')' == c && '(' != top) {
                    return false;
                }

                if (']' == c && '[' != top) {
                    return false;
                }

                if ('}' == c && '{' != top) {
                    return false;
                }

                stk.pop();
            }
        }

        return stk.empty();
    }
};