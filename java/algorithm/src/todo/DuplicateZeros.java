package todo;

public class DuplicateZeros {
    public void duplicateZeros(int[] arr) {
        int shift = 0;
        int n = 0, i = 0;
        while (i < arr.length) {
            if (arr[i] == 0){
                int _n = arr[i + 1];
                arr[i+1] = 0;

            }
            shift += 1;
            i++;
        }
    }

}
