#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int current1 = m - 1;
  int current2 = n - 1;
  int back = nums1Size - 1;

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

int main(void) {
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] =  {2, 5, 6};
    merge(nums1, 6, 3, nums2, 3, 3);

    for (int i = 0; i < 6; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
