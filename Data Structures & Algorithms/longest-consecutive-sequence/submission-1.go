func longestConsecutive(nums []int) int {
	mp := make(map[int]int)
	res := 0
	for _, x := range nums {
		if mp[x] == 0 {
			mp[x] = mp[x-1] + mp[x+1] + 1
			mp[x - mp[x-1]] = mp[x]
			mp[x + mp[x+1]] = mp[x]
			res = max(res, mp[x])
		}
	}
	return res
}
