# Created by oportunitas at 2026/10/18 10:19
# leetgo: 1.4.18
# https://leetcode.com/problems/minimum-interval-selection-to-cover-target-intervals/
# https://leetcode.com/contest/weekly-contest-524/problems/minimum-interval-selection-to-cover-target-intervals/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def minSelection(self, availableIntervals: List[List[int]], targetIntervals: List[List[int]]) -> int:
        

# @lc code=end

if __name__ == "__main__":
    availableIntervals: List[List[int]] = deserialize("List[List[int]]", read_line())
    targetIntervals: List[List[int]] = deserialize("List[List[int]]", read_line())
    ans = Solution().minSelection(availableIntervals, targetIntervals)
    print("\noutput:", serialize(ans, "integer"))
