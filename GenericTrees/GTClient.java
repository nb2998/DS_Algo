package Lec8;

public class GTClient {

	// 10 3 20 2 50 0 60 1 80 1 90 0 30 0 40 1 70 0
	
//	10 2 20 2 40 1 70 1 100 0 50 0 30 2 60 1 80 0 70 0
	
//	10 3 20 2 50 0 60 3 80 3 140 0 150 0 160 0 90 0 100 2 110 0 120 1 130 0 30 0 40 1 70 0
	public static void main(String[] args) {
		GenericTree gt = new GenericTree();
		gt.display();

		System.out.println("Size = " + gt.size());
		System.out.println("Max = " + gt.maxNode());
		System.out.println("found "+ gt.found(50));
		System.out.println("found "+ gt.found(70));
		System.out.println("found "+ gt.found(400));
		System.out.println("found "+ gt.found(11));
		System.out.println("Height = "+gt.height());
		
//		gt.mirror();
//		gt.display();
		
//		gt.rightView();
//		gt.levelOrderLine();
		gt.levelOrderR();
		System.out.println();
//		gt.display();
		gt.levelOrderI();
	}
}
