#include "semantic.h"
#include "tree.h"
// 运行时维护头指针head和尾指针tail
void insertSymbol(char* name, T type, ListNode** ptail) {
    printf("debug flag for insert\n");
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    strcpy(newNode -> name, name);
    newNode -> type = type;

    (*ptail) -> next = newNode;
    *ptail = newNode; //其实没改变tail的值
}
// 找到链表中的某个结点
ListNode* findSymbol(char* name, ListNode* head){
    // printf("debug flag for find\n");
    ListNode* current = head;
    // printf("debug flag for find 2\n");
    while (current != NULL) {
        // printf("debug flag for find 3\n");
        if (strcmp(current->name, name) == 0) {
            return current; // 找到了匹配的标识符
        }
        // printf("debug flag for find 4\n");
        current = current->next;
    }
    // printf("debug flag for find 3\n");
    return NULL; // 没有找到匹配的标识符
}

//打印错误信息
void print_error(int error_type, int line){
    printf("Error type %d at Line %d:\n",error_type,line);
}

//填表
void fill_symboltable(struct ASTNode* astnode, ListNode** ptail){
    // printf("debug flag for fill\n");
    if(astnode == NULL){
        return;
    }
    if(astnode -> type == DEF){
        T type;
        // printf("after T?\n");
        // printf("%s\n",astnode -> first_child -> type_name);
        // Def → Specifier DecList SEMI
        // assume Specifier 不包括结构体
        printf("%s\n",astnode -> type_name);
        if(astnode -> first_child == NULL){
            printf("been here?\n");
            //若是叶子结点
            if(astnode -> type == INTNUMBER){
                // printf("been here?\n");
                type.kind = 0; // 0 for BASIC
                type.u.basic = 0; // 0 for INT
            }
            if(astnode -> type == FLOATNUMBER){
                // printf("been here?\n");
                type.kind = 0; // 0 for BASIC
                type.u.basic = 1; // 1 for FLOAT
            }
            if(astnode -> type == ID_TYPE){
                // printf("been here?\n");
                insertSymbol(astnode -> data.stringval,type,ptail);
            }
        }
        else{
            // printf("reach here?\n");
            //如果不是叶子节点
            fill_symboltable(astnode -> first_child,ptail);
        }
        fill_symboltable(astnode -> next_sib,ptail);
    }
    if(astnode -> type == EXTDEF){
        // printf("here?\n");
        T type;
        // printf("after T?\n");
        // printf("%s\n",astnode -> first_child -> type_name);
        // Def → Specifier DecList SEMI
        // assume Specifier 不包括结构体
        printf("%s\n",astnode -> type_name);
        if(astnode -> first_child == NULL){
            printf("been here?\n");
            //若是叶子结点
            if(astnode -> type == INTNUMBER){
                // printf("been here?\n");
                type.kind = 0; // 0 for BASIC
                type.u.basic = 0; // 0 for INT
            }
            if(astnode -> type == FLOATNUMBER){
                // printf("been here?\n");
                type.kind = 0; // 0 for BASIC
                type.u.basic = 1; // 1 for FLOAT
            }
            if(astnode -> type == ID_TYPE){
                // printf("been here?\n");
                insertSymbol(astnode -> data.stringval,type,ptail);
            }
        }
        else{
            // printf("reach here?\n");
            //如果不是叶子节点
            fill_symboltable(astnode -> first_child,ptail);
        }
        fill_symboltable(astnode -> next_sib,ptail);
    }
}

//查表
void check_symboltable(struct ASTNode* astnode, ListNode* head){
    // printf("debug flag for check_\n");
    if(astnode == NULL){
        return;
    }
    if(astnode -> first_child == NULL){
        // printf("%s\n",astnode -> type_name);
        // 如果是叶子结点
        if(astnode -> type == ID_TYPE){
            // printf("%s\n",astnode -> data.stringval);
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
    // printf("debug flag for traversal\n");
    if(root == NULL){
        return;
    }

    // printf("type_name:%s\n",root->type_name);

    if(root -> type == EXTDEF || root -> type == DEF){
        // 填表
        fill_symboltable(root,ptail);
    }
    if(root -> type == EXP){
        // printf("***\n");
        // 查表
        // 查表时候，该填写的项一定已经被填写了吗？ 若否，似乎查表应该重新遍历
        check_symboltable(root,head);
    }

    ASTtraversal(root -> first_child, head, ptail);
    ASTtraversal(root -> next_sib, head, ptail);
}

// for variables
// 我们需要的信息似乎都在叶子上



