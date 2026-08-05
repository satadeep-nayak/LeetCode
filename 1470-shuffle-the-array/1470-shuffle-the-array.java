class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] ans = new int[nums.length];

        int a = 0;
        int b = n;

        for(int i = 0 ; i < nums.length ; i++){
            if(i % 2 == 0){
                ans[i] = nums[a];
                a++;
            }
            else{
                ans[i] = nums[b];
                b++;
            }
        }
        return ans;
    }
}