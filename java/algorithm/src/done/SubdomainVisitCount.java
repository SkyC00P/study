package done;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SubdomainVisitCount {

    /**
     * Runtime: 28 ms, faster than 35.30% of Java online submissions for Subdomain Visit Count.
     * Memory Usage: 40.5 MB, less than 39.36% of Java online submissions for Subdomain Visit Count.
     */
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> visits = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        // discuss.leetcode.com
        for (String domain : cpdomains) {
            String[] arr = domain.split(" ");
            String url = arr[1];
            int num = Integer.parseInt(arr[0]);

            while (url.contains(".")) {
                int n = map.getOrDefault(url, 0);
                map.put(url, num + n);
                url = url.substring(url.indexOf(".") + 1);
            }

            int n = map.getOrDefault(url, 0);
            map.put(url, num + n);
        }
        for (String url : map.keySet()) {
            String str = String.format("%s %s", map.get(url), url);
            visits.add(str);
        }

        return visits;
    }
}
