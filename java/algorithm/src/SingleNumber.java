import java.util.*;

/**
 * 有限制
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 */
public class SingleNumber {

    /**
     * 暴力解法
     * Runtime: 79 ms, faster than 5.33% of Java online submissions for Single Number.
     * Memory Usage: 41.4 MB, less than 28.31% of Java online submissions for Single Number
     */
    public int singleNumber(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            boolean isSingle = true;
            for (int j = 0; j < i; j++) {
                if (nums[i] == nums[j]) {
                    isSingle = false;
                    break;
                }
            }
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    isSingle = false;
                    break;
                }
            }
            if (isSingle) return nums[i];
        }
        return 0;
    }

    /**
     * 暴力解法的优化，不开辟新的内存空间，减少不必要的比较
     * Runtime: 12 ms, faster than 8.85% of Java online submissions for Single Number.
     * Memory Usage: 41.4 MB, less than 28.31% of Java online submissions for Single Number.
     */
    public int singleNumber_1(int[] nums) {
        int len = nums.length;
        while (len > 1) {
            boolean isSingle = true;
            for (int j = 1; j < len; j++) {
                if (nums[0] == nums[j]) {
                    isSingle = false;
                    if (j != len - 1 && j != len - 2) {
                        nums[0] = nums[len - 1];
                        nums[j] = nums[len - 2];
                    } else if (j == len - 1) {
                        nums[0] = nums[len - 2];
                    } else if (j == len - 2) {
                        nums[0] = nums[len - 1];
                    }
                    len -= 2;
                    break;
                }
            }
            if (isSingle) return nums[0];
        }
        return len == 1 ? nums[0] : 0;
    }

    /**
     * 链表 - ArrayList
     * Runtime: 88 ms, faster than 5.02% of Java online submissions for Single Number.
     * Memory Usage: 41 MB, less than 31.83% of Java online submissions for Single Number
     * <p>
     * 链表 - LinkedList
     * Runtime: 553 ms, faster than 5.02% of Java online submissions for Single Number.
     * Memory Usage: 39.9 MB, less than 51.34% of Java online submissions for Single Number.
     */
    public int singleNumber_2(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (!list.remove(Integer.valueOf(nums[i]))) {
                list.add(nums[i]);
            }
        }
        return list.isEmpty() ? 0 : list.get(0);
    }

    /**
     * Runtime: 7 ms, faster than 33.35% of Java online submissions for Single Number.
     * Memory Usage: 40.6 MB, less than 41.72% of Java online submissions for Single Number.
     */
    public int singleNumber_3(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (!set.remove(nums[i])) {
                set.add(nums[i]);
            }
        }
        return set.isEmpty() ? 0 : set.iterator().next();
    }

    /**
     * Runtime: 6 ms, faster than 35.39% of Java online submissions for Single Number.
     * Memory Usage: 40.8 MB, less than 36.91% of Java online submissions for Single Number.
     */
    public int singleNumber_4(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
            sum += nums[i];
        }
        int sum_single = 0;
        Iterator<Integer> iterable = set.iterator();
        while (iterable.hasNext()) {
            sum_single += iterable.next();
        }
        return 2 * sum_single - sum;
    }

    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Single Number.
     * Memory Usage: 42 MB, less than 7.87% of Java online submissions for Single Number.
     */
    public int singleNumber_5(int[] nums) {
        int a = 0;
        for (int i = 0; i < nums.length; i++) {
            a ^= nums[i];
        }
        return a;
    }
}
