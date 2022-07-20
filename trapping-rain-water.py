# https://www.geeksforgeeks.org/trapping-rain-water/
def trappedWater(arr):
	num_blocks = 0
	n = 0
	max_height = float('-inf')

	# Find total blocks, max height and length of array
	for height in arr:
		num_blocks += height
		n += 1
		max_height = max(max_height, height)

	# Total water, left pointer and right pointer
	# initialized to 0 and n - 1
	total = 0
	left = 0
	right = n - 1

	for i in range(1, max_height+1):
		
		# Find leftmost point greater than current row (i)
		while arr[left] < i:
			left += 1
		
		# Find rightmost point greater than current row (i)
		while arr[right] < i:
			right -= 1
		
		# Water in this row = right - left + 1
		total += (right - left + 1)
	
	total -= num_blocks
	return total

# Driver code
if __name__ == "__main__":
	arr = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
	print(trappedWater(arr))
