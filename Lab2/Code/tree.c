#include "tree.h"
// 创建节点 (bison中的非叶子结点，非终结符)
Node *bison_create_node(NodeType type, char* type_name) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node != NULL) {
        node->type = type; //type
        strcpy(node->type_name,type_name); //type_name
        node->first_child = NULL; 
        node->next_sib = NULL;
        //至于data为什么没有填写？
        //因为不同的data类型需要对yytext进行不同的处理
    }
    return node;
}
//添加孩子结点，使用C语言的va_list,接收不定个参数
void addchild(Node* father, int children_cnt, ...){
    va_list args;
    //初始化可变参数列表
    va_start(args,children_cnt);
    for(int i = 0;i<children_cnt;i++){
        Node* child = va_arg(args, Node*);
        if(father -> first_child == NULL){
            father -> first_child = child;
        }
        else{
            Node* child_far_right = father -> first_child;
            while(child_far_right -> next_sib != NULL){
                child_far_right = child_far_right -> next_sib;
            }
            child_far_right -> next_sib = child;
        }
    }
    va_end(args);
}
// 创建节点 (flex中的叶子结点，终结符)
Node *flex_create_node(NodeType type, char* type_name, int line) {
    Node *node = (Node *)malloc(sizeof(Node));
    if(node != NULL){
        node->type = type; //type
        strcpy(node->type_name,type_name); //type_name
        node->first_child = NULL; 
        node->next_sib = NULL;
        //至于data为什么没有填写？
        //因为不同的data类型需要对yytext进行不同的处理
        node->lineno = line;
    }
}
// 前序遍历语法树
void preorder_traversal_AST(Node* root){
    if(root == NULL){
        return;
    }

    printf("type_name:%s\n",root->type_name);
    
    preorder_traversal_AST(root -> first_child);
    preorder_traversal_AST(root -> next_sib);
}

// 获取某个父节点的第n个孩子
Node* get_child(Node* father, int n){
    if(father == NULL){
        printf("error: Father node is NULL!\n");
        return NULL;
    }
    Node* target_node = father -> first_child;
    while((target_node != NULL) && n>0){
        n--;
        target_node = target_node -> next_sib;
    }
    if(target_node == NULL){
        // printf("error: No such child!\n");
    }
    return target_node;
}

