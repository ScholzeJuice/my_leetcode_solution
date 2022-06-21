class Solution {
public:
    int furthestBuilding(vector<int>& h, int bri, int lad) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int bs = 0;
        for(int i = 1; i<h.size(); i++){
            int diff = h[i]-h[i-1];
            if(diff<=0)
                continue;
            pq.push(diff);
            if(pq.size()>lad){
                int cur = pq.top();
                pq.pop();
                if(bri<cur)
                    return i-1;
                bri -= cur;
            }
        }
        return h.size()-1;
    }
};
