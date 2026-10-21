# Created by oportunitas at 2026/10/21 08:43
# leetgo: 1.4.18
# https://leetcode.com/problems/to-lower-case/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def toLowerCase(self, s: str) -> str:
        return s.lower()

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().toLowerCase(s)
    print("\noutput:", serialize(ans, "string"))
