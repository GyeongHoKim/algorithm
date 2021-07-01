import sys
sys.setrecursionlimit(10**4)
input = sys.stdin.readline

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
    def __str__(self):
        return self.data

class BST:
    def __init__(self, root) -> None:
        self.root = root
    
    def insert(self, current, data):
        if current is None:
            return Node(data)
        else:
            if current.data == data:
                return current
            elif current.data < data:
                current.right = self.insert(current.right, data)
            elif current.data > data:
                current.left = self.insert(current.left, data)
        return current
    
    def postorder_traverse(self, current):
        if current:
            self.postorder_traverse(current.left)
            self.postorder_traverse(current.right)
            print(current.data)

root = int(input())
binary_search_tree = BST(Node(root))
while True:
    try:
        data = int(input())
    except:
        break
    binary_search_tree.insert(binary_search_tree.root, data)
binary_search_tree.postorder_traverse(binary_search_tree.root)