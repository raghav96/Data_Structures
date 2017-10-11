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

	def remove_edge(self, src, dest):
		self.edges[src].remove(dest)
		self.weights.pop((src, dest))

	def print_graph(self):
		print "Printing graph.. \n"
		print "vertices: ", self.vertices
		print "edges: ", self.edges.items()
		print "weights: ", self.weights

	def djikstras(self, root):
		visited = {root: 0}
		path = {}
		dist = 0

		verts = self.vertices
		while verts:
			next_node = None 
			for node in verts:
				if node in visited:
					if next_node == None:
						next_node = node
					elif (visited[node] < visited[next_node]):
						next_node = node

			if next_node == None:
				break

			verts.remove(next_node)
			dist = visited[next_node]
			min_dist = 10000
			min_index = 0

			for edge in self.edges[next_node]:
				new_dist = dist + self.weights[(next_node,edge)]
				if (edge not in visited):
					visited[edge] = new_dist
					if(min_dist > new_dist):
						min_dist = new_dist
						print min_dist
					
			if(min_dist < 10000):
				print visited, path
				min_index = visited.values().index(min_dist)
				key = visited.keys()[min_index]
				path[next_node] = key		
		return visited, path


sample_graph = Graph()
sample_graph.add_vertex(1)
sample_graph.add_edge(1, 2, 1)
sample_graph.add_edge(2, 3, 7)
sample_graph.add_edge(3, 4, 4)
sample_graph.add_edge(3, 5, 1)
sample_graph.print_graph()
print sample_graph.djikstras(2)










