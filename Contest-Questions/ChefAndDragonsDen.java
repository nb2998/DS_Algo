import java.io.*;
import java.util.*;

class FenwickTrees {
    int n;
    long[] bit;

    FenwickTrees(int n, Mountain node, int[][] timeStamps) {
        this.n = 2 * n + 2;
        this.bit = new long[this.n];
        this.dfs(node, timeStamps);
    }

    void dfs(Mountain node, int[][] timeStamps) {
        this.rangeAdd(timeStamps[0][node.index], timeStamps[1][node.index], node.taste);
        for (Mountain child :
                node.children) {
            dfs(child, timeStamps);
        }
    }

    void add(int pos, long val) {
        for (; pos < this.n; pos += pos & -pos)
            this.bit[pos] += val;
    }

    void rangeAdd(int left, int right, long val) {
        add(left, val);
        add(right + 1, -val);
    }

    long getSumFromRootToNode(int pos, int[][] timeStamps) {
        long result = 0;
        pos = timeStamps[0][pos];
        for (; pos > 0; pos -= pos & -pos)
            result += bit[pos];
        return result;
    }
}

class Mountain {
    long height, taste;
    int index;
    ArrayList<Mountain> children;
    Mountain parent;

    Mountain(int index, long value, long taste) {
        this.index = index;
        this.height = value;
        this.taste = taste;
        this.children = new ArrayList<>();
        this.parent = null;
    }

}

class ChefAndDragons2 {
    static int time;

    static void update(int pos, long updateVal, ArrayList<Mountain> left, ArrayList<Mountain> right, FenwickTrees[] leftFenwick, FenwickTrees[] rightFenwick, int[][] timeStampsLeft, int[][] timeStampsRight) {
        int posOfTreeL = findInWhichTree(pos, left, "left");
        int posOfTreeR = findInWhichTree(pos, right, "right");
        FenwickTrees nodeL = leftFenwick[posOfTreeL];
        FenwickTrees nodeR = rightFenwick[posOfTreeR];
        nodeL.rangeAdd(timeStampsLeft[0][pos], timeStampsLeft[1][pos], updateVal);
        nodeR.rangeAdd(timeStampsRight[0][pos], timeStampsRight[1][pos], updateVal);

    }

