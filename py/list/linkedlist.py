class Node:
	def __init__(self, value):
		self.key = value
		self.next = None

class LinkedList:
	def __init__(self, value=None):
		self.head = None

	def head(self):
		return self.head

	def tail(self):
		return self.head.next

	def insertHead(self, value):
		val = Node(value)
		if self.head == None:
			self.head = val
		else:
			val.next = self.head
			self.head = val

	def insertTail(self, value):
		val = Node(value)
		if self.head == None:
			self.head = val
		else:
			node = self.head
			while(node.next != None):
				node = node.next
			node.next = val

	def removeHead(self):
		if self.head == None:
			print "Empty list"
		else:
			self.head = self.head.next

	def removeTail(self):
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

l = LinkedList()
l.insertTail(10)
l.insertHead(20)
l.insertHead(30)
l.insertTail(20)
l.removeHead()
l.removeTail()
l.printAll()

