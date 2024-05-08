# 编译原理临时笔记

### 0505 during Lab 2

```c
struct FieldList* Dec_check(struct ASTNode* node, struct Type* type){
    // Dec -> VarDec | VarDec ASSIGNOP Exp
    if(node == NULL){
        return NULL;
    }
    // struct FieldList* structure = (struct FieldList*)malloc(sizeof(struct FieldList));
    struct FieldList* tmp = VarDec_check(get_child(node, 0),type);
    // structure -> name = tmp -> name;
    // structure -> type = tmp -> type;
    // structure -> tail = NULL;

    return tmp;
}
```

行不通，因为`VarDec_check`这个函数需要负责数组，其返回类型不能是`struct FieldList*`。

前面之所以很多函数返回类型设为`struct FieldList*`，是因为它们的`struct type`中的`kind`域是确定的STRUCTURE，所以没必要返回`struct Type*`，只需要返回需要填写的`struct FieldList*`域即可。

修改为：

```c
struct FieldList* Dec_check(struct ASTNode* node, struct Type* type){
    // Dec -> VarDec | VarDec ASSIGNOP Exp
    if(node == NULL){
        return NULL;
    }
    struct FieldList* structure = (struct FieldList*)malloc(sizeof(struct FieldList));
    struct Type* tmp = VarDec_check(get_child(node, 0),type);
    structure -> name = tmp -> u.structure -> name;
    structure -> type = tmp -> u.structure -> type;
    structure -> tail = NULL;

    return structure;
}
```

### 段错误

- 指针在使用前需要排除空指针

  ```C
  if(ptr != NULL){}
  ```

- 创建一个新指针需要给它分配空间，尤其需要注意，结构体里面的指针需要另外给分配指针

  ```c
  #include "stdlib"
  struct foo{
      int member1;
      struct foo* member2;
  };
  int main(){
      struct foo* x = (struct foo*) malloc(sizeof(struct foo));
      //你可以使用 x->member1 x->member2但不能使用x->member2->member1
      x -> member2 = (struct foo*) malloc(sizeof(struct foo));
      //此时你才可以使用x->member2->member1
  }
  ```

  
