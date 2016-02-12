---
layout: post
title: "keynote笔记"
comments: true
date: 2015-4-20 19:18
tags: 

---

- 制作keynote除了一些技巧外，更需要提高自己的**审美观**。这点得慢慢来。
- 制作keynote的时候,**首先要明确这是单纯用来给人看的，还是自己用来配合演讲的。**这完全是两种风格的幻灯片。通常单纯提供个别人看的，文字图表会比较多。作者把想讲的的内容都放进了幻灯片里了。
- 要保证**视觉元素的一致性与整个幻灯片的完整性**，要有逻辑性，尤其是当演讲内容很多的时候，不要把幻灯片做的支离破碎。这样可以让观众更好的理解演讲者讲的内容。
- 根据不同的场景，不同的观众，选择不同的**字体效果**（大小、形状、颜色(善用取色放大镜)、下划线等等）。幻灯片**背景**要保证与所讲内容主题匹配。比如介绍书籍时，背景可以是个书架，然后书依次显示到书架上。这几点要慎重考虑。
- keynote可以对图片进行简单的裁剪和修饰(Edit Mask with shape& Instant Alpha)，有时候图片或者视频更能表达出演讲者所想讲的内容，对观众的视觉冲击力更大，可以采用声画同步。<!--more-->
- Shape图片里不要直接在里面编辑文字，最好新建Text后拖进图片里。



-------

#Gist
##次序
如果在不同的幻灯片里展示第一点、第二点...这样观众看到新的容易忘记旧的。

如果在同一页全部展示，会造成视觉的混乱，观众的注意力会被分散。

**所以当要展示多个内容的时候，要一次只让观众只注意一点，其余点采用幻灯片的透明效果展示出来。**

![次序](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/keynote/%E6%AC%A1%E5%BA%8F.png)

1. 点击Text，填写`1`、`2`。
2. 选择`2`，Build In 里选择 Appear。
3. 选择`1`，Action 里选择 Opacity，透明度调到10%。Build Order里选择与上个动作同时发生。
4. 继续添加`3`，选择Appear。把`2`透明度调低...以此类推...

可以在结尾时，让所有之前透明的次序同时出现，进行总结。

1. 复制前一个幻灯片，全选次序，把 Build In 和 Action 调成无。
2. 选择前一个幻灯片，Add an Effect，选择Dissolve。
<br>

------------
##纵深关系
每一页幻灯片是有层次的，比如当制作文字背景时，因为背景后添加，所以覆盖在文字上。这时候，选择文字右键Bring to Front，文字就显示在最上层了。同理也可以操作Send to back。

通常情况各种图片**有层次顺序叠加**配上相应的**动画效果**，能展示出好看的幻灯片。
例如要实现把app丢进垃圾桶的动态幻灯片，可以使用move动作效果，但是app会遮挡到垃圾桶。所以这里添加了垃圾桶前半部分图片，利用图片的纵深关系实现了最终的效果。
![纵深效果](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/keynote/%E7%BA%B5%E6%B7%B1%E6%95%88%E6%9E%9C.png)

<br>

------------
##Magic Move
如果上一页幻灯片和下一页幻灯片，同时有相同的元素存在，比如仅仅文字大小不同，或者图片摆放不同。在这种情况就可以采用神奇移动的效果。这个效果经常使用，会大大增强幻灯片的表现力。

下面有三张幻灯片，都有相同的元素。第一张内容文字杂乱无序，选中第一张幻灯片，动作效果选择`Magic Move`。

![magicmove1](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/keynote/magicmove1.png)

播放到下一页时，相同元素就会移动到指定的位置。

![magicmove2](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/keynote/magicmove2.png)

同理建立第三张幻灯片，把要呈现的元素复制到第三张的幻灯片中。选中第二张幻灯片，动作效果选择`Magic Move`。

![magicmove3](https://raw.githubusercontent.com/thddaniel/Myblog/master/image/keynote/magicmove3.png)

神奇移动时间设置不要太慢，通常大概0.7~0.8秒。



------

图片视频资源网站：

- [shutterstock](http://www.shutterstock.com)
- [dreamstime](http://www.dreamstime.com/)
- [istockphoto](http://www.shutterstock.com)
- [iconarchive](http://www.iconarchive.com)
- [iconfinder](https://www.iconfinder.com)
- [unsplash](https://unsplash.com/)人物、生活、自然类素材较多，素材尺寸大多在5k 像素。基本上每天更新一张。
- [Realistic Shots](http://realisticshots.com/)素材尺寸大多在2.5k 像素。
- [Free Nature Stock](http://freenaturestock.com/)主打自然类素材，素材尺寸大多在5k 像素。