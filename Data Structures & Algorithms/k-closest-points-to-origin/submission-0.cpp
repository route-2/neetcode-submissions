class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> v;
v.reserve(points.size());

for (auto &p : points) {
    int d = p[0]*p[0] + p[1]*p[1];
    v.push_back({d, p});
}

sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.first < b.first; });

vector<vector<int>> ans;
for (int i = 0; i < k; i++) ans.push_back(v[i].second);
return ans;

    }
};
