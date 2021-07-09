/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
 var buildTree = function(preorder, inorder) {
    if (preorder.length < 1 || inorder.length < 1) return null;
    let i = 0;
    for (; i < inorder.length; ++i)
        if (preorder[0] == inorder[i]) break;
    let l = buildTree(preorder.slice(1, i + 1), inorder.slice(0, i));
    let r = buildTree(preorder.slice(i + 1), inorder.slice(i + 1));
    return {'val': preorder[0], 'left': l, 'right': r};
};