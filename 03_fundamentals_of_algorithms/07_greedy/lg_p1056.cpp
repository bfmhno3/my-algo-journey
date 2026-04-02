#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int idx;
    int cnt;
};

int main() {
    int m{}, n{}, k{}, l{}, d{};
    std::cin >> m >> n >> k >> l >> d;
    std::vector<Node> row(m + 1), col(n + 1);

    for (int i = 1; i <= m; i++) {
        row[i].idx = i;
    }

    for (int i = 1; i <= n; i++) {
        col[i].idx = i;
    }

    for (int i = 0; i < d; i++) {
        int x{}, y{}, p{}, q{};
        std::cin >> x >> y >> p >> q;

        if (x == p) {
            col[std::min(y, q)].cnt++;
        } else {
            row[std::min(x, p)].cnt++;
        }
    }

    auto cmp_cnt = [](const Node& a, const Node& b) {
        return a.cnt > b.cnt;
    };

    auto cmp_idx = [](const Node& a, const Node& b) {
        return a.idx < b.idx;
    };

    // 先按 cnt 降序排列
    std::sort(row.begin() + 1, row.end(), cmp_cnt);
    std::sort(col.begin() + 1, col.end(), cmp_cnt);

    // 再按 idx 升序排列
    std::sort(row.begin() + 1, row.begin() + 1 + k, cmp_idx);
    std::sort(col.begin() + 1, col.begin() + 1 + l, cmp_idx);

    for (int i = 1; i <= k; i++) {
        std::cout << row[i].idx << " \n"[i == k ? 1 : 0];
    }

    for (int i = 1; i <= l; i++) {
        std::cout << col[i].idx << " \n"[i == l ? 1 : 0];
    }

    return 0;
}
