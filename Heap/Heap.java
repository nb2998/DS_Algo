package Lec10;

import java.util.ArrayList;

public class Heap {

	private ArrayList<Integer> data = new ArrayList<>();

	public int size() {
		return data.size();
	}

	public void insert(int item) {
		data.add(item);
		upHeapify(data.size() - 1);
	}

	private void upHeapify(int ci) {
		int pi = (ci - 1) / 2;

		if (data.get(pi) > data.get(ci)) {
			swap(ci, pi);
			upHeapify(pi);
		}
	}

	private void swap(int ci, int pi) {
		int ith = data.get(ci);
		data.set(ci, data.get(pi));
		data.set(pi, ith);
	}

	public void display() {
		System.out.println(data);
	}

	public int remove() {
		int rv = data.get(0);
		swap(0, data.size() - 1);
		data.remove(data.size() - 1);
		downHeapify(0);
		return rv;
	}

	private void downHeapify(int pi) {
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		int mini = pi;
		if (lci < data.size() && data.get(lci) < data.get(mini))
			mini = lci;
		if (rci < data.size() && data.get(rci) < data.get(mini))
			mini = rci;
		if (mini != pi) {
			swap(mini, pi);
			downHeapify(mini);
		}
	}

	public int getMin() {
		return data.get(0);
	}

}
