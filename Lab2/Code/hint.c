// 对于变量，符号表至少要记录变量名及其类型；
// 对于函数，符号表至少要记录其返回类型、参数个数以及参数类型这些信息

// 每当遇到语法单元 ExtDef 或者 Def，就说明该节点的子节点们包含了变量或者函数的定义信
// 息，这时候应当将这些信息通过对子节点们的遍历提炼出来并插入到符号表里

// 每当遇到语法单元 Exp，说明该节点及其子节点们会对变量或者函数进行使用，这个时候应当查符号表以确认这
// 些变量或者函数是否存在以及它们的类型是什么

// function type_check(node):
//     if node is null:
//         return

//     if node is a variable_declaration_node:
//         # 处理变量声明节点
//         add_variable_to_symbol_table(node)
//         # 在此处可以进行类型检查

//     if node is an assignment_statement_node:
//         # 处理赋值语句节点
//         check_assignment_types(node)
//         # 在此处可以进行类型检查

//     if node is an arithmetic_expression_node:
//         # 处理算术表达式节点
//         check_arithmetic_types(node)
//         # 在此处可以进行类型检查

//     for child_node in node.children:
//         type_check(child_node)  # 递归调用以处理子节点

// # 在语法分析后，调用 type_check 函数开始遍历并执行类型检查
// type_check(root_node_of_syntax_tree)