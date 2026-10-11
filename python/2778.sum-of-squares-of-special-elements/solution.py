# Created by oportunitas at 2026/10/11 12:10
# leetgo: 1.4.18
# https://leetcode.com/problems/sum-of-squares-of-special-elements/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19MB/98th%)
        we go golf
    '''
    def sumOfSquares(self, nums: List[int]) -> int:
        return sum(n*n for i,n in enumerate(nums)if len(nums)%(i+1)<1)

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().sumOfSquares(nums)
    print("\noutput:", serialize(ans, "integer"))
