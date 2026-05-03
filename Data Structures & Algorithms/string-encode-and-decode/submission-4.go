type Solution struct{}

func (s *Solution) Encode(strs []string) string {
    var res string
    for _, word := range strs {
        length := len(word)
        res += strconv.Itoa(length)+"#"+word; 
    }
    return res
}

func (s *Solution) Decode(encoded string) []string {
    var res []string
    i := 0

    for i < len(encoded) {
        j := i
        for{
            if(encoded[j] != '#'){
                j++
            }else{
                break
            }
        }

        length, err := strconv.Atoi(encoded[i:j])
        if err != nil {
            fmt.Println("lora")
            return nil
        }
        j++
        res = append(res, encoded[j:j+length])
        i = j + length
    }
    return res
}
