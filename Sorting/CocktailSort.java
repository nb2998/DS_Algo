public class CocktailSort
{

    public static void cocktailSort(Integer[] inputArrays,
                                    Integer n)
    {
        boolean swapped = true;
        Integer start = 0;
        Integer end = inputArrays.length;

        while (swapped == true) {
            swapped = false;

            for (int i = start; i < end - 1; ++i) {
                if (inputArrays[i] > inputArrays[i + 1]) {
                    int temp = inputArrays[i];
                    inputArrays[i] = inputArrays[i + 1];
                    inputArrays[i + 1] = temp;
                    swapped = true;
                }
            }

            if (swapped == false) {
                break;
            }

            swapped = false;
            end--;

            for (int i = end - 1; i >= start; i--) {
                if (inputArrays[i] > inputArrays[i + 1]) {
                    int temp = inputArrays[i];
                    inputArrays[i] = inputArrays[i + 1];
                    inputArrays[i + 1] = temp;
                    swapped = true;
                }
            }

            start++;
        }
    }

}
