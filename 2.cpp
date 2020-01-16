//there are bugs in this program
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag=0;
        ListNode* head=l1;
        while(l1->next!=NULL && l2->next!=NULL){
            if(l1->val + l2->val < 10){
                l1->val = l1->val + l2->val +flag;
                flag=0;
            }
            else{
                flag=1;
                l1->val = l1->val + l2->val -10;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1->next==NULL && l2->next!=NULL){
            l1->val = l1->val + l2->val +flag;
            if(l1->val<10) flag=0;
            else {l1->val-=10;flag=1;}
            l2->next->val+=flag;
            l1->next=l2->next;
            l1=l1->next;
            if(l1->val>=10){
                l1->val-=10;
                l1->next=new ListNode(1);
            }
        }
        else if(l2->next==NULL && l1->next!=NULL){
            l1->val = l1->val + l2->val +flag;
            if(l1->val<10) flag=0;
            else {
            l1->val-=10;
            flag=1;}
            l1->next->val+=flag;
            l1=l1->next;
            if(l1->val>=10){
            l1->val-=10;
            l1->next=new ListNode(1);}
            }
        else{
            l1->val = l1->val + l2->val +flag;
            if(l1->val>=10){
                l1->val-=10;
                l1->next=new ListNode(1);
            }
        }
        return head;
    }
};



// revised program

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*p=l1; //traverse linked list l1
        ListNode*q=l2; //traverse linked list l2
        int x,y,carry=0; //added numbers and carry
        ListNode* dummyhead=new ListNode(-1); //the head point of linked list result
        ListNode* result=dummyhead; //traverse linked list result

        while(p!=NULL || q!=NULL){ // when the traversal do not end
            int x= (p==NULL)? 0:p->val;
            int y= (q==NULL)? 0:q->val;

            int sum=x+y+carry; //result number
            
            carry=sum/10; //carry 
            result->next=new ListNode(sum%10); //the expression of carry and next result number

            result=result->next;

            if(q!=NULL) q=q->next;
            if(p!=NULL) p=p->next;

        }
        if(carry>0) result->next=new ListNode(1);
        return dummyhead->next;
    }
};

//thought: algorithm is to solve pratical problem, go to find essense and use compter languge to express it! 