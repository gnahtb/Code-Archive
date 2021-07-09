class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        levels = []
        
        def dfs(u, lv):
            if u == None:
                return
            if len(levels) < lv:
                levels.append([])
            levels[lv - 1].append(u.val)
            dfs(u.left, lv + 1)
            dfs(u.right, lv + 1)
        
        dfs(root, 1)
        return levels