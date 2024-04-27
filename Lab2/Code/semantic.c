#include "semantic.h"
#include "tree.h"
// 运行时维护头指针head和尾指针tail
void insertSymbol(char* name, T type, ListNode** ptail) {
    // printf("$$$\n");
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode -> name = (char*)malloc(sizeof(char));//如果可能触及到的指针，都必须初始化。否则segfault
    // printf("!!!\n");
    strcpy(newNode -> name, name);
    
    newNode -> type = type;

    (*ptail) -> next = newNode;
    *ptail = newNode; //其实没改变tail的值
}
// 找到链表中的某个结点
ListNode* findSymbol(char* name, ListNode* head){
    ListNode* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current; // 找到了匹配的标识符
        }
        current = current->next;
    }
    return NULL; // 没有找到匹配的标识符
}

//打印错误信息
void print_error(int error_type, int line){
    printf("Error type %d at Line %d:\n",error_type,line);
}

//填表
void fill_symboltable(struct ASTNode* astnode, ListNode** ptail){
    // printf("***\n");
    if(astnode == NULL){
        return;
    }
    T type;
    if(astnode -> first_child == NULL){
        //若是叶子结点
        if(astnode -> type == KEYWORD_TYPE){
            // printf("flag1\n");
            type.kind = 0; // 0 for BASIC
            // printf("flag2\n");
            if(strcmp(astnode -> data.stringval,"int") == 0){
                // printf("flag3\n");
                type.u.basic = 0;
            }
            else{
                type.u.basic = 1;
            }
        }
        if(astnode -> type == ID_TYPE){
            // printf("%s",astnode -> data.stringval);
            insertSymbol(astnode -> data.stringval,type,ptail);
        }

        if (strcmp(astnode -> data.stringval,";") == 0)
        {
            /* code */
        }else if(strcmp(astnode -> data.stringval,"(") == 0)
        {
            /* code */
        }else{
            if(astnode -> type == ID_TYPE){
                // printf("%s",astnode -> data.stringval);
                insertSymbol(astnode -> data.stringval,type,ptail);
            }
            
            // printf("flag5\n");

        }
        
        
        // if(astnode -> type == ID_TYPE){
        //     printf("%s",astnode -> data.stringval);
        //     insertSymbol(astnode -> data.stringval,type,ptail);
        //     // printf("flag5\n");
        // }
    }
    else{
        //如果不是叶子节点
        fill_symboltable(astnode -> first_child,ptail);
    }
    fill_symboltable(astnode -> next_sib,ptail);    
}

//查表
void check_symboltable(struct ASTNode* astnode, ListNode* head){
    if(astnode == NULL){
        return;
    }
    if(astnode -> first_child == NULL){
        // 如果是叶子结点
        // printf("flag\n");
        if(astnode -> type == ID_TYPE){
            // printf("***\n");
            if(findSymbol(astnode -> data.stringval,head) == NULL){
                print_error(1,4);
                // exit(0);
            }
        }
        }
        else{
            //如果不是叶子节点
            check_symboltable(astnode -> first_child,head);
        }
        check_symboltable(astnode -> next_sib,head);
}

// 遍历AST进行语义分析
void ASTtraversal(struct ASTNode* root, ListNode* head, ListNode** ptail){
    if(root == NULL){
        return;
    }

    if(root -> type == EXTDEF || root -> type == DEF){
        // 填表
        fill_symboltable(root,ptail);
        // printf("###\n");
    }
    if(root -> type == EXP){
        // printf("#\n");
        // 查表
        // 查表时候，该填写的项一定已经被填写了吗？ 若否，似乎查表应该重新遍历
        check_symboltable(root,head);
    }

    ASTtraversal(root -> first_child, head, ptail);
    ASTtraversal(root -> next_sib, head, ptail);
}




