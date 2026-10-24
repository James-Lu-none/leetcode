class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        freq = {0: 1} # sum 0 has 1 result: select nothing
        sum = 0
        result = 0
        for num in nums:
            sum += num
            result += freq.get(sum-k, 0)
            freq[sum] = freq.get(sum, 0) + 1
        return result

        