package todo;

import java.util.Random;

public class Minimum_Moves_to_Equal_Array_Elements {
    public int minMoves(int[] nums) {
        Random r = new Random();
        for(int i =0;i<5;i++){
            System.out.print(r.nextInt(5) );
        }
        return 1;
    }

    public static void main(String[] args) {
        // [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
        Minimum_Moves_to_Equal_Array_Elements test = new Minimum_Moves_to_Equal_Array_Elements();
        int i = test.minMoves(new int[]{1, 2, 3});
        System.out.println(i == 3);
    }
}
