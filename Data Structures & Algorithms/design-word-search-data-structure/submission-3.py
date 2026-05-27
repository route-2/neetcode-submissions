class WordDictionary:
    def __init__(self):
        self.words = set()
    
    def addWord(self, word: str) -> None:
        self.words.add(word)
    
    def search(self, word: str) -> bool:
        # Check each word in dictionary
        for w in self.words:
            # First check: same length?
            if len(w) != len(word):
                continue
            
            # Go through each position
            match = True
            for i in range(len(w)):
                c1 = w[i]        # Character from dictionary
                c2 = word[i]     # Character from search pattern
                
                # Check if they match
                if c1 == c2:
                    # Exact match ✓
                    continue
                elif c2 == '.':
                    # Wildcard matches anything ✓
                    continue
                else:
                    # No match ✗
                    match = False
                    break
            
            # If this word matched, return True
            if match:
                return True
        
        # No matching word found
        return False


