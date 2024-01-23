def find_subsets_with_sum(nums, target):
    def backtrack(start, target, path):
        if target == 0:
            result.append(path)
            return
        for i in range(start, len(nums)):
            if nums[i] > target:
                continue
            backtrack(i + 1, target - nums[i], path + [nums[i]])
    result = []
    nums.sort()
    backtrack(0, target, [])
    return result
nums=list(map(int, input("Enter numbers separated by space: ").split()))
target_sum = int(input("Enter the target sum: "))
subsets = find_subsets_with_sum(nums, target_sum)
if not subsets:
    print("No subset found with the given sum.")
else:
    print("Subsets with sum", target_sum, ":")
    for subset in subsets:
        print(subset)