public class CountingSort {
    public static int[] countingSort(int[] a, int k) {
        int[] c = new int[k];

        // frequence
        for (int i = 0; i < a.length; i++) {
            c[a[i] - 1] += 1;
        }
        
        // cumulative
        for (int i = 1; i < c.length; i++) {
            c[i] += c[i-1];
        }
        int[] b = new int[a.length];

        for (int i = a.length - 1; i >= 0; i--) {
            b[c[a[i] - 1] -1] = a[i];
            c[a[i] - 1] -= 1;
        }
        return b;
    }
}