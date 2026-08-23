public class Solution {
    public IList<int> FindDuplicates(int[] nums) {
        HashSet<int>seen=new HashSet<int>();;
        List<int>result=new List<int>();
        for(int i=0;i<nums.Length;i++){
            if(!seen.Add(nums[i])){
                result.Add(nums[i]);
            }
        }
        return result;
        
    }
}