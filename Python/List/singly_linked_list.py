# Node:Represents individual elements in the linked list.
class Node:
    def __init__(self, data=None, next=None):
        self.data = data  # Contains the value in a node.
        self.next = next  # Contains the location of the next node.


class LinkedList:
    def __init__(self):
        self.head = None  # Points to the head of the linked list.

    def insert_at_begining(self,data):
        node = Node(data, self.head)
        self.head = node

    def print(self):
        if self.head is None:
            print("Linked list is empty")
            return

        ptr = self.head  # Taking an iterator for traversing.
        list = ''  # For printing elements.
        while ptr:
            list += str(ptr.data) + ' --> '
            ptr = ptr.next

        print(list)

    def insert_at_end(self, data):
        if self.head is None:
            self.head = Node(data, None)
            return

        ptr = self.head
        while ptr.next:
            ptr = ptr.next

        ptr.next = Node(data, None)

    # Taking a list of values and then creating a linked list.
    def insert_values(self, data_list):
        self.head = None
        for data in data_list:
            self.insert_at_end(data)

    def get_length(self):
        count = 0
        ptr = self.head
        while ptr:
            count += 1
            ptr = ptr.next

        return count

    # Removing an element at a given index.
    def remove_at(self, index):
        if index < 0 or index >= self.get_length():
            raise Exception("Invalid Index")

        if index == 0:
            self.head = self.head.next
            return

        count = 0
        ptr = self.head
        while ptr:
            if count == index-1:
                ptr.next = ptr.next.next
                break

            ptr = ptr.next
            count += 1

    def insert_at(self, index, data):
        if index < 0 or index > self.get_length():
            raise Exception("Invalid Index")

        if index == 0:
            self.insert_at_begining(data)
            return

        count = 0
        ptr = self.head
        while ptr:
            if count == index - 1:
                node = Node(data, ptr.next)
                ptr.next = node
                break

            ptr = ptr.next
            count += 1


if __name__ == '__main__':
    ll = LinkedList()
    # ll.insert_at_begining(5)
    # ll.insert_at_begining(10)
    # ll.insert_at_end(69)
    ll.insert_values(["Banana", "Mango", "Coconut", "Grape"])
    ll.print()
    print("Length of the linked list: ", ll.get_length())
    ll.remove_at(2)
    ll.print()
    ll.insert_at(2, "figs")
    ll.print()
