class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        for(int i=1;i<n;i++){
            mini = abs(min(mini, arr[i]-arr[i-1]));
        }
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1] == mini){
                vector<int> sub(2, -1);
                sub[0] = arr[i-1];
                sub[1] = arr[i];
                ans.push_back(sub);
            }
        }
        return ans;
    }
};