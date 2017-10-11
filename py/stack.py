class Node:
	def __init__(self, value):
		self.key = value
		self.n = None

class Stack:
	def __init__(self, value=None):
		val = Node(value)
		self.top = val

	def push(self, value):
		val = Node(value)
		val.n = self.top
		self.top = val

	def pop(self):
		self.top = self.top.n

	def top_val(self):
		print self.top.key

	def is_empty(self):
		if self.top == None:
			return True
		else:
			return False

	def print_stack(self):
		if self == None:
			print "empty"
		else:
			node = self.top
			while(node.n):
				print node.key
				node = node.n

st = Stack()
st.push(10)
st.push(20)
st.push(30)
st.push(40)
st.push(50)
st.pop()
print st.is_empty()
st.print_stack()
st.top_val()





