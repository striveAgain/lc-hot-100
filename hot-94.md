### 算法一：递归，时间复杂度 $O(n)$，空间复杂度 $O(n)$

经典的中序遍历二叉树问题，采用递归实现即可；

### C++ 代码
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode *root, vector<int>& ans) {
        if (!root) {
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);

        return ans;
    }
};
```

---

### 算法二：栈模拟，时间复杂度 $O(n)$，空间复杂度 $O(n)$

先一直往左走，并将遍历到的节点入栈，然后取栈顶节点，将该节点的值加入答案后对它的右子树作同样的处理即可；

### C++ 代码
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            ans.push_back(root->val);
            root = root->right;
        }
    }
};
```

---

### 算法三：利用线索树进行中序遍历，时间复杂度 $O(n)$，空间复杂度 $O(1)$

* 如果 `x` 无左孩子，直接将 `x->val` 加入答案，然后处理 `x` 的右孩子；
* 如果 `x` 有左孩子，记 `predecessor` 为中序序列中 `x` 的前驱，即 `x` 的左子树中最右边的节点
  * 如果 `predecessor` 的右孩子为空，则将 `predecessor->right` 指向 `x`，表示处理完 `x` 左子树的最右节点后直接回到 `x`；然后处理 `x` 的左子树；
  * 如果 `predecessor` 的右孩子不为空，此时 `predecessor->right == x`，说明已经处理完了左子树，因此 `predecessor->right = nullptr` 来断开这条链，将 `x->val` 加入答案，然后处理 `x` 的右子树；
* 重复上述步骤直接访问完整棵树；

### C++ 代码
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *predecessor = nullptr;

        while (root) {
            if (root->left) {
                predecessor = root->left;
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    ans.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
                ans.push_back(root->val);
                root = root->right;
            }
        }

        return ans;
    }
};
```

---

### 拓展：前序遍历的三种实现

#### 递归
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *predecessor = nullptr;

        while (root) {
            if (root->left) {
                predecessor = root->left;
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    ans.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
                ans.push_back(root->val);
                root = root->right;
            }
        }

        return ans;
    }
};
```

#### 栈模拟
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                ans.push_back(root->val);
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            root = root->right;
        }

        return ans;
    }
};
```

#### 线索数前序遍历
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        TreeNode *predecessor = nullptr;
        while (root) {
            predecessor = root->left;
            if (predecessor) {
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    ans.push_back(root->val);
                    predecessor->right = root;
                    root = root->left;
                } else {
                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
                ans.push_back(root->val);
                root = root->right;
            }
        }

        return ans;
    }
};
```

---

### 拓展：后序遍历的三种实现

#### 递归
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postorder(TreeNode *root, vector<int>& ans) {
        if (!root) {
            return;
        }

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);

        return ans;
    }
};
```

#### 栈模拟
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> st;
        TreeNode *prev = nullptr;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            if (!root->right || root->right == prev) {
                ans.push_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                st.push(root);
                root = root->right;
            }
        }

        return ans;
    }
};
```

#### 线索数后序遍历
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void addPath(vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.emplace_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                    addPath(res, p1->left);
                }
            }
            p1 = p1->right;
        }
        addPath(res, root);
        return res;
    }
};
```
