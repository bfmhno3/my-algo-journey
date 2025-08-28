from typing import *

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        j = 0
        for i in range(0, len(nums)):
            if (nums[i] != 0):
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
            i += 1
