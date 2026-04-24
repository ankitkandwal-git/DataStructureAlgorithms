class NonOverlappingIntervals:
    def minRemoveOverlap(self,intervals):
        n = len(intervals)
        if n==0:
            return 0
        intervals.sort(key=lambda x:x[1])
        count = 1
        end = intervals[0][1]
        for i in range(1,n):
            if intervals[i][0]>=end:
                count+=1
                end = intervals[i][1]
        return n-count

n = int(input("Enter the number of intervals: "))
intervals = []
for _ in range(n):
    start, end = map(int, input("Enter the interval (start end): ").split())
    intervals.append([start, end])

obj = NonOverlappingIntervals()
print("Minimum number of intervals to remove:", obj.minRemoveOverlap(intervals))