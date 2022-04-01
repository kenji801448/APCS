#get the number of input, and throw it away
input()

#get whole list as string list
grade = input().split()

#treat grade list as a integer list and sort it!
grade.sort(key=int)

#print out the list with space as delimiter
print(" ".join(grade))

#convert the list into integer list for easy comparison
grade = [int(i) for i in grade]

#map grade into two list
passed = [i for i in grade if i >= 60]
failed = [i for i in grade if i < 60]

if failed: #the list has at least one element
    print(failed[-1])
else: #the list is empty
    print("best case")

if passed: #the list has at least one element
    print(passed[0])
else: #the list is empty
    print("worst case")
