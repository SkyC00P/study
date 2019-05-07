public class FirstBadVersion {
    private int badVersion;

    public void setBadVersion(int badVersion) {
        this.badVersion = badVersion;
    }

    boolean isBadVersion(int version) {
        return version >= badVersion;
    }

    /**
     * Runtime: 10 ms, faster than 99.93% of Java online submissions for First Bad Version.
     * Memory Usage: 32.1 MB, less than 100.00% of Java online submissions for First Bad Version
     */
    public int firstBadVersion(int n) {
        return find(1, n);
    }

    private int find(int left, int right) {
        if (Math.abs(right - left) <= 1) {
            return isBadVersion(left) ? left : right;
        }
        int mid = (right / 2) + (left / 2);
        return isBadVersion(mid) ? find(left, mid) : find(mid + 1, right);
    }
}

