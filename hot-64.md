### 算法，时间复杂度 $O(mn)$

#### 状态表示

`dp[i][[j]` -- 从 `(0, 0)` 到 `(i, j)` 的最小路径总和；

#### 状态计算

##### 初始状态

`dp[0][0] = grid[0][0]`，其他全部初始化为极大值；

##### 状态转移

`dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]`

**注意判断 `i - 1` 和 `j - 1` 的有效性！**

### C++ 代码
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int> > dp(m, vector<int>(n, 1e9));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= 1) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                }

                if (j >= 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
```
