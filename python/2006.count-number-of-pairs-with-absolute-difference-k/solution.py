# Created by oportunitas at 2026/10/15 10:56
# leetgo: 1.4.18
# https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

from typing import *
from leetgo_py import *

# @lc code=begin
from itertools import combinations as c

class Solution:
    def countKDifference(self, n: list[int], k: int) -> int:
        return sum(abs(i-j)==k for i,j in c(n,2))

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    k: int = deserialize("int", read_line())
    ans = Solution().countKDifference(nums, k)
    print("\noutput:", serialize(ans, "integer"))
