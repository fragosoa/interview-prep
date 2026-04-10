#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long W, H;
    cin >> W >> H;
    long long ax1, ay1, ax2, ay2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;
    long long rw, rh;
    cin >> rw >> rh;

    if (W < rw || H < rh) {
        cout << -1 << "\n";
        return;
    }

    // 4 strips adjacent to A (at d=0)
    // left:  width=ax1,    height=H
    // right: width=W-ax2,  height=H
    // top:   width=W,      height=H-ay2
    // bot:   width=W,      height=ay1

    // Already fits without moving?
    if ((ax1 >= rw && H >= rh) || (W-ax2 >= rw && H >= rh) ||
        (H-ay2 >= rh && W >= rw) || (ay1 >= rh && W >= rw)) {
        cout << 0 << "\n";
        return;
    }

    long long ans = LLONG_MAX;

    // Move A right by d → left strip grows: need ax1+d >= rw, constraint d <= W-ax2
    if (H >= rh) {
        long long d = rw - ax1;
        if (d > 0 && d <= W - ax2) ans = min(ans, d);
    }

    // Move A left by d → right strip grows: need (W-ax2)+d >= rw, constraint d <= ax1
    if (H >= rh) {
        long long d = rw - (W - ax2);
        if (d > 0 && d <= ax1) ans = min(ans, d);
    }

    // Move A up by d → bottom strip grows: need ay1+d >= rh, constraint d <= H-ay2
    if (W >= rw) {
        long long d = rh - ay1;
        if (d > 0 && d <= H - ay2) ans = min(ans, d);
    }

    // Move A down by d → top strip grows: need (H-ay2)+d >= rh, constraint d <= ay1
    if (W >= rw) {
        long long d = rh - (H - ay2);
        if (d > 0 && d <= ay1) ans = min(ans, d);
    }

    if (ans == LLONG_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}
