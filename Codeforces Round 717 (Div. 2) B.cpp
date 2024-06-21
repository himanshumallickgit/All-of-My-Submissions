

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define INF INT_MAX
// #define NINF INT_MIN
// #define FAST cin.tie(0); cout.tie(0);ios_base::sync_with_stdio(0);
// #define pb push_back
// #define ret(msg) cout << msg << endl
// #define rep(i,a,b) for(ll i = a; i < b; i++)
// #define trav(a, v) for(auto&a:v)
// #define all(x) x.begin(),x.end()
// int mod = 1000000007;

// bool isVowel(char ch) {
    // if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
        // return true;
    // }
    // return false;
// }
// 
// bool compare(pair<ll, ll> a, pair<ll, ll> b) {
    // return a.first < b.first;
// }
// 
// bool isPrime(ll n) {
    // if(n%2==0 && n!=2) {
        // return false;
    // }
    // for(ll i=3; i*i<=n; i+=2) {
        // if(n%i==0) {
            // return false;
        // }
    // }
    // return true;
// }
// 
// ll binary_exp(ll x, ll n, ll mod)
// {
    // if (n == 0) {
        // return 1;
    // } else if (n == 1) {
        // return x % mod;
    // } else {
        // ll temp = binary_exp(x, n / 2, mod);
        // temp = (temp * temp) % mod;
// 
        // if (n % 2 == 0) {
            // return temp;
        // } else {
            // return ((x % mod) * temp) % mod;
        // }
    // }
// }
// 
// namespace std {
    // template <>
    // struct hash<pair<int, int>> {
        // size_t operator()(const pair<int, int>& p) const {
            // return hash<int>()(p.first) ^ hash<int>()(p.second);
        // }
    // };
// 
    // template <>
    // struct hash<vector<int>> {
        // size_t operator()(const vector<int>& v) const {
            // size_t seed = 0;
            // for (const auto& i : v) {
                // seed ^= hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            // }
            // return seed;
        // }
    // };
// }

//BIT

//  x & 1 -- Check is number is odd
//  (x >> k) & 1  -- Checks if kth bit is set or not
//  x = x ^ (1 << k)  -- Flips the kth Bit
//  x = x | (1 << k)  -- Set the kth bit
//  x = x & ~(1 << k)  -- Unset the kth BIT
//  x & (x - 1)  -- Checks if a number is a power of 2
//  a + b = (a | b) + (a & b)
//  

//  __builtin_popcountll(x) -- Counting the number of 1s in binary representation of integer
//  __builtin_clzll(x)      -- Counts number of zeros before the first occurrence of one; count leading zeros
//  __builtin_ctzll(x)      -- Count no of zeros from last to first occurrence of one; count trailng zeros
// msb for 32 bit integer is 31 - __builtin_clzll(x) && mab in 64 bit integers is 63 - __builtin_clzll(x); 


void rec(){
   ll n;
   cin >> n;
   vector<ll> a(n);
   for(ll i = 0; i < n; i++){
   		cin >> a[i];
   }
   int bahar = 0;
   for(int i = 0; i < n; i++){
   	bahar = bahar ^ a[i];
   	int andar = 0;
   	bool flag = false;
   	for(int j = i+1; j < n; j++){
   		andar = andar ^ a[j];
   		if(bahar == andar){
   			flag = true;
   			andar = 0;
   		}
   	}
   	if(flag == true && andar == 0){
   		cout << "YES" << endl;
   		return;
   	}
   }
   cout << "NO" << endl;
   return;
}

int main(){
    // FAST
    int t;
    cin >> t;
    while(t--){
        rec();
    }
}

