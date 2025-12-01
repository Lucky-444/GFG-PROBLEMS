class Solution {
public:
    int maxScore(string s, vector<vector<char>>& jumps) {
        int n = s.size();
        vector<char> chars(s.begin(), s.end());
        
        // Precompute next same character positions
        vector<int> nextSameChar(n, -1);
        unordered_map<char, int> lastPos;
        
        for (int i = n - 1; i >= 0; i--) {
            if (lastPos.count(chars[i])) 
                nextSameChar[i] = lastPos[chars[i]];
            lastPos[chars[i]] = i;
        }

        // Build jumpMap
        unordered_map<char, vector<char>> jumpMap;
        for (auto &jump : jumps) {
            jumpMap[jump[0]].push_back(jump[1]);
        }

        // Precompute char positions
        unordered_map<char, vector<int>> charPositions;
        for (int i = 0; i < n; i++) {
            charPositions[chars[i]].push_back(i);
        }

        // Prefix sum of ASCII values
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + chars[i];
        }

        // DP memo
        vector<int> dp(n, -1);

        return dfs(0, chars, nextSameChar, jumpMap, charPositions, prefixSum, dp);
    }

private:

    int dfs(int idx,
            vector<char> &chars,
            vector<int> &nextSameChar,
            unordered_map<char, vector<char>> &jumpMap,
            unordered_map<char, vector<int>> &charPositions,
            vector<int> &prefixSum,
            vector<int> &dp) {

        int n = chars.size();
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];

        int maxScore = 0;
        char currentChar = chars[idx];

        // Option 1: Jump to next same character
        int nextSame = nextSameChar[idx];
        if (nextSame != -1) {
            int score = calculateScore(idx, nextSame, chars, prefixSum);
            maxScore = max(maxScore, score + dfs(nextSame, chars, nextSameChar,
                                                 jumpMap, charPositions, prefixSum, dp));
        }

        // Option 2: Jump according to jump rules
        if (jumpMap.count(currentChar)) {
            for (char target : jumpMap[currentChar]) {
                if (charPositions.count(target)) {
                    auto &positions = charPositions[target];

                    // Binary search: first index > idx
                    int posIndex = upper_bound(positions.begin(), positions.end(), idx)
                                   - positions.begin();

                    // Check limited next 3 positions
                    for (int i = posIndex; i < min(posIndex + 3, (int)positions.size()); i++) {
                        int nextPos = positions[i];
                        if (nextPos > idx) {
                            int score = calculateScore(idx, nextPos, chars, prefixSum);
                            maxScore = max(maxScore, score + dfs(nextPos, chars, nextSameChar,
                                                                 jumpMap, charPositions, prefixSum, dp));
                        }
                    }
                }
            }
        }

        dp[idx] = maxScore;
        return maxScore;
    }

    // calculate score between jump
    int calculateScore(int i, int j,
                       vector<char> &chars,
                       vector<int> &prefixSum) {

        char target = chars[j];
        int total = prefixSum[j] - prefixSum[i];

        // subtract targetChar ASCII inside range
        for (int k = i; k < j; k++) {
            if (chars[k] == target)
                total -= chars[k];
        }

        return total;
    }
};
