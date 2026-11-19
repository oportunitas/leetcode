// Created by oportunitas at 2026/11/19 15:54
// leetgo: 1.4.18
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 15.6MB/99th%)
        we can use a stack to convert preorder traversal to bst format,
        and the implementation is pretty self-explanatory
    */
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<TreeNode*> node_stack;

        TreeNode* root = nullptr;
        for (const auto& val : preorder) {
            TreeNode* new_node = new TreeNode();
            new_node->val = val;

            if (node_stack.empty()) {
                root = new_node;
            } else {
                TreeNode* parent = nullptr;
                while (!node_stack.empty() && node_stack.back()->val < val) {
                    parent = node_stack.back();
                    node_stack.pop_back();
                }

                if (parent != nullptr) {
                    parent->right = new_node;
                } else {
                    node_stack.back()->left = new_node;
                }
            } node_stack.push_back(new_node);
        }

        return root;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> preorder = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.bstFromPreorder(preorder);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
