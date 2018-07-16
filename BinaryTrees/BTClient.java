package Lec9;

public class BTClient {

	// 10 true 20 true 25 false false true 30 true 80 false false false true 15 true 45 false false true 70 false false
	// 10 true 20 true 25 false false true 30 true 80 false false false true 15 true 45 false false true 70 false true 90 false true 100 false false
	// 10 true 20 true 40 true 50 false false false false true 30 false true 60 false false
	public static void main(String[] args) {
		 BinaryTree bt = new BinaryTree();
		 bt.display();
		 System.out.println(bt.pathSum(120));
//		 System.out.println("Size = "+bt.size());
//		 System.out.println("Max = "+bt.max());
//		 System.out.println("Height = "+bt.height());
		//
		// bt.preOrder();
		// System.out.println();
		// bt.inOrder();
		// System.out.println();
		// bt.postOrder();
		// System.out.println();
		// bt.levelOrder();
		// System.out.println();
		// bt.levelOrderIt();
		// System.out.println();
//		 System.out.println(bt.isBalanced());
		//
		// System.out.println();
//		 System.out.println(bt.isBalancedBtr());
		//
		// System.out.println();
		// System.out.println("Diameter : "+bt.diameter());
		// System.out.println();
		// System.out.println("Diam 2: "+ bt.diameterBtr());

		// int[] pre = {10, 20, 40, 50, 30};
		// int[] in = {40, 20, 50, 10, 30};

//		int[] pre = { 10, 20, 40, 50, 30, 80, 70 };
//		int[] post = { 40, 70, 60, 50, 20, 40, 30, 10 };
//		// int[] in= {40, 20, 50, 10, 80, 30, 70};
//		int[] in = { 40, 20, 70, 60, 50, 10, 30, 40 };
//		BinaryTree bt2 = new BinaryTree(post, in);
//		bt2.display();

//		int[] pre1 = { 100, 5, 3, 7, 20, 15, 25, 22, 30, 40 };
//		int[] in1 = { 3, 5, 7, 100, 15, 20, 22, 25, 30, 40 };
//		BinaryTree bt3 = new BinaryTree(pre1, in1);
//		bt3.display();
//		bt3.largestBST();

	}
}
