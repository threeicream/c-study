/*
sql初步学习：
数据库管理系统(DBMS):
前端→(双向)DBMS→数据库

关联式数据库 mysql等
非关联式数据库 redis等

关联式数据库储存数据原理：
将数据存储在tables中，通过key（索引）识别数据和将tables互相链接
primary key（主键）：可以唯一区分每份数据的属性（一个表可以有多个主键，一同区分唯一数据）
foreign key（外键）：对应到另外一张表的primary key，或者自己表的primary key
同一个属性可以同时设定为主键和外键

相关类型：
int 整数
decimal(3,2) 浮点数 2.33
vachar(n) 字符串（最多存放n个字符）
bolb 图片 影片 档案
date 日期 2021-08-08
timestamp 记录时间 2021-08-08 12:12:59

基础指令：
create database `sql_tutorial`;//创建数据库
show databases;//展示所有数据库
drop database `sql_tutorial`;//删除数据库
use `sql_tutorial`;//使用该数据库

create table `student`(//创建表格
	`student_id` int primary key auto_increment,//递增
	`name` varchar(20) not null,//该数据不能为空
	`major` varchar(20) unique//该数据不能重复
						default '历史'//预设数据
);

describe `student`;//显示表格属性内容
alter table `student` add gpa decimal(3,2);//添加表格属性
alter table `student` drop column `gpa`;//移除表格属性

select * from `student`;//显示表格所有数据
select `name` from `student` order by `score`,`student_id` desc;//显示name这一列的所有数据，并按照成绩进行排序（默认升序）desc是降序
select * from `student` limit 3;//只传前三个数据
drop table `student`;//删除表格

insert into `student` values(1,'小白','历史');//添加表格数据
insert into `student`(`name`,`major`,`student_id`) values('小白','历史',1);//添加表格数据

set sql_safe_updates=0;//设置安全模式0
update `student`
set `major` = '历史文学'
where `student_id`=3 or/and `major`='物理';//将表格中满足要求科目修改为历史文学
where `student_id` in(1,2,3);//相当于多个or，满足一个就符合条件

delete from `student`
where `student_id`=3;//删除 <>是不等于
*/
