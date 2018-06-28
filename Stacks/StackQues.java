package Lec5;

import java.util.ArrayList;

import Lec5.Stack;

public class StackQues {

	static void displayRev(Stack s) throws Exception {

		if (s.isEmpty())
			return;

		int ele = s.pop();
		displayRev(s);
		System.out.print(ele + " ");
		s.push(ele);
	}

	static void actualRev(Stack s, Stack helper) throws Exception {
		if (s.isEmpty()) {

			if (helper.isEmpty())
				return;
			int temph = helper.pop();
			actualRev(s, helper);
			s.push(temph);
			return;
		}

		helper.push(s.pop());
		actualRev(s, helper);
	}

	// static ArrayList<Integer> stockSpan(int[] arr, int n) {
	// ArrayList<Integer> al = new ArrayList<>();
	// Stack s = new Stack();
	// for(int i=0; i<n; i++) {
	// s.push(arr[i]);
	// }
	//
	// while(!s.isEmpty()) {
	// Stack helper=new Stack();
	// int ele=s.pop();
	// int ctr=0;
	// boolean flag = false;
	// while(!s.isEmpty() && s.peek()<ele) {
	// helper.push(s.pop());
	// ctr++;
	// }
	// if(!s.isEmpty() && s.peek()>=ele) {
	// al.add(ctr+1);
	// flag=true;
	// }
	// if(!flag) al.add(1);
	// while(!helper.isEmpty()) s.push(helper.pop());
	//
	//
	// }
	// return al;
	// }

	static int[] stockSpan(int[] arr, int n) throws Exception {
		int[] ans = new int[n];

		Stack s = new Stack();
		s.push(0);
		ans[0] = 1;

		for (int i = 1; i < arr.length; i++) {
			while (!s.isEmpty() && arr[s.peek()] < arr[i]) {
				s.pop();
			}
			if (s.isEmpty()) {
				ans[i] = i + 1;
			} else {
				ans[i] = i - s.peek();
			}
			s.push(i);
		}
		return ans;

	}

	static void nextGreatest(int[] arr, int n) throws Exception {
		// int[] ans = new int[n];

		Stack s = new Stack();
		s.push(arr[0]);

		for (int i = 1; i < n; i++) {

			while (!s.isEmpty() && arr[i] > s.peek())
				System.out.println(s.pop() + "->" + arr[i]);
			
			s.push(arr[i]);
		}

		while (!s.isEmpty()) {
			System.out.println(s.pop() + " -> -1 ");
		}

	}

	public static void main(String[] args) throws Exception {
		Stack s = new Stack();
		s.push(10);
		s.push(20);
		s.push(30);
		s.push(40);
		System.out.println("Original");
		s.display();
		System.out.println();
		System.out.println("Rev disp");
		displayRev(s);
		System.out.println();
		System.out.println("Original");
		s.display();
		System.out.println();
		System.out.println("Rev actual");
		actualRev(s, new Stack());
		s.display();
		System.out.println();
		int[] arr = { 10, 5, 13, 17, 12, 9, 15, 6, 11 };
		int[] ans = stockSpan(arr, arr.length);
		for (int i = 0; i < ans.length; i++) {
			System.out.print(ans[i] + " ");
		}

		int[] arr1 = { 5, 60, 10, 30, 40 };
		int[] arr2 = { 2, 5, 13, 1, 6, 25 };
		System.out.println();
		nextGreatest(arr1, arr1.length);
		System.out.println();

		nextGreatest(arr2, arr2.length);
	}
}
