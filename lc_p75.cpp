#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int red = 0;
        int blue = size - 1;
        int i = 0;

        while (i <= blue) {
            if (nums[i] == 0) { // 红色
                std::swap(nums[i++], nums[red++]);
            } else if (nums[i] == 1) { // 白色
                i++;
            } else if (nums[i] == 2) { // 蓝色
                std::swap(nums[i], nums[blue--]);
            } else {
                break;
            }
        }
    }
};

int main(void) {
    std::vector<int> nums = {2, 0 , 1};
    Solution().sortColors(nums);

    for (const auto& i : nums) {
        std::cout << i << " ";
    }
    
    return 0;
}
