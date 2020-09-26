#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,n)        for (i = 0; i < n; ++i)
#define REP(i,k,n)      for (i = k; i <= n; ++i)
#define REPR(i,k,n)     for (i = k; i >= n; --i)
#define w(x)            int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr=new type[n];
#define inrange(i, a, b)((i >= min(a, b)) && (i <= max(a, b)))
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fsb(index)      (index & -index)
typedef long long       ll;
typedef pair<int,int>   pi;
typedef pair<long,long> pl;
typedef vector<int>     vi;
typedef vector<pi>      vpi;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int mod = 1000000007;

int arr[100000];

int bs(int lo, int hi, int k){
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == k){
            return mid;
        }
        if(arr[mid] > k){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return -1;
}

int main() {
    fast
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    w(t){
        int n, k;
        cin >> n >> k;
        int i; rep(i,n) cin >> arr[i];
        sort(arr, arr + n);
        int cnt = 0;
        rep(i,n){
            int tar = k - arr[i];
            int idx = bs(i + 1, n - 1, tar);
            if(idx != -1){
                // every element is unqiue, so there will be distincy pairs to add upto a number
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}