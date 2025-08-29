from typing import *

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        red: int = 0
        blue: int = len(nums) - 1
        i = 0

        while i <= blue:
            if nums[i] == 0:
                nums[i], nums[red] = nums[red], nums[i]
                i += 1
                red += 1
            elif nums[i] == 1:
                i += 1
            elif nums[i] == 2:
                nums[i], nums[blue] = nums[blue], nums[i]
                blue -= 1
            else:
                break


def main() -> None:
    nums = [2, 0, 1]
    Solution().sortColors(nums)
    print(nums)

if __name__ == "__main__":
    main()
