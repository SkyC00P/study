package todo;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class BinaryPrefixDivisibleBy5 {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> list = new ArrayList<>();
        List<Integer> arr = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            arr.add(nums[i]);
            list.add(check(arr));
        }
        return list;
    }

    private Boolean check(List<Integer> arr) {
        int size = arr.size();
        Iterator<Integer> iterator = arr.iterator();
        double n = 0;
        while (iterator.hasNext()) {
            int i = iterator.next();
            if (i != 0) {
                n = n + Math.pow(2, size - 1);
            }
            size--;
        }
        return n % 5 == 0;
    }
    // [false,false,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false]
    // [false,false,true,true,true,true,true,true,true,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,true,true,false,false,false]

    public static void main(String[] args) {
        BinaryPrefixDivisibleBy5 main = new BinaryPrefixDivisibleBy5();
        main.prefixesDivBy5(new int[]{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1
        });
    }
}
