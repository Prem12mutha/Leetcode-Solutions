class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        int n = nums1.size();

        vector<long long> diff(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (total <= k)
            return 0;

        long long lo = 0, hi = 100000;

        while (lo < hi) {
            long long mid = (lo + hi) / 2;

            long long need = 0;
            for (auto d : diff)
                if (d > mid)
                    need += d - mid;

            if (need <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long x = lo;

        vector<long long> arr;
        long long used = 0;

        for (auto d : diff) {
            if (d > x) {
                used += d - x;
                arr.push_back(x);
            } else {
                arr.push_back(d);
            }
        }

        long long rem = k - used;

        for (auto &d : arr) {
            if (rem == 0)
                break;

            if (d == x && d > 0) {
                d--;
                rem--;
            }
        }

        long long ans = 0;

        for (auto d : arr)
            ans += d * d;

        return ans;
    }
};