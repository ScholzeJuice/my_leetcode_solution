class Solution {
public:
    int maximumsSplicedArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> sub(arr1);
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i<n; i++){
            sub[i] = arr2[i] - arr1[i];
            sum1 += arr1[i];
            sum2 += arr2[i];
        }
      //Kadane DP solution
        int ans1 = 0;   int ans2 = 0;
        int cur1 = 0;   int cur2 = 0;
        for(int ele:sub){
            cur1 = ele + max(cur1, 0);
            ans1 = max(cur1, ans1);
            cur2 = -1*ele + max(cur2, 0);
            ans2 = max(cur2, ans2);
        }
        return max(sum1+ans1, sum2+ans2);
    }
};
