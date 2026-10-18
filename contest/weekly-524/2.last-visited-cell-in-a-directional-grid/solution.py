# Created by oportunitas at 2026/10/18 10:19
# leetgo: 1.4.18
# https://leetcode.com/problems/last-visited-cell-in-a-directional-grid/
# https://leetcode.com/contest/weekly-contest-524/problems/last-visited-cell-in-a-directional-grid/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def lastVisitedCell(self, grid: list[list[str]]) -> list[int]:
        

# @lc code=end

if __name__ == "__main__":
    grid: List[List[str]] = deserialize("List[List[str]]", read_line())
    ans = Solution().lastVisitedCell(grid)
    print("\noutput:", serialize(ans, "integer[]"))
