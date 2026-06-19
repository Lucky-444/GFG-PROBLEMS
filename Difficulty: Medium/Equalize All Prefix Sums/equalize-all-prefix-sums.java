class Solution {
    public ArrayList<Integer> optimalArray(int[] arr) {
        // code here
        ArrayList<Integer>ans=new ArrayList<>();

        ans.add(0);

        for(int i=1;i<arr.length;i++){

            int next=ans.get(i-1)+(arr[i]-arr[i/2]);

            ans.add(next);

        }

        return ans;
    }
}