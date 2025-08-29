#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int* merged = (int*)malloc((m + n) * sizeof(int));

  if (merged == NULL) {
    return;
  }

  int i = 0;
  int j = 0;
  int k = 0;

  while (i < m && j < n) {
    if (nums1[i] <= nums2[j]) {
      merged[k++] = nums1[i++];
    } else {
      merged[k++] = nums2[j++];
    }
  }

  while (i < m) {
    merged[k++] = nums1[i++];
  }

  while (j < n) {
    merged[k++] = nums2[j++];
  }

  for (int i = 0; i < (m + n); i++) {
    nums1[i] = merged[i];
  }

  free(merged);
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
