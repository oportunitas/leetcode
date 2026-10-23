# Created by oportunitas at 2026/10/23 16:40
# leetgo: 1.4.18
# https://leetcode.com/problems/maximum-k-to-sort-a-permutation/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def sortPermutation(self, a: List[int]) -> int:
        return max(0,[k:=-1,*(k:=k&n for i,n in enumerate(a)if n^i)]and k)

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().sortPermutation(nums)
    print("\noutput:", serialize(ans, "integer"))
