### 算法一：手写快排，时间复杂度 $O(n \log n) / O(n^2)$，空间复杂度 $O(\log n) / O(n)$

背模板即可；

### C++ 代码
```c++
class Solution {
public:
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }

        int i = l - 1, j = r + 1;
        int x = nums[l + r >> 1];
        while (i < j) {
            do {
                ++i;
            } while (nums[i] < x);

            do {
                --j;
            } while (nums[j] > x);

            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }

        quickSort(nums, l, j);
        quickSort(nums, j + 1, r);
    }

    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};
```

---

### 算法二：单指针，时间复杂度 $O(n)$

**由于知道数据元素的值域，且取值个数很小，只有 `3` 个，因此可以两遍遍历，应该很容易想到！**

遍历两遍，第一遍确定所有 `0` 的位置，第二遍确定所有 `1` 的位置；

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
	
        int pos0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ++pos0;
                swap(nums[pos0], nums[i]);
            }
        }
        
        int pos1 = pos0;
        for (int i = pos0 + 1; i < n; ++i) {
            if (nums[i] == 1) {
                ++pos1;
                swap(nums[pos1], nums[i]);
            }
        }
    }
};
```

---

### 算法三：双指针 1，时间复杂度 $O(n)$

采用 `ptr0` 表示最后一个 `0` 的位置 + 1，初始值为 `0`；`ptr1` 表示最后一个 `1` 的位置 + 1；

`case 1: ` 如果遍历到了 `0`，则将 `nums[pos0]` 与 `nums[i]` 交换，但是这次交换可能会将已经排好的 `1` 交换出去，因此还要再与 `pos1` 交换一次；

`case 2: ` 如果遍历到了 `1`，直接与 `nums[pos1]` 交换即可，因此此时 `nums[pos1]` 一定是 `2`；

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
	
        int pos0 = 0, pos1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[pos0]);
                
                if (nums[i] == 1) {
                    swap(nums[i], nums[pos1]);
                }
                ++pos0, ++pos1;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[pos1]);
                ++pos1;
            }
        }
    }
};
```

---

### 算法四：双指针 2，时间复杂度 $O(n)$

采用 `pos0` 表示最后一个 `0` 的位置 + 1，`pos2` 表示最后一个 `2` 的位置 - 1；

需要注意在对 `2` 进行交换时，可能原位置 `pos2` 也存的是 `2`，但是下一次遍历时 `i` 已经 + 1 了，跳过了交换过来的 `2`；

因此还要进行交换，直到交换后 `nums[i] != 2`；

然后判断当前位置是 `0` 还是 `1`，进行下一步操作；

### C++ 代码
```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
	
        int pos0 = 0, pos2 = n - 1;
        for (int i = 0; i <= pos2; ++i) {
            while (i <= pos2 && nums[i] == 2) {
                swap(nums[i], nums[pos2]);
                --pos2;
            }

            if (nums[i] == 0) {
                swap(nums[i], nums[pos0]);
                ++pos0;
            }
        }
    }
};
```
