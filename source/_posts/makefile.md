---
layout: post
title: "Makefile basics"
comments: true
tags: 

	
---

每次看完文档，过一段时间不用就忘记了。今天做毕业设计需要写Makefile,又重新看了一下[GNU make](http://www.gnu.org/software/make/manual/make.html)，干脆把常用的提取出来。以后也把一些常用的函数等等写在博客好了，我这记忆力也是没救了。

-----------

后来google发现阮一峰老师总结的很好。文中部分内容来自[阮一峰Make命令教程](http://www.ruanyifeng.com/blog/2015/02/make.html),以后发现常用的知识就在这篇补充好了。

------


#Makefile
Makefile文件由一系列规则（rules）构成。每条规则的形式如下。

```
<target> : <prerequisites> 
[tab]  <commands>
```
目标（target）是必须的，不能省略。前置条件（prerequisites）和命令（commands）都是可选的，但是必须要有一个。

在Makefile中，规则的顺序是很重要的，因为，**Makefile中只应该有一个最终目标**，其它的目标都是被这个目标所连带出来的，所以一定要让make知道你的最终目标是什么。<!--more-->

##目标（target）
一个目标（target）就构成一条规则。目标通常是文件名，指明Make命令所要构建的对象。目标可以是一个文件名，也可以是多个文件名，之间用空格分隔。

```
test:a.c b.c a.h	gcc -o test a.c b.c
``` 

除了文件名，目标还可以是某个操作的名字，这称为"伪目标"（phony target）。


- `all`	所有目标的目标，其功能一般是编译所有的目标
- `clean`	删除所有被make创建的文件
- `install`	安装已编译好的程序，其实就是把目标可执行文件拷贝到指定的目录中去
- `print`	列出改变过的源文件
- `tar`	把源程序打包备份. 也就是一个tar文件
- `dist`	创建一个压缩文件, 一般是把tar文件压成Z文件. 或是gz文件
- `TAGS`	更新所有的目标, 以备完整地重编译使用
- `check` 或 `test`	一般用来测试makefile的流程

下面代码的目标是clean，它不是文件名，而是一个操作的名字，属于"伪目标 "，作用是删除对象文件。但是，如果当前目录中，正好有一个文件叫做clean，那么这个命令不会执行。因为Make发现clean文件已经存在，就认为没有必要重新构建了，就不会执行指定的rm命令。

```
clean:
      rm *.o
```

为了避免这种情况，可以明确声明clean是"伪目标"，写法如下。声明clean是"伪目标"之后，make就不会去检查是否存在一个叫做clean的文件，而是每次运行都执行对应的命令。像.PHONY这样的内置目标名还有不少，可以查看[手册](http://www.gnu.org/software/make/manual/html_node/Special-Targets.html#Special-Targets)。

```
.PHONY: clean
clean:
        rm *.o temp
```

如果Make命令运行时没有指定目标，默认会执行Makefile文件的第一个目标。

```
utorial:
	@# todo: have this actually run some kind of tutorial wizard?
	@echo "Please read the 'Makefile' file to go through this tutorial"
```
执行make命令相当于make tutorial。

##前置条件（prerequisites）

前置条件通常是一组文件名，之间用空格分隔。它指定了"目标"是否重新构建的判断标准：只要有一个前置文件不存在，或者有过更新（前置文件的last-modification时间戳比目标的时间戳新），"目标"就需要重新构建。

```
result.txt: source.txt
    cp source.txt result.txt
```
上面代码中，构建 result.txt 的前置条件是 source.txt 。如果当前目录中，source.txt 已经存在，那么make result.txt可以正常运行，否则必须再写一条规则，来生成 source.txt 。

```
source.txt:
    echo "this is the source" > source.txt
```
上面代码中，source.txt后面没有前置条件，就意味着它跟其他文件都无关，只要这个文件还不存在，每次调用make source.txt，它都会生成。

##命令（commands）
命令（commands）表示如何更新目标文件，由一行或多行的Shell命令组成。它是构建"目标"的具体指令，它的运行结果通常就是生成目标文件。
每行命令之前必须有一个tab键。如果想用其他键，可以用内置变量.RECIPEPREFIX声明。

```
.RECIPEPREFIX = >
all:
> echo Hello, world
```

需要注意的是，每行命令在一个单独的shell中执行。这些Shell之间没有继承关系。

```
var-lost:
    export foo=bar
    echo "foo=[$$foo]"
```

上面代码执行后（make var-lost），取不到foo的值。因为两行命令在两个不同的进程执行。一个解决办法是将两行命令写在一行，中间用分号分隔。

```
var-kept:
    export foo=bar; echo "foo=[$$foo]"
```

另一个解决办法是在换行符前加反斜杠转义。

```
var-kept:
    export foo=bar; \
    echo "foo=[$$foo]"
```

最后一个方法是加上.ONESHELL:命令。

```
.ONESHELL:
var-kept:
    export foo=bar; 
    echo "foo=[$$foo]"
```

If you want to export specific variables to a **sub-make**, use the export directive, like this: `export variable` …

If you want to prevent a variable from being exported, use the unexport directive, like this: `unexport variable` …
#常用语法

##注释
井号（#）在Makefile中表示注释。如果要使用或者输出"#"字符, 需要进行转义, "\#"
##回声（echoing）
正常情况下，**make会打印每条命令**，然后再执行，这就叫做回声（echoing）。

- 不用前缀   : 输出执行的命令以及命令执行的结果, 出错的话停止执行
- 前缀 `@`  : 只输出命令执行的结果, 出错的话停止执行
- 前缀 `-`   : 命令执行有错的话, 忽略错误, 继续执行


```
test:
    # 这是测试
```
执行上面的规则，会得到下面的结果。

$ make test

```
# 这是测试
```
在命令的前面加上@，就可以关闭回声。

```
test:
    @# 这是测试
```
现在再执行make test，就不会有任何输出。
由于在构建过程中，需要了解当前在执行哪条命令，**所以通常只在注释和纯显示的echo命令前面加上@。**

```
test:
    @# 这是测试
    @echo TODO
```
##通配符
通配符（wildcard）用来指定一组符合条件的文件名。Makefile 的通配符与 Bash 一致，主要有星号（*）、问号（？）和 [...] 。

- `*`      表示任意一个或多个字符
- `?`      表示任意一个字符
- `[...]`  ex. [abcd] 表示a,b,c,d中任意一个字符, [^abcd]表示除a,b,c,d以外的字符, [0-9]表示 0~9中任意一个数字
- `~`      表示用户的home目录

比如， *.o 表示所有后缀名为o的文件。

```
clean:
        rm -f *.o
```

##路径搜索
当一个Makefile中涉及到大量源文件时(这些源文件和Makefile极有可能不在同一个目录中),

这时, 最好将源文件的路径明确在Makefile中, 便于编译时查找. Makefile中有个特殊的变量 VPATH 就是完成这个功能的.

指定了 VPATH 之后, 如果当前目录中没有找到相应文件或依赖的文件, Makefile 回到 VPATH 指定的路径中再去查找..

VPATH 使用方法:

- `vpath <directories>`             当前目录中找不到文件时, 就从`directories`中搜索
- `vpath <pattern> <directories>`   符合`pattern`格式的文件, 就从`directories`中搜索
- `vpath <pattern>`                 清除符合`pattern`格式的文件搜索路径 
- `vpath`                           清除所有已经设置好的文件路径 

```
# 示例1 - 当前目录中找不到文件时, 按顺序从 src目录 ../parent-dir目录中查找文件
VPATH src:../parent-dir   

# 示例2 - .h结尾的文件都从 ./header 目录中查找
VPATH %.h ./header

# 示例3 - 清除示例2中设置的规则
VPATH %.h

# 示例4 - 清除所有VPATH的设置
VPATH
``` 
                           

##模式匹配
Make命令允许对文件名，进行类似正则运算的匹配，主要用到的匹配符是%。比如，假定当前目录下有 f1.c 和 f2.c 两个源码文件，需要将它们编译为对应的对象文件。

```
%.o: %.c
```
等同于下面的写法。

```
f1.o: f1.c
f2.o: f2.c
```
**使用匹配符%，可以将大量同类型的文件，只用一条规则就完成构建。**
##变量和赋值符
Makefile 允许使用等号自定义变量。

```
txt = Hello World
test:
    @echo $(txt)
```
上面代码中，变量 txt 等于 Hello World。调用时，变量需要放在 `$( )` 之中。
调用Shell变量，需要在美元符号前，再加一个美元符号，这是因为Make命令会对美元符号转义。

```
test:
    @echo $$HOME
```
有时，变量的值可能指向另一个变量。

```
v1 = $(v2)
```
上面代码中，变量 v1 的值是另一个变量 v2。这时会产生一个问题，v1 的值到底在定义时扩展（静态扩展），还是在运行时扩展（动态扩展）？如果 v2 的值是动态的，这两种扩展方式的结果可能会差异很大。

为了解决类似问题，Makefile一共提供了四个赋值运算符 （=、:=、？=、+=），它们的区别请看[StackOverflow](http://stackoverflow.com/questions/448910/makefile-variable-assignment)。其中 = 和 := 的区别在于, := 只能使用前面定义好的变量, = 可以使用后面定义的变量

```
# Makefile内容
OBJS2 = $(OBJS1) programC.o
OBJS1 = programA.o programB.o

all:
    @echo $(OBJS2)

# bash中执行 make, 可以看出虽然 OBJS1 是在 OBJS2 之后定义的, 但在 OBJS2中可以提前使用
$ make
programA.o programB.o programC.o
---------------------------------------
# Makefile内容
OBJS2 := $(OBJS1) programC.o
OBJS1 := programA.o programB.o

all:
    @echo $(OBJS2)

# bash中执行 make, 可以看出 OBJS2 中的 $(OBJS1) 为空
$ make
programC.o
```

##内置变量（Implicit Variables）
Make命令提供一系列内置变量，比如，$(CC) 指向当前使用的编译器，$(MAKE) 指向当前使用的Make工具。这主要是为了跨平台的兼容性，详细的内置变量清单见[手册](https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html)。

```
output:
    $(CC) -o output input.c
```

##自动变量（Automatic Variables）
Make命令还提供一些自动变量，它们的值与当前规则有关。主要有以下几个。

###$@
`$@`指代当前目标，就是Make命令当前构建的那个目标。比如，make foo的 `$@` 就指代foo。

```
a.txt b.txt: 
    touch $@
```
等同于下面的写法。

```
a.txt:
    touch a.txt
b.txt:
    touch b.txt
```
###$<
`$<`指代第一个前置条件。比如，规则为 t: p1 p2，那么$< 就指代p1。

```
a.txt: b.txt c.txt
    cp $< $@ 
```
等同于下面的写法。

```
a.txt: b.txt c.txt
    cp b.txt a.txt 
```
###$?
 `$?` 指代比目标更新的所有前置条件，之间以空格分隔。比如，规则为 t: p1 p2，其中 p2 的时间戳比 t 新，$?就指代p2。

###$^
`$^` 指代所有前置条件，之间以空格分隔。比如，规则为 t: p1 p2，那么 $^ 就指代 p1 p2 。

###$*
`$*` 指代匹配符 % 匹配的部分， 比如% 匹配 f1.txt 中的f1 ，`$*` 就表示 f1。

###$(@D) 和 $(@F)
`$(@D)` 和 `$(@F)` 分别指向 $@ 的目录名和文件名。比如，`$@`是 src/input.c，那么`$(@D)` 的值为 src ，`$(@F)` 的值为 input.c。

###$(<D) 和 $(<F)
`$(<D)` 和 `$(<F)` 分别指向 `$<` 的目录名和文件名。
所有的自动变量清单，请看[手册](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)。下面是自动变量的一个例子。

```
dest/%.txt: src/%.txt
    @[ -d dest ] || mkdir dest
    cp $< $@
```
上面代码将 src 目录下的 txt 文件，拷贝到 dest 目录下。首先判断 dest 目录是否存在，如果不存在就新建，然后，`$<` 指代前置文件（src/%.txt）， `$@` 指代目标文件（dest/%.txt）。

##判断和循环
Makefile使用 Bash 语法，完成判断和循环。条件判断的关键字主要有 ifeq ifneq ifdef ifndef

```
ifeq ($(CC),gcc)
  libs=$(libs_for_gcc)
else
  libs=$(normal_libs)
endif
```
上面代码判断当前编译器是否 gcc ，然后指定不同的库文件。

```
LIST = one two three
all:
    for i in $(LIST); do \
        echo $$i; \
    done

#等同于

all:
    for i in one two three; do \
        echo $i; \
    done
```
上面代码的运行结果。

```
one
two
three
```
##函数
Makefile 还可以使用函数，格式如下。

```
$(function arguments)
# 或者
${function arguments}
```
Makefile提供了许多[内置函数](http://www.gnu.org/software/make/manual/html_node/Functions.html)，可供调用。下面是几个常用的内置函数。

###shell 函数
shell 函数用来执行 shell 命令 语法：`$(shell <shell command>)`

```
srcfiles := $(shell echo src/{00..99}.txt)
```
### 字符串函数
（1）strip函数
功能: 去掉 `string` 字符串中开头和结尾的空字符

返回: 被去掉空格的字符串值

```
# Makefile 内容
VAL := "       aa  bb  cc "

all:
    @echo "去除空格前: " $(VAL)
    @echo "去除空格后: " $(strip $(VAL))

# bash 中执行 make
$ make
去除空格前:         aa  bb  cc 
去除空格后:   aa bb cc
```

（2）wildcard 函数
它的用法是：`$(wildcard PATTERN...)`。在Makefile中，它被展开为已经存在的、使用空格分开的、匹配此模式的所有文件列表。如果不存在任何符合此模式的文件，函数会忽略模式字符并返回空。

获取src目录下所有`.txt`结尾的文件
```
srcfiles := $(wildcard src/*.txt)
```
（3）subst 函数
subst 函数用来文本替换，格式如下。

```
$(subst from,to,text)
```

下面的例子将字符串"feet on the street"替换成"fEEt on the strEEt"。

```
$(subst ee,EE,feet on the street)
```
下面是一个稍微复杂的例子。

```
comma:= ,
empty:=
# space变量用两个空变量作为标识符，当中是一个空格
space:= $(empty) $(empty)
foo:= a b c
bar:= $(subst $(space),$(comma),$(foo))
# bar is now `a,b,c'.
```
（4）patsubst函数
patsubst 函数用于模式匹配的替换，格式如下。

```
$(patsubst pattern,replacement,text)
```
下面的例子将文件名"x.c.c bar.c"，替换成"x.c.o bar.o"。

```
$(patsubst %.c,%.o,x.c.c bar.c)
```
（5）替换后缀名
替换后缀名函数的写法是：变量名 + 冒号 + 后缀名替换规则。它实际上patsubst函数的一种简写形式。

```
min: $(OUTPUT:.js=.min.js)
```
上面代码的意思是，将变量OUTPUT中的后缀名 .js 全部替换成 .min.js 。

（6）查找字符串函数: `$(findstring <find>,<in>)`

功能: 在字符串 `in` 中查找 `find` 字符串

返回: 如果找到, 返回 `find` 字符串,  否则返回空字符串

```
# Makefile 内容
VAL := "       aa  bb  cc "

all:
    @echo $(findstring aa,$(VAL))
    @echo $(findstring ab,$(VAL))

# bash 中执行 make
$ make
aa

```

（7）过滤函数: `$(filter <pattern...>,<text>)`

功能: 以 `pattern` 模式过滤字符串 `text`, *保留* 符合模式 `pattern` 的单词, 可以有多个模式

返回: 符合模式 `pattern` 的字符串

```
# Makefile 内容
all:
    @echo $(filter %.o %.a,program.c program.o program.a)


# bash 中执行 make
$ make
program.o program.a

```
（8）反过滤函数: `$(filter-out <pattern...>,<text>)`

功能: 以 `pattern` 模式过滤字符串 `text`, *去除* 符合模式 `pattern` 的单词, 可以有多个模式

返回: 不符合模式 `pattern` 的字符串

```
# Makefile 内容
all:
    @echo $(filter-out %.o %.a,program.c program.o program.a)

# bash 中执行 make
$ make
program.c
```
（9）排序函数: `$(sort <list>)`
功能: 给字符串 `list` 中的单词排序 (升序)

返回: 排序后的字符串

```
# Makefile 内容
all:
    @echo $(sort bac abc acb cab)

# bash 中执行 make
$ make
abc acb bac cab
```
（10）取单词函数: `$(word <n>,<text>)`
功能: 取字符串 `text` 中的 第`n`个单词 (n从1开始)

返回: `text` 中的第`n`个单词, 如果`n` 比 `text` 中单词个数要大, 则返回空字符串

```
# Makefile 内容
all:
    @echo $(word 1,aa bb cc dd)
    @echo $(word 5,aa bb cc dd)
    @echo $(word 4,aa bb cc dd)

# bash 中执行 make
$ make
aa

dd
```

（11）取单词串函数: `$(wordlist <s>,<e>,<text>)`

功能: 从字符串`text`中取从`s`开始到`e`的单词串. `s`和`e`是一个数字.

返回: 从`s`到`e`的字符串

```
# Makefile 内容
all:
    @echo $(wordlist 1,3,aa bb cc dd)
    @echo $(word 5,6,aa bb cc dd)
    @echo $(word 2,5,aa bb cc dd)


# bash 中执行 make
$ make
aa bb cc

bb
```
 

（12）单词个数统计函数: `$(words <text>)`

功能: 统计字符串 `text` 中单词的个数

返回: 单词个数

```
# Makefile 内容

all:
    @echo $(words aa bb cc dd)
    @echo $(words aabbccdd)
    @echo $(words )

# bash 中执行 make
$ make
4
1
0
```

（13）首单词函数: `$(firstword <text>)`

功能: 取字符串 `text` 中的第一个单词

返回: 字符串 `text` 中的第一个单词

```
# Makefile 内容
all:
    @echo $(firstword aa bb cc dd)
    @echo $(firstword aabbccdd)
    @echo $(firstword )

# bash 中执行 make
$ make
aa
aabbccdd
```
###文件名函数

（1）取目录函数: `$(dir <names...>)`

功能: 从文件名序列 `names> 中取出目录部分

返回: 文件名序列 `names> 中的目录部分

```
# Makefile 内容
all:
    @echo $(dir /home/a.c ./bb.c ../c.c d.c)


# bash 中执行 make
$ make
/home/ ./ ../ ./
```
 

（2）取文件函数: `$(notdir <names...>)`

功能: 从文件名序列 `names` 中取出非目录部分

返回: 文件名序列 `names` 中的非目录部分

```
# Makefile 内容
all:
    @echo $(notdir /home/a.c ./bb.c ../c.c d.c)

# bash 中执行 make
$ make
a.c bb.c c.c d.c
```
 

（3）取后缀函数: `$(suffix <names...>)`

功能: 从文件名序列 `names` 中取出各个文件名的后缀

返回: 文件名序列 `names` 中各个文件名的后缀, 没有后缀则返回空字符串

```
# Makefile 内容
all:
    @echo $(suffix /home/a.c ./b.o ../c.a d)

# bash 中执行 make
$ make
.c .o .a
```
 

（4）取前缀函数: `$(basename <names...>)`

功能: 从文件名序列 `names` 中取出各个文件名的前缀

返回: 文件名序列 `names` 中各个文件名的前缀, 没有前缀则返回空字符串

```
# Makefile 内容
all:
    @echo $(basename /home/a.c ./b.o ../c.a /home/.d .e)


# bash 中执行 make
$ make
/home/a ./b ../c /home/
```
 

（5）加后缀函数: `$(addsuffix <suffix>,<names...>)`

功能: 把后缀 `suffix` 加到 `names` 中的每个单词后面

返回: 加过后缀的文件名序列

```
# Makefile 内容
all:
    @echo $(addsuffix .c,/home/a b ./c.o ../d.c)


# bash 中执行 make
$ make
/home/a.c b.c ./c.o.c ../d.c.c
```
 

（6）加前缀函数: `$(addprefix <prefix>,<names...>)`

功能: 把前缀 `prefix` 加到 `names` 中的每个单词前面

返回: 加过前缀的文件名序列

```
# Makefile 内容
all:
    @echo $(addprefix test_,/home/a.c b.c ./d.c)

# bash 中执行 make
$ make
test_/home/a.c test_b.c test_./d.c
```
 

（7）连接函数: `$(join <list1>,<list2>)`

功能: `list2` 中对应的单词加到 `list1` 后面

返回: 连接后的字符串

```
# Makefile 内容
all:
    @echo $(join a b c d,1 2 3 4)
    @echo $(join a b c d,1 2 3 4 5)
    @echo $(join a b c d e,1 2 3 4)

# bash 中执行 make
$ make
a1 b2 c3 d4
a1 b2 c3 d4 5
a1 b2 c3 d4 e
```

###foreach函数
语法: `$(foreach <var>,<list>,<text>)`

示例:

```
# Makefile 内容
targets := a b c d
objects := $(foreach i,$(targets),$(i).o)

all:
    @echo $(targets)
    @echo $(objects)

# bash 中执行 make
$ make
a b c d
a.o b.o c.o d.o
```

###if
这里的if是个函数, 和前面的条件判断不一样, 前面的条件判断属于Makefile的关键字

语法:

`$(if <condition>,<then-part>)`

`$(if <condition>,<then-part>,<else-part>)`

 

示例:

```
# Makefile 内容
val := a
objects := $(if $(val),$(val).o,nothing)
no-objects := $(if $(no-val),$(val).o,nothing)

all:
    @echo $(objects)
    @echo $(no-objects)

# bash 中执行 make
$ make
a.o
nothing
```

### call - 创建新的参数化函数

语法:

`$(call <expression>,<parm1>,<parm2>,<parm3>...)`

 

示例:

```
# Makefile 内容
log = "====debug====" $(1) "====end===="

all:
    @echo $(call log,"正在 Make")

# bash 中执行 make
$ make
====debug==== 正在 Make ====end====
```

###origin - 判断变量的来源
语法:

`$(origin <variable>)`

返回值有如下类型:

- `undefined`	`variable` 没有定义过
- `default`	`variable` 是个默认的定义, 比如 CC 变量
- `environment`	`variable` 是个环境变量, 并且 make时没有使用 -e 参数
- `file`	`variable` 定义在Makefile中
- `command line`	`variable` 定义在命令行中
- `override`	`variable` 被 override 重新定义过
- `automatic`	`variable` 是自动化变量

示例:

```
# Makefile 内容
val-in-file := test-file
override val-override := test-override

all:
    @echo $(origin not-define)    # not-define 没有定义
    @echo $(origin CC)            # CC 是Makefile默认定义的变量
    @echo $(origin PATH)         # PATH 是 bash 环境变量
    @echo $(origin val-in-file)    # 此Makefile中定义的变量
    @echo $(origin val-in-cmd)    # 这个变量会加在 make 的参数中
    @echo $(origin val-override) # 此Makefile中定义的override变量
    @echo $(origin @)             # 自动变量, 具体前面的介绍

# bash 中执行 make
$ make val-in-cmd=val-cmd
undefined
default
environment
file
command line
override
automatic
```

###make 控制函数

产生一个致命错误: `$(error <text ...>)`

功能: 输出错误信息, 停止Makefile的运行

```
# Makefile 内容
all:
    $(error there is an error!)
    @echo "这里不会执行!"

# bash 中执行 make
$ make
Makefile:2: *** there is an error!.  Stop.
```
 

输出警告: `$(warning <text ...>)`

功能: 输出警告信息, Makefile继续运行

```
# Makefile 内容
all:
    $(warning there is an warning!)
    @echo "这里会执行!"

# bash 中执行 make
$ make
Makefile:2: there is an warning!
这里会执行!
```

#示例
模仿linux内核scripts文件夹里的makefile的编写思路。Makefile主要分成3类:

- 顶层目录的Makefile
- 顶层目录的Makefile.build 
- 各级子目录的Makefile

##各级子目录的Makefile
它最简单，形式如下：```obj-y += file.oobj-y += subdir/```"obj-y += file.o"表示把当前目录下的file.c编进程序里。
"obj-y += subdir/"表示要进入subdir这个子目录下去寻找文件来编进程序里，是哪些文件由subdir目录下的Makefile决定。**注意: "subdir/"中的斜杠"/"不可省略**
##顶层目录的Makefile
它除了定义obj-y来指定根目录下要编进程序去的**文件、子目录**外，主要是定义**工具链、编译参数、链接参数**──就是文件中用export导出的各变量。
```CROSS_COMPILE = arm-linux-AS		= $(CROSS_COMPILE)asLD		= $(CROSS_COMPILE)ldCC		= $(CROSS_COMPILE)gccCPP		= $(CC) -EAR		= $(CROSS_COMPILE)arNM		= $(CROSS_COMPILE)nmSTRIP		= $(CROSS_COMPILE)stripOBJCOPY		= $(CROSS_COMPILE)objcopyOBJDUMP		= $(CROSS_COMPILE)objdumpexport AS LD CC CPP AR NMexport STRIP OBJCOPY OBJDUMPCFLAGS := -Wall -Werror -O2 -gCFLAGS += -I $(shell pwd)/includeLDFLAGS := -lm -lfreetype -lts -lpthread -ljpegexport CFLAGS LDFLAGSTOPDIR := $(shell pwd)export TOPDIRTARGET := digitpic```

##顶层目录的Makefile.build
这是最复杂的部分，它是利用递归的方式编译。它的功能就是把某个目录及它的所有子目录中、需要编进程序去的文件都编译出来，打包为built-in.o

```
PHONY := __build__build:obj-y :=subdir-y :=include Makefile# obj-y := a.o b.o c/ d/# $(filter %/, $(obj-y))   : c/ d/# __subdir-y  : c d# subdir-y    : c d__subdir-y	:= $(patsubst %/,%,$(filter %/, $(obj-y)))subdir-y	+= $(__subdir-y)# c/built-in.o d/built-in.osubdir_objs := $(foreach f,$(subdir-y),$(f)/built-in.o)# a.o b.ocur_objs := $(filter-out %/, $(obj-y))dep_files := $(foreach f,$(cur_objs),.$(f).d)dep_files := $(wildcard $(dep_files))ifneq ($(dep_files),)  include $(dep_files)endifPHONY += $(subdir-y)__build : $(subdir-y) built-in.o$(subdir-y):	make -C $@ -f $(TOPDIR)/Makefile.buildbuilt-in.o : $(cur_objs) $(subdir_objs)	$(LD) -r -o $@ $^dep_file = .$@.d%.o : %.c	$(CC) $(CFLAGS) -Wp,-MD,$(dep_file) -c -o $@ $<	.PHONY : $(PHONY)
```
##怎么使用这套Makefile

1. 把顶层Makefile, Makefile.build放入程序的顶层目录
2. 修改顶层Makefile（工具链、编译选项、链接选项、obj-y决定顶层目录下哪些文件、哪些子目录被编进程序、修改TARGET，这是用来指定编译出来的程序的名字）