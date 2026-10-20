# Created by oportunitas at 2026/10/20 18:09
# leetgo: 1.4.18
# https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def minimumAverage(self, n: List[int]) -> float:
        return min(map(sum,zip(s:=sorted(n),s[::-1])))/2

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().minimumAverage(nums)
    print("\noutput:", serialize(ans, "double"))
