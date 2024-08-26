class Solution {
public:

    vector<ListNode*> nodes;

    Solution(ListNode* head)
    {
        while(head!=NULL)
        {
            nodes.push_back(head);
            head=head->next;
        }
    }
    int getRandom()
    {
        int n=nodes.size();
        int radn=rand()%n;
        return nodes[radn]->val;  
    }
};