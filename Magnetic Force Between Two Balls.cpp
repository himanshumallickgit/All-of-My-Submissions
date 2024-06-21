class Solution {
public:
    bool canPlace(vector<int>& position, int mid, int m){
        int n = position.size();
        int prevpos = position[0];
        int placed = 1;
        for(int i = 1; i < n && placed < m; i++){
            if(position[i] - prevpos >= mid){
                placed++;
                prevpos = position[i];
            }
        }
        if(placed == m){
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1;
        int high = position[n-1]/(m-1);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canPlace(position, mid, m)){
                low = mid + 1;
                ans = max(ans, mid);
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};