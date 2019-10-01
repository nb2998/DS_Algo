package trie;

public class TrieClient {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Trie trie  = new Trie();
		trie.insert("the");
		trie.insert("a");
		trie.insert("there");
		trie.insert("answer");
		trie.insert("any");
		trie.insert("by");
		trie.insert("bye");
		trie.insertRecursive("their");
		System.out.println(trie.search("answer"));
		trie.delete("any");
		System.out.println(trie.search("any"));//prints false

		
	}

}
