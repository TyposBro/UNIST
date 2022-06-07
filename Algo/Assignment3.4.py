import heapq
import math


def min_distance(points, n):
    distance = 0.0
    node, distance, nodes = [(0, 0)], 0, set(range(n))
    heapq.heapify(node)
    while nodes:
        d, i = heapq.heappop(node)
        while i not in nodes:
            d, i = heapq.heappop(node)
        distance += d
        nodes.remove(i)
        for j in nodes:
            heapq.heappush(node, (math.sqrt((
                points[j][0] - points[i][0]) ^ 2 + (points[j][1] - points[i][1]) ^ 2), j))
    return distance
