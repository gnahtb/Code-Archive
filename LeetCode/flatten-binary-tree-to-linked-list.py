class Solution:
    def flatten(self, root: TreeNode) -> None:
        if root == None:
            return
        self.flatten(root.left)
        self.flatten(root.right)
        if root.left == None:
            return
        tail = root.left
        while tail.right != None:
            tail = tail.right
        tail.right = root.right
        root.right = root.left
        root.left = None