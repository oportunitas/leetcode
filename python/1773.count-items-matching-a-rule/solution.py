# Created by oportunitas at 2026/10/19 14:13
# leetgo: 1.4.18
# https://leetcode.com/problems/count-items-matching-a-rule/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def countMatches(self, it: list[list[str]], k: str, v: str) -> int:
        m={"type":0,"color":1,"name":2};return sum(i[m[k]]==v for i in it)

# @lc code=end

if __name__ == "__main__":
    items: List[List[str]] = deserialize("List[List[str]]", read_line())
    ruleKey: str = deserialize("str", read_line())
    ruleValue: str = deserialize("str", read_line())
    ans = Solution().countMatches(items, ruleKey, ruleValue)
    print("\noutput:", serialize(ans, "integer"))
