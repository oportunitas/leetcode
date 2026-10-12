# Created by oportunitas at 2026/10/12 08:44
# leetgo: 1.4.18
# https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

from typing import *
from leetgo_py import *

# @lc code=begin

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    ''' idea #0 (281ms/88th% | 26.9MB/73th%)
        we go golf, (at least as far as we can because the function name is long)
        the implementation itself is based on the c++ implementation
    '''
    def getTargetCopy(self, o: TreeNode, c: TreeNode, t: TreeNode) -> TreeNode:
        # if c and () is falsy, it evaluates to c, else it evaluates to ()
        return c and (
            c if t.val==c.val else 
            self.getTargetCopy(o.left,c.left,t)or self.getTargetCopy(o.right,c.right,t)
        )

# @lc code=end

# Warning: this is a manual question, the generated test code may be incorrect.
if __name__ == "__main__":
    tree: TreeNode = deserialize("TreeNode", read_line())
    target: int = deserialize("int", read_line())
    ans = Solution().getTargetCopy(tree, target)
    print("\noutput:", serialize(ans, "TreeNode"))
