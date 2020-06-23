#include<bits/stdc++.h>
using namespace std;
int dp[202][202][2];

 int Solve(string s,int i,int j,bool isTrue)
{
    if(i>j)
    {
        return dp[i][j][isTrue]=0;
    }
    
    
    if(i==j)
    {
        if(isTrue)
        {
            if(s[i]=='T')
            return dp[i][j][isTrue]=1;
            else
            return dp[i][j][isTrue]=0;
        }else{
           if(s[i]=='F')
            return dp[i][j][isTrue]=1;
            else
            return dp[i][j][isTrue]=0; 
        }
    }
    
    
    if(dp[i][j][isTrue]!=-1)
    return dp[i][j][isTrue];
 
    
    long long int ans=0;
    
    for(int k=i+1;k<=j-1;k+=2)
    {
        long long int lt,rt,lf,rf;
        
         if(dp[i][k-1][true]!=-1)
         {
             lt=dp[i][k-1][true];
         }else{
             lt=Solve(s,i,k-1,true);
             dp[i][k-1][true]=lt;
         }
        
         if(dp[i][k-1][false]!=-1)
         {
             lf=dp[i][k-1][false];
         }else{
             lf=Solve(s,i,k-1,false);
             dp[i][k-1][false]=lf;
             
         }
         
         if(dp[k+1][j][true]!=-1)
         {
             rt=dp[k+1][j][true];
         }else{
             rt=Solve(s,k+1,j,true);
             dp[k+1][j][true]=rt;
             
         }
         
         if(dp[k+1][j][false]!=-1)
         {
             rf=dp[k+1][j][false];
         }else{
             rf=Solve(s,k+1,j,false);
             dp[k+1][j][false]=rf;
         }
         
      
        if(s[k]=='&')
        {
            if(isTrue==true)
            {
                ans+=(lt*rt)%1003;
            }else{
                ans+=((lf*rf)%1003+(lt*rf)%1003+(lf*rt)%1003);
            }
        }
        else if(s[k]=='|')
        {
            if(isTrue==true)
            {
                ans+=((lt*rt)%1003 +(lt*rf)%1003+(lf*rt)%1003);
            }else{
                ans+=((lf*rf)%1003);
            }
        }
        else{
            if(isTrue==true)
            {
                ans+=((lt*rf)%1003+(lf*rt)%1003);
            }else{
                ans+=((lt*rt)%1003+(lf*rf)%1003);
            }
        }
    }
    ans=ans%1003;
    return dp[i][j][isTrue]=ans;
}
int main()
 {
	//code
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
	int t;cin>>t;
	while(t--)
	{
	  
	    int n;cin>>n;
	    string s;cin>>s;
	    memset(dp,-1,sizeof(dp));
	    cout<<Solve(s,0,n-1,true)<<endl;
	   
	}
	return 0;
}
