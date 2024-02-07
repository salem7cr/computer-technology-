#Concept is to move the first element in the array at all instances to the right of the last element in the array by k steps
#creating a function using the def keyword
def rotateArray(arr,k):
    while k >0:
            temp=arr[0]
            arr.__delitem__(0)
            arr.append(temp)
            k-=1
    return arr

array=[1,2,3,4,5,6,7,8,9,10]
k= int(input("Enter the number of steps(k);"))
if(k<= 0):
        print(array)#if k steps are negative then we return the array as is
elif(k> len(array)):
      #else we rotate the array but if k is larger then the array size we can reduce the number of operations by removing a whole rotation
      #  through doing a modulo operation to get the remainder and use it as the step count
      k=k% len(array)
      print(rotateArray(array,k))
else:
       print(rotateArray(array,k))