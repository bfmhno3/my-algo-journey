#include <stdio.h>

void swap(int* const a, int* const b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numSize) {
    int red = 0;
    int blue = numSize - 1;
    int i = 0;

    while (i <= blue) {
        switch (nums[i]) {
            case 0: {
                swap(&nums[i++], &nums[red++]);
                break;
            }
            case 1: {
                i++;
                break;
            }
            case 2: {
                swap(&nums[i], &nums[blue--]);
                break;
            }
        }
    }
}

int main(void) {
    int nums[3] = {2, 0, 1};
    sortColors((int *)&nums, 3);

    for (int i = 0; i < 3; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
