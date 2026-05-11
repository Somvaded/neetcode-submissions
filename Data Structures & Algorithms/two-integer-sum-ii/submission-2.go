func twoSum(numbers []int, target int) []int {
	i:=0
	j:=len(numbers)-1

	for{
		if numbers[i] + numbers[j] < target {
			i++
		} else if numbers[i] + numbers[j] > target {
			j--
		} else {
			return []int{i+1,j+1}
		}
	}
	return []int{-1,-1}
}
