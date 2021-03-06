#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

/* Solution explanation in Goodnotes 5 on my ipad*/
int dp[int(1e6+5)][3];
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    rep(i, 1, n){
        dp[i][0] = dp[i-1][0] + (s[i] != s[i-1]);
        dp[i][1] = max(dp[i-1][1] + (s[i] != s[i-1]), dp[i-1][0] + (s[i] == s[i-1]));
        dp[i][2] = max(dp[i-1][2] + (s[i] != s[i-1]), dp[i-1][1] + (s[i] == s[i-1]));
    }
    int ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    cout<<ans;
    return 0;
}
