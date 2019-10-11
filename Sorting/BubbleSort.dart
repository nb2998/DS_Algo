
bubbleSort(List numbers) {

        for (int i = 1; i < numbers.length; i++) {
                for (int j = 0; j < numbers.length - i; j++) {
                        if (numbers[j] > numbers[j + 1]) {
                                int temp = numbers[j];
                                numbers[j] = numbers[j + 1];
                                numbers[j + 1] = temp;
                        }
                }
        }

}


displayNumbers(List numbers) {
        for (int i = 0; i < numbers.length; i++) {
                print(numbers[i]);
        }
}



void main() {

        var numbers = [10,1,4,2,6];
        bubbleSort(numbers);
        displayNumbers(numbers);

}

