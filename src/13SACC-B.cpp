//工作时间m
//作物n种
//每种作物处理收益为w
//每种作物处理时间[left,right]
//解除限制后随便时长
//工作时间const为m

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
using ll = long long;

void sortByW(vector<array<ll,3>>& toS) {
    std::sort(toS.begin(), toS.end(), [](const auto& x, const auto& y) {
        return x[0] < y[0];
    });
};

ll getMaxProfit(ll l,ll r,ll basetime,ll maxtime,ll ulimitindex,ll ulimittime,ll baseprofit,ll& sbW,vector<array<ll,3>> plr) {
    auto *SortedByW = plr.erase(plr.begin() + ulimitindex);
    sortByW(SortedByW);
    ll extraTime = plr[ulimitindex][1];
    ll maxProfit = baseprofit - plr[ulimitindex][0] * plr[ulimitindex][1] + plr;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    ll m;

    cin>>n>>m;

    vector<array<ll,3>> plr;

    for (ll i = 0;i <= n;i++) {
        cin >> plr[i][0] >> plr[i][1] >> plr[i][2];
    }

    auto sortedByW = plr;



}
