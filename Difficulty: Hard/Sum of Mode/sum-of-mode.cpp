class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        unordered_map<int,int> freq;      // frequency of each number
        map<int, set<int>> freq_count;    // groups numbers by frequency
        int n = arr.size();
        int max_freq = 0;                 // current highest frequency in window
        int sum = 0;                      // final answer

        // Function to add an element into current window
        auto add = [&](int x) {
            int old = freq[x]; // old frequency of x

            // remove from old frequency set
            if (old > 0) {
                freq_count[old].erase(x);
                if (freq_count[old].empty()) freq_count.erase(old);
            }

            // update new frequency
            freq[x] = old + 1;
            freq_count[old+1].insert(x);

            // update maximum frequency
            max_freq = max(max_freq, old+1);
        };

        // Function to remove an element from current window
        auto remove = [&](int x) {
            int old = freq[x]; // old frequency of x

            // remove x from old frequency group
            freq_count[old].erase(x);
            if (freq_count[old].empty()) freq_count.erase(old);

            // decrease frequency
            if (--freq[x] > 0) {
                freq_count[old-1].insert(x);
            }

            // if no elements remain at max_freq, reduce max_freq
            if (freq_count[max_freq].empty()) max_freq--;
        };

        // Step 1: Add first k elements into window
        for (int i = 0; i < k; i++) add(arr[i]);
        // take smallest element among max frequency numbers
        sum += *freq_count[max_freq].begin();

        // Step 2: Slide window
        for (int i = k; i < n; i++) {
            remove(arr[i-k]);   // remove outgoing element
            add(arr[i]);        // add incoming element
            // again take smallest element among max frequency numbers
            sum += *freq_count[max_freq].begin();
        }

        return sum;
    }
};
