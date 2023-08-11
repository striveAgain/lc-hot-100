### 算法，时间复杂度 $O(\log n)$

二分的思想，一般的二分是在有序的序列中进行，但是本题是在局部分别有序的序列中进行二分

此题告诉我们局部分别有序的序列也是可以进行二分的，通过 `mid` 判断左边还是右边有序，然后判断 `target` 应该在有序部分还是无序部分，缩小范围即可；

### C++ 代码
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
	
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            
            if (nums[mid] > nums[n - 1]) {
                if (nums[0] <= target && nums[mid] >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && nums[n - 1] >= target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
        
        return ((nums[l] == target) ? l : -1);
    }
};
```
