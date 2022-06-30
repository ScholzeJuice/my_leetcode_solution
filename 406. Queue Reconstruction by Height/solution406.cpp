class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        map<int, vector<int>> mmp;
        for(const auto&ele:people)
            mmp[ele[0]].push_back(ele[1]);
        for(auto &ele:mmp)
            sort(ele.second.begin(), ele.second.end());
        vector<vector<int>> res;
        int n = people.size();
        people.clear();
        res.resize(n);
        list<int> pos;
        for(int i=0; i<n; i++)
            pos.push_back(i);
        for(const auto& vec:mmp){
            vector<vector<int>::iterator> cal;
            for(auto &num:vec.second){
                auto iter = pos.begin();
                advance(iter, num);
                res[*iter] = {vec.first, num};
            }
            int i= 0;
            for(auto &num:vec.second){
                auto iter = pos.begin();
                advance(iter, num-i);
                i++;
                pos.erase(iter);
            }
        }
        return res;
    }
};
