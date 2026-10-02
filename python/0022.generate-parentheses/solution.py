# Created by oportunitas at 2026/10/02 10:33
# leetgo: 1.4.18
# https://leetcode.com/problems/generate-parentheses/

from typing import *
from leetgo_py import *

# @lc code=begin

''' idea #0 (2ms/35th% | 19.4MB/75th%)
    in python, we can always look at things better as a list.

    an interesting idea is to have a general description of what a valid
    string is as a recursive array definition, not function calls.

    in the cpp implementation, the definition is:
        - a sequence of open and closing brackets, where in each place of the
          string, the amount of closing bracket before it never exceeds the 
          amount of opening bracket, and eventually must have the same number
          of open and close brackets
    this is a 'procedural/dp-ish' definition.

    now, we can define the same thing as an 'object-ish/afterthought' definition, as such:
        assume A is a valid string of length 6.
        A can be defined as:
            '(' + X + ')' + Y
        in which X and Y is a valid string, where the length of X and Y is equal to 4. or:
            X + '(' + Y + ')'
        
        however, notice that the definition of A may also be used to define X or Y, but
        instead of starting with 6 and constraining to 4, we start at 4 and constraining to 2.
    nice! we have found a way to generally define a valid string as a object instead of a series
    of instructions.
'''
class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        return [x + '(' + y + ')'
                for i in range(n) 
                for x in self.generateParenthesis(i) 
                for y in self.generateParenthesis(n - 1 - i)] or ['']

# @lc code=end

if __name__ == "__main__":
    n: int = deserialize("int", read_line())
    ans = Solution().generateParenthesis(n)
    print("\noutput:", serialize(ans, "string[]"))
