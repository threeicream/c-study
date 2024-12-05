/*
sql����ѧϰ��
���ݿ����ϵͳ(DBMS):
ǰ�ˡ�(˫��)DBMS�����ݿ�

����ʽ���ݿ� mysql��
�ǹ���ʽ���ݿ� redis��

����ʽ���ݿⴢ������ԭ��
�����ݴ洢��tables�У�ͨ��key��������ʶ�����ݺͽ�tables��������
primary key��������������Ψһ����ÿ�����ݵ����ԣ�һ��������ж��������һͬ����Ψһ���ݣ�
foreign key�����������Ӧ������һ�ű��primary key�������Լ����primary key
ͬһ�����Կ���ͬʱ�趨Ϊ���������

������ͣ�
int ����
decimal(3,2) ������ 2.33
vachar(n) �ַ����������n���ַ���
bolb ͼƬ ӰƬ ����
date ���� 2021-08-08
timestamp ��¼ʱ�� 2021-08-08 12:12:59

����ָ�
create database `sql_tutorial`;//�������ݿ�
show databases;//չʾ�������ݿ�
drop database `sql_tutorial`;//ɾ�����ݿ�
use `sql_tutorial`;//ʹ�ø����ݿ�

create table `student`(//�������
	`student_id` int primary key auto_increment,//����
	`name` varchar(20) not null,//�����ݲ���Ϊ��
	`major` varchar(20) unique//�����ݲ����ظ�
						default '��ʷ'//Ԥ������
);

describe `student`;//��ʾ�����������
alter table `student` add gpa decimal(3,2);//��ӱ������
alter table `student` drop column `gpa`;//�Ƴ��������

select * from `student`;//��ʾ�����������
select `name` from `student` order by `score`,`student_id` desc;//��ʾname��һ�е��������ݣ������ճɼ���������Ĭ������desc�ǽ���
select * from `student` limit 3;//ֻ��ǰ��������
select distinct sex from `employee`;//�����ظ�����
drop table `student`;//ɾ�����

insert into `student` values(1,'С��','��ʷ');//��ӱ������
insert into `student`(`name`,`major`,`student_id`) values('С��','��ʷ',1);//��ӱ������

set sql_safe_updates=0;//���ð�ȫģʽ0
update `student`
set `major` = '��ʷ��ѧ'
where `student_id`=3 or/and `major`='����';//�����������Ҫ���Ŀ�޸�Ϊ��ʷ��ѧ
where `student_id` in(1,2,3);//�൱�ڶ��or������һ���ͷ�������

delete from `student`
where `student_id`=3;//ɾ�� <>�ǲ�����

-- �������
ALTER TABLE `Employee`
add foreign key(`branch_id`)
references `branch`(`branch_id`)
on delete set null;

�ۺϺ�����
select count(*) from `employee`;//ȡ����������
select avg(`salary`) from `employee` ;//ȡ��ƽ��ֵ
select sum(`salary`) from `employee` ;//ȡ���ܺ�
select max(`salary`) from `employee` ;//ȡ�����ֵ
select min(`salary`) from `employee` ;//ȡ����Сֵ

ͨ�����% �������ַ��� _ ����һ���ַ�
select * from `client` where `phone` like '%335';ȡ��β��Ϊ335������
select * from `employee` where `birth_date` like '_____10%';

����union��
select `name` as `Name` from `employee`
union
select `client_name` from `client`;//������ָ��Ľ���ϲ���һ���������ͱ���һ�� as���Ǹı���������
*/
