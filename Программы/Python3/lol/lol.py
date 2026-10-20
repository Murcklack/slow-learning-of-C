nums = [-5,3,-1,4,-2,0]
print(sorted(nums))

word = ["banana", "Apple", "Broken", "meow"]
print(sorted(word))

languages = ["python", "c", "java"]
print(sorted(languages, key=len))

print(sorted(word, key=lambda w: w[1])) # Сортировка через 1ag