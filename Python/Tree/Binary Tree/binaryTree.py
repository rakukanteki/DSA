class BinarySearchTree:
    def __init__(self, data):
        self.data = data
        self.right = None
        self.left = None

    def add_child(self, data):
        # Check the value first.
        if data == self.data:  # Base Case
            return
        elif data < self.data:
            # Add to the left.
            if self.left:  # If there any node present already ?
                self.left.add_child(data)
            else:  # If there is no node.
                self.left = BinarySearchTree(data)
        else:
            # Add to the right.
            if self.right:  # If there any node present already ?
                self.right.add_child(data)
            else:  # If there is no node.
                self.right = BinarySearchTree(data)

    def inorder_traversal(self):
        elements = []
        # Go check Left
        if self.left:
            elements += self.left.inorder_traversal()

        # Go check base.
        elements.append(self.data)

        # Go check Right.
        if self.right:
            elements += self.right.inorder_traversal()

        return elements

    # Searching
    def search(self, value):
        if self.data == value:
            return True

        if value < self.data:
            # Might be present in left sub-tree.
            if self.left:  # Is there any node present?
                return self.left.search(value)
            else:
                return False

        if value > self.data:
            # Might be present in right sub-tree.
            if self.right:  # Is there any node present?
                return self.right.search(value)
            else:
                return False


    def find_max(self):
        # In BST, Maximum element is present in Right Side. So no checking in Left is necessary.
        if self.right is None:
            return self.data
        else:
            return self.right.find_max()

    def find_min(self):
        # In BST, Minimum element is present in Left Side. So no checking in Right is necessary.
        if self.left is None:
            return self.data
        else:
            return self.left.find_min()

    def calculate_sum(self):
        left_sum = self.left.calculate_sum() if self.left else 0
        right_sum = self.right.calculate_sum() if self.right else 0

        return self.data + left_sum + right_sum

def build_tree(elements):
    root = BinarySearchTree(elements[0])

    for i in range(1, len(elements)):
        root.add_child(elements[i])

    return root


if __name__ == '__main__':
    numbers = [12, 17, 18, 22, 10, 2, 18, 2]
    numbers_tree = build_tree(numbers)
    print(numbers_tree.inorder_traversal())
    print(numbers_tree.search(18))
    print("Min:", numbers_tree.find_min())
    print("Max:", numbers_tree.find_max())
    print("Sum:", numbers_tree.calculate_sum())