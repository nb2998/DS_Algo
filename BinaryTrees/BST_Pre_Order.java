import java.util.Stack;

public class BST_Pre_Order {

  public static void main(String[] args) throws Exception {

    // construct the binary tree given in question
    BinaryTree bt = new BinaryTree();
    BinaryTree.TreeNode root = new BinaryTree.TreeNode("1");
    bt.root = root;
    bt.root.left = new BinaryTree.TreeNode("2");
    bt.root.left.left = new BinaryTree.TreeNode("3");

    bt.root.left.right = new BinaryTree.TreeNode("4");
    bt.root.right = new BinaryTree.TreeNode("5");
    bt.root.right.right = new BinaryTree.TreeNode("6");

    // printing nodes in recursive preOrder traversal algorithm
    bt.preOrder();

    System.out.println();

    // traversing binary tree in PreOrder without using recursion
    bt.preOrderWithoutRecursion();

  }

}

class BinaryTree {
  static class TreeNode {
    String data;
    TreeNode left, right;

    TreeNode(String value) {
      this.data = value;
      left = right = null;
    }

    boolean isLeaf() {
      return left == null ? right == null : false;
    }

  }

  // root of binary tree
  TreeNode root;

  public void preOrder() {
    preOrder(root);
  }

  /**
   * traverse the binary tree in PreOrder
   * 
   * @param node
   *          - starting node, root
   */
  private void preOrder(TreeNode node) {
    if (node == null) {
      return;
    }
    System.out.printf("%s ", node.data);
    preOrder(node.left);
    preOrder(node.right);
  }

  /**
   * Java method to visit tree nodes in PreOrder traversal without recursion.
   */
  public void preOrderWithoutRecursion() {
    Stack<TreeNode> nodes = new Stack<>();
    nodes.push(root);

    while (!nodes.isEmpty()) {
      TreeNode current = nodes.pop();
      System.out.printf("%s ", current.data);

      if (current.right != null) {
        nodes.push(current.right);
      }
      if (current.left != null) {
        nodes.push(current.left);
      }
    }
  }

}