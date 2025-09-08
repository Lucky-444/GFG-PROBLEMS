class Solution {
public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int Time = 0;
        for (int i = 0; i < mices.size(); i++) {
            int d = abs(mices[i] - holes[i]);  // directly match ith mouse to ith hole
            Time = max(Time, d);
        }
        return Time;
    }
};
