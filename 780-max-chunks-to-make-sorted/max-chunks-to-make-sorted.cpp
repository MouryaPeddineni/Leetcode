class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0, mini = 11, chunks = 0, lastChunkLastIdx = -1;
        for(int i=0;i<n;i++) {
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
            if(mini > lastChunkLastIdx && maxi == i) {
                chunks++;
                lastChunkLastIdx = i;
                mini = 11;
                maxi = 0;
            }
        }
        return chunks;
    }
};