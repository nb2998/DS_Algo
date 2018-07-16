package Lec9;

public class BST {

	class Node {
		int data;
		Node left, right;

		Node(int data) {
			this.data = data;
		}
	}

	Node root;

	public BST(int[] arr) {
		this.root = constructBST(arr, 0, arr.length - 1);
	}
 
	
	// REVISE Constructing BST using inorder traversal
	private Node constructBST(int[] arr, int lo, int hi) {
		if (lo > hi)
			return null;
		int mid = (lo + hi) / 2;

		Node nn = new Node(arr[mid]);
		nn.left = constructBST(arr, lo, mid - 1);
		nn.right = constructBST(arr, mid + 1, hi);

		return nn;
	}
	
	public void display() {
		System.out.println("************** ");
		display(this.root);
		System.out.println("************** ");
	}

	private void display(Node node) {
		if(node==null) return;
		StringBuilder sb = new StringBuilder();
		if(node.left!=null) sb.append(node.left.data + " => ");
		else sb.append("END => ");
		
		sb.append(node.data);
		
		if(node.right!=null) sb.append(" <= "+node.right.data);
		else sb.append(" <= END");
		
		System.out.println(sb.toString());
		
		if(node.left!=null) display(node.left);
		if(node.right!=null) display(node.right);
	}
	
	public boolean find(int key) {
		return find(key, this.root);
	}
	
	private boolean find(int key, Node node) {
		if(node==null) return false;
		if(key == node.data) return true;
		else if(key < node.data) {
			if(find(key, node.left)) return true;
		}
		else {
			if(find(key, node.right)) return true;
		}
		
		return false;
	}
	
	public int max() {
		return max(this.root);
	}
	
	private int max(Node node) {
		if(node.right == null) return node.data;
		return max(node.right);
	}
	
	public void add(int item) {
		add(this.root, item);
	}

	private void add(Node node, int item) {
		if(item<node.data) {
			if(node.left==null) {
				Node nn = new Node(item);
				node.left = nn;
				return;
			} else {
				add(node.left, item);
			}
			
		} else {
			if(node.right==null) {
				Node nn = new Node(item);
				node.right=nn;
				return;
			} else {
				add(node.right, item);
			}
			
		}
	}
	
	public void remove(int item) {
		remove(this.root, null, false, item);
	}
	
	private void remove(Node node, Node parent, boolean isLeft, int item) {
		if(node==null) return;
		
		if(item<node.data) {
			remove(node.left, node, true, item);
		} else if(item > node.data) {
			remove(node.right, node, false, item);
		} else {
			
			if(node.left==null && node.right==null) {
				if(isLeft) parent.left = null;
				else parent.right = null;
			} 
			
			else if(node.left==null && node.right!=null) {
				if(isLeft) parent.left = node.right;
				else parent.right = node.right;
			}
			
			else if(node.left!=null && node.right==null) {
				if(isLeft) parent.left = node.left;
				else parent.right = node.left;
			}
			
			else {
				
				int max = this.max(node.left);
				node.data = max;
				remove(node.left, node, true, max);
				
			}
			
			
		}
	}
	
	public void printInRange(int sv, int fv) {
		printInRange(this.root, sv, fv);
	}

	private void printInRange(Node node, int sv, int fv) {
		
		if(node==null) return;
		
		if(node.data>=sv && node.data<=fv) {
			printInRange(node.left, sv, fv);
			System.out.print(node.data+" ");
			printInRange(node.right, sv, fv);
		}
		else if(node.data<sv) printInRange(node.right, sv, fv);
		else if(node.data>fv) printInRange(node.left, sv, fv);
		
		
	}

	private class Mover{
		int sum;
	}
	
	public void replaceWithSumOfLarger() {
		Mover mover = new Mover();
		mover.sum=0;
		replaceWithSumOfLarger(this.root, mover);
	}
	
	private void replaceWithSumOfLarger(Node node, Mover mover) {
		if(node==null) return;
		
		replaceWithSumOfLarger(node.right, mover);
		int temp = node.data;
		node.data= mover.sum;
		mover.sum+=temp;
		
		replaceWithSumOfLarger(node.left, mover);	
	}

}
