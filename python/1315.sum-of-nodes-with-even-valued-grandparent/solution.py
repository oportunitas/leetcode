# Created by oportunitas at 2026/10/10 06:22
# leetgo: 1.4.18
# https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

from typing import *
from leetgo_py import *

# @lc code=begin

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

''' idea #0 (11ms/34th% | 22.2MB/67th%)
    we go golfing
    
    t: tree (as list)
    s: sum

    [n,p,g]: [node, parent, grandparent]
    [c,n.val,p]: [child, node.val, parent]
'''
class Solution:
    def sumEvenGrandparent(self, root: TreeNode | None) -> int:
        t,s=[[root,-1,-1]],0
        for n,p,g in t:s+=n.val*(g%2<1);t+=[[c,n.val,p]for c in(n.left,n.right)if c]
        return s
        

# @lc code=end

if __name__ == "__main__":
    root: TreeNode = deserialize("TreeNode", read_line())
    ans = Solution().sumEvenGrandparent(root)
    print("\noutput:", serialize(ans, "integer"))
