# Created by oportunitas at 2026/10/15 09:10
# leetgo: 1.4.18
# https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

from typing import *
from leetgo_py import *

# @lc code=begin
from itertools import combinations as c
import numpy as np
import sys

class Solution:
    def sumCounts(self, n: List[int]) -> int:
        return sum(len(set(n[r:l]))**2 for r,l in c(range(len(n)+1),2))

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().sumCounts(nums)
    print("\noutput:", serialize(ans, "integer"))
