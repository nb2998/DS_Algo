package Lec10;

import java.util.ArrayList;

public class GenericHeap<T extends Comparable<T>> {

	private ArrayList<T> data = new ArrayList<>();

	public int size() {
		return data.size();
	}

	public void insert(T item) {
		data.add(item);
		upHeapify(data.size() - 1);
	}

	private void upHeapify(int ci) {
		int pi = (ci - 1) / 2;

		if (getLarger(data.get(ci), data.get(pi)) > 0) {
			swap(ci, pi);
			upHeapify(pi);
		}
	}

	private void swap(int ci, int pi) {
		T ith = data.get(ci);
		data.set(ci, data.get(pi));
		data.set(pi, ith);
	}

	public void display() {
		System.out.println(data);
	}

	public T remove() {
		T rv = data.get(0);
		swap(0, data.size() - 1);
		data.remove(data.size() - 1);
		downHeapify(0);
		return rv;
	}

	private void downHeapify(int pi) {
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		int mini = pi;
		if (lci < data.size() && getLarger(data.get(lci), data.get(mini)) > 0)
			mini = lci;
		if (rci < data.size() && getLarger(data.get(rci), data.get(mini)) > 0)
			mini = rci;
		if (mini != pi) {
			swap(mini, pi);
			downHeapify(mini);
		}
	}

	public T getMin() {
		return data.get(0);
	}

	private int getLarger(T t, T other) {
		return t.compareTo(other);
	}

}
