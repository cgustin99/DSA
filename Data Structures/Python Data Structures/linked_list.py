class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def __str__(self):
        print(str(self.head))


if __name__ == "__main__":
    llist = LinkedList()
    llist.head = Node(1)
    '''second = Node(2)
    third = Node(3)

    #Connect Nodes
    llist.head.next = second
    second.next = third

    print(llist)'''

    print(llist.head.data)
