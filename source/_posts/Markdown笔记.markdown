---
layout: post
title: "Markdown笔记"
date: 2014-10-26 9:18
comments: true
tags: 
	- markdown
    
---
# **斜体和粗体** 
使用 \* 和 \** 表示斜体和粗体。
```
这是 *斜体*，这是 **粗体**。
```
这是 *斜体*，这是 **粗体**。

# **分级标题**

使用 === 表示一级标题，使用 --- 表示二级标题。

```
这是一个一级标题
============================

这是一个二级标题
--------------------------------------------------

### 这是一个三级标题
```

你也可以选择在行首加井号表示不同级别的标题 (H1-H6)，例如：# H1, ## H2, ### H3，#### H4。
<!-- more -->
# **外链接**

使用 \[描述](链接地址) 为文字增加外链接。
```
这是去往 [本人博客](www.tanghaoblog.me) 的链接。
```  
这是去往 [本人博客](http://thddaniel.github.com) 的链接。

# **无序列表**

使用 *，+，- 表示无序列表。

```
* 无序列表项 一
+ 无序列表项 二
- 无序列表项 三

```
* 无序列表项 一
+ 无序列表项 二
- 无序列表项 三



# **有序列表**

使用数字和点表示有序列表。
```
1. 有序列表项 一
2. 有序列表项 二 
3. 有序列表项 三
```

# **文字引用**

使用 > 表示文字引用。

```
> 一盏灯， 一片昏黄
```
> 一盏灯， 一片昏黄

注：  > 和文本之间要保留一个字符的空格。

# **行内代码块**

使用 \`代码` 表示行内代码块。

示例：

让我们聊聊 `html`。

# **代码块**

使用 四个缩进空格 表示代码块。

    这是一个代码块，此行左侧有四个不可见的空格。
    hello world.
    
# **插入图像**

使用 \!\[描述](图片链接地址) 插入图像。

```
![我的头像](https://raw.githubusercontent.com/thddaniel/Myblog/master/themes/yilia/source/img/anonymous.jpg)
```
![我的头像](https://raw.githubusercontent.com/thddaniel/Myblog/master/themes/yilia/source/img/anonymous.jpg)



# **删除线**

使用 ~~ 表示删除线。
```
~~这是一段错误的文本。~~
```
~~这是一段错误的文本。~~


# **加强的代码块**

支持编程语言的语法高亮的显示，行号显示。

非代码示例：

```
$ sudo apt-get install vim-gnome
```

Python 示例：

```python
@requires_authorization
def somefunc(param1='', param2=0):
    '''A docstring'''
    if param1 > param2: # interesting
        print 'Greater'
    return (param2 - param1 + 1) or None

class SomeClass:
    pass

>>> message = '''interpreter
... prompt'''
```

JavaScript 示例：

``` javascript
/**
* nth element in the fibonacci series.
* @param n >= 0
* @return the nth element, >= 0.
*/
function fib(n) {
  var a = 1, b = 1;
  var tmp;
  while (--n >= 0) {
    tmp = a;
    a += b;
    b = tmp;
  }
  return a;
}

document.write(fib(10));
```



# **表格支持**

```
| 项目        | 价格   |  数量  |
| --------   | -----:  | :----:  |
| 计算机     | $1600 |   5     |
| 手机        |   $12   |   12   |
| 管线        |    $1    |  234  |
```
| 项目        | 价格   |  数量  |
| --------   | -----:  | :----:  |
| 计算机     | $1600 |   5     |
| 手机        |   $12   |   12   |
| 管线        |    $1    |  234  |
