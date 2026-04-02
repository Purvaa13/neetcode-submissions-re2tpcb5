class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string word : strs) {
        string temp = word;          // make a copy
        sort(temp.begin(), temp.end());  // sort the copy
        mp[temp].push_back(word);    // group original word
    }

    vector<vector<string>> result;

    for (auto it : mp) {
        result.push_back(it.second); // take only values
    }

    return result;
}
};
