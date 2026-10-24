class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        result = 0
        left = 0
        freq = {}
        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right], 0) + 1
            while True:
                key, value = max(freq.items(), key=lambda x: x[1])
                if (right-left+1) > (value+k):
                    freq[s[left]]-=1
                    left+=1
                else:
                    result = max(result, right-left+1) 
                    break
        return result