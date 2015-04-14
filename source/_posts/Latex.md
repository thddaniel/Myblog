---
layout: post
title: "Sublime Text with latex & skim"
date: 2015-2-23 19:18
comments: true
tags: 

---
# 安装步骤
1. 安装[Sublime Text 3](http://www.sublimetext.com/3)、[MacTex](https://tug.org/mactex/)(2.4G)。
2. 给 Sublime Text 安装[Package Control](https://packagecontrol.io/installation)。
3. 在 Sublime Text 窗口中按下 Cammand + Shift + P，键入「install」之后回车，找到「LaTeXTools」这个 Sublime Text Package 并安装。
4. 安装[Skim](http://skim-app.sourceforge.net/)，在`偏好设置->同步` 修改预设成自定义，指令：/Applications/Sublime Text.app/Contents/SharedSupport/bin/subl。<!--more-->
5. 打开编辑`~/Library/Application\ Support/Sublime\ Text\ 3/Packages/User/LaTeXTools.sublime-settings`，将其中"builder"条目改为：
```
“builder”: “simple”
```
编辑`~/Library/Application\ Support/Sublime\ Text\ 3/Packages/LaTeXTools/builders/simpleBuilder.py `第41行:
```
pdflatex = [“pdflatex”, “-interaction=nonstopmode”, “-synctex=1″]
修改为
pdflatex = [“xelatex”, “-interaction=nonstopmode”, “-synctex=1″]
```

# LaTex 语法
