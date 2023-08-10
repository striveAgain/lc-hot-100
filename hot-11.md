### 算法，时间复杂度 $O(n)$

采用双指针，但是这里的双指针不同于一般的双指针在于初始在首尾设置两个指针，而不是一般的都从开头开始遍历；

#### 思路

开始在首尾设置两个指针 `l` 和 `r`，假设 `height[l] < height[r]`，此时的容量为 `(r - l) * height[l]`，因此向左移动 `r` 只会让答案减小（要么 `height[l]` 变得更小，要么 `r - l` 变小），故此时不能移动右指针；

因此可以移动左指针，且跳过那些比 `height[l]` 小的值，才有可能使得答案变大；

**木桶效应：只有让最短的木板延长了，才能增加整个木桶的容量**

### C++ 代码
```c++
int maxArea(vector<int>& height) {
    int n = height.size(), ans = -1;
    
    int l = 0, r = n - 1;
    while (l < r) {
        ans = max(ans, (r - l) * min(height[l], height[r]));
        
        int tmp = (height[l] <= height[r]) ? l : r;
        if (tmp == l) {
            int rec = height[l];
            while (height[l] <= rec && l < r) {
                ++l;
            }
        } else {
            int rec = height[r];
            while (height[r] <= rec && l < r) {
                --r;
            }
        }
    }
    
    return ans;
}
```

---

简洁版：
```c++
int maxArea(vector<int>& height) {
    int n = height.size(), ans = -1;
    
    int l = 0, r = n - 1;
    while (l < r) {
        ans = max(ans, (r - l) * min(height[l], height[r]));

        (height[l] <= height[r]) ? ++l : --r;
    }
    
    return ans;
}
```
