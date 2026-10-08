class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> diffsArr;
        for(int i = 0; i < arr.size(); i++) {
            diffsArr.push_back({abs(arr[i] - x), arr[i]});
        }

        sort(diffsArr.begin(), diffsArr.end()); // lowest diffs first

        //for(const auto& [diff, val] : diffsArr) {
        //    cout << "Diff: " << diff << ", val: " << val << "\n";
        //}

        vector<int> res(k);
        for(int i = 0; i < k; i++) {
            res[i] = diffsArr[i].second;
        }

        sort(res.begin(), res.end());

        return res;
    }
};

/*
n<= 1e4

Given sorted int array arr
Return k closest ints to x


*/