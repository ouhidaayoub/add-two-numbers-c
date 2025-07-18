#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    struct ListNode {
        int val;
        struct ListNode* next;
    };

    struct ListNode *createNewNode();

    struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        
        struct ListNode *temp1 = l1;
        struct ListNode *temp2 = l2;

        struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *temp3 = l3;
        struct ListNode *before_temp3 = l3;

        bool thereisaCarry = false;

        bool isThel1Ended = 0;
        bool isThel2Ended = 0;

        while( (temp1 != NULL) || (temp2 != NULL) ){

            if(temp1 == NULL) (isThel1Ended = 1);
            if(temp2 == NULL) (isThel2Ended = 1);

            if((isThel1Ended == 0) && (isThel2Ended == 1)) ((temp3 -> val) = (temp1 -> val));
            else if((isThel1Ended == 1) && (isThel2Ended == 0)) ((temp3 -> val) = (temp2 -> val));
            else ( (temp3 -> val) = (temp1 -> val) + (temp2 -> val));

            if( thereisaCarry ){
                (temp3 -> val) += 1;
                thereisaCarry = false;
            }
            if( (temp3 -> val) >= 10 ){
                (temp3 -> val) %= 10;
                thereisaCarry = true;
            }

            if(isThel1Ended == 0) (temp1 = (temp1 -> next));
            else (isThel1Ended = true);

            if(isThel2Ended == 0) (temp2 = (temp2 -> next));
            else (isThel2Ended = true);

            (temp3 -> next) = createNewNode();
            before_temp3 = temp3;
            temp3 = (temp3 -> next);
        }
        if(thereisaCarry){
            (temp3 -> val) = 1;
            (temp3 -> next) = NULL;
        }else{
            free(temp3);
            (before_temp3 -> next) = NULL;
        }
        return l3;
    }
    struct ListNode *createNewNode(){
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        return newNode;
    }