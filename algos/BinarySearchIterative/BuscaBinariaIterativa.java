package program;

public class BuscaBinariaIterativa {

	public static void main(String[] args) {
		int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		System.out.println(buscaBinaria(array, 0, array.length - 1, 3));
	}

	static int buscaBinaria(int[] array, int leftIndex, int rightIndex, int x) { 
	
		while(leftIndex <= rightIndex) {
			int meio = (leftIndex + rightIndex) / 2;
			if(array[meio] == x) {
				return meio;
			}
			else {
				if(x < array[meio]) {
					rightIndex = meio - 1;
				}
				else leftIndex = meio + 1;
			}
		}
		
//		Caso nao encontre o indice do elemento
		return -1;

	}
}
