// Created by oportunitas at 2026/10/12 08:24
// leetgo: 1.4.18
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (357ms/92th% | 167.7MB/58th%)
        we can use recursion here
    */
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return nullptr;
        } 
        if (cloned->val == target->val) {
            return cloned;
        }

        TreeNode* left {getTargetCopy(original->left, cloned->left, target)};
        if (left != nullptr) return left;

        TreeNode* right {getTargetCopy(original->right, cloned->right, target)};
        if (right != nullptr) return right;

        return nullptr;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* tree = LeetCodeIO::deserialize<TreeNode*>(cin);
        TreeNode* clone = LeetCodeIO::deserialize<TreeNode*>(cin);
		int target = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.getTargetCopy(tree, clone, target);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
