package Lec10;

import java.util.ArrayList;

public class HeapClient {

	public static class SortedInfo implements Comparable<SortedInfo> {
		int listNo;
		int num;
		int itemNo;

		public SortedInfo(int listNo, int num, int itemNo) {
			this.listNo = listNo;
			this.num = num;
			this.itemNo = itemNo;
		}

		@Override
		public int compareTo(SortedInfo o) {
			// TODO Auto-generated method stub
			return o.num - this.num;
		}

		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return "item no " + itemNo + " list no" + listNo + " data : " + num;
		}

	}

	static ArrayList<Integer> mergeKSortedAL(ArrayList<ArrayList<Integer>> lists) {
		ArrayList<Integer> ans = new ArrayList<>();
		GenericHeap<SortedInfo> heap = new GenericHeap<>();
		for (int i = 0; i < lists.size(); i++) {
			heap.insert(new SortedInfo(i, lists.get(i).get(0), 0));
		}

		while (heap.size() != 0) {
			SortedInfo ele = heap.remove();
			ans.add(ele.num);
			if (ele.itemNo + 1 < lists.get(ele.listNo).size())
				heap.insert(new SortedInfo(ele.listNo, lists.get(ele.listNo).get(ele.itemNo + 1), ele.itemNo + 1));
		}

		return ans;
	}

	static ArrayList<Integer> kLargest(ArrayList<Integer> list) {
		ArrayList<Integer> ans = new ArrayList<>();
		return ans;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// Heap heap = new Heap();
		// heap.insert(10);
		// heap.insert(5);
		// heap.insert(18);
		// heap.insert(40);
		// heap.insert(20);
		//
		// heap.display();
		// System.out.println();
		// System.out.println(heap.remove());
		// System.out.println(heap.remove());
		// System.out.println(heap.remove());
		// System.out.println(heap.remove());
		// System.out.println();

		ArrayList<ArrayList<Integer>> lists = new ArrayList<>();
		ArrayList<Integer> list1 = new ArrayList<>();
		list1.add(2);
		list1.add(3);
		list1.add(5);
		list1.add(10);
		list1.add(15);

		ArrayList<Integer> list2 = new ArrayList<>();
		list2.add(15);
		list2.add(100);
		list2.add(200);
		list2.add(300);

		ArrayList<Integer> list3 = new ArrayList<>();
		list3.add(6);
		list3.add(8);
		list3.add(9);
		list3.add(10);

		lists.add(list1);
		lists.add(list2);
		lists.add(list3);
		System.out.println(mergeKSortedAL(lists));
	}

}
