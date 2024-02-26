class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []
        self.parent = None

    def add_child(self, child):
        child.parent = self
        self.children.append(child)

    def get_level(self):
        # We can get levels by counting ancesters.
        level = 0
        p = self.parent
        while p:
            level += 1
            p = p.parent
        return level

    def print_tree(self):
        spaces = ' ' * self.get_level() * 4
        prefix = spaces + '|__' if self.parent else ""
        print(prefix + self.data)
        if len(self.children) > 0:  # Handling Leaf Nodes.
            for child in self.children:
                child.print_tree()  # Recursive Calls.


def build_product_tree():
    root = TreeNode("Electronics")

    laptop = TreeNode("Laptop")
    laptop.add_child((TreeNode("MacBook Air")))
    laptop.add_child((TreeNode("Surface")))
    laptop.add_child((TreeNode("ThinkPad")))
    laptop.add_child((TreeNode("Samsung")))

    cellphone = TreeNode("Cell Phones")
    cellphone.add_child(TreeNode("iPhone"))
    cellphone.add_child(TreeNode("Google Pixel"))
    cellphone.add_child(TreeNode("Samsung"))

    tv = TreeNode("Televisions")
    tv.add_child(TreeNode("LG"))
    tv.add_child(TreeNode("Vision"))
    tv.add_child(TreeNode("Samsung"))

    root.add_child(laptop)
    root.add_child(cellphone)
    root.add_child(tv)

    print(tv.get_level())
    return root


if __name__ == '__main__':
    root = build_product_tree()
    root.print_tree()