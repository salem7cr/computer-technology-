def findDup(arr):  # arr is the parameter
    found = False
    i = 0
    while (i < len(arr) - 1):
        j = 1
        while (j < len(arr) - 1):
            if (arr[i] == arr[j] and i != j):
                # the first condition of the logical AND statement checks if there is a duplicate element
                #  the second condition is to make sure that i am not checking elementsof the same index in the array
                found = True
            j += 1
        i += 1
    return found


array = [1, 2, 3, 4, 5, 6]
print(findDup(array))  # we pass 'array' here as an argument to the function
