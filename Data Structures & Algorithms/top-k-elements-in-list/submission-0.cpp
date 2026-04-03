class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    // Step 1: count frequency
    for (int num : nums) {
        mp[num]++;
    }

    // Min heap (freq, element)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // Step 2: push into heap
    for (auto it : mp) {
        pq.push({it.second, it.first});

        if (pq.size() > k) {
            pq.pop(); // remove smallest freq
        }
    }

    // Step 3: get result
    vector<int> result;

    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}
    
};
