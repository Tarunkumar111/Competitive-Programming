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
#define rrep(i,a,b)   for(int i=a;i>b;i--)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;while(t--)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

bool check(set<char> a, unordered_map<char, int> b) {
  for(auto it = a.begin(); it != a.end() ; it++) {
    if (b[(*it)] <= 0)
      return false;
  }
  return true;
}

int main(){
  int n, ans = MOD;
  cin>>n;
  string str;
  cin>>str;
  set<char> unique;
  unordered_map<char, int> x;
  rep(i, 0, n)
    unique.insert(str[i]);
  int start = 0, end = 0;
  while(start <= end && end < n) {
    x[str[end]]++;
    while(check(unique, x)) {
      ans = min(ans, end - start + 1);
      x[str[start]]--;
      start++;
    }
    end++;
  }
  cout<<ans;
  return 0;
}
