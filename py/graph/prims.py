import sys
from collections import defaultdict

class Graph:

	def __init__(self):
		self.vertices = set()
		self.edges = defaultdict(list)
		self.weights = {}

	def add_vertex(self, value):
		self.vertices.add(value)

	def remove_vertex(self, value):
		self.vertices.remove(value)
		dests = self.edges[value]
		self.edges.pop(value)
		for key in self.weights.keys():
			if key[0] == value:
				self.weights.pop(key)
		for dest in dests:
			self.edges[dest].remove(value)

	def add_edge(self, src, dest, weight):
		if(src not in self.vertices):
			self.vertices.add(src)
		if(dest not in self.vertices):
			self.vertices.add(dest)

		self.edges[src].append(dest)
		self.weights[(src, dest)] = weight

	def print_graph(self):
		print "Printing graph.. \n"
		print "vertices: ", self.vertices
		print "edges: ", self.edges.items()
		print "weights: ", self.weights

	def prims(self, start):
		visited = set()
		min_span = 99999
		mst = []
		visited.add(start)
		while (visited != set()):
			node = visited.pop()
			for edge in self.edges[node]:
				print "node:", node, "edge: ", edge
				if (min_span > self.weights[(node, edge)]):
					min_span = self.weights[(node, edge)]
					min_edge = edge
				mst.append([node, edge, self.weights[(node, edge)]])
				visited.add(edge)

			print "visited: ", visited
			print "min_span: ", min_span, " min_edge: ", min_edge
			
		tree = Graph()
		for edge in mst:
			tree.add_edge(edge[0], edge[1], edge[2])
		
		tree.print_graph()





		


sample_graph = Graph()
sample_graph.add_vertex(1)
sample_graph.add_edge(1, 2, 1)
sample_graph.add_edge(2, 3, 7)
sample_graph.add_edge(3, 4, 4)
sample_graph.add_edge(3, 5, 1)
sample_graph.print_graph()
sample_graph.prims(1)

