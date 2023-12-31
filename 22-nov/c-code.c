/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int compare(const void* num1, const void* num2)
{
    return *(int*)num1 - *(int*)num2;
}
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    *returnSize = lSize;
    bool* ans = (bool*)malloc(*returnSize * sizeof(bool));
    int* temp_array = (int*)malloc(numsSize * sizeof(int));
    
    for(int i = 0; i < *returnSize; i++)
    {
        int nums_index;
        int array_index;
        
        for(nums_index = l[i], array_index = 0; nums_index <= r[i]; nums_index++, array_index++)
        {
            temp_array[array_index] = nums[nums_index];
        }
        
        qsort(temp_array, array_index, sizeof(int), compare);
        
        int valid = 1;
        
        for(int j = 1; j < array_index; j++)
        {
            if(temp_array[j] - temp_array[j - 1] != temp_array[1] - temp_array[0])
            {
                valid = 0;
                
                break;
            }
        }
        
        if(valid == 1)
        {
            ans[i] = true;
        }
        else
        {
            ans[i] = false;
        }
    }
    
    free(temp_array);
    
    return ans;
}