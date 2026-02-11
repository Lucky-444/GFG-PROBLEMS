class Solution {
public:
    bool canPossible(vector<int>& arr, int k, int w, int mid) {
        int n = arr.size();
        vector<int> diff(n + 1, 0);  // difference array
        long long waterUsed = 0;
        long long currAdd = 0;

        for (int i = 0; i < n; i++) {
            currAdd += diff[i];  // apply range delta
            int currentHeight = arr[i] + currAdd;

            if (currentHeight < mid) {
                int delta = mid - currentHeight;
               

                waterUsed += delta;
                if (waterUsed > k) return false;

                currAdd += delta;
                if(i + w <= n)
                diff[i + w] -= delta;  // stop the effect at i + w
            }
        }

        return true;
    }

    int maxMinHeight(vector<int>& arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = 1e9;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPossible(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
