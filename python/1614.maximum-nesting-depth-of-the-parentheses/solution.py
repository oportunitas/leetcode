# Created by oportunitas at 2026/10/06 10:39
# leetgo: 1.4.18
# https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    ''' idea #0 (0ms/100th% | 19.2MB/84th%)
        we golf
    '''
    def maxDepth(self, s: str) -> int:
        return max(d for i, c in enumerate(s) if [
            d := (d if i else 0) + (1 if c == '(' else -1 if c == ')' else 0)])

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().maxDepth(s)
    print("\noutput:", serialize(ans, "integer"))
