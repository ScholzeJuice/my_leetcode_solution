class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> indg(num, 0);
        unordered_map<int,vector<int>> ht;
    //indegree & hash_table
        for(const auto& ele:pre){
            indg[ele[0]]++;
            ht[ele[1]].push_back(ele[0]);
        }
    //queue for nodes whose indegree is 0
        queue<int> que;
        for(int i=0; i<indg.size(); i++){
            if(indg[i]==0)
                que.push(i);
        }
    //cnt: the number of nodes that will have 0 indegree in the end 
        int cnt = 0;

        vector<int> res;
        while(que.size()){
            int cur = que.front();
            que.pop();
            res.push_back(cur);
            cnt++;
            auto &vec = ht[cur];
            for(int ele:vec){
            //decrease the indegree of the connected nodes
                indg[ele]--;
            //push the 0-indegree nodes into our queue
                if(indg[ele]==0)
                    que.push(ele);
            }
        }
    //if cnt<num, that means we cannot finish all the courses
        if(cnt<num)
            res.clear();
        return res;
    }
};
