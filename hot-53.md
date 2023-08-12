### 算法一：DP，时间复杂度 $O(n)$，空间复杂度 $O(n)$

#### 状态表示

##### 集合

`dp[i]` -- 以 `nums[i]` 结尾的所有连续子数组；

##### 属性

`Max`

#### 状态计算

##### 初始状态

数组中的所有元素自成一段，即 `dp[i] = nums[i]`；

##### 状态转移

`dp[i]` 的计算有两种方式，一种是自成一段，一种是加入到以 `nums[i - 1]` 结尾的连续子数组中去，即 `dp[i] = max(dp[i], dp[i - 1] + nums[i])`；

### C++ 代码
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
	
        for (int i = 1; i < n; ++i) {
            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
        }
        
        return *max_element(nums.begin(), nums.end());
    }
};
```

---

### 算法二：分治，时间复杂度 $O(n)$ (遍历所有节点)，空间复杂度 $O(\log n)$

`get(nums, l, r)` -- 求 `nums` 数组中区间 `[l, r]` 中的最大子数组和；

采用二分的思想，可以将 `[l, r]` 分成 `[l, l + r >> 1]` 和 `[(l + r >> 1) + 1, r]`；

过程中需要维护 4 个量：

`lsum` -- 以 `nums[l]` 为左端点的最大区间和；

`rsum` -- 以 `nums[r]` 为左端点的最大区间和；

`msum` -- `[l, r]` 中的最大区间和；

`isum` -- `[l, r]` 中所有数的和；

左子区间 `lst` 和右子区间 `rst` 合并时：

`int lsum = max(lst.lsum, lst.isum + rst.lsum);`

`int rsum = max(rst.rsum, rst.isum + lst.rsum);`

`int msum = max(max(l.msum, r.msum), l.rsum + r.lsum);`

`int isum = lst.isum + rst.isum;`

### C++ 代码
```c++
class Solution {
public:
    struct st {
        int lsum, rsum, msum, isum;
    };

    st pushup(st l, st r) {
        int lsum = max(l.lsum, l.isum + r.lsum);
        int rsum = max(r.rsum, r.isum + l.rsum);
        int msum = max(max(l.msum, r.msum), l.rsum + r.lsum);
        int isum = l.isum + r.isum;
        
        return {lsum, rsum, msum, isum};
    }

    st get(vector<int>& nums, int l, int r) {
        if (l == r) {
            return {nums[l], nums[l], nums[l], nums[l]};
        }
        
        int m = l + r >> 1;
        st lst = get(nums, l, m);
        st rst = get(nums, m + 1, r);
        
        return pushup(lst, rst);
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
	    return get(nums, 0, n - 1).msum;
    }
};
```
