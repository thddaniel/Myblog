---
layout: post
title: "sublime text 3"
date: 2015-02-24 19:18
comments: true
tags: 
	- sublime text
	
---
- 改字体：Sublime Text -> Preferences -> Settings-User
- 从终端打开：sudo ln /Applications/Sublime\ Text.app/Contents/SharedSupport/bin/subl /bin/subl 以后可直接输入subl

---
|符号 | 键 |
| - | -----:  | 
|⌘ | Command key|
|⌃ |Control key|
|⌥ |Option key|
|⇧ |Shift Key|
<!--more-->
#Edit(编辑)
- ⌘[ 向左缩进 | Left indent
- ⌘] 向右缩进 | Right Indent
- ⌘⌃↑ 与上一行互换（超实用！）| Swap line up
- ⌘⌃↓ 与下一￼行互换￼（超实用！）| Swap line down
- ⌘⇧D 复制粘贴当前行（减少多余的粘贴）| Duplicate line
- ⌘J 拼接行（css格式化时挺有用） | join lines
- ⌘← 去往行的开头 | Beginning of line
- ⌘→ 去往行末尾 | End of line
- ⌘⌃/ 块注释 | Toggle comment block
- ⌃K 从光标开始的地方删除到行尾 | Delete to end
- ⌃⇧K 删除一整行 | delete line
- ⌃T 相邻单词互换位置，在','前试用，有惊喜（很有趣）| Transpose
- ⌘⇧↩ 向光标前插入一行|insert line before
- ⌘↩ 向光标后插入一行|inter line after
- ⌘⌥T 插入特殊字符|Special characters
- ⌃D 向后删除（很怪异的操作，不过感觉很酷炫）

#Selection(光标选中)
- ⌘D 选中相同的词 | Expand selection to words
- ⌃⌘G 多重文本光标选中（再也不用⌘ D一个一个的找啦）| Expand all selection to words
- ⌘L 选中一行|Expand selection to line
- Esc 单选（取消多重选择）|Single selection,Cancel multiple selections
- ⌃⇧↑ 一行一行向上选中|Add previous line
- ⌃⇧↓ 一行一行向下选中|Add next line
- ⌘⇧L 将选中的区域分割成多行选中状态(多光标操作状态)|Split into lines
- ⌥+拖动鼠标 多重光标选中
- ⌘⇧J 已缩进层级为依据，一层层向外选中|Expand selection to indentation
- ⌃⇧M 将匹配括号中的内容选中|Expand selection to brackets



#Find(查找)
- ⌘F 普通查找|Find
- ⌘G 查找下一个|Find next
- ⌘⇧F 在文件夹中查找| Find in files
- ⌘⇧E 缓存用于替换的内容，方便之后的替换|Use selection for replace
- ⌘E 缓存用于查找的内容，方便之后的查找|Use selection for find
- ⌘⌥E 一个接一个往下替换|Replace next



#View(视图)
- 推荐使用Origami插件，可以随意对sublime进行分割

#Go to(跳转/定位)
- ⌘P 跳转文件（很方便）| Go to anything
- ⌘R 定位文件中的方法@| Go to symbol
- ⌘G 定位文件中的行号:| Go to line
- ⌃M 定位匹配的括号 | Jump to matching bracket
- ⌘F2 设置/取消定位标记| Toggle bookmark
- F2 跳转到定位标记处 | Next bookmark
- ⌘⇧F2 清除所有定位标记| Clear all bookmarks
- ⌘⌥→ 下一个打开的文件| Next file

#Project(工程)
- ⌘⌃P 在保存过的工程中切换，随意变换工程环境|Switch project window

Resource:[Sublime Text 3 Documentation](http://www.sublimetext.com/docs/3/)