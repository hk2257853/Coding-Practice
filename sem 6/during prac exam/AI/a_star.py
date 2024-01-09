import networkx as nx
import matplotlib.pyplot as plt
from queue import PriorityQueue

heuristic = {}
graph = {}

def addNodeWithHeuristic(node, heuristic_val):
    heuristic[node] = heuristic_val

def addEdge(start, end, cost):
    graph.setdefault(start, []).append((end, float(cost)))
    graph.setdefault(end, []).append((start, float(cost)))

def retCost(a, b):
    for e in graph[a]:
        if e[0] == b:
            return e[1]

def aStar(src, target):

    visited = set()
    path = []
    cost = {}

    q = PriorityQueue()
    q.put((0, src))
    cost[src] = 0

    while not q.empty():
        u = q.get()[1]
        path.append(u)

        if u == target:
            print("Path:", " ".join(path))
            print("Cost (Addition of Edge Costs):", cost[u])
            break

        if u in visited:
            continue

        visited.add(u)
        for neighbour in graph[u]:
            v = neighbour[0]
            edge_cost = neighbour[1]
            if   v not in cost  or   cost[u] + edge_cost < cost[v]:
                cost[v] = cost[u] + edge_cost
                heuristic_cost = cost[v] + heuristic[v]
                q.put((heuristic_cost, v))

def plotGraph():
    G = nx.Graph()
    for node in graph:
        G.add_node(node)
    for node, edges in graph.items():
        for edge in edges:
            G.add_edge(node, edge[0], weight=edge[1])

    pos = nx.spring_layout(G)
    labels = {node: node for node in G.nodes()}
    edge_labels = {(u, v): str(d['weight']) for u, v, d in G.edges(data=True)}

    nx.draw_networkx_nodes(G, pos, node_color='lightblue', node_size=500, alpha=0.8)
    nx.draw_networkx_edges(G, pos, width=1, alpha=0.5, edge_color='gray')
    nx.draw_networkx_labels(G, pos, labels, font_size=12)
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=8)

    plt.title('Graph')
    plt.axis('off')
    plt.show()


# def plotGraph2(graph):
#     G = nx.Graph()

#     # Add nodes and edges to the graph
#     for node, edges in graph.items():
#         G.add_node(node)
#         for edge, weight in edges:
#             G.add_edge(node, edge)

#     # Generate the layout of the graph
#     pos = nx.spring_layout(G)

#     # Draw the graph
#     nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=500, alpha=0.8, width=1, edge_color='gray')

#     # Display the graph
#     plt.show()


if __name__ == '__main__':

    num_nodes = int(input("Enter the number of nodes: "))
    for i in range(num_nodes):
        node, heuristic_val = input("Enter Node and Heuristic Value separated by space: ").split()
        addNodeWithHeuristic(node, float(heuristic_val))

    num_edges = int(input("Enter the number of edges: "))
    for i in range(num_edges):
        start, end, cost = input("Enter Start node, Destination node, and Cost of the Edge separated by space: ").split()
        addEdge(start, end, float(cost))

    src = input("Enter the Start Node: ")
    target = input("Enter the Target Node: ")

    aStar(src, target)
    plotGraph()