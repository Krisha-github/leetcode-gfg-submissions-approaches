class Solution {
    public int longestStrChain(String[] words) {
        //sort the array in increasing order of length of words
    Arrays.sort(words, (a,b)->a.length()-b.length());
    int[] dp = new int[words.length];
    int maxLen = 0;
        //logic similar to longest increasing sequence (LIS) problem
    for (int i = 0; i < words.length; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            //since the words in the string array are in increasing order of length, all we need to check is the difference of length is equal to 1 (only one letter can be added) and check the sequence of existing characters in both the strings.
            if (words[i].length() - words[j].length() == 1 && isPredecessor(words[j], words[i]) ) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
        maxLen = Math.max(maxLen, dp[i]);
    }
    return maxLen;
}

 private boolean isPredecessor(String s1, String s2) {
    int diff = 0;
    for (int i = 0, j = 0; i < s1.length(); ) {
        //keep incrementing i and j if both chars are same in both strings
        if (s1.charAt(i) == s2.charAt(j)) {
            i++;
            j++;
        } 
        else {
            diff++;
            //diff counts the number of different characters in two strings for the same indices
            if (diff > 1) return false;
            j++;
        }
    }
    return true;
}
}