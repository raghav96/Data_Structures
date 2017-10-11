class Node:
	def __init__(self, value):
		self.key = value
		self.next = None
		self.prev = None

class Circular:
	def __init__(self):
		self.head = None
		self.tail = None
		self.count = 0

	def head(self):
		return self.head

	def tail(self):
		return self.tail

	def insertHead(self, value):

		self.count += 1
		val = Node(value)
		if self.head == None:
			self.head = val
			self.tail = val
		else:
			val.next = self.head
			self.head = val
			self.head.prev = self.tail

		print "count %d" , self.count

	def insertTail(self, value):
		self.count += 1
		val = Node(value)
		if self.head == None:
			self.head = val
			self.tail = val
		else:
			val.prev = self.tail
			self.tail.next = val
			self.tail = val
			self.tail.next = self.head

		print "count %d" , self.count


	def removeHead(self):
		self.count -= 1
		if self.head == None:
			print "Empty deque"
		else:
			node = self.head.next
			self.head = node
			self.head.prev = self.tail

		print "count %d" , self.count

	def removeTail(self):
		self.count -= 1
		if self.head == None:
			print "Empty deque"
		else:
			node = self.tail.prev
			self.tail = node
			self.tail.next = None

		print "count %d" , self.count


	def printAll(self):
		node = self.head
		i = 0
		while(i <= self.count):
			if node != None:
				print node.key
				node = node.next
			i += 1


l = Circular()
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