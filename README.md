# 📘 数据结构与算法仓库 / Data Structure & Algorithm Repository

---

## 🇨🇳 中文版

GitHub账号实际上早在几年前就有了，但当时的我对这计算机领域一窍不通，对于GitHub的理解也只是道听途说，不过我的确隐隐约约觉得Git以及GitHub在IT领域有着举足轻重的地位💡，我想，正是我这样的观念，在冥冥之中决定了我终有一天会在GitHub开源第一个项目🚀。  

没错，就是今天，就是你所看到的这个项目✨。说是项目，倒不如说就是一个仓库📦，这里面放的都是一些关于数据结构与算法的内容，下面我将对仓库中的内容做一个简要的介绍——  

---

### 第一️ 
这里并没有线性表、栈和队列这样结构的实现，不是因为这些不重要，而是这三个数据结构是入门基础，它们三个的实现思想以及运用已经融入到其他算法的实现当中，所以，想要看懂这些算法的实现，还是有一些门槛，我想多多少少要花一些时间⌛。  

---

### 第二️
与 `.git` 同文件路径下的 `.cpp` 文件主要是列举了一些基础的乃至世界著名的算法📘，比如 `Dijkstra.cpp`、`KMP.cpp` 等这些算法都出自大师之手。而 `Radix_sorting.cpp`、`Boeing_minus_tree` 这些算法对于我这样的小白，在初次学习时的启发性就比较大🌱，所以也就放在了这里。  

---

### 第三️ 
为什么有 Turing 的论文？🤔  
简单的来说这是一种致敬🙏，其次这可能略带一点我自己的个性——关于什么是算法的理解，有人可能会用抽象的数理逻辑语言再加上一堆符号化的公式来解释什么是算法，“数学家”都这么干📐。  

我当然不否认这种理解，这种理解的确很精确很有必要，但这种理解对于我这种小白来说真的是太难入门了，而且我并不认为这种理解是基于当今计算机科学的视角🧠，这明显是一种数学视角以便于量化算法进行分析。  

我比较喜欢简洁的，所以我比较认同的是清华大学邓俊辉教授给出的解释📖：  
**算法，是基于特定的计算模型，旨在解决某一信息处理问题而设计的一个指令序列。**  

这里的计算模型正是大名鼎鼎的图灵机模型🤖，当然还有 RAM（随机存储模型）不过这都是后话了。  

---

### 第四️
关于算法的实现语言，在这里我用的都是 **C++** 💻。在 `Data Structure by  Yan_Weimin` 文件里，是我自己实现的清华大学严蔚敏教授书上写的算法。由于技术熟练度有限，并没使用 C++ 面向对象的思想，以及模板库和算法竞赛里常用的库函数，更多的是一种介于 C 和 C++ 之间的语法方式🧩，结构化地实现了这些算法（这实际上已经满足了研究生考试的要求🎓）。  

相比之下，邓俊辉教授的 Dsacpp Tsinghua University by Deng_Junhui 实现就比我写的专业得多📚，细心的你一定也能发现。这也是我还需努力学习的方向💪。  

---

以上就是这个仓库的简单介绍📜。  

本仓库我在本地已进行 Git 管理（这里插一句——Linus Benedict Torvalds 花十天开发 Git，我花十天才学会 Git 🤦，这就是差距）。  

往后随着技术水平的提升，我极有可能修改或添加仓库里的内容🛠️，同时我也很希望有技术水平的你，会给到我一些指点💬，这并不限于算法学习，有关计算机科学学习的一切经验都可以给我留言讨论🧠。  

如有大佬想修改我的仓库，欢迎进行 **Fork** 🤝。  

---

## 🇺🇸 English Version

My GitHub account has actually existed for several years, but back then I knew nothing about the field of computer science 🤓. My understanding of GitHub was merely hearsay. Still, I somehow felt that Git and GitHub hold an essential position in the IT world 🌍 — and I believe it was that intuition that destined me to one day open-source my first project here on GitHub 🚀.  

Yes — today is that day! 🎉  
This project (or more precisely, this repository 📦) contains various notes and code examples about **data structures and algorithms**. Below is a brief introduction:  

---

### 1️⃣  
There are no implementations of basic structures like **lists**, **stacks**, or **queues** — not because they are unimportant, but because these fundamental concepts have already been deeply embedded in other algorithmic implementations 🧠. To understand these algorithms, you might still need to invest a bit of time ⏳.  

---

### 2️⃣  
The `.cpp` files under the same directory as `.git` mainly demonstrate both foundational and world-famous algorithms 📘 — for example, `Dijkstra.cpp` and `KMP.cpp`, which come from the masters themselves.  
Meanwhile, `Radix_sorting.cpp` and `Boeing_minus_tree` were particularly enlightening 🌱 to me as a beginner, so I included them here as well.  

---

### 3️⃣  
Why include **Turing’s paper**? 🤔  
Simply put, it’s both a **tribute** 🙏 and an expression of my personal perspective.  

Some people explain algorithms using abstract mathematical logic and formal notation — as mathematicians often do 📐. While I respect that rigorous viewpoint, it’s admittedly difficult for beginners like me and doesn’t always reflect the **computational** perspective of modern computer science 💻.  

I prefer the concise definition by **Professor Deng Junhui** from Tsinghua University 📖:  
> “An algorithm is a sequence of instructions designed to solve an information-processing problem under a specific computational model.”  

The model here is none other than the famous **Turing Machine 🤖**, or sometimes the **RAM model** — but that’s another story.  

---

### 4️⃣  
All implementations are written in **C++** 💻.
 In the `Data Structure` folder, I recreated algorithms from **Professor Yan Weimin’s** textbook. Since my technical proficiency is still developing, I didn’t use advanced C++ features like templates, OOP, or STL algorithms. Instead, my code sits somewhere between C and C++ syntax 🧩 — enough for graduate-level understanding 🎓.

In contrast, the file `Dsacpp Tsinghua University by Deng_Junhui` is much more professional 📚 than what I wrote — and careful readers will surely notice that. This is also the direction I need to keep improving 💪.

---

That’s the brief introduction to this repository 📜.  

It’s already under Git version control locally (fun fact: Linus Torvalds wrote Git in 10 days, while it took me 10 days just to learn it 🤦 — that’s the gap).  

As my skills grow, I’ll likely update or expand the contents 🛠️.  
I also welcome any advice or discussions 💬 — not only about algorithms but about computer science in general 🧠.  

If you’d like to modify or contribute, feel free to **Fork** 🤝.  

---

⭐ **感谢阅读 / Thanks for reading!**  
如果喜欢这个仓库，别忘了点个 Star 支持我吧～✨/ If you like this repository, don’t forget to give it a ⭐ star to support me! ✨