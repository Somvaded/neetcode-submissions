func threeSum(nums []int) [][]int {
	res := make([][]int,0)
	sort.Ints(nums)

	for i := range nums {
		if nums[i] > 0 { break }

		if i > 0 && nums[i] == nums[i-1] { continue }

		r := len(nums)-1
		l := i+1

		for l < r {
			temp := nums[i] + nums[l] + nums[r]
			if temp > 0 {
				r--
			} else if temp < 0 {
				l++
			}else {
				res = append(res, []int{nums[i], nums[l], nums[r]})
				l++
				r--
				for l<r && nums[l] == nums[l-1]{
					l++
				}
			}
		} 
	}
	return res
}
