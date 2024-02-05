// https://leetcode.com/problems/reverse-linked-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            auto nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

// https://leetcode.com/problems/reverse-linked-list-ii/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(-1, head);
        ListNode* p0 = &dummy;

        for (int i = 0; i < left - 1; i++) {
            p0 = p0->next;
        }

        ListNode* prev = nullptr;
        auto cur = p0->next;
        for (int i = 0; i < right - left + 1; i++) {
            auto nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        // update old head's next to the next node outside the range
        p0->next->next = cur;
        // update new head
        p0->next = prev;
        return dummy.next;
              
    }
};

// https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }
        ListNode dummy(-1, head);
        ListNode* p0 = &dummy;
        ListNode* prev = nullptr;

        int n = 0;
        while (head) {
            head = head->next;
            ++n;
        }

        ListNode* cur = p0->next;

        while (n >= k) {
            n -= k;
            for (int i = 0; i < k; i++) {
                auto nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }

            auto nxt = p0->next;
            p0->next->next = cur;
            p0->next = prev;
            p0 = nxt;
        }

        return dummy.next;
    }
};

