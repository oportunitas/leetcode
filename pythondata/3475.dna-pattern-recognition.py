# Created by oportunitas at 2026/10/19 08:26
# leetgo: 1.4.18
# https://leetcode.com/problems/dna-pattern-recognition/

# @lc code=begin

import pandas as pd

def analyze_dna_patterns(samples: pd.DataFrame) -> pd.DataFrame:
    patterns = {
        'has_start': r'^ATG',
        'has_stop' : r'T(A[AG]|GA)$',
        'has_atat' : r'ATAT',
        'has_ggg'  : r'GGG'}
    samples = samples.assign(**{
        column_name: samples['dna_sequence'].str.contains(pattern, regex=True) 
        for column_name, pattern in patterns.items()})
    return samples

# @lc code=end
