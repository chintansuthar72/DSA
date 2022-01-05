#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

// approach 1 --- recursive
ll ans = 0;
void ways1(int m,int n,int x,int y){
    if(x>m or y>n){
        return;
    }
    if(x==m and y==n){
        ans+=1;
    }
    ways1(m,n,x+1,y);
    ways1(m,n,x,y+1);
}


// approach 2 --- dynamic programming

ll ways2(int m,int n){
    ll dp[m+1][n+1];
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            dp[i][j]=0;
        }
    }
    if(dp[m][n]!=0){
        return dp[m][n];
    }
    if(m==1 and n==1){
        dp[m][n]=1;
        return dp[m][n];
    }
    dp[m][n]=ways2(m-1,n)+ways2(m,n-1);
    return dp[m][n];
}

int main(){
    solve();
    int m,n;
    scanf("%d %d",&m,&n);

//    ways1(m,n,1,1);
//    printf("%lld\n",ans);
    cout<<ways2(m,n);

    return 0;
}
