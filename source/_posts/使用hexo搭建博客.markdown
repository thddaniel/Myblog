---
title: "使用hexo搭建博客"
date: 2014-10-26 19:19
comments: true
tags: 

---

----------------------------2015.03.16 更新----------------------------------

最近出了3.0新版本，目前有些插件和主题并不兼容。所以暂时不更新，继续用2.8.3版本。若要更新可参考[Migrating from 2.x to 3.0](https://github.com/hexojs/hexo/wiki/Migrating-from-2.x-to-3.0)

----------------------------2015.04.26 更新----------------------------------

更新博客托管一份至GitCafe上。因为要用到新的插件，首先删除/usr/local/bin/hexo,按照上面文档升级hexo3.0。

-----

#**Hexo安装**
Hexo的作者是[tommy351](https://twitter.com/tommy351)，根据官方介绍，Hexo是一个简单、快速、强大的博客发布工具，支持Markdown格式。Hexo是一个基于Node.js的静态博客程序，其编译上百篇文字只需要几秒。hexo生成的静态网页可以直接放到GitHub Pages，BAE，SAE等平台上。
参考[官方文档](http://hexo.io/docs/index.html)


##**安装Node.js**
在 Windows 环境下安装 Node.js非常简单，仅须[下载](http://nodejs.org/)安装文件并执行即可完成安装。

##**安装Hexo**
打开git。利用 `npm` 命令即可安装。
```
npm install -g hexo
```
<!--more-->
##**创建hexo文件夹**
安装完成后，在你喜爱的文件夹下（如H:\hexo），执行以下指令(在H:\hexo内点击鼠标右键，选择Git bash)，Hexo 即会自动在目标文件夹建立网站所需要的所有文件。
```
hexo init
```
##**安装依赖包**
```
npm install
```
本地查看

现在我们已经搭建起本地的hexo博客了，执行以下命令(在H:\hexo)，然后到浏览器输入localhost:4000看看。
```
hexo generate #生成静态页面至public目录
hexo server #开启预览访问端口（默认端口4000，'ctrl + c'关闭server）
```
出现了默认的网页界面。至此，本地博客已经搭建起来了。
<br>
#**Hexo的使用**
首先大致了解下默认生成了一些文件。

- `scaffolds`   layout模板文件目录，其中的md文件可以添加编辑
- `scripts` 写文件的js，扩展hexo的功能
- `source/_posts` 存放博客正文内容
- `node_modules` 插件的目录
- `themes` 存放皮肤的目录
- `themes/landscape` 默认的主题
- `_config.yml` 全局的配置文件，大多数的设置都在这里
- `db.json` 静态常量

_posts目录：Hexo是一个静态博客框架，因此没有数据库。文章内容都是以文本文件方式进行存储的，直接存储在_posts的目录。Hexo天生集成了markdown，我们可以直接使用markdown语法格式写博客，例如:hello-world.md。新增加一篇文章，就在_posts目录，新建一个xxx.md的文件。

themes目录：是存放主题的，包括一套Javascript+CSS样式和基于EJS的模板设置。通过在themes目录下，新建一个子目录，就可以创建一套新的皮肤，当然我们也可以直接在landscape上面修改。

##**安装插件和主题**

Hexo提供丰富[主题](https://github.com/hexojs/hexo/wiki/Themes)的以及[插件](https://github.com/hexojs/hexo/wiki/Plugins)。安装方法都是一样的。

- 主题

```
$ git clone <repository> themes/<theme-name>
```
无论是插件还是主题在安装后都需要在根目录下_config.yml中修改plugins和theme的值以启用他们。
主题目录里也有个_config.yml文件，不同主题配置方法不同。
我的博客左边一栏里的社交链接。图标来源设置在main.style里。
```
├── layout #布局，根目录下的*.ejs文件是对主页，分页，存档等的控制
|   ├── _partial   #局部的布局，此目录下的*.ejs是对头尾等局部的控制
|   
├── source #源码
|   ├── css#css源码 
|   |   ├── _base  #*.styl基础css
|   |   ├── _partial   #*.styl局部css
|   |   ├── fonts  #字体
|   |   ├── style.styl #*.styl引入需要的css源码
|   ├── images #图片fancybox   
|   |—— fancybox效果源码
|   └── js #javascript源代码
├── _config.yml#主题配置文件
└── README.md  #用GitHub的都知道
```

- 插件

``` 
 npm install <plugin-name> --save
```

启用插件：在根目录\ _config.yml文件添加：
```
plugins:
- <plugin-name>  #插件名
```

升级插件：
```
npm update
```

卸载插件：
```
npm uninstall <plugin-name>
```

###**添加RSS**

hexo提供了RSS的生成插件，需要手动安装和设置。步骤如下：
安装RSS插件到本地：
```
npm install hexo-generator-feed
```
开启RSS功能：编辑hexo/_config.yml，添加如下代码：
```
plugins:
- hexo-generator-feed
```
在站点添加链接：
在themes/light/_config.yml中，编辑 rss: /atom.xml



###**添加sitemap**
同样的，我们使用hexo提供的插件，方法与添加RSS类似。
安装sitemap到本地：
```
npm install hexo-generator-sitemap
```
开启sitemap功能：编辑`hexo/_config.yml`，添加如下代码：
```
plugins:
- hexo-generator-sitemap
```
###**添加Google Analytics**

1. 注册[Google Analytics账号](http://www.google.com/analytics/)。
2. 添加自己的网站域名。
3. 把JS代码Copy到Hexo的\themes\yilia\layout\_partial\after_footer文件中。
4. 保存文件，重新生成、部署Hexo。数据统计不会立即生效，需要等待几个小时。

在mac平台上，可以使用[GAget](https://itunes.apple.com/cn/app/gaget-simple-widget-for-google/id968487158?l=en&mt=12)方便查看。
<br>
#**部署到github上**

部署到Github前需要配置`_config.yml`文件。
```
deploy:
  type: github
  repository: git@github.com:thddaniel/thddaniel.github.io.git
  branch: master
```
执行下列指令即可完成部署。
```
hexo clean
hexo generate #生成静态页面至public目录
hexo deploy  #将.deploy目录部署到GitHub
```
每次修改本地文件后，需要`hexo generate`才能保存。
有的时候当你修改页面或更改配置后发现并没有立即生效，可以执行`hexo clean`，通常直接执行`hexo g && hexo d`。

Github的版本库通常建议同时附上README.md说明文件，但是hexo默认情况下会把所有md文件解析成html文件，所以即使你在线生成了README.md，它也会在你下一次部署时被删去。怎么解决呢？

在执行hexo deploy前把在本地写好的README.md文件复制到.deploy文件夹中，再去执行hexo deploy。
注：之前修改过branch: gh-pages，但是一直显示404.不填默认为master 
<br>

#**部署到gitCafe上**
目前baidu无法扒取github的数据了，托管在github的朋友们会碰到抓取失败的问题。现在采取把博客同步到github和gitcafe的方案，通过DNSPod自定义线路类型，使电信的走电信的，网通的走网通的，国内的走Gitcafe，国外的走Github,速度大增。首先注册[gitcafe](https://gitcafe.com/signup)。必须注意git全局变量中的user.name与user.email在两个网站的注册信息中必须都是一样的。

因为使用github已经有了一套公秘钥，我希望能够在 GitCafe 上使用另一套独立的公秘钥，使得多套公秘钥可以同时存在与工作。

1.生成新的 SSH 秘钥

假设已经有了一套名为 id_rsa 的公秘钥，将要生成的公秘钥名称为 gitcafe，也可以使用任何你喜欢的名字。
```
ssh-keygen -t rsa -C "thddaniel92@gmail.com" -f ~/.ssh/gitcafe
```
生成过程中会出现一些信息，按屏幕提示操作，并记得输入 passphrase 口令。

这将在 ~/.ssh/ 目录下生成 `gitcafe` 和 `gitcafe.pub` 文件，记住千万不要把私钥文件 `gitcafe` 透露给任何人。


2.在 SSH 用户配置文件 ~/.ssh/config 中指定对应服务所使用的公秘钥名称，如果没有 config 文件的话就新建一个，并输入以下内容：
```
Host gitcafe.com www.gitcafe.com
  IdentityFile ~/.ssh/gitcafe
```

3.进入 GitCafe -->账户设置-->SSH 公钥管理设置项，点击添加新公钥 按钮，在 Title 文本框中输入任意字符，在 Key 文本框粘贴刚才复制的公钥字符串`gitcafe.pub`，按保存按钮完成操作。

4.最后测试配置文件是否正常工作
```
ssh -T git@gitcafe.com
```
如果是第一次连接的话，会出现警告，请检查一下显示的指纹是否一致：84:9e:c9:8e:7f:36:28:08:7e:13:bf:43:12:74:11:4e。输入 yes 按回车就可以了。

5.创建公开项目。如果你创建的项目名与用户名相同，GitCafe会自动识别成这是一个Page项目。

- 进入你的hexo博客目录下面的’.deploy’目录，创建gitcafe-pages分支，并切换到该分支
```
git checkout -b gitcafe-pages
```
- 添加到gitcafe的远程仓库
```
git remote add origin 'git@gitcafe.com:tanghao/tanghao.git'
```
- push到gitcafe仓库
```
git push -u origin gitcafe-pages
```
在完成上述操作后，即可访问 tanghao.gitcafe.io ,来查看页面效果了！

6.要使Hexo支持同时发布到多个git仓库中。 

先安装 [hexo-deployer-git](https://github.com/hexojs/hexo-deployer-git),支持hexo 3.0版本。
```
npm install hexo-deployer-git --save
```

需要修hexo根目录下的改_config.yml，原来的配置:
```
deploy:
type: github
repo: github: https://github.com/<username>/<username>.github.io.git
branch: master
```
现在改成
```
deploy:
   type: git
   repo: 
      github: https://github.com/thddaniel/thddaniel.github.io,master
      gitcafe: https://gitcafe.com/tanghao/tanghao.git,gitcafe-pages
```


7.写个复合命令别名添加到`~/.bash_profile`

```
alias upblog='cd ~/Documents/hexo/ && hexo g && hexo d'

```
输入命令`source .bash_profile`即可使用`upblog`命令。  

note:

In OSX the terminal you get is a login session so reads `.bash_profile` etc.

On other Unices xterm runs a non login shell by default so they read `.bashrc`.

8.绑定域名。

Gitcafe则可以绑定多个域名，在博客项目页面下项目管理->Pages服务->添加自定义域名添加自己的域名。

我使用[namecheap](https://www.namecheap.com/)管理域名。在`All Host Records`添加URL指向。

9.Dnspod做定向DNS解析

在[Dnspod国际版](https://www.dnspod.com)中选择自己的域名，添加两条A记录，国内路线使用GitCafe（A地址：207.226.141.135 CName:gitcafe.io）国外走Github线路（A地址192.30.252.153及192.30.252.154）


#**写文章**

markdown语法参考[Markdown笔记](http://tanghaoblog.me/2014/10/26/Markdown笔记/)

- **开头加信息**

标准示例：
```
---
layout: post
title: "使用hexo搭建博客"
date: 2014-10-26 19:18
comments: true
tags: 
	- hexo
description：
---
```

如果你是不想hexo g时被模板改变你的html的话，可在在文件头加layout: false

例如新建一个404页面，添加 source/404.html

```
layout: false
---
<html>
<head>
    <meta charset="UTF-8" />
    <title>公益404</title>
</head>
<body>
<h1>404 Page Not Found</h1>
<br>
<script type="text/javascript" src="http://www.qq.com/404/search_children.js"     charset="utf-8">
</script>
<br>
</body>
</html>
```


- **关于摘要**

在文档中插入`<!--more-->`就可以将文章分隔，more以上的部分会已摘要的形式显示，当查看全文时more以下的部分才会显示出来。也可以在Markdown文件中定义description。

- **嵌入图片、音乐、视频**

实际上，在hexo中，markdown支持html标签，md文件解析为html时原有的html部分会保留。有基于此，我们只要在文中插入符合html规范的代码即可。

**图片：**
同样放到source目中下。建议大家建立一个image文件夹，把文章中使用到的图片丢到这里来（当然可以按照你的习惯进行分类），之后在Markdown文件中按照这样的语法进行插入图片的操作。
```
![图片名称]({{BASE_PATH}}image/图片名称.jpg) 
```

**音乐：**
以『虾米音乐』为例，歌曲页面有个『转帖』选项，将html代码或javascript代码复制到文中即可。
```
<embed src="http://www.xiami.com/widget/0_168498_235_346_FF8719_494949/albumPlayer.swf" type="application/x-shockwave-flash" width="235" height="346" wmode="transparent"></embed>
```
<embed src="http://www.xiami.com/widget/0_168498_235_346_FF8719_494949/albumPlayer.swf" type="application/x-shockwave-flash" width="235" height="346" wmode="transparent"></embed>

**视频：**
嵌入视频的方法和音乐类似，视频网站每个视频页面都会有一个『分享』或『转帖』按钮，点击可以查看代码。


<br>
<br>

--------

**参考文献**
- [不如-hexo你的博客](http://ibruce.info/2013/11/22/hexo-your-blog/?utm_source=tuicool)
- [hexo博客同步到github和gitcafe](http://www.zhaokongnuan.com/2015/03/01/github-gitcafe/)
- [如何将托管在github上的hexo博客转到gitcafe](http://blog.maxwi.com/2014/03/19/hexo-github-to-gitcafe/)
- [如何创建Page](https://gitcafe.com/GitCafe/Help/wiki/Pages-相关帮助)



