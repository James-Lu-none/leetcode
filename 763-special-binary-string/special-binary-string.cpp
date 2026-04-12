class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> res;
        
        for (int j = 0; j < s.length(); j++) {
            count += (s[j] == '1') ? 1 : -1;
            // A sub binary string s[i..j] from s will that fullfill this if statement (count==0) has following property
            // 1. it must start with 1 and end with 0 (since prefix sum of 1s must > 0s && it has as many 1 as 0)
            // 2. you can't find two consecutive special substring in s[i..j], since if there are, then s[i..k] | k<j will be the sub string instead
            if (count == 0) {
                // Recursively maximize inner part, wrap with 1...0
                res.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1; // set next chunk start index i
            }
        }
        
        // Return the lexicographically largest resulting string
        sort(res.begin(), res.end(), greater<string>());
        
        string result;
        for (const string& str : res) {
            result += str;
        }
        return result;
    }
};