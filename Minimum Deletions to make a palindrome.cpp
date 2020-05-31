#include <bits/stdc++.h>
using namespace std;

int minDel(string s){
    string s1=s;
    reverse(s.begin(),s.end());
    string s2=s;
    int n=s1.length();
        int m=s2.length();
        int tmp[n+1][m+1];
        for(int i=0;i<=n;i++){
            tmp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
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
        int total = n - tmp[n][m];
        return total;
}

int main() {
	//code
	int t;cin>>t;
	while(t--){
	   string s;
	   cin>>s;
	   cout<<minDel(s)<<"\n";
	}
	return 0;
}
