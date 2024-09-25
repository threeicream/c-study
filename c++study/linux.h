/*
计算机组成：
硬件和软件
软件：操作系统等
操作系统：作为用户和计算机硬件的桥梁，调度和管理计算机硬件进行工作
调度CPU、内存、硬盘、网卡

Linux系统：
组成：Linux内核、系统级应用程序
Linux内核：调度cpu、内存等 最核心的功能
应用程序：文件管理器、人物管理器等

Linux发行版：提供了内核+系统应用程序的完整封装 例如Centos、ubuntu
虚拟机快照：相当于存档，避免损坏后无法回溯

Linux目录结构：树形结构，只有一个根目录/，层级关系使用/表示
命令行：即Linux终端（terminal）
命令：即Linux程序
基础格式：command [-options] [parameter]
command:命令本身
-options:[可选非必填]命令的一些选项可以通过选项控制命令的行为细节
parameter:[可选非必填]命令的参数，多数用于命令的指向目标等
命令基础：
ls [-a -l -h] [Linux路径]：列出目录下的内容，输入ls命令默认展示HOME目录（每个操作用户的个人账户目录）下的内容
-a:列出全部文件，包括隐藏文件
-l:以列表的形式展示内容
-h:以易于阅读的形式列出文件大小，如K、M、G （就是容量大小）
选项可以互相组合-la

cd [Linux路径]：更改当前所在的工作目录change directory
pwd：查看当前所在的工作目录 print work directory

相对路径和绝对路径：
绝对路径：cd /home/user/Desktop 以根目录为起点
相对路径：cd Desktop	以当前目录为起点
特殊路径符：
.:表示当前目录
..:表示上一级目录
~:表示HOME目录 cd ~/Desktop 切换到home目录下的Desktop文件

mkdir [-p] Linux路径：创建新的文件夹 make directory
-p：自动创建不存在的父目录

touch Linux路径：创建文件
cat：查看文件的内容
more：查看文件的内容，支持翻页,空格翻页，b上一页，q退出查看

cp [-r] 参数1 参数2：复制文件\文件夹 copy
-r：复制文件夹使用，表示递归
参数1：路径，被复制
参数2：路径，复制到
mv 参数1 参数2：移动文件\文件夹，也可以用来改名 move
rm [-4 -f] 参数1 参数2 参数n：删除文件、文件夹 remove
-r：删除文件夹
-f：force强制删除
参数1、参数n:表示要删除的文件或文件夹

通配符：*，即匹配任意内容（包括空），例如：
test*，表示匹配任何以test开头的内容
*test，表示匹配任何以test结尾的内容
* test*，表示匹配任何包含test的内容
su - root：进入root管理员
exit：退回普通用户


*/
