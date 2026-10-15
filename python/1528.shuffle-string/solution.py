# Created by oportunitas at 2026/10/15 10:00
# leetgo: 1.4.18
# https://leetcode.com/problems/shuffle-string/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def restoreString(self, s: str, i: list[int]) -> str:
        return ''.join(c for _,c in sorted(zip(i,s)))

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    indices: List[int] = deserialize("List[int]", read_line())
    ans = Solution().restoreString(s, indices)
    print("\noutput:", serialize(ans, "string"))
