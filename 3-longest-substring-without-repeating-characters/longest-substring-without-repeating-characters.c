int max(int a, int b) {
    return (a>b)?a:b;
}

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if(n==0) return 0;
    if(n==1) return 1;
    int freq[256] = {0};
    int left = 0;
    int right = 0;
    int result = 1;
    
    while(right<n){
        char c = s[right];
        freq[c]++;
        while (freq[c]>1) {
            // shrink untill no duplicate
            freq[s[left]]--;
            left++;
        }
        int current_len = right-left+1;
        result = max(result, current_len);
        right++;
    }
    return result;


}