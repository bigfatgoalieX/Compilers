// #include"tree.h"
// struct Tree_Node *bison_init(char* tok,int liner){
//     struct Tree_Node * my_node=(struct Tree_Node *)malloc(sizeof(struct Tree_Node));
//     my_node->child=my_node->next_sib=NULL;
//     strcpy(my_node->name,tok);
//     my_node->height=1;
//     my_node->type=LEX_OTHERS;
//     if(emptyflag||strcmp(tok,"Program")!=0) my_node->lineno=liner;
//     else my_node->lineno=mrk_empty;
//     return my_node;
// }
// void bison_insert(struct Tree_Node *top_node,int num_args,...){

// }
// void func(struct Tree_Node* s_node,int h){
//     if(s_node==NULL) return;
//     for(int i=1;i<=h;i++) printf("  ");
//     printf("%s",s_node->name);
//     if(!s_node->height){

//     }else if(s_node->height==1) printf(" (%d)",s_node->lineno);
//     printf("\n");
//     func(s_node->child,h+1);
//     func(s_node->next_sib,h);
// }