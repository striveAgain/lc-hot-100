### 算法

经典的 DFS，但是需要注意每个数可以取多次，需要用 `cnt` 来控制当前取的数。

**先递归重复取一个数到极限，然后开始回溯，通过 `cnt + 1` 来取下一个数！！！**

### C++ 代码
```c++
class Solution {
    vector<int> rec;
public:
    void dfs(vector<int>& nums, int target, vector<vector<int> >& ans, int cnt, int cur) {
        if (cur == target) {
            ans.push_back(rec);
            return;
        }
        
        if (cnt == nums.size()) {
            return;
        }

        if (cur > target) {
            return;
        }
        
        rec.push_back(nums[cnt]);
        dfs(nums, target, ans, cnt, cur + nums[cnt]);
        
        rec.pop_back();
        dfs(nums, target, ans, cnt + 1, cur);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        dfs(candidates, target, ans, 0, 0);
        
        return ans;
    }
};
```
