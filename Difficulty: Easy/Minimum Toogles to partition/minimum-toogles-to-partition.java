class Solution {
    int minToggle(int[] arr) {
        // code here
         int n = arr.length;

        // Count total zeros initially
        int totalZeros = 0;
        for (int num : arr) {
            if (num == 0) totalZeros++;
        }

        int leftOnes = 0;
        int rightZeros = totalZeros;

        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {

            // Current partition before index i
            ans = Math.min(ans, leftOnes + rightZeros);

            // Update counts
            if (arr[i] == 1)
                leftOnes++;
            else
                rightZeros--;
        }

        // Partition after last element
        ans = Math.min(ans, leftOnes + rightZeros);

        return ans;
    }
}