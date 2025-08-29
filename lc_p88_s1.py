from typing import *

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        merged: List[int] = [0] * (m + n)
        i: int = 0
        j: int = 0
        k: int = 0

        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                merged[k] = nums1[i]
                k += 1
                i += 1
            else:
                merged[k] = nums2[j]
                k += 1
                j += 1
        
        while i < m:
            merged[k] = nums1[i]
            k += 1
            i += 1

        while j < n:
            merged[k] = nums2[j]
            k += 1
            j += 1

        nums1[:] = merged


def main() -> None:
    nums1: List[int] = [1, 2, 3, 0, 0, 0]
    nums2: List[int] = [2, 5, 6]

    Solution().merge(nums1, 3, nums2, 3)
    print(nums1)


if __name__ == "__main__":
    main()
