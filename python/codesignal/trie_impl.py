from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.is_end_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        iter = self.root

        for character in word:
            if not character in iter.children:
                iter.children[character] = TrieNode()
            iter = iter.children[character]
        iter.is_end_word = True
    
    def search(self, word: str) -> bool:
        iter = self.root

        for character in word:
            if not character in iter.children:
                return False
            iter = iter.children[character]
        return iter.is_end_word

    def startsWith(self, prefix: str) -> bool:
        iter = self.root

        for character in prefix:
            if not character in iter.children:
                return False
            iter = iter.children[character]
        return True
    

trie = Trie()
trie.insert("apple")
res = trie.search("apple")
print(res)
res = trie.search("app")
print(res)
res = trie.startsWith("app")
print(res)