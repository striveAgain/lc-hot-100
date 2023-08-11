### 算法，时间复杂度 $O(n!)$

经典的全排列 `DFS` 问题；

### C++ 代码
```c++
class Solution {
    vector<int> path;
    vector<bool> vis;
public:
    void dfs(vector<int>& nums, int n, int cnt, vector<vector<int> >& ans) {
        if (cnt == n) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                path[cnt] = nums[i];

                vis[i] = true;
                dfs(nums, n, cnt + 1, ans);
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ans;

        path.resize(n, 0), vis.resize(n, false);

        dfs(nums, n, 0, ans);

        return ans;
    }
};
```
