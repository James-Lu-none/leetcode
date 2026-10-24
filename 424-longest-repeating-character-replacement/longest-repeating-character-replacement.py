class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        result = 0
        left = 0
        largest_freq = 0
        freq = {}
        for right in range(len(s)):
            curr_char = s[right]
            freq[curr_char] = freq.get(curr_char, 0) + 1
            # only curr_char freq will change
            largest_freq = max(largest_freq, freq[curr_char])

            while (right-left+1) > (largest_freq+k):
                freq[s[left]]-=1
                left+=1

            result = max(result, right-left+1)
        return result