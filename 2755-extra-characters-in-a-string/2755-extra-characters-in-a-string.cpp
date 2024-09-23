class Solution {
public:
    int traverseString(int index, string &s, int cnt, unordered_set<string>& us, int &ans, vector<int>& dp) {

        if (cnt > ans)
            return s.size() + 1;

        if (index == s.size()) {
            ans = min(ans, cnt);
            return 0;
        }

        if (dp[index] != s.size() + 2)
            return dp[index];

        for (string it : us) {
            int len = it.size();
            string nxt = s.substr(index, len);
            
            if (nxt == it) {
                dp[index] = min(dp[index], traverseString(index + len, s, cnt, us, ans, dp));
            }
        }

        dp[index] = min(dp[index], 1 + traverseString(index + 1, s, cnt + 1, us, ans, dp));

        return dp[index];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> us;
        int len = s.size();
        vector<int> dp(len, len + 2);
        int n = dictionary.size();

        for (int i = 0; i < n; i++) {
            us.insert(dictionary[i]);
        }

        int ans = INT_MAX;

        traverseString(0, s, 0, us, ans, dp);

        return min(dp[0], ans);
    }
};