package Lec8;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class GenericTree {

	class Node {
		int data;
		ArrayList<Node> children = new ArrayList<>();

		Node(int data) {
			this.data = data;
		}
	}

	Scanner scn = new Scanner(System.in);
	private Node root;

	public GenericTree() {

		this.root = takeInput(null, -1);

	}

	private Node takeInput(Node parent, int ith) {

		if (parent == null)
			System.out.println("Enter input for root node: ");
		else
			System.out.println("Enter input for " + ith + " child of " + parent.data);

		Node nn = new Node(scn.nextInt());

		System.out.println("Enter number of children for " + nn.data);
		int noc = scn.nextInt();

		for (int i = 0; i < noc; i++) {
			Node child = takeInput(nn, i);
			nn.children.add(child);
		}

		return nn;

	}

	public void display() {
		display(this.root);
	}

	private void display(Node node) {

		StringBuilder sb = new StringBuilder();
		sb.append(node.data + " -> ");
		for (int i = 0; i < node.children.size(); i++) {
			sb.append(node.children.get(i).data + " ");

		}
		sb.append(".");
		System.out.println(sb.toString());

		for (int i = 0; i < node.children.size(); i++) {
			display(node.children.get(i));
		}

	}

	public int size() {
		return size(this.root);
	}

	private int size(Node node) {
		int count = 0;
		for (Node child : node.children)
			count += size(child);
		return count + 1;
	}

	public int maxNode() {
		return maxNode(this.root);
	}

	private int maxNode(Node node) {

		int max = node.data;
		for (Node child : node.children) {
			max = Math.max(max, maxNode(child));
		}
		return max;
	}

	public int height() {
		return height(this.root);
	}

	private int height(Node node) {
		int height = -1;
		for (Node child : node.children) {
			height = Math.max(height(child), height);
		}
		return height + 1;
	}

	public boolean found(int key) {
		return found(this.root, key);
	}

	private boolean found(Node node, int key) {

		if (node.data == key)
			return true;
		for (Node child : node.children) {
			if (found(child, key))
				return true;
		}

		return false;
	}

	public void mirror() {
		mirror2(this.root);
	}

	private void mirror(Node node) {

		java.util.Collections.reverse(node.children);
		for (int i = 0; i < node.children.size(); i++) {
			// Node temp = node.children.get(i);
			// node.children.set(i, node.children.get(node.children.size()-i));
			// node.children.set(node.children.size()-i, temp);

			mirror(node.children.get(i));
		}
	}

	private void mirror2(Node node) {

		for (int i = 0; i <= node.children.size() / 2; i++) {
			Node temp = node.children.get(i);
			node.children.set(i, node.children.get(node.children.size() - i - 1));
			node.children.set(node.children.size() - i - 1, temp);
		}

		for (int i = 0; i < node.children.size(); i++) {
			mirror(node.children.get(i));
		}
	}

	public void rightView() {
		rightView(this.root, 0);
	}

	// TODO
	private void rightView(Node node, int level) {

		// for(int i=0; i<node.children.size(); i++) {
		// rightView();
		//
		//
		//// rightView(node.children.get(i));
		// if(i==node.children.size()-1) {
		// System.out.print(node.children.get(i).data+" ");
		//
		// }
		// }
	}

	public void levelOrderR() {
		int height=this.height();
		for(int i=0; i<=height; i++) {
			printAtLevel(this.root, 0, i);
		}
		
	}

	
	private void printAtLevel(Node node, int curr, int level) {
		
		if(curr==level) {
			System.out.print(node.data+" ");
		}
		
		for(Node child : node.children) {
			printAtLevel(child, curr+1, level);
		}
		
		
	}

	
	public void levelOrderI() {
		
		LinkedList<Node> queue = new LinkedList<>();
		queue.addLast(this.root);
		
		while(!queue.isEmpty()) {
			Node nRem = queue.removeFirst();
			System.out.print(nRem.data+" ");
			for(Node child: nRem.children) {
				queue.addLast(child);
			}
		}
	}
	
}
