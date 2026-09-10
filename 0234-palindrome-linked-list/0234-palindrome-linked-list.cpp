class Solution {
public:

    ListNode* reversedLinkedList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reversedLinkedList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* newHead = reversedLinkedList(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        // Compare both halves
        while (second != NULL) {

            if (first->val != second->val) {
                reversedLinkedList(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        // Restore the list
        reversedLinkedList(newHead);

        return true;
    }
};