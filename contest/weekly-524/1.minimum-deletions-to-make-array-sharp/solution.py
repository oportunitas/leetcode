# Created by oportunitas at 2026/10/18 10:19
# leetgo: 1.4.18
# https://leetcode.com/problems/minimum-deletions-to-make-array-sharp/
# https://leetcode.com/contest/weekly-contest-524/problems/minimum-deletions-to-make-array-sharp/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def minDeletions(self, nums: list[int]) -> int:
        

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().minDeletions(nums)
    print("\noutput:", serialize(ans, "integer"))
