package todo;
import java.util.HashMap;
import java.util.Map;

public class DetectPatternOfLengthMRepeatedKOrMoreTimes {
    // 这是模式匹配的题
    public boolean containsPattern(int[] arr, int m, int k) {
        Map<Integer, Integer> pattern = new HashMap<>();
        int num_count = m;
        int repeat_count = k;

        for(int i : arr){
            int count = pattern.getOrDefault(i, 0);
            pattern.put(i, count + 1);
        }

        for(int n : pattern.keySet()){
            int count = pattern.getOrDefault(n, 0);
            if(count >= repeat_count){
                num_count--;
            }
        }

        return num_count <= 0;
    }
}
