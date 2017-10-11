# Inspired by pseudocode from https://brilliant.org/wiki/ford-fulkerson-algorithm/ 
# Author: Raghav Ravisankar

from collections import defaultdict

class Node:
	def __init__(self, value):
		self.value = value

	def setValue(self, value):
		self.value = value

	def getValue(self, value):
		return self.value

class Edge:
	def __init__(self, a, b, cap):
		self.a = a
		self.b = b
		self.cap = cap
		self.flow = 0
		self.backflow = None

class MaxFlow:
	def __init__(self):
		self.vertices = []
		self.edges = defaultdict(list)
		self.source = None
		self.sink = None

	def getVertex(self, value):
		for vert in self.vertices:
			if value == vert.value:
				return vert
		return None

	def getEdges(self):
		allEdges = []
		for vert in self.vertices:
			for edge in self.edges[vert.value]:
				allEdges.append(edge)
		return allEdges

	def setSource(self, vert):
		self.source = vert

	def setSink(self, vert):
		self.sink = vert

	def addVertex(self, name):
		if (self.getVertex(name)):
			return "Duplicate vertex"
		if (self.source == None):
			self.source = Node(name)
		if (self.sink == None and self.source != Node(name)):
			self.sink = Node(name)
		self.vertices.append(Node(name))
		self.edges[name] = []

	def addEdge(self, a, b, cap):
		if(self.getVertex(a) == None or self.getVertex(b) == None):
			return "Vertices must be added to the graph first"
		newEdge = Edge(a, b, cap)
		backEdge = Edge(b, a, 0)
		newEdge.backflow = backEdge
		backEdge.backflow = newEdge
		self.edges[a].append(newEdge)
		self.edges[b].append(backEdge)

	
	def getPath(self, source, sink, path):
		if (source == sink):
			return path
		for edge in self.edges[source]:
			res = edge.cap - edge.flow
			if res > 0 and not (edge, res) in path:
				rec_val = self.getPath(edge.b, sink, path + [(edge, res)])
				if rec_val != None:
					return rec_val

	def fordFulkerson(self):
		if self.source == None or self.sink == None:
			return "Source or sink not set"
		path = self.getPath(self.source, self.sink, [])
		while path != None:
			flow = min(edge[1] for edge in path)
			for edge, res in path:
				edge.flow += flow
				edge.backflow.flow -= flow
			path = self.getPath(self.source, self.sink, [])

		max_flow = 0
		for edge in self.edges[self.source]:
			max_flow += edge.flow
		return max_flow


fn = MaxFlow()
fn.addVertex('s')
fn.setSource('s')
fn.addVertex('t')
fn.setSink('t')
map(fn.addVertex, ['a', 'b','c','d'])
fn.addEdge('s', 'a', 4)
fn.addEdge('a', 'b', 4)
fn.addEdge('b', 't', 2)
fn.addEdge('s', 'c', 3)
fn.addEdge('c', 'd', 6)
fn.addEdge('d', 't', 6)
fn.addEdge('b', 'c', 3)
print [vertex.value for vertex in fn.vertices]
print ['%s -> %s' % (e.a, e.b) for e in fn.getEdges()]
print fn.fordFulkerson()







