#include "./solution.cpp"
int main(){
    ListNode *l1 = new ListNode(10);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(10);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    Solution sl = Solution();
    ListNode *head = sl.insertionSortList(l1);
    while(NULL != head){
        cout<<head->val<<" ";
        head = head->next;
    }
}
