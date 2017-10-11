class Node:
	def __init__(self, value):
		self.key = value
		self.next = None

class Queue:
	def __init__(self, value=None):
		self.head = None

	def head(self):
		return self.head

	def tail(self):
		return self.head.next

	def insert(self, value):
		val = Node(value)
		if self.head == None:
			self.head = val
		else:
			val.next = self.head
			self.head = val

	def remove(self):
		if self.head == None:
			self.head = val
		else:
			node = self.head
			while(node.next.next != None):
				node = node.next
			node.next = None


	def printAll(self):
		node = self.head
		while(node != None):
			print node.key
			node = node.next


l = Queue()
l.insert(10)
l.insert(20)
l.insert(30)
l.insert(20)
l.remove()
l.printAll()