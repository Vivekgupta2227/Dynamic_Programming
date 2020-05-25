class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           sum+=nums[i]; 
        }
        if (S > sum || -S < -sum || (S + sum) % 2 == 1) return 0;
        int s1=(sum+S)/2;
        int tmp[n+1][s1+1];
        for(int i=0;i<=n;i++){
            tmp[i][0]=1;
        }
        for(int i=1;i<=s1;i++){
            tmp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
                if(nums[i-1]==0){
                    tmp[i][0]=2*tmp[i-1][0];
                }
                else{
                    tmp[i][0]=tmp[i-1][0];
                }
            }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s1;j++){
                if(nums[i-1]>j){
                    tmp[i][j]=tmp[i-1][j];
                }
                else{
                    tmp[i][j]=tmp[i-1][j-nums[i-1]]+tmp[i-1][j];
                }
            }
        }
        return tmp[n][s1];
    }
};
