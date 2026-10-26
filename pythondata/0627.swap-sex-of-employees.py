# Created by oportunitas at 2026/10/26 16:47
# leetgo: 1.4.18
# https://leetcode.com/problems/swap-sex-of-employees/

# @lc code=begin

import pandas as pd

def swap_salary(salary: pd.DataFrame) -> pd.DataFrame:
    salary['sex'] = salary['sex'].map({'f': 'm', 'm': 'f'})
    return salary
    

# @lc code=end
