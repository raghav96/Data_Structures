class Node:
	def __init__(self, value):
		self.key = value
		self.next = None
		self.prev = None

class Deque:
	def __init__(self, value=None):
		self.head = None
		self.tail = None

	def head(self):
		return self.head

	def tail(self):
		return self.tail

	def insertHead(self, value):
		val = Node(value)
		if self.head == None:
			self.head = val
			self.tail = val
		else:
			val.next = self.head
			self.head = val

	def insertTail(self, value):
		val = Node(value)
		if self.head == None:
			self.head = val
			self.tail = val
		else:
			val.prev = self.tail
			self.tail.next = val
			self.tail = val


	def removeHead(self):
		if self.head == None:
			print "Empty deque"
		else:
			node = self.head.next
			self.head = node
			self.head.prev = None

	def removeTail(self):
		if self.head == None:
			print "Empty deque"
		else:
			node = self.tail.prev
			self.tail = node
			self.tail.next = None


	def printAll(self):
		node = self.head
		while(node != None):
			print node.key
			node = node.next


l = Deque()
l.insertHead(10)
l.insertHead(20)
l.insertTail(30)
l.insertTail(20)
l.insertHead(20)
l.printAll()
print "---"
l.removeTail()
l.removeHead()
l.printAll()