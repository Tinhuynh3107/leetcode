int lengthOfLongestSubstring(char* s) {
    int map[256];
    for(int i = 0; i < 256; i++) map[i] = -1;

    int maxlen = 0;
    int left = 0;

    for(int right = 0; s[right]; right++){
        if(map[s[right]] >= left){
            left = map[s[right]] + 1;
        }

        map[s[right]] = right;

        int len = right - left + 1;
        if(len > maxlen) maxlen = len;
    }
    return maxlen;
}