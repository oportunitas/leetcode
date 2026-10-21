# Created by oportunitas at 2026/10/21 08:21
# leetgo: 1.4.18
# https://leetcode.com/problems/minimum-operations-to-sort-a-string/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def minOperations(self, s: str) -> int:
        i,a=min(s),max(s);return 0 if[*s]==sorted(s)else-1 if len(s)<3 else 1 if i==s[0]or a==s[-1]else 3-(i in(c:=s[1:-1])or a in c)

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().minOperations(s)
    print("\noutput:", serialize(ans, "integer"))
