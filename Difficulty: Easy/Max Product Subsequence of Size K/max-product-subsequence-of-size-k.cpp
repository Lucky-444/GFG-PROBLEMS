class Solution {
	public:
	int maxProduct(vector<int> &arr, int k) {
		int n = arr.size();
		
		sort(arr.begin(), arr.end());
		
		long long pro = 1;
		int st = 0, end = n - 1;
		if (k%2)
			{
			pro = arr[n - 1]; end = n - 2;
			k--;
		}
		while (st< end && k)
			{
			pro = max(1ll*pro*arr[st]*arr[st + 1], 1ll*arr[end]*pro*arr[end - 1]);
			if (1ll*pro*arr[st]*arr[st + 1]>1ll*pro*arr[end]*arr[end - 1])
				{
				st = st + 2;
			}
			else
				{
				end = end - 2;
			}
			k = k - 2;
		}
		return pro;
	}
};
