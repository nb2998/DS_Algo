

public class ReverseList {

    public ListNode reverseList(ListNode root) {
        if (root == null)
            return root;
        ListNode prev = null;
        ListNode curr = root;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public static void main(String[] args) {

        ListNode node = new ListNode(1);
        node.next = new ListNode(2);
        node.next.next = new ListNode(3);
        System.out.println(node.val);
        System.out.println(node.next.val);
        System.out.println(node.next.next.val);
        System.out.println("Reversed list::");
        ReverseList reverseList = new ReverseList();
        ListNode reverseNode = reverseList.reverseList(node);
        System.out.println(reverseNode.val);
        System.out.println(reverseNode.next.val);
        System.out.println(reverseNode.next.next.val);
    }

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
}
