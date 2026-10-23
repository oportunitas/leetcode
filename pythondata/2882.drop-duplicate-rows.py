# Created by oportunitas at 2026/10/23 16:58
# leetgo: 1.4.18
# https://leetcode.com/problems/drop-duplicate-rows/

# @lc code=begin

import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates(subset='email', keep='first')
    
# @lc code=end
