class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = {}
        for s in strs:
            freq = [0]*26
            for c in s:
                freq[ord(c)-97]+=1
            k = tuple(freq)

            if k not in d:
                d[k] = []
            d[k].append(s)
        result = []
        for key, value in d.items():
            result.append(value)
        return result
