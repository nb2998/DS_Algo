package Lec9;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class BinaryTree {

	private class Node {
		int data;
		Node left, right;

		Node(int data) {
			this.data = data;
		}
	}

	Scanner scn = new Scanner(System.in);
	private Node root;

	public BinaryTree() {
		this.root = takeInput(null, false);
	}

	public BinaryTree(int[] pre, int[] in) {
		this.root = construct(pre, 0, pre.length - 1, in, 0, in.length - 1);
		// this.root = constructPost(post, 0, post.length-1, in, 0, in.length-1);
	}

	private Node construct(int[] pre, int pLo, int pHi, int[] in, int iLo, int iHi) {
		if (iLo > iHi || pLo > pHi)
			return null;

		int rootEle = pre[pLo];

		Node nn = new Node(rootEle);

		int pos = 0;
		for (int i = iLo; i <= iHi; i++) {
			if (in[i] == rootEle) {
				pos = i;
				break;
			}
		}

		nn.left = construct(pre, pLo + 1, pHi, in, iLo, pos - 1);
		nn.right = construct(pre, pLo + (pos - iLo) + 1, pHi, in, pos + 1, iHi);

		return nn;
	}

	private Node constructPost(int[] post, int pLo, int pHi, int[] in, int iLo, int iHi) {

		if (iLo > iHi || pLo > pHi || iLo < 0 || pLo < 0 || iHi > in.length - 1 || pHi > post.length - 1)
			return null;

		int rootEle = post[pHi];

		Node nn = new Node(rootEle);

		int pos = 0;
		for (int i = iLo; i <= iHi; i++) {
			if (in[i] == rootEle) {
				pos = i;
				break;
			}
		}

		nn.left = constructPost(post, pLo, pHi - (iHi - pos) - 1, in, iLo, pos - 1);
		nn.right = constructPost(post, pHi - (iHi - pos), pHi - 1, in, pos + 1, iHi);

		return nn;
	}

	private Node takeInput(Node parent, boolean isLeftOrRight) {

		if (parent == null) {
			System.out.println("Enter the data for root node: ");
		} else {
			if (isLeftOrRight)
				System.out.println("Enter the data of left child of " + parent.data + ": ");
			else
				System.out.println("Enter the data for right child of " + parent.data + ": ");
		}

		Node nn = new Node(scn.nextInt());
		System.out.println("Does " + nn.data + " have any left child? ");
		boolean choice = scn.nextBoolean();
		if (choice)
			nn.left = takeInput(nn, true);

		System.out.println("Does " + nn.data + " have any right child? ");
		choice = scn.nextBoolean();
		if (choice)
			nn.right = takeInput(nn, false);

		return nn;
	}

	public void display() {
		display(this.root);
	}

	private void display(Node node) {

		StringBuilder sb = new StringBuilder();

		if (node.left != null)
			sb.append(node.left.data + " => ");
		else
			sb.append("END =>");
		sb.append(node.data);
		if (node.right != null)
			sb.append(" <= " + node.right.data);
		else
			sb.append("<= END");
		System.out.println(sb.toString());

		if (node.left != null)
			display(node.left);
		if (node.right != null)
			display(node.right);

	}

	public int size() {
		return size(this.root);
	}

	private int size(Node node) {
		if (node == null) 
			return 0;

		int ctr = 1;
		if (node.left != null)
			ctr += size(node.left);
		if (node.right != null)
			ctr += size(node.right);
		return ctr;

	}

	public int max() {
		return max(this.root);
	}

	private int max(Node node) {
		int max = node.data;
		if (node.left != null)
			max = Math.max(max, max(node.left));
		if (node.right != null)
			max = Math.max(max, max(node.right));

		return max;
	}

	public int height() {
		return height(this.root);
	}

	private int height(Node node) {
		if (node == null)
			return -1;
		int h = -1;
		if (node.left != null)
			h = Math.max(h, height(node.left));
		if (node.right != null)
			h = Math.max(h, height(node.right));
		return h + 1;
	}

	public void preOrder() {
		System.out.println("Pre Order ");
		preOrder(this.root);
	}

	private void preOrder(Node node) {
		if (node == null)
			return;
		System.out.print(node.data + " ");
		preOrder(node.left);
		preOrder(node.right);
	}

	public void postOrder() {
		System.out.println("Post order ");
		postOrder(this.root);
	}

	private void postOrder(Node node) {
		if (node == null)
			return;
		postOrder(node.left);
		postOrder(node.right);
		System.out.print(node.data + " ");
	}

	public void inOrder() {
		System.out.println("In order ");
		inOrder(this.root);
	}

	private void inOrder(Node node) {
		if (node == null)
			return;
		inOrder(node.left);
		System.out.print(node.data + " ");
		inOrder(node.right);
	}

	public void levelOrder() {
		System.out.println("Level Order: ");
		int ht = this.height();
		for (int i = 0; i <= ht; i++) {
			printAtLevel(this.root, 0, i);
			System.out.println();
		}
	}

	private void printAtLevel(Node node, int curr, int level) {
		if (curr == level)
			System.out.print(node.data + " ");

		if (node.left != null)
			printAtLevel(node.left, curr + 1, level);
		if (node.right != null)
			printAtLevel(node.right, curr + 1, level);
	}

	public void levelOrderIt() {
		LinkedList<Node> queue = new LinkedList<>();
		queue.addLast(this.root);
		while (!queue.isEmpty()) {
			Node nr = queue.removeFirst();
			System.out.print(nr.data + " ");
			if (nr.left != null)
				queue.addLast(nr.left);
			if (nr.right != null)
				queue.addLast(nr.right);
		}

	}

	public boolean isBalanced() {
		return isBalanced(this.root);
	}

	private boolean isBalanced(Node node) {

		if (node == null)
			return true;

		if (Math.abs(this.height(node.left) - this.height(node.right)) != 0
				&& Math.abs(this.height(node.left) - this.height(node.right)) != 1) {
			return false;
		} else {
			return isBalanced(node.left) && isBalanced(node.right);
		}

	}

	class IsBalPair {
		boolean isBal;
		int height;

		public IsBalPair(boolean isBal, int height) {
			this.isBal = isBal;
			this.height = height;
		}
	}

	public boolean isBalancedBtr() {
		return isBalancedBtr(this.root).isBal;
	}

	private IsBalPair isBalancedBtr(Node node) {

		if (node == null)
			return new IsBalPair(true, -1);

		IsBalPair left = isBalancedBtr(node.left);
		IsBalPair right = isBalancedBtr(node.right);

		if (Math.abs(left.height - right.height) != 0 && Math.abs(left.height - right.height) != 1) {
			return new IsBalPair(false, Math.max(left.height, right.height) + 1);
		} else {
			return new IsBalPair(left.isBal && right.isBal, Math.max(left.height, right.height) + 1);
		}

	}

	public int diameter() {
		return diameter(this.root);
	}

	private int diameter(Node node) {

		if (node == null)
			return 0;

		int dLeft = diameter(node.left);
		int dRight = diameter(node.right);

		// self participation
		int sp = this.height(node.left) + this.height(node.right) + 2;

		return Math.max(sp, Math.max(dLeft, dRight));
	}

	class DiamAndHeight {
		int diam;
		int height;

		public DiamAndHeight(int diam, int height) {
			this.diam = diam;
			this.height = height;
		}
	}

	public int diameterBtr() {
		return diameterBtr(this.root).diam;
	}

	private DiamAndHeight diameterBtr(Node node) {
		if (node == null)
			return new DiamAndHeight(0, -1);
		DiamAndHeight left = diameterBtr(node.left);
		DiamAndHeight right = diameterBtr(node.right);

		int spHeight = Math.max(left.height, right.height) + 1;
		int spDiam = left.height + right.height + 2;
		DiamAndHeight sp = new DiamAndHeight(Math.max(spDiam, Math.max(left.diam, right.diam)), spHeight);

		return sp;
	}

	private class BSTPair {
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		Node largestBSTRoot = null;
		int size = 0;
		boolean isBST = true;

	}

	public void largestBST() {
		BSTPair pair = largestBST(this.root);
		System.out.println(pair.size);
		System.out.println(pair.largestBSTRoot.data);
	}

	private BSTPair largestBST(Node node) {
		if (node == null) {
			BSTPair bp = new BSTPair();
			return bp;
		}

		BSTPair lp = largestBST(node.left);
		BSTPair rp = largestBST(node.right);
		BSTPair sp = new BSTPair();

		sp.max = Math.max(node.data, Math.max(lp.max, rp.max));
		sp.min = Math.min(node.data, Math.min(lp.min, rp.min));

		if (node.data > lp.max && node.data < rp.min && lp.isBST && rp.isBST) {
			sp.largestBSTRoot = node;
			sp.size = lp.size + rp.size + 1;
			sp.isBST = true;
		} else {
			if (lp.size >= rp.size) {
				sp.largestBSTRoot = lp.largestBSTRoot;
				sp.size = lp.size;
				sp.isBST = false;

			} else {
				sp.largestBSTRoot = rp.largestBSTRoot;
				sp.size = rp.size;
				sp.isBST = false;
			}

		}

		return sp;
	}

//	ArrayList<ArrayList<Integer>> al = new ArrayList<>();
//    ArrayList<Integer> ans = new ArrayList<>();
	public ArrayList<ArrayList<Integer>> pathSum(int B) {
        ArrayList<ArrayList<Integer>> al = new ArrayList<>();
        path(this.root, B, 0, new ArrayList<>(), al, 0);
        return al;
    }
    
    boolean path(Node A, int B, int sum, ArrayList<Integer> ans, ArrayList<ArrayList<Integer>> al, int num){
        
        if(A==null) {
            // ans.removeAll(ans);
            return false;
        }
        if(sum>B){
            // ans.remove(A.val);
            return false;
        }
        if(A.left==null && A.right==null && sum+A.data!=B) {
        	return false;
        }
        if(A.left==null && A.right==null && sum+A.data==B){
//            ArrayList<Integer> temp = ans;
            // System.out.println(temp.size());
            // ans.removeAll(ans);
        	ans.add(A.data);
             System.out.println(ans);
            if(ans.size()!=0) al.add(num, ans);
            num++;
            System.out.println(al);
            // ans = new ArrayList<>();
            return true;
        }
        
        ans.add(A.data);
        boolean isValid = path(A.left, B, sum+A.data, ans, al, num) || path(A.right, B, sum+ A.data, ans, al, num);
        if(!isValid && ans.contains(A.data)) {
            ans.remove(Integer.valueOf(A.data));
        }
        return false;
    }
	
}
