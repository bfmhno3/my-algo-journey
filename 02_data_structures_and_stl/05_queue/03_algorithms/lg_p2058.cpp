#include <iostream>
#include <queue>

using Passenger = std::pair<int, int>;  // <到达时间, 国籍>

std::queue<Passenger> ships;              // 统计每个乘客的信息
std::vector<int> countries(10e5 + 1, 0);  // 记录每个国家的乘客人数
int kinds = 0;                            // 记录国家的数量

int main(void) {
  int n = 0;  // 船只的数量
  std::cin >> n;

  while (n-- != 0) {
    int time, passenger_count, nationality;
    std::cin >> time >> passenger_count;

    // 将所有乘客入队
    while (passenger_count-- != 0) {
      std::cin >> nationality;
      ships.push({time, nationality});

      if (countries[nationality]++ == 0) {  // 如果本来是 0，说明是新加的国家
        kinds++;
      }
    }

    // 确保队列合法：时间间隔小于 86400
    while (!ships.empty() &&
           ships.back().first - ships.front().first >= 86400) {
      int nationality = ships.front().second;
      ships.pop();

      if (countries[nationality]-- ==
          1) {  // 如果已经是 1，说明没有这个国家的乘客
        kinds--;
      }
    }
    std::cout << kinds << std::endl;
  }

  return 0;
}
