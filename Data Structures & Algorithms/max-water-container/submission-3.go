func maxArea(heights []int) int {
	i:= 0
    j:=len(heights)-1
    res := 0
    for i<j {
        length := j-i
        volume := min(heights[i],heights[j])*(length)
        res = max(res, volume)
        if(heights[i] <= heights[j]){
            i++
            continue
        } else {
            j--
            continue
        }
    }
    return res
}
