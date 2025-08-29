from typing import *


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        current1 = m - 1
        current2 = n - 1
        back = len(nums1) - 1

        while current1 >= 0 and current2 >= 0:
            if nums1[current1] >= nums2[current2]:
                nums1[back] = nums1[current1]
                back -= 1
                current1 -= 1
            else:
                nums1[back] = nums2[current2]
                back -= 1
                current2 -= 1

        while current2 >= 0:
            nums1[back] = nums2[current2]
            back -= 1
            current2 -= 1


def main() -> None:
    nums1: List[int] = [1, 2, 3, 0, 0, 0]
    nums2: List[int] = [2, 5, 6]
    Solution().merge(nums1, 3, nums2, 3)
    print(nums1)


if __name__ == "__main__":
    main()