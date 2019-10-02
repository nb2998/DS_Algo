package program;

public class BuscaBinariaRecursiva {

	public static void main(String[] args) {
		int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		
		System.out.println(buscaBinariaRecursiva(array, 4));
	}

	private static int buscaBinariaRecursiva(int[] array, int elemento) {
		return BuscaBinaria(array, 0, array.length - 1, elemento);
	}

	private static int BuscaBinaria(int[] array, int leftIndex, int rightIndex, int elemento) {
		int meio = (leftIndex + rightIndex) /2 ;
			
		if(leftIndex > rightIndex) 
			meio = -1;
		else if(array[meio] == elemento) {}
		
		else if(elemento < array[meio])
			meio = BuscaBinaria(array, leftIndex, meio - 1, elemento);
		else
			meio = BuscaBinaria(array, meio + 1, rightIndex, elemento);
	
		return meio;
	}
	
	
	
}
