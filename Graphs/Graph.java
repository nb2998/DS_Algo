package Lec14;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;

import Lec10.GenericHeap;

public class Graph {

	private class Vertex {
		HashMap<String, Integer> nbrs = new HashMap<>();
	}

	HashMap<String, Vertex> vertices = new HashMap<>();

	public int numVertex() {
		return vertices.size();
	}

	public boolean containsVertex(String vname) {
		return vertices.containsKey(vname);
	}

	public void addVertex(String vname) {
		if (vertices.containsKey(vname))
			return;
		vertices.put(vname, new Vertex());
	}

	public boolean removeVertex(String vname) {
		Vertex vtx = vertices.get(vname);
		// ArrayList<String> al = new ArrayList<>();
		if (vtx == null)
			return false;

		for (String nbr : vtx.nbrs.keySet()) {
			vertices.get(nbr).nbrs.remove(vname);
		}

		vertices.remove(vname);

		return true;
	}

	public int numEdges() {
		int sum = 0;
		for (String key : vertices.keySet()) {
			sum += vertices.get(key).nbrs.size();
		}
		return sum / 2;
	}

	public boolean containsEdge(String vname1, String vname2) {
		Vertex vtx1 = vertices.get(vname1);
		Vertex vtx2 = vertices.get(vname2);

		if (vtx1 == null || vtx2 == null || !vtx1.nbrs.containsKey(vname2))
			return false;

		return true;
	}

	public void addEdge(String vname1, String vname2, int cost) {
		Vertex vtx1 = vertices.get(vname1);
		Vertex vtx2 = vertices.get(vname2);
		if (vtx1 == null || vtx2 == null || vtx1.nbrs.containsKey(vname2))
			return;

		vtx1.nbrs.put(vname2, cost);
		vtx2.nbrs.put(vname1, cost);
	}

	public void removeEdge(String vname1, String vname2) {
		Vertex vtx1 = vertices.get(vname1);
		Vertex vtx2 = vertices.get(vname2);
		if (vtx1 == null || vtx2 == null || !vtx1.nbrs.containsKey(vname2))
			return;

		vtx1.nbrs.remove(vname2);
		vtx2.nbrs.remove(vname1);
	}

	public void display() {
		for (String key : vertices.keySet()) {
			System.out.println(key + " -> " + vertices.get(key).nbrs);
		}
	}

	public boolean hasPath(String src, String dest, HashSet<String> map) {
		// if(curr == src) return false;
		if (map.contains(src))
			return false;

		Vertex vtx = vertices.get(src);
		if (vtx.nbrs.containsKey(dest))
			return true;
		else {
			map.add(src);
			for (String key : vtx.nbrs.keySet()) {
				if (!map.contains(key)) {
					boolean rv = hasPath(key, dest, map);
					map.add(key);
					if (rv)
						return true;
				}
			}
		}

		return false;
	}

	public boolean hasPath1(String src, String dest, HashSet<String> map) {
		
		Vertex vtx1 = vertices.get(src);
		
		if(vtx1.nbrs.containsKey(dest)) return true;
		map.add(src);
		
		for(String nbr: vtx1.nbrs.keySet()) {
			if(!map.contains(nbr)) {
				map.add(nbr);
				boolean rv= hasPath1(nbr, dest, map);
				if(rv) return rv;
			}
		}
		return false;
	}
	
	private class Pair {
		String vname;
		String psf;
		Vertex vtx;
	}

	public boolean BFS(String src, String dest) {
		HashSet<String> processed = new HashSet<>();

		LinkedList<Pair> queue = new LinkedList<>();

		Pair p = new Pair();
		p.vname = src;
		p.psf = src;
		p.vtx = vertices.get(src);
		queue.addLast(p);

		while (!queue.isEmpty()) {
			Pair rp = queue.removeFirst();

			if (processed.contains(rp.vname))
				continue;

			processed.add(rp.vname);

			if (this.containsEdge(rp.vname, dest)) { // cycle
				System.out.println(rp.psf + dest);
				return true;
			}

			for (String nbr : rp.vtx.nbrs.keySet()) {
				if (!processed.contains(nbr)) {
					Pair np = new Pair();
					np.vname = nbr;
					np.psf = rp.psf + nbr;
					np.vtx = vertices.get(nbr);
					queue.addLast(np);
				}
			}

		}

		return false;
	}

