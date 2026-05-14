func trap(height []int) int {
	n := len(height)
	prefix := make([]int, len(height))
	suffix := make([]int, len(height))
	prefix[0] = height[0]
    for i:=1; i<n;i++ {
		prefix[i] = max(height[i], prefix[i-1])
	}

	suffix[n-1] = height[n-1]
	for i:=n-2; i>=0 ;i-- {
		suffix[i] = max(height[i], suffix[i+1])
	}

	res := 0
	for i:= 1; i<n-1;i++ {
		res += min(prefix[i],suffix[i])-height[i]
	}
	return res
}
