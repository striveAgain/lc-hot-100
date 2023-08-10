### 算法，时间复杂度 $O(n^2)$

为了使用双指针算法，因此首先对数据进行排序；
然后，由于有 `i, j, k` 三个指针，采用定一移二的思路，先定 `i`，然后在剩下的部分里面采用双指针算法来确定 `j, k`；

### C++ 代码
```c++
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());
    
    if (nums.front() > 0 || nums.back() < 0) {
        return ans;
    }
    
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i) {
        if (i && nums[i] == nums[i - 1]) {
            continue;
        }
        
        for (int j = i + 1, k = n - 1; j < n - 1; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            
            int sum = nums[i] + nums[j] + nums[k];
            while (k > j && sum > 0) {
                --k;
                sum = nums[i] + nums[j] + nums[k];
            }
            
            if (k <= j) {
                break;
            }
            
            if (!sum) {
                ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
    }
    
    return ans;
}
```
