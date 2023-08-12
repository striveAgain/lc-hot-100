### 算法，时间复杂度 $O(n)$

维护可以到达的最远距离 `maxdis`，若 `maxdis >= n - 1`，则说明可以到达；

### C++ 代码
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxdis = 0;
        for (int i = 0; i < n; ++i) {
            if (i > maxdis) {
                return false;
            }

            maxdis = max(maxdis, i + nums[i]);
        }

        return true;
    }
};
```
