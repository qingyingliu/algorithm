
/*************************************************************************
> File Name: merge-stone[version2].cpp
> Author: Lewin
> Mail: 2596736318@qq.com
> Created Time: Tue 04 Dec 2018 02:33:31 PM CST
************************************************************************/

#include<stdio.h>
#include<memory.h>

/*========== define data ==========*/
const int MAXN = 2005;
const int INF = 10000000;
int n;
int stone[MAXN];
long long sum[MAXN];
int dpmax[MAXN][MAXN],dpmin[MAXN][MAXN];
int pi[MAXN][MAXN];

void init(){
    memset(dpmax,0,sizeof(dpmax));
    memset(dpmin,0,sizeof(dpmin));
    memset(pi,0,sizeof(pi));
    for(int i=0;i<MAXN;i++){
        for(int j=i+1;j<MAXN;j++){
            dpmin[i][j] = INF;
        }
    }
    //长度为1和长度为2
    for(int i=0;i+1<MAXN;i++) pi[i][i] = pi[i][i+1] = i;
    
}

inline int max(const int &x,const int &y){
    return x>y?x:y;
}

inline int min(const int &x,const int &y){
    return x>y?y:x;
}

// dp[s][t] = dp[s][k] + dp[k+1][t] + sum[s][t]

// return a merge way where score is max in interval [s,t].
int max_score(int s,int t){
    int maxl = t - s  + 1;
    for(int l=2;l<=maxl;l++){
        for(int i = s;i+l<=t;i++){
            int j = i + l -1;
            for(int k=i;k<j;k++){
                if(dpmax[i][j]<dpmax[i][k] + dpmax[k+1][j] + sum[j] - sum[i-1]){
                    dpmax[i][j] = dpmax[i][k] + dpmax[k+1][j] + sum[j] - sum[i-1];
                }
            }
        }
    }
    return dpmax[s][t];
}

// return a merge way where score is min in interval [s,t].
int min_score(int s,int t){

    int maxl = t - s +1;
    for(int l=2;l<=maxl;l++){
        for(int i = s;i+l<=t;i++){
            int j = i + l -1;
            for(int k=pi[i][j-1];k<=pi[i+1][j];k++){
                if(dpmin[i][j]>=dpmin[i][k] + dpmin[k+1][j] + sum[j] - sum[i-1]){
                    dpmin[i][j] = dpmin[i][k] + dpmin[k+1][j] + sum[j] - sum[i-1];
                    pi[i][j] = k;
                }
            }
        }
    }
    return dpmin[s][t];
}

    void print(int dp[MAXN][MAXN]){
        for(int i=1;i<=2*n;i++){
            for(int j=1;j<=2*n;j++){
                printf("%d ",dp[i][j]);
            }
            puts("\n");
        }
    }
    int main(){
        while(~scanf("%d",&n)){
            init();
            sum[0]=0;
            for(int i=1;i<=n;i++){
                scanf("%d",&stone[i]);
                stone[n+i] = stone[i];
            }

            for(int i=1;i<=2*n;i++){
                sum[i] = sum[i-1] + stone[i];
            }
            max_score(1,2*n-1);
            min_score(1,2*n-1);

            int maxres = 0;
            int minres = INF;

            for(int i=1;i<=n;i++){
                maxres = max(maxres,dpmax[i][i+n-1]);
                minres = min(minres,dpmin[i][i+n-1]);
            }

            printf("%d\n%d\n",minres,maxres);
            //print(dpmin);
        }
    }
