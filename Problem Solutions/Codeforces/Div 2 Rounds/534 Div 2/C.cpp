#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i <= (b); i ++)
    #define rep(i, n)       fl(i, 1, (n))
    #define loop(i, n)      fl(i, 0, (n) - 1)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, (n), 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    /* String methods */
    #define dig(i)          (s[i] - '0')
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define fr              first
    #define sc              second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define clr(a)          fill(a, 0)
    #define endl            '\n'
    /* Mathematical */
    #define IINF            0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    /* Fast Input Output */
    #define FAST_IO                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 100010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    string s;
    cin >> s;

    // 0 - vertical, 1 - horizontal
    int n = slen(s);

    int mat[5][5];
    rep (i, 4) {
        rep (j, 4) {
            mat[i][j] = 0;
        }
    }

    loop (t, n) {
        if (s[t] == '0') {
            for (int c = 1; c <= 4; c ++) {
                for (int r = 1; r <= 3; r ++) {
                    if (mat[r][c] == 0 && mat[r + 1][c] == 0) {
                        mat[r][c] = 1; mat[r + 1][c] = 1;
                        cout << r << " " << c << endl;
                        goto end;
                    } 
                }
            }
        }
        else if (s[t] == '1') {
            for (int r = 1; r <= 4; r ++) {
                for (int c = 1; c <= 3; c ++) {
                    if (mat[r][c] == 0 && mat[r][c + 1] == 0) {
                        mat[r][c] = 1; mat[r][c + 1] = 1;
                        cout << r << " " << c << endl;
                        goto end;
                    } 
                }
            }
        }

        end:
        rep (i, 4) {
            int ct = 0;
            rep (j, 4) {
                if (mat[i][j] == 1) {
                    ct ++;
                }
            }
            if (ct == 4) {
                rep (j, 4) {
                    mat[i][j] = 0;
                }
            }
        }

        rep (j, 4) {
            int ct = 0;
            rep (i, 4) {
                if (mat[i][j] == 1) {
                    ct ++;
                }
            }
            if (ct == 4) {
                rep (i, 4) {
                    mat[i][j] = 0;
                }
            }
        }
    }

    // rep (i, 4) {
    //     rep (j, 4) {
    //         cerr << mat[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    return 0;
}