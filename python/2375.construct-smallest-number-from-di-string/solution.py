# Created by oportunitas at 2026/10/19 13:55
# leetgo: 1.4.18
# https://leetcode.com/problems/construct-smallest-number-from-di-string/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    def smallestNumber(self, p: str) -> str:
        l=[str(len(p)+1)]
        for i in range(len(p))[::-1]:l[:0]=['']*(p[i]=='I');l[0]+=str(i+1)
        return''.join(l)


# @lc code=end

if __name__ == "__main__":
    pattern: str = deserialize("str", read_line())
    ans = Solution().smallestNumber(pattern)
    print("\noutput:", serialize(ans, "string"))
