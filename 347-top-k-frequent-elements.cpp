// inline bool operator<(const pair<int, int>& a, const pair<int, int>& b){
//     return a.second < b.second;
// }
// failed to overload a std::less() function 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq_map;
        
        for(size_t i = 0; i < nums.size(); ++i){
            freq_map[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq_freqent_k;
        
        for(auto ele : freq_map)
            pq_freqent_k.push(pair<int, int>(ele.second, ele.first)); // kind of tricky here by ultilizing the logic in std::less() of pair<int, int>.
        
        for(size_t i = 0; i < k; ++i){
            result.push_back(pq_freqent_k.top().second);
            pq_freqent_k.pop();
        }
        return result;
    }
};