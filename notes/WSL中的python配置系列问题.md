### 什么是`pyenv`?

是一个python版本管理工具。注意这和`conda`还是不一样的，`conda`相当于隔离出了若干个不同的子环境。

### 暂时设置环境变量

```bash
export PATH="$HOME/.pyenv/bin:$PATH"
```

> 为什么给`./bashrc`里面写没有用？可能是写错地方了(确实写错地方了...)

### 注意符号含义

```
~ -> root
```

### 绕过报错

```bash
"qt.qpa.plugin: Could not load the Qt platform plugin "xcb" in "" even though it was found."
export QT_QPA_PLATFORM=offscreen
```

> 这是否disable了QT？

### 另外的奇怪报错

```bash
https://stackoverflow.com/questions/44967202/pip-is-showing-error-lsb-release-a-returned-non-zero-exit-status-1
```

![屏幕截图 2024-05-08 190741](D:\NJU_undergraduate\大三下\编译原理\notes\屏幕截图 2024-05-08 190741.png)