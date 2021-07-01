from collections import deque

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
    def __str__(self):
        return str(self.data)

class BT:
    def __init__(self, root=None):
        self.root = root

    def find(self, data):
        q = deque([self.root])
        while q:
            cur = q.popleft()
            if cur.data == data:
                return cur
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)
        return Node('No')

    def push(self, parentData, leftData, rightData):
        parent = self.find(parentData)
        if parent.data == 'No':
            return False
        if leftData != '.':
            parent.left = Node(leftData)
        if rightData != '.':
            parent.right = Node(rightData)
        return True

    def levelorder_traverse(self):
        q = deque([self.root])
        while q:
            cur = q.popleft()
            print(cur.data, end='')
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)
    
    def preorder_traverse(self, cur):
        if cur:
            print(cur.data, end='')
            self.preorder_traverse(cur.left)
            self.preorder_traverse(cur.right)


    def inorder_traverse(self, cur):
        if cur:
            self.inorder_traverse(cur.left)
            print(cur.data, end='')
            self.inorder_traverse(cur.right)

    def postorder_traverse(self, cur):
        if cur:
            self.postorder_traverse(cur.left)
            self.postorder_traverse(cur.right)
            print(cur.data, end='')

n = int(input())
tree = BT(Node('A'))
for _ in range(n):
    parent, left, right = input().split()
    if not tree.push(parent, left, right):
        print("Error")

tree.preorder_traverse(tree.root)
print()
tree.inorder_traverse(tree.root)
print()
tree.postorder_traverse(tree.root)
