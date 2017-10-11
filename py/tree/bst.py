class Node:
	def __init__(self, key):
		self.left = None;
		self.right = None;
		self.key = key;

def inorder(root):
	if root:
		inorder(root.left)
		print(root.key)
		inorder(root.right)

def postorder(root):
	if root:
		postorder(root.left)
		postorder(root.right)
		print(root.key)

def preorder(root):
	if root:
		print(root.key)
		preorder(root.left)
		preorder(root.right)


def insert(root, val):
	if root is None:
		root.key = val;
	if (root.key <= val):
		if root.left == None:
			root.left = Node(val)
		else:
			insert(root.left, val)
	else:
		if root.right == None:
			root.right = Node(val)
		else:
			insert(root.right, val)

def search(root, key):
	if (root.key == key):
		return True;
	elif (root.key < node.key):
		if root.left == None:
			return False;
	else:
		if root.right == None:
			return False;

r = Node(50)
insert(r, 30)
insert(r, 20)
insert(r, 90)
insert(r, 70)
insert(r, 80)
insert(r, 10)
insert(r, 100)
insert(r, 40)
insert(r, 60)

preorder(r)
print "--"
postorder(r)
print "__"
inorder(r)

