# Created by oportunitas at 2026/10/22 09:58
# leetgo: 1.4.18
# https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def minOperations(self, n: List[int]) -> int:
        l=len(n);s=sum(b:=[n[i]>n[i-1]for i in range(l)]);return-(1<s<l-1)or min(i:=b.index(c:=s<l-1),l-i+2-2*c)+c

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().minOperations(nums)
    print("\noutput:", serialize(ans, "integer"))
