### 算法，时间复杂度 $O(n)$，空间复杂度 $O(1)$

思路：这和 `C++` 中 `algorithm` 库中的 `nextpermutation()` 实现方法是一样的；

要让序列的字典序变大，要将左边的较小的数和右边的较大的数进行交换；

由于要让新得到的序列和旧序列的字典序接近，因此找到的左边的较小数要尽量靠右，右边的较大数要和左边的较小数最接近；

因此有：

`step 1: ` 先找左边的较小数。从最右侧开始找到第一个 `a[i] <= a[i + 1]` 的地方，可以知道其后面是降序排列的，降序排列的序列只能全部取反才可能使字典序变大；

`step 2: ` 然后找右边的较大数。从最右侧往左找第一个比 `a[i]` 大的数，记下标为 `k`；

`step 3: ` 交换 `a[i]` 和 `a[k]`。这样左边字典序的增幅最小，右边还是降序的，由于左边字典序已经增大了，因此右边 reverse 一下，使字典序变成最小的即可；

`step 4: ` reverse(a + i + 1, a + n)；

### C++ 代码
```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
	
        int l = n - 2;
        while (l >= 0 && nums[l] >= nums[l + 1]) {
            --l;
        }
        
        if (l >= 0) {
            int r = nums.size() - 1;
            while (r >= 0 && nums[l] >= nums[r]) {
                --r;
            }
            swap(nums[l], nums[r]);
        }
        
        reverse(nums.begin() + l + 1, nums.end());
    }
};
```
