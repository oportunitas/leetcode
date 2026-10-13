# Created by oportunitas at 2026/10/13 08:38
# leetgo: 1.4.18
# https://leetcode.com/problems/maximum-alternating-sum-of-squares/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (137ms/97th% | 32.7MB/52th%)
        we go golf
    '''
    def maxAlternatingSum(self, n: List[int]) -> int:
        return sum((N:=sorted([_**2 for _ in n]))[len(n)//2:])-sum(N[:len(n)//2])

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().maxAlternatingSum(nums)
    print("\noutput:", serialize(ans, "long"))
