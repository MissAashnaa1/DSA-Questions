class Solution {
    long long int most_k_chars(vector<int> &s, int k)
{
    if (s.size() == 0) {
        return 0;
    }
    unordered_map<int, int> map;
    long long int num = 0, left = 0;
 
    for (int i = 0; i < s.size(); i++) {
        map[s[i]]++;
        while (map.size() > k) {
            map[s[left]]--;
            if (map[s[left]] == 0) {
                map.erase(s[left]);
            }
            left++;
        }
        num += i - left + 1;

    }
    return num;
}
public:
    int subarraysWithKDistinct(vector<int>& s, int k) {
        
        return most_k_chars(s, k) - most_k_chars(s, k - 1);
    }
};