        #include<bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)
#define pb          push_back
#define ll          long long int
#define vi          vector<int>
#define pi          pair<int, int>
#define W(t)        int t; cin >> t; while(t--)
#define FIO         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff          first
#define ss          second
#define rep(i, a, b)for(ll i = a; i <= b; i++)
#define dep(i, a, b)for(ll i = a; i >= b; i--) 
#define all(x)      x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI                3.141592653589793238
using namespace std;
const ll mod = (ll)(998244353);
const ll mod2 = (ll)1e9+7;
ll test = 1;
vector<ll> read(int n){
    
    vector<ll> v(n);

    loop(i, n)
        cin >> v[i];
    return v;
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void RadixSort(vector<ll>&v, ll exp){
    int n = v.size();

    vector<ll>count(10, 0);

    for (int i = 0; i < n; ++i)
    {
        count[(v[i]/exp)%10]++;
    }

    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i-1];
    }   

    vector<ll>out(n, 0);

    for (int i = n-1; i >= 0; i--)
    {
        out[count[(v[i]/exp)%10]-1] = v[i];
        count[(v[i]/exp)%10]--;
    }

    for (int i = 0; i < n; ++i)
    {
        v[i] = out[i];
    }

}

void solve(){
    ll i, j, k, m,n, cnt = 0, ans = 0, sum = 0;

    cin >> n;

    vector<ll>v = read(n);

    ll mx = *max_element(all(v));

    while(mx){
        cnt++;
        mx /= 10;
    }
    ans = 1LL;

    for (int i = 0; i < cnt; ++i)
    {
        RadixSort(v, ans);
        ans *= 10LL;
    }

    for(auto it : v){
        cout << it << " ";
    }
    cout << "\n";
    test++;
}

int main(){
    FIO
    
    #ifndef ONLINE_JUDGE
    freopen("C:/Codeforces/input.txt", "r", stdin);
    freopen("C:/Codeforces/output.txt", "w", stdout);
    #endif
    ll i = 1;
    //W(t)
    solve();
    
    return 0;
    
}