package Lec14;

import java.util.HashSet;

public class GraphClient {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Graph g = new Graph();
		g.addVertex("A");
		g.addVertex("B");
		g.addVertex("C");
		g.addVertex("D");
		g.addVertex("E");
		g.addVertex("F");
		g.addVertex("G");
		
		g.addEdge("A", "B", 1);
		g.addEdge("A", "D", 5);
		g.addEdge("B", "C", 2);
		g.addEdge("C", "D", 1);
		g.addEdge("D", "E", 15);
		g.addEdge("E", "F", 2);
		g.addEdge("G", "F", 6);
		g.addEdge("E", "G", 5);
		g.display();
//		g.removeEdge("A", "D");
		
		System.out.println(g.hasPath1("A", "G", new HashSet<>()));
		System.out.println(g.BFS("A", "F"));
//		System.out.println(g.DFS("A", "F"));
//		g.BFT();
//		g.DFT();
		System.out.println(g.isConnected());
//		System.out.println(g.isCyclic());
		System.out.println(g.connectedComponents());
//		System.out.println(g.isTree());
//		g.prims().display();
		g.djikstra("A");
	}

}
