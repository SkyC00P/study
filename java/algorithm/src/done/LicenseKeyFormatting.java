package done;

import java.util.Stack;

public class LicenseKeyFormatting {
    /**
     * Runtime: 23 ms, faster than 42.47% of Java online submissions for License Key Formatting.
     * Memory Usage: 38.9 MB, less than 67.35% of Java online submissions for License Key Formatting.
     */
    public String licenseKeyFormatting(String S, int K) {
        Stack<Character> stack = new Stack<>();
        int size = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            char ch = S.charAt(i);
            if (ch == '-') continue;
            if (size != K) {
                stack.push(Character.toUpperCase(ch));
                size++;
            } else {
                stack.push('-');
                stack.push(Character.toUpperCase(ch));
                size = 1;
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        LicenseKeyFormatting test = new LicenseKeyFormatting();
        String s = test.licenseKeyFormatting("5F3Z-2e-9-w", 4);
        System.out.println("5F3Z-2E9W".equals(s));

        s = test.licenseKeyFormatting("2-5g-3-J", 2);
        System.out.println("2-5G-3J".equals(s));
    }
}
