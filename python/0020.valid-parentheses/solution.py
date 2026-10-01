# Created by oportunitas at 2026/10/01 07:31
# leetgo: 1.4.18
# https://leetcode.com/problems/valid-parentheses/

from typing import *
from leetgo_py import *

# @lc code=begin

class Solution:
    """ idea #0
        (fyi, this is the first python code i submit in leetcode)

        we use python for its zen, and its rapid prototyping/coding speed. therefore, we shall
        not use the default for loop as a way to learn python (because in that sense, why not
        use cpp anyway?)

        so in this implementation, i try to use python's all() method. this is a more zen
        way of looping through something, until we find an exception, then we break and stop
        the loop completely.

        in this sense, whenever we want the loop to continue, we set its value as 1
        (i.e.: `stack.append(c) or True`), this appends 1 to the list.

        whenever we want the loop to break, we set its value to 0
        (i.e.: stack and stack.pop() == map[c] will only evaluate to 0 if either condition
        fails {stack is empty or the last character of the opening bracket stack does not
        match the closing bracket})

        in python, its nice to look at everything as an array/list. and we're rewarded here by
        doing so. using the all() method should stop calculation whenever there's the 0 condition,
        since this method is used to find if all the elements of a list is truthy.
    """
    def isValid(self, s: str) -> bool:
        stack, map = [], {')': '(', '}': '{', ']': '['}
        return all(
            stack.append(c) or True if c in map.values() else stack and stack.pop() == map[c] 
            for c in s) and not stack

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().isValid(s)
    print("\noutput:", serialize(ans, "boolean"))
