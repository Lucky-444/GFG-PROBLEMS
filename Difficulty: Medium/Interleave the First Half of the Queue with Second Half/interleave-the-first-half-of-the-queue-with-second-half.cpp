class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
          int n = q.size();
    
    // If size is odd, interleaving is not possible
    if (n % 2 != 0)
        return;
    
    queue<int> q1, q2;
    int half = n / 2;
    
    // Push first half into q1
    for (int i = 0; i < half; i++) {
        q1.push(q.front());
        q.pop();
    }
    
    // Push second half into q2
    while (!q.empty()) {
        q2.push(q.front());
        q.pop();
    }
    
    // Interleave q1 and q2 back into q
    while (!q1.empty() && !q2.empty()) {
        q.push(q1.front());
        q1.pop();
        
        q.push(q2.front());
        q2.pop();
    }
    }
};