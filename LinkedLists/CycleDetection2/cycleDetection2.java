package LinkedLists.CycleDetection2;

public class cycleDetection2{
    class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public class Solution {
        public ListNode detectCycle(ListNode head) {
            if (head == null || head.next == null) {
                return null;
            }

            ListNode slow = head;
            ListNode fast = head;

            // Find the meeting point
            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast) {
                    break;
                }
            }

            // If no cycle, return null
            if (fast == null || fast.next == null) {
                return null;
            }

            // Move one pointer to the head and advance both at the same pace
            // The point where they meet is the start of the cycle
            ListNode ptr1 = head;
            ListNode ptr2 = slow; // or fast, they are at the same meeting point
            while (ptr1 != ptr2) {
                ptr1 = ptr1.next;
                ptr2 = ptr2.next;
            }

            return ptr1;
        }
    }
    public static void main(String[] args) {
        // Example usage
        cycleDetection2 solution = new cycleDetection2();
        ListNode head = solution.new ListNode(3);
        head.next = solution.new ListNode(2);
        head.next.next = solution.new ListNode(0);
        head.next.next.next = solution.new ListNode(-4);
        head.next.next.next.next = head.next; // Create a cycle

        Solution sol = solution.new Solution();
        ListNode cycleStart = sol.detectCycle(head);
        if (cycleStart != null) {
            System.out.println("Cycle detected at node with value: " + cycleStart.val);
        } else {
            System.out.println("No cycle detected.");
        }
    }
}