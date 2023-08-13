### 算法

#### 状态表示

##### 集合

`dp[i]` -- 节点数为 `i` 的所有二叉搜索树

##### 属性

`数量`

#### 状态计算

##### 初始状态

`dp[0] = 1, dp[1] = 1`；

##### 状态转移

节点数为 `i` 的所有二叉搜索树数量等于以 `k` 为根节点，左子树节点数为 `k - 1` 的二叉搜索树数量，右子树节点数为 `i - k` 的二叉搜索树数量的乘积；

`dp[i] += dp[k - 1] * dp[i - k]`

### C++ 代码
```c++
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};
```
