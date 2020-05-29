#include<bits/stdc++.h>
using namespace std;

char lcs(string s1,string s2,int n,int m){
    int tmp[n+1][m+1];
    for(int i=0;i<=n;i++){
        tmp[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        tmp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                tmp[i][j]=1+tmp[i-1][j-1];
            }
            else{
                tmp[i][j]=max(tmp[i-1][j],tmp[i][j-1]);
            }
        }
    }
    int index=tmp[n][m];
    char dp[index+1];
    dp[index]='\0';
    int i=n,j=m;
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){
            dp[index-1]=s1[i-1];
            i--;
            j--;
            index--;
        }
        else{
            if(tmp[i-1][j]>tmp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<dp;
}
int main() {
	//code
	    int n,m;
	    string s1,s2;
	    cin>>n>>m;
	    cin>>s1;
	    cin>>s2;
	    lcs(s1,s2,n,m);
	return 0;
}
