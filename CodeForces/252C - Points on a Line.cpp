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

int main(){
    ll n,d;
    cin>>n>>d;
    vector<ll> pts(n);
    rep(i, 0, n)
        cin>>pts[i];
    ll ans = 0;
    rep(i, 0, n-2){
        ll oneP = pts[i];
        ll largestDistancePoint = oneP + d;
        ll ind = upper_bound(all(pts), largestDistancePoint) - pts.begin();
        //cout<<"i: "<<i<<"   arr[i]: "<<pts[i]<<"   ind: "<<ind<<endl;
        ind--;
        if(pts[ind] - oneP > d)
            continue;
        ll numOfPoints = ind-i;
        ans += numOfPoints * (numOfPoints-1)/2;
    }
    cout<<ans;
    return 0;
}