    static int findInWhichTree(int target, ArrayList<Mountain> forest, String query) {
        int left = 0, right = forest.size() - 1, mid, ans = -1;
        if (query.equals("left")) {
            while (left <= right) {
                mid = (left + right) / 2;
                int compareVal = forest.get(mid).index;
                if (compareVal == target) {
                    ans = mid;
                    break;
                } else if (compareVal < target) {
                    left = mid + 1;
                    ans = mid;
                } else {
                    right = mid - 1;
                }
            }

        } else {
            while (left <= right) {
                mid = (left + right) / 2;
                int compareVal = forest.get(mid).index;
                if (target <= compareVal) {
                    right = mid - 1;
                    ans = mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return ans;
    }

    public static void buildFenwickTrees(ArrayList<Mountain> forest, FenwickTrees[] fenwickTrees, int[][] timeStamps) {
        for (int pos = 0; pos < forest.size(); pos++) {
            Mountain root = forest.get(pos);
            FenwickTrees node = new FenwickTrees(timeStamps[1][root.index] / 2, root, timeStamps);//Dividing the Tout for the root node by 2 gives the total no of nodes in the tree
            fenwickTrees[pos] = node;
        }
    }

    public static void dfs(Mountain root, int[][] timeStamps) {
        timeStamps[0][root.index] = ++time;
        for (Mountain child :
                root.children) {
            dfs(child, timeStamps);
        }
        timeStamps[1][root.index] = ++time;
    }

    public static void updateTimeStamps(ArrayList<Mountain> forest, int[][] timeStamps) {
        for (Mountain tree :
                forest) {
            time = 0;
            dfs(tree, timeStamps);
        }
    }

    public static void buildTrees(ArrayList<Mountain> forest, long[] heights, long[] tastes) {
        int n = heights.length;
        Mountain temp = new Mountain(0, heights[0], tastes[0]), currParent = temp;
        forest.add(temp);
        for (int pos = 1; pos < n; pos++) {
            if (heights[pos] < currParent.height) {
                temp = new Mountain(pos, heights[pos], tastes[pos]);
                currParent.children.add(temp);
                temp.parent = currParent;
                currParent = temp;
            } else {
                while (heights[pos] >= currParent.height && currParent.parent != null) {
                    currParent = currParent.parent;
                }
                if (heights[pos] < currParent.height) {
                    temp = new Mountain(pos, heights[pos], tastes[pos]);
                    currParent.children.add(temp);
                    temp.parent = currParent;
                    currParent = temp;
                } else {
                    temp = new Mountain(pos, heights[pos], tastes[pos]);
                    forest.add(temp);
                    currParent = temp;
                }
            }
        }
    }

    public static void buildTrees(ArrayList<Mountain> forest,  long[] heights, long[] tastes, int order) {
        int n = heights.length;
        Mountain temp = new Mountain(n - 1, heights[n - 1], tastes[n - 1]), currParent = temp;
        forest.add(temp);
        for (int pos = n - 2; pos >= 0; pos--) {
            if (heights[pos] < currParent.height) {
                temp = new Mountain(pos, heights[pos], tastes[pos]);
                currParent.children.add(temp);
                temp.parent = currParent;
                currParent = temp;
            } else {
                while (heights[pos] >= currParent.height && currParent.parent != null) {
                    currParent = currParent.parent;
                }
                if (heights[pos] < currParent.height) {
                    temp = new Mountain(pos, heights[pos], tastes[pos]);
                    currParent.children.add(temp);
                    temp.parent = currParent;
                    currParent = temp;
                } else {
                    temp = new Mountain(pos, heights[pos], tastes[pos]);
                    forest.add(temp);
                    currParent = temp;
                }
            }
        }
        Collections.reverse(forest);
    }

    static boolean isNotAncestor(int posChild, int posPossAncs, int[][] timeStamps) {
        if (timeStamps[0][posPossAncs] <= timeStamps[0][posChild] && timeStamps[1][posPossAncs] >= timeStamps[1][posChild])
            return false;
        return true;
    }

    static long getSum(int start, int end,  FenwickTrees[] fenwickTreesL, FenwickTrees[] fenwickTreesR, ArrayList<Mountain> forestL, ArrayList<Mountain> forestR, int[][] timeStampsL, int[][] timeStampsR) {
        if (start < end) {
            int pos = findInWhichTree(end, forestL, "left");
            if (pos != findInWhichTree(start, forestL, "left"))return -1;
            if (isNotAncestor(end, start, timeStampsL)) return -1;
            FenwickTrees tree = fenwickTreesL[pos];
            return tree.getSumFromRootToNode(end, timeStampsL) - tree.getSumFromRootToNode(start, timeStampsL);
        } else {
            int pos = findInWhichTree(end, forestR, "right");
            if (pos != findInWhichTree(start, forestR, "right"))return -1;
            if (isNotAncestor(end, start, timeStampsR)) return -1;
            FenwickTrees tree = fenwickTreesR[pos];
            return tree.getSumFromRootToNode(end, timeStampsR) - tree.getSumFromRootToNode(start, timeStampsR);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] inp = buffer.readLine().split(" ");
        int n = Integer.parseInt(inp[0]), q = Integer.parseInt(inp[1]);
        inp = buffer.readLine().split(" ");
        long[] heights = new long[n];
        for (int pos = 0; pos < n; pos++) {
            heights[pos] = Integer.parseInt(inp[pos]);
        }
        long[] tastes = new long[n];
        inp = buffer.readLine().split(" ");
        for (int pos = 0; pos < n; pos++) {
            tastes[pos] = Integer.parseInt(inp[pos]);
        }
        //Pre-computation starts
        ArrayList<Mountain> forestFromLeft = new ArrayList<>();
        ArrayList<Mountain> forestFromRight = new ArrayList<>();
        buildTrees(forestFromLeft, heights, tastes);
        buildTrees(forestFromRight, heights, tastes, -1);
        int[][] timeStampsForLeft = new int[2][n];//1st position for tin 2nd for tout
        int[][] timeStampsForRight = new int[2][n];//1st position for tin 2nd for tout
        updateTimeStamps(forestFromLeft, timeStampsForLeft);
        updateTimeStamps(forestFromRight, timeStampsForRight);
        FenwickTrees[] forLeft = new FenwickTrees[forestFromLeft.size()];
        FenwickTrees[] forRight = new FenwickTrees[forestFromRight.size()];
        buildFenwickTrees(forestFromLeft, forLeft, timeStampsForLeft);
        buildFenwickTrees(forestFromRight, forRight, timeStampsForRight);
        //Pre-computation ends
        for (int query = 0; query < q; query++) {
            inp = buffer.readLine().split(" ");
            int queryType = Integer.parseInt(inp[0]);
            if (queryType == 1) {
                int pos = Integer.parseInt(inp[1]);
                long val = Integer.parseInt(inp[2]);
                update(pos - 1, val-tastes[pos-1], forestFromLeft, forestFromRight, forLeft, forRight, timeStampsForLeft, timeStampsForRight);
                tastes[pos-1] = val;

            } else {
                int start = Integer.parseInt(inp[1]) - 1, end = Integer.parseInt(inp[2]) - 1;
                long sum =  start == end ? tastes[start] : (heights[end] >= heights[start] ? -1 :getSum(start, end, forLeft, forRight, forestFromLeft, forestFromRight, timeStampsForLeft, timeStampsForRight));
                if (sum!=-1 && start!=end)sum += tastes[start];
                sb.append(sum).append("\n");
            }
        }
        System.out.println(sb);
    }

}
