def min_cost_to_join_rods(rods):
    import heapq

    # Create a min-heap from the list of rods
    heapq.heapify(rods)
    total_cost = 0

    # While there is more than one rod to join
    while len(rods) > 1:
        # Pop the two smallest rods
        first = heapq.heappop(rods)
        second = heapq.heappop(rods)

        # The cost to join them is the sum of their lengths
        cost = first + second
        total_cost += cost

        # Push the new rod back into the heap
        heapq.heappush(rods, cost)

    return total_cost

n = int(input("Enter the number of rods: "))
rods = []
for _ in range(n):
    length = int(input("Enter the length of rod: "))
    rods.append(length)
    
min_cost = min_cost_to_join_rods(rods)
print("Minimum cost to join rods:", min_cost)

#