/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let n=nums.length;
    let total=0
    let sum=0;
    for(let i=0;i<n;i++){
        sum+=nums[i];
    }
    total=n*(n+1)/2


return total -sum
    
};