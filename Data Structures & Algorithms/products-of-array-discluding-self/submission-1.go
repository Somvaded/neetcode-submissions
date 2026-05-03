func productExceptSelf(nums []int) []int {
	n := len(nums)
	prefix := make([]int,n+1)
	suffix := make([]int, n+1)
	res := make([]int,n)

	prefix[0] = 1
	for i:=0; i<n;i++{
		prefix[i+1] = prefix[i]*nums[i];
	}
	suffix[n] = 1
	for i:=n-1;i>=0;i--{
		suffix[i] = suffix[i+1]*nums[i]
	}

	for i:=0;i<n;i++{
		res[i] = prefix[i]*suffix[i+1] 
	}
	return res
}
