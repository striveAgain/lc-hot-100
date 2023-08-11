### 算法

经典的二分问题，注意 `mid` 计算时什么时候 `+ 1` 即可；

### C++ 代码

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};

        int n = nums.size();
        if (!n) {
            return ans;
        }

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;

            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (nums[l] != target) {
            return ans;
        }
        ans[0] = l;

        l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;

            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans[1] = l;

        return ans;
    }
};
```
