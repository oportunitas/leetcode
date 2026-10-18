# Created by oportunitas at 2026/10/18 10:19
# leetgo: 1.4.18
# https://leetcode.com/problems/find-root-of-a-colored-tree/
# https://leetcode.com/contest/weekly-contest-524/problems/find-root-of-a-colored-tree/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def findColoredRoot(self, edges: list[list[int]], colors: str) -> int:
        

# @lc code=end

if __name__ == "__main__":
    edges: List[List[int]] = deserialize("List[List[int]]", read_line())
    colors: str = deserialize("str", read_line())
    ans = Solution().findColoredRoot(edges, colors)
    print("\noutput:", serialize(ans, "integer"))
