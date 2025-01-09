class Solution {
    public int prefixCount(String[] words, String pref) {
        int ans = 0;
        for(String x: words){
            if(x.startsWith(pref)) ans++;
        }
        return ans;
    }
}