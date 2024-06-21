class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                sum += customers[i];
            }
        }
        vector<int> prefix_one(n, 0);
        if(grumpy[0] == 1){
            prefix_one[0] = customers[0];
        }
        for(int i = 1; i < n; i++){
            if(grumpy[i] == 1){
                prefix_one[i] = prefix_one[i-1] + customers[i];
            }else{
                prefix_one[i] = prefix_one[i-1];
            }
        }
        int maxi = 0;
        int onesum = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 1){
                onesum = 0;
                int last = min(n-1, minutes + i - 1);
                if(i > 0){
                    onesum = prefix_one[last] - prefix_one[i-1];
                }else{
                    onesum = prefix_one[last] - 0;
                }
                maxi = max(maxi, onesum);
            }
        }
        return sum + maxi;
    }
};