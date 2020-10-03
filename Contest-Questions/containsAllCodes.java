 public boolean containsAllCodes(String s, int k) {
        Set<String> visited = new HashSet<>();
        for (int i = k; i <= s.length() && visited.size() < 1 << k; ++i) {
            visited.add(s.substring(i - k, i));
        }
        return visited.size() == 1 << k;
    }
