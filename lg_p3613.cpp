#include <iostream>
#include <vector>

int main(void) {
  int n = 0;
  int q = 0;
  std::cin >> n >> q;
  std::vector<std::vector<int>> lockers(n + 1);

  for (int count = 0; count < q; count++) {
    int operation = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    std::cin >> operation;

    if (1 == operation) {  // 存放操作
      std::cin >> i >> j >> k;
      if (lockers[i].size() <= j + 1) {
        lockers[i].resize(j + 1);
      }
      lockers[i][j] = k;
    } else if (2 == operation) {  // 查询操作
      std::cin >> i >> j;
      std::cout << lockers[i][j] << std::endl;
    } else {
      break;
    }
  }

  return 0;
}
