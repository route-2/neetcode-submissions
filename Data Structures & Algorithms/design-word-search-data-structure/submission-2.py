
class WordDictionary:
    def __init__(self):
        self.words = set()
    
    def addWord(self, word: str) -> None:
        self.words.add(word)
    
    def search(self, word: str) -> bool:
        for w in self.words:
            if len(w) == len(word):
                if all(c1 == c2 or c2 == '.' for c1, c2 in zip(w, word)):
                    return True
        return False