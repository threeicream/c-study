/*
��̬�滮��1.��ٷ�->2.���仯����/��֦->3.dp������ʽ
0/1��������
�����n����Ʒ������Ϊv�ı�����ÿ����Ʒֻ����һ�Σ���i����Ʒ�ļ�ֵΪvi�����Ϊwi����⽫��Щ��Ʒװ�뱳������ʹ��Щ��Ʒ��������������������������ܼ�ֵ����������ֵ��
�ⷨ��
1.���װ���µ�ǰ��Ʒ����ôǰn����Ʒ�������Ϻ�ǰn-1����Ʒ����������һ����
2.���װ���µ�ǰ��Ʒ
2.1װ��ǰ����Ʒ���ڸ���ǰ��ƷԤ������Ӧ�ռ������£�ǰn-1����Ʒ�������ϼ��ϵ�ǰ��Ʒ�ļ�ֵ�����ܼ�ֵ
2.2��װ��ǰ��Ʒ����ôǰn����Ʒ�������Ϻ�ǰn-1����Ʒ����������һ����
ѡȡ2.1��2.2�нϴ�ļ�ֵ����Ϊ��ǰ�����ϵļ�ֵ
��������
���֪����ֵ�����֪������װ����Щ��Ʒ
�ⷨ��
�ӱ������½ǿ�ʼ���ݣ��������ǰn����Ʒ�������ϵļ�ֵ��ǰn-1����Ʒ�����ϵļ�ֵһ����˵����n����Ʒû�б�װ��
���򣬵�n����Ʒ��װ��

�������⣺
��һ�����飬ѡ�����е����������Ľ��

�����㷨�û���
1.�ռ临�Ӷ�
2.ʱ�临�Ӷ�
�㷨Ӧ�ã�
1.���ң�2.����3.���㣻4.���ž���
����Ƶ�ʱ�临�Ӷȣ�
1.��������Ϊ1
2.ֻ����ʱ�亯���е���߽���
3.����߽�����ڣ���ʡȥ��߽���ǰ���ϵ��
O(1)<)(logn)<O(n)<O(n^2)
����Ƶ��ռ临�Ӷȣ�
1.�㷨�洢�ռ��С�̶����������ģ��ֱ�ӹ�ϵ��O(1)
void fun1(int n){int var = 3;}
2.�㷨����ռ���һ�����Լ��ϣ������飩�����Ҽ��ϴ�С�������ģn�����ȣ�O(n)
void fun2(int n){int[] array = new int[n];}
3.�㷨����ռ���һ����ά���鼯�ϣ����Ҽ��ϳ��ȿ��ȶ��������ģn�����ȣ�O(n^2)
void fun3(int n){ int[][] matrix = new int[n][n];}
3.����Ϊ�ݹ麯������Ȼû����ʽ�������������߼��ϣ����ǻ����ڴ�洢����������ջ������������ջ������ջ�ͽ�ջ������Ϊ
void fun4(int n){if(n<=1){return;} fun4(n-1);}
���ݹ����Ϊn��O(n)
ʱ����ռ��ȡ��
*/