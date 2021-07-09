class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        
        def f(root):
            if root == None:
                return (100000, 0)
            fl0, fl1 = f(root.left)
            fr0, fr1 = f(root.right)
            f1 = fl0 + fr0 + 1
            f0 = min(f1, min(fl1 + fr0, fl0 + fr1))
            return (f0, f1)
        
        return f(root)[0]