	public boolean DFS(String src, String dest) {
		HashSet<String> processed = new HashSet<>();

		LinkedList<Pair> stack = new LinkedList<>();

		Pair p = new Pair();
		p.vname = src;
		p.psf = src;
		p.vtx = vertices.get(src);
		stack.addFirst(p);

		while (!stack.isEmpty()) {
			Pair rp = stack.removeFirst();

			if (processed.contains(rp.vname))
				continue;

			processed.add(rp.vname);

			if (this.containsEdge(rp.vname, dest)) { // cycle
				System.out.println(rp.psf + dest);
				return true;
			}

			for (String nbr : rp.vtx.nbrs.keySet()) {
				if (!processed.contains(nbr)) {
					Pair np = new Pair();
					np.vname = nbr;
					np.psf = rp.psf + nbr;
					np.vtx = vertices.get(nbr);
					stack.addFirst(np);
				}
			}

		}

		return false;
	}

	public void BFT() {

		HashSet<String> processed = new HashSet<>();

		LinkedList<Pair> queue = new LinkedList<>();

		for (String key : vertices.keySet()) {
			Pair p = new Pair();
			p.vname = key;
			p.psf = key;
			p.vtx = vertices.get(key);
			queue.addLast(p);

			if (processed.contains(key))
				continue;

			while (!queue.isEmpty()) {
				Pair rp = queue.removeFirst();

				if (processed.contains(rp.vname))
					continue;

				System.out.println(rp.vname + " via " + rp.psf);

				processed.add(rp.vname);

				for (String nbr : rp.vtx.nbrs.keySet()) {
					if (!processed.contains(nbr)) {
						Pair np = new Pair();
						np.vname = nbr;
						np.psf = rp.psf + nbr;
						np.vtx = vertices.get(nbr);
						queue.addLast(np);
					}
				}
			}

		}
	}

	public void DFT() {

		HashSet<String> processed = new HashSet<>();

		LinkedList<Pair> stack = new LinkedList<>();

		for (String key : vertices.keySet()) {
			Pair p = new Pair();
			p.vname = key;
			p.psf = key;
			p.vtx = vertices.get(key);
			stack.addFirst(p);

			if (processed.contains(key)) // already done; works for disconnected components
				continue;

			while (!stack.isEmpty()) {
				Pair rp = stack.removeFirst();

				if (processed.contains(rp.vname)) // C alreadyy processed not to be done again
					continue;

				System.out.println(rp.vname + " via " + rp.psf);

				processed.add(rp.vname);

				for (String nbr : rp.vtx.nbrs.keySet()) {
					if (!processed.contains(nbr)) {
						Pair np = new Pair();
						np.vname = nbr;
						np.psf = rp.psf + nbr;
						np.vtx = vertices.get(nbr);
						stack.addFirst(np);
					}
				}
			}

		}

	}

	public boolean isConnected() {

		boolean flag = true;

		HashSet<String> processed = new HashSet<>();

		LinkedList<Pair> queue = new LinkedList<>();

		for (String key : vertices.keySet()) {

			if (processed.contains(key))
				continue;
			Pair p = new Pair();
			p.vname = key;
			p.psf = key;
			p.vtx = vertices.get(key);
			queue.addLast(p);

			// if(processed.contains(key))
			if (!processed.contains(key) && !flag) {
				return false;
			}

			while (!queue.isEmpty()) {
				Pair rp = queue.removeFirst();

				if (processed.contains(rp.vname))
					continue;

				// System.out.println(rp.vname + " via " + rp.psf);

				processed.add(rp.vname);

				for (String nbr : rp.vtx.nbrs.keySet()) {
					if (!processed.contains(nbr)) {
						Pair np = new Pair();
						np.vname = nbr;
						np.psf = rp.psf + nbr;
						np.vtx = vertices.get(nbr);
						queue.addLast(np);
					}
				}
			}
			flag = false;
		}
		return !flag;
	}

	public boolean isCyclic() {

		HashSet<String> processed = new HashSet<>();

		LinkedList<Pair> queue = new LinkedList<>();

		for (String key : vertices.keySet()) {
			Pair p = new Pair();
			p.vname = key;
			p.psf = key;
			p.vtx = vertices.get(key);
			queue.addLast(p);

			if (processed.contains(key))
				continue;

			while (!queue.isEmpty()) {
				Pair rp = queue.removeFirst();

				if (processed.contains(rp.vname)) {
					return true;
				}

				// System.out.println(rp.vname + " via " + rp.psf);

				processed.add(rp.vname);

				for (String nbr : rp.vtx.nbrs.keySet()) {
					if (!processed.contains(nbr)) {
						Pair np = new Pair();
						np.vname = nbr;
						np.psf = rp.psf + nbr;
						np.vtx = vertices.get(nbr);
						queue.addLast(np);
					}
				}
			}
		}
		return false;
	}

	public ArrayList<ArrayList<String>> connectedComponents() {
		ArrayList<ArrayList<String>> al = new ArrayList<ArrayList<String>>();

		HashSet<String> processed = new HashSet<>();

		LinkedList<Pair> queue = new LinkedList<>();

		ArrayList<String> comp = new ArrayList<>();
		for (String key : vertices.keySet()) {
			Pair p = new Pair();
			p.vname = key;
			p.psf = key;
			p.vtx = vertices.get(key);
			queue.addLast(p);

			if (processed.contains(key)) {
				comp = new ArrayList<>();
				continue;
			}

			while (!queue.isEmpty()) {
				Pair rp = queue.removeFirst();

				if (processed.contains(rp.vname))
					continue;

				// System.out.println(rp.vname + " via " + rp.psf);
				comp.add(rp.vname);

				processed.add(rp.vname);

				for (String nbr : rp.vtx.nbrs.keySet()) {
					if (!processed.contains(nbr)) {
						Pair np = new Pair();
						np.vname = nbr;
						np.psf = rp.psf + nbr;
						np.vtx = vertices.get(nbr);
						queue.addLast(np);
					}
				}
			}
			al.add(comp);
		}
		return al;
	}

	public boolean isTree() {
		return this.isConnected() && !this.isCyclic();
	}

	class PrimsPair implements Comparable<PrimsPair> {
		String vname;
		String aqdVtx;
		int cost;

		@Override
		public int compareTo(PrimsPair o) {
			return o.cost - this.cost;
		}
	}

	public Graph prims() {
		Graph mst = new Graph();

		GenericHeap<PrimsPair> heap = new GenericHeap<>();
		HashMap<String, PrimsPair> processed = new HashMap<>();

		for (String key : vertices.keySet()) {
			PrimsPair pair = new PrimsPair();
			pair.vname = key;
			pair.aqdVtx = null;
			pair.cost = Integer.MAX_VALUE;

			heap.insert(pair);
			processed.put(key, pair);
		}

		while (!heap.isEmpty()) {
			PrimsPair rp = heap.remove();
			processed.remove(rp.vname);

			if (rp.aqdVtx == null) {
				mst.addVertex(rp.vname);
			} else {
				mst.addVertex(rp.vname);
				mst.addEdge(rp.vname, rp.aqdVtx, rp.cost);
			}

			for (String nbr : vertices.get(rp.vname).nbrs.keySet()) {

				if (processed.containsKey(nbr)) {
					int oc = processed.get(nbr).cost;
					int nc = vertices.get(nbr).nbrs.get(rp.vname);

					if (nc < oc) {
						processed.get(nbr).cost = nc;
						processed.get(nbr).aqdVtx = rp.vname;
						heap.updatePriority(processed.get(nbr));
					}
				}
			}
		}
		return mst;
	}
	
	class DjikstraPair implements Comparable<DjikstraPair> {
		String vname;
		String psf;
		int cost;

		@Override
		public int compareTo(DjikstraPair o) {
			return o.cost - this.cost;
		}
	}
	
	public void djikstra(String src) {
		GenericHeap<DjikstraPair> heap = new GenericHeap<>();
		HashMap<String, DjikstraPair> processed = new HashMap<>();

		for (String key : vertices.keySet()) {
			DjikstraPair pair = new DjikstraPair();
			pair.vname = key;
			pair.psf = "";
			pair.cost = Integer.MAX_VALUE;

			if(key.equals(src)) {
				pair.psf=src;
				pair.cost=0;
			}
			heap.insert(pair);
			processed.put(key, pair);
		}

		while (!heap.isEmpty()) {
			DjikstraPair rp = heap.remove();
			processed.remove(rp.vname);

			System.out.println(rp.vname +" via "+rp.psf);

			for (String nbr : vertices.get(rp.vname).nbrs.keySet()) {

				if (processed.containsKey(nbr)) {
					int oc = processed.get(nbr).cost;
					int nc = rp.cost + vertices.get(nbr).nbrs.get(rp.vname);

					if (nc < oc) {
						processed.get(nbr).cost = nc;
						processed.get(nbr).psf = rp.psf +nbr;
						heap.updatePriority(processed.get(nbr));
					}
				}
			}
		}
		
	}
}
