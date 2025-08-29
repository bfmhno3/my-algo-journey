#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int current1 = m - 1;
    int current2 = n - 1;
    int back = nums1.size() - 1;

    while (current1 >= 0 && current2 >= 0) {
        if (nums1[current1] >= nums2[current2]) {
            nums1[back--] = nums1[current1--];
        } else {
            nums1[back--] = nums2[current2--];
        }
    }

    while (current2 >= 0) {
        nums1[back--] = nums2[current2--];
    }
  }
};

int main(void) {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  std::vector<int> nums2 = {2, 5, 6};
  Solution().merge(nums1, 3, nums2, 3);

  for (const auto& i : nums1) {
    std::cout << i << " ";
  }
  return 0;
}
