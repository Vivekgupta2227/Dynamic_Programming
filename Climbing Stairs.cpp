class Solution {
public:
    int climbStairs(int n) {
        int tmp[n+1];
            if(n<=1){
                return 1;
            }
            tmp[1]=1;
            tmp[0]=1;
            for(int j=2;j<=n;j++){
                    tmp[j]=tmp[j-1]+tmp[j-2];
            }
        return tmp[n];
    }
};
