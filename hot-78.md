### 算法一：DFS，时间复杂度 $O(2^n)$

经典的 DFS 求子集；

### C++ 代码
```c++
class Solution {
    vector<int> rec;
public:
    void dfs(vector<int>& nums, int n, vector<vector<int> >& ans, int cnt) {
        if (cnt == n) {
            ans.push_back(rec);
            return;
        }

        rec.push_back(nums[cnt]);
        dfs(nums, n, ans, cnt + 1);

        rec.pop_back();
        dfs(nums, n, ans, cnt + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ans;

        dfs(nums, n, ans, 0);
        return ans;
    }
};
```

---

### 算法二：二进制枚举，时间复杂度 $O(n \times 2^n)$

对应的二进制位为 `0` 表示不选择这个数，二进制位为 `1` 表示选择这个数；

```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
    
        vector<vector<int> > ans;
        for (int i = 0; i < 1 << n; ++i) {
            vector<int> tmp;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    tmp.push_back(nums[j]);
                }
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
```
