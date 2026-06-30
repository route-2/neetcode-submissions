from sortedcontainers import SortedDict
class TimeMap:

    def __init__(self):
        self.mp = defaultdict(SortedDict)

        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.mp[key][timestamp] = value
        

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.mp:
            return ""
        timestamps = self.mp[key]
        idx = timestamps.bisect_right(timestamp) - 1
        if idx >= 0:
            return timestamps.peekitem(idx)[1]
            
        return ""
        

        
