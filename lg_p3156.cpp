#include <iostream>
#include <vector>

int main(void) {
  std::vector<int> student_ids;
  int student_count = 0;
  int query_count = 0;
  std::cin >> student_count >> query_count;

  // 下标 0 位置不使用，真实数据从下标 1 开始计数
  student_ids.reserve(student_count + 1);
  student_ids.push_back(0);

  for (int i = 1; i <= student_count; i++) {
    int id = 0;
    std::cin >> id;
    student_ids.push_back(id);
  }

  for (int i = 0; i < query_count; i++) {
    int index = 0;
    std::cin >> index;
    std::cout << student_ids[index] << std::endl;
  }

  return 0;
}
