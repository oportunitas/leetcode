// Created by oportunitas at 2026/09/25 10:36
// leetgo: 1.4.18
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 77.1MB/77%th)
        this is the recursion alternative
    */
    void swap_values(TreeNode* a, TreeNode* b, int level) {
        if (a == nullptr || b == nullptr) return;

        if (level % 2 == 1) {
            swap(a->val, b->val);
        }

        swap_values(a->right, b->left, level + 1);
        swap_values(a->left, b->right, level + 1);

        return;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        swap_values(root->left, root->right, 1);
        return root;
    }

    // /* idea #0 (0ms/100th% | 77MB/90th%)
    //     in this implementation, we serialize the tree one level at a time to an array,
    //     and flip values when in odd levels. this implementation does not use recursion, which
    //     imo is always nice. there would be time taken in initializing the huge array at the start
    //     though.
    // */
    // TreeNode* reverseOddLevels(TreeNode* root) {
    //     const int64_t max_level {14};
    //     array<TreeNode*, (size_t)(1 << max_level)> cur_level_node {nullptr};
    //     cur_level_node[0] = root;
    //     int64_t cur_level {0};

    //     while (cur_level < max_level) {
    //         int64_t step {1 << (max_level - cur_level)};

    //         // swap nodes in odd rows
    //         if (cur_level % 2 == 1) {
    //             int64_t l {0};
    //             for (int64_t i {0}; i < (1 << (max_level - 1)); i += step) {
    //                 swap(
    //                     cur_level_node[i]->val, 
    //                     cur_level_node[(1 << max_level) - ((1 + l) * step)]->val
    //                 );
    //                 l += 1;
    //             }
    //         }

    //         // add in the next row
    //         for (int64_t i {0}; i < (1 << max_level); i += step) {
    //             cur_level_node[i + (step >> 1)] = cur_level_node[i]->right;
    //             cur_level_node[i] = cur_level_node[i]->left;
    //             if (i == 0 && cur_level_node[i] == nullptr) goto finally_state;
    //         } 

    //         cur_level += 1;
    //     }

    // finally_state:
    //     return root;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.reverseOddLevels(root);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
