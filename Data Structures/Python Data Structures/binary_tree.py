class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root == None:
            self.root = Node(data)
        else:
            self._insert(data, self.root)

    def _insert(self, data, current_node):
        if data < current_node.data:
            if current_node.left == None:
                current_node.left = Node(data)
            else:
                self._insert(data, current_node.left)
        else:
            if current_node.right == None:
                current_node.right = Node(data)
            else:
                self._insert(data, current_node.right)


    def print_tree(self):
        if self.root != None:
            self._print_tree(self.root)

    def _print_tree(self, current_node):
        if current_node != None:
            self._print_tree(current_node.left)
            print(str(current_node.data))
            self._print_tree(current_node.right)


    def size_of_tree(self):
        if self.root == None:
            return 0
        else:
            self._size_of_tree(self, current_node)

    def _size_of_tree(self, current_node):
        pass






if __name__ == '__main__':
    btree = BinaryTree()
    btree.insert(3)
    btree.insert(4)
    btree.insert(0)
    btree.insert(8)
    btree.insert(2)
    btree.print_tree()
