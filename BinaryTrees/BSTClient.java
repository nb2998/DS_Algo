package Lec9;

public class BSTClient {
	

	public static void main(String[] args) {
		int[] arr = {10, 20, 30, 40, 50, 60, 70};
		int[] in = {5, 10, 15, 20, 25, 30, 40};
		BST bst = new BST(in);
		bst.display();
		
		System.out.println("Find "+bst.find(30));
		System.out.println("Find "+bst.find(70));
		System.out.println("Find "+bst.find(35));
		
		System.out.println("Max: "+bst.max());
		
//		bst.add(55);
//		bst.display();
//		bst.add(22);
//		bst.display();
//		
		bst.remove(30);
		bst.display();
		
//		bst.printInRange(20, 60);
//		bst.replaceWithSumOfLarger();
//		bst.display();
	}

}
