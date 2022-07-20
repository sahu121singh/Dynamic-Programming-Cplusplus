class Node:
	def __init__(self, key):
		self.data = key
		self.left = None
		self.right = None
		self.hd = 0

def Vertical_order_traversal(root):
	if(root == None):
		return
	q = []
	m = dict()
	hd = 0
	root.hd = hd

	# push node and horizontal distance to queue
	q.append(root)

	while(len(q)):
		root = q[0]
		hd = root.hd

		# count function returns 1 if the container contains an element
		# whose key is equivalent to hd, or returns zero otherwise.
		if hd not in m:
		    m[hd] = []
		m[hd].append(root.data)
		if(root.left):
			root.left.hd = hd - 1
			q.append(root.left)

		if(root.right):
			root.right.hd = hd + 1
			q.append(root.right)

		q.pop(0)
	for i in sorted(m):
		print(m[i], end=" ")


# Driver Code
if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)
	root.right.left = Node(6)
	root.right.right = Node(7)
	root.right.left.right = Node(8)
	root.right.right.right = Node(9)
	print("Following are nodes in top", "view of Binary Tree")
	Vertical_order_traversal(root)
