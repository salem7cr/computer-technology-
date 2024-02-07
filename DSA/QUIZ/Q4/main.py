#using the XOR opeeation to determine the single element in an array with duplicates and one single element
def findSingle(nums):
    result = 0
    for num in nums:
        result ^= num
        #the '^=' operator calculates the exclusive OR of two corresponding values in the array and assigns the result back to the variable on its left handside.
        #by using the XOR operation the duplicate numbers will  "cancel" each other out leaving behind the single element as the result.
    return result

nums = [1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7]
single = findSingle(nums)
print("The single element is:", single)