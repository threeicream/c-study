#include <iostream>
#include <typeinfo>
#include<string>
#include<vector>
#include <initializer_list>
#include<stdexcept>
#include<cassert>//Ԥ�����  assert(x);xΪ�٣������Ϣ����ֹ��������
#include"test.h"


//#include "Sales_item.h"
/*
һ��
���>>Ҫ����<<std::endl�������֤buffer�������е����ݶ�������������
����
int a = 09;//�и�0���Զ���ɰ˽���
��ʼ����
int a=0;
int a={0}
int a{0}
int a(0)

������extern int i;//ʹ������Ϊ������֪
���壺extern int i=10;//���𴴽����ֹ�����ʵ��
�����Ҷ��壺int i;
���ã�int a=5; int &b=a;//b����a�ı���������ֻ�ܰ󶨱���
	int i = 10;
	int* p = &i;
	int*& a = p;
	*a = 4;
	std::cout << i;

 ::i��ȫ�ֱ��� ���������
 i�Ǿֲ����� �ڲ�������

 ��ָ�룺
 int *p=0��
 int *p=NULL��//nullptr
 NULL��nullptr����
 ���ͣ�NULL ��һ������������ͨ������Ϊ 0��nullptr ������Ϊ std::nullptr_t �ĳ�����
 ת����NULL ������ʽת��Ϊ�������ͣ�����ܵ��º�������ѡ������⡣nullptr ֻ����ʽת��Ϊָ�����ͣ��������������⡣
 ��ȫ�ԣ�ʹ�� nullptr ���Ӱ�ȫ����ȷ���������ں������غ�ģ�����С�

 void*���Ϳ��Դ���������ĵ�ַ

 const��ʼ����const�Ķ���һ��Ҫ��ʼ��,����ָ�룬����ûɶ����
 const int *const i=&a\\ָ��int���ͳ����ĳ���ָ��
 const int &r=1;\\�Ϸ�
 int &r=1;\\���Ϸ��������������ó���
 const int* p;\\�Ϸ�������pû��ֵ��û���κ�����
 
 constexpr
 ����const�����󣬳���ָ��			    ������ı� ��������ֵ��ָ�룺�����ǳ��������޸�ָ������ֵ�����ǲ������޸�ָ��ĵ�ַ��
 �ײ�const��ָ������ָ��,����         ����ı�   ����������ֵ��ָ�룺ͨ��ָ���������ָ�����������޸�ָ������ֵ�����ǿ����޸�ָ��ĵ�ַ��
 1.����	                            const=���� ���Ϸ������Ǳ���=const �Ϸ�
 2.ָ������ָ��or���ã�			    ����=const ���Ϸ�������const=���� �Ϸ�//����
	int i = 10;
	const int a = 5;
	i = a;//�Ϸ�
	a = i;//�Ƿ�
	int* p2;
	const int& p1 = i;//�Ϸ�
	p2 = &a;//�Ƿ�
	std::cout << p1;
 3.����ָ�룺�����޺ζ����ܸı䣬һ������Ҫ��ʼ�� ����ָ��ֻ��=����������=const
	int * const p1=NULL;
	constexpr const int *p2=NULL;
	constexpr int *p3=NULL;
 2��3������
 ָ������ָ��
 ָ������ָ����һ��ָ�������ݵ�ָ�룬����ζ��ͨ�����ָ�벻���޸�����ָ���ֵ��
 ����ָ��
 ����ָ����ָ�뱾���ǳ���������ζ��һ��ָ���ʼ���󣬲��ܸı�����ָ�򣬵�����ͨ��ָ���޸�����ָ������ݡ�

 const char*p="love";//right
 char*p="love";//erro
 cout<<p;//���love
 cout<<*p;//���l

 const constexpr ����
 ����ʱ��:
 const ������ʱ���㡣
 constexpr �ڱ���ʱ���㡣
 ʹ�÷�Χ:
 const ���������κ���Ҫ���ɱ�ֵ�ĵط�����ֵ����������ʱ���㡣
 constexpr ������Ҫ�ڱ���ʱȷ��ֵ�ĵط����������С��ģ������ȡ�
 ����:
 const ��������������ʱ��ʼ����Ҳ����ͨ�����ӵı��ʽ����ֵ��
 constexpr ���������ڱ���ʱ��ʼ�������ʽ�е�����ֵ�Ͳ����������Ǳ���ʱ������

 size_t
 ���壺size_t �Ǳ�׼���е�һ�����Ͷ��壬ͨ�����ڱ�ʾ����Ĵ�С����������������� <cstddef> ͷ�ļ��ж��塣
 ��;��size_t ���㷺���ڱ�׼�⺯������ malloc��sizeof �ȣ���ʾ�ڴ��С���������������������޷������ͣ�����ȷ��������ָ�ֵ��
 ��׼���壺size_t �Ķ���������ƽ̨����ͨ��������Ϊ�޷����������ͣ��ܹ���ʾ�����ܵ��ڴ��С��
 size_type
 ���壺size_type �� C++ ��׼���������� std::vector��std::string �ȣ��е�һ�����Ͷ��塣ÿ�����������Լ��� size_type��
 ��;��size_type ��Ҫ���ڱ�ʾ�����Ĵ�С�����������ڲ�ͬ���������в�ͬ��ʵ�֣�size_type �ṩ��һ��������ʵ���޹صķ�ʽ����ʾ��С��������
 ������أ�size_type �������������ص����Ͷ��塣���磬std::vector<int>::size_type �� std::vector<int> �Ĵ�С���͡�std::vector<int>::size_type i = 0��������
 iterator:��������ר�����ͣ�ÿ�����������Լ���iterator

 ���ͱ�����
 typedef double wage;
 typedef wage base,*p;
 using SI=Sales_item;
 typedef int arr[10];//�������Ч
 using arr = int[10];

 typedef char *pstring;
 const pstring cstr = 0;              //ʹ�ñ���ʱ��������һ�������ǳ�����ָ�루const����pstring������壩
 const char *cstr1 = 0;               //ֱ���滻ʱ��������һ��ָ������ָ�루const����char��

 auto���ͣ�������ͨ����ʼֵ�ж����ͣ����Ա�����г�ʼֵ
 auto���Զ��㣬�����ײ�
 �Գ�������ȡ��ַ��һ�ֵײ�const

 decltype()����������ʵ�ʼ�����ʽ��ֵ//������������������
 ��������
 ���ڱ��ʽ�����߶��������ȫ����Ϊint &���ͣ������ò����ı���Ҳ��Ϊint &����
 typeid(p).name()

 string s1
 string s2(s1)
 string s2=s1
 string s3(n,"c")
 string s1 = "fuck you baby";
 s1.empty();
 s1.length(); s1.size();//�ַ�����
 s1.find("baby");
 s1.replace(6, 3, "me");
 s1.erase(6, 2);//ɾ��
 s1.insert(4,"you")��//����
 getline(cin,s);//����һ�У�ֻ���յ����з��˲ŷ���

 string+����ֵ������string������ǰ��
 string s4=s+",";
 	isalnum(c);
	isalpha(c);
	iscntrl(c);
	isdigit(c);
	isgraph(c);
	islower(c);
	isprint(c);
	ispunct(c);
	isspace(c);
	isupper(c);
	isxdigit(c);
	tolower(c);
	toupper(c);
	����ַ���s1��ÿһ���ַ�
	for (auto b : s1)
		cout << b << endl;

 vector(��������ģ��),��С���̶������������
 vector<int>a;//�б�ӵ�ж��Ԫ�أ����Ƕ�̬����
 vector<int>a(10,1);//����ʮ��Ԫ�أ�ֵ��Ϊ1
 vector<int>a{10,1};//��������Ԫ�أ��ֱ�Ϊ10��1
 v1.push_back(1);//β�˲���1��Ԫ�أ�ֵΪ1

 ����������ָ��Ƚ���(ָ��Ҳ�ǵ�����)
 vector<int>v;
 v.begin()Ԫ��/�ַ���λ ����()
 v.end()Ԫ��/�ַ�ĩλ ����
 const vector<int>cv;
 cv.cbeign()	����
 cv.cend() ����
 auto i=v.begin()
 (*i).empty()==i->empty()
 *(v.begin())����v��һ��Ԫ�ص�ֵ

 ���飺���ڵ����˳�����Ķ���⺬��
 ָ�룺����ʹ��begin()��end()���������������Ԫ�غ�βԪ��
 �����ʼ��vector��
 int a[]={1,2,3,4};
 vector<int>x={begin(a),end(b)};//1 2 3 4
 vector<int>x = { a + 1,a + 4 };//2 3 4
 c++����˵û�ж�ά���飬��ά����������������
 forѭ�����ƶ�ά���飬�����ڲ�ѭ��������ѭ���Ŀ��Ʊ�����������&��������
 int it[3][4];
 for (auto p = it; p != it + 3; p++)
		for (auto q = *p; q != *p+4; q++)
			cout << *q << ' ';

 ��λ��������������ɣ����������ҽ����
 �����������ȼ����ڶ���

 ��ʾת������һ�㲻�Ƽ���
 1.static_cast:ǿ��ת�����˵ײ�const���������(�е㼦�ߣ�ָ�뷽��ֻ�����void)�����������֮���ת�������������֮�䣨�� int �� float�������νṹ�л����������֮���ת�����Լ� void ָ�����������ָ��֮���ת����
 int a = 1;
 void* c = &a;
 double* b = static_cast<double*>(c);
 2.const_cast:��Ҫ�����Ƴ�����ӵײ�const�ԣ�ת��Ϊ�������Ͳ���
 const char* a;
 char* b = const_cast<char*>(a);//right
 string* b = const_cast<string*>(a);//erro�����ܽ�char*ת��Ϊstring*
 3.reinterpret_cast:�����ڼ�����������֮�����ת����ͨ��������ָ������֮���ת��������ת��������ؽ��еģ�û���κ���ʽ�ļ��ͱ�֤��
 int*a;
 char*b=reinterpret_cast<char*>(a);

 cin.get(a);//������������������
 ��Χforѭ��
 for(auto b:v)//����v�е�����Ԫ��

 try������ʹ��
 while(cin >> a >> b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("��������Ϊ0");//���������쳣�����������κ����͵��쳣�����������ַ������Զ����쳣��ȣ���һ��ִ�е� throw ��䣬try ����ʣ��Ĵ��뽫����ִ�С�
			cout << a / b << endl;
		}
		catch (runtime_error &e)//���ڲ�׽�ʹ����쳣��
		{
			cerr << e.what() << "��Ҫ������" << endl;//e.what()��������������Ϊ0��
			char ch;
			cin >> ch;
			if (ch != 'y' && ch != 'Y')
				break;
		}
		catch (...)
		{
			cerr << "unknown exception" << endl;
		}
	}
 
 ����ѭ��
 ֵ���ݣ���ͳ��ʽ
 ���ô��ݣ�1.���⿽���������2.ֱ�Ӳ���ʵ��3.���������βδӶ����������ֵ(һ�����������ͻ��������ͣ���string�������⿽���������)

 ������Ϊ�βΣ����ߵȼۣ��Ҷ��ǽ�����ת����ָ������
 void print(const int*)
 void print(const int[])
 void print(const int[10])//����������ʹ�ô�С�����Դ󣬲���С
 ���鲻��ֱ�ӱ��������أ��������ػط�ʽ��
 1.ֱ������ funct
 2.����
 3.β�÷���
 4.decltype

 int a[10];//a��һ������10������������
 int*p1[10];//p1��һ������10������ָ�������
 int(*p2)[10]=&a;//p2��һ��ָ����10�����������ָ��

 ���пɱ��βεĺ�����
 initializer_lists<int>x;//��vector�Ƚ��񣬵���iniֻ��ֻ������ӦԪ���ǳ���

 �������أ�
 ͬһ�����ĺ�������һ���Ĺ���
 ����const�޷����ֺ���
 �β����������β����Ͳ�ͬ�������ֳ���

 Ĭ��ʵ��Ӧ�÷���ͷ�ļ��У����ұ���ʹ��ȫ�ֱ���
 ĳ���βα�������Ĭ��ʵ�Σ���������������βζ�������Ĭ��ʵ�Ρ�
 (a) int ff(int a, int b = 0, int c = 0);//right
 (b) char *init(int ht = 24, int wd, char bckgrnd);//error
 �����޸�һ���Ѿ��趨�õ�Ĭ��ֵ

 constexpr������inlink������������ͷ�ļ��ж���
 constexpr��1.ֻ��һ��return���2.����ֵ�����ǳ������ʽ

 ����ָ�룺��������Ϊ�βξ���ָ�����ͣ�
 1����������һ������int func(int, int)�����庯��ָ��ķ�������
 int (*func_ptr)(int, int);
 2��������ַ��ֵ������ָ��
 func_ptr = &func; // ����ֱ�� func_ptr = func;
 3ʹ�ú���ָ����ú���
 int result = func_ptr(2, 3);
 
 ����ָ���β�
 1������ܺ���ָ����Ϊ�����ĺ���
 void callFunction(int (*func)(int, int), int a, int b) 
 {
	int result = func(a, b);
	std::cout << "Result: " << result << std::endl;
 }
 2���ô��к���ָ���βεĺ���
 int add(int a, int b) 
 {
	return a + b;
 }

int main() 
{
	callFunction(add, 5, 3);
	return 0;
 }
 ����(ָ�������)�ͺ���ָ�붼����ֱ�ӷ��أ�ֻ���ػ�
 1.����
   using PF=int(*)(int*);//PFΪ����ָ������
   using F=int(int*);//FΪ��������
   PF f1(int);��ЧΪF *f2(int);
 2.ֱ������
   int(*f1(int))(int*);
 3.β�÷���
   auto f1(int)->int (*)(int*);
 4.decltype
   int xyz(int*);
   decltype(xyz) *f1(int);
 ���巵�غ���ָ��ĺ���
 int (*getFunction(char op))(int, int) 
 {
	int add(int a, int b) { return a + b; }
	int subtract(int a, int b) { return a - b; }

	if (op == '+') {
		return add;
	} else if (op == '-') {
		return subtract;
	} else {
		return nullptr;
	}
 }
 ���÷��غ���ָ��ĺ���
 int main() {
	char op = '+';
	int (*func_ptr)(int, int) = getFunction(op);

	if (func_ptr != nullptr) {
		int result = func_ptr(10, 5);
		std::cout << "Result: " << result << std::endl;
	} else {
		std::cout << "Invalid operation" << std::endl;
	}

	return 0;
}

�ࣺ�ؼ��� public private protected
class��Աһ��Ĭ��˽��
struct��Աһ��Ĭ�Ϲ���
ͨ�ù�����
��Ա����private����Ա����public
�ඨ���ⲿ:
class xyz{int area();};
int xyz::area(){return w;}:

thisָ�루��ʽִ�У���
int area(){return w;};     r1.area();
int area(xyz *this){return (this->w)};    r1.area(&r1);
ע�����
1.thisΪϵͳ���ɣ������Լ�����
2.�����ڳ�Աִ���ڲ�ʹ�ã�member function��
3.thisָ��ָ���ܸı䣬Ϊconst pointer���ͣ�����const��
 
 ������Ա������
 string isbn() const { return bookno; }//����д����ʾ���� isbn ������һ�� ������Ա�������������޸�����κγ�Ա������
 ��������
 1������Ա�������ڳ�����Ա�����У������޸���ĳ�Ա�������������Է�ֹ�����иı�����״̬����ߴ���İ�ȫ�ԺͿɿ��ԡ�
 2������������ã�ֻ�г�����Ա�������ܱ����������� const ���εĶ��󣩵��á�
 class Book {
public:
	string isbn() const { return bookno; } // ������Ա����
private:
	string bookno;
};

int main() {
	const Book myBook;  // ��������
	cout << myBook.isbn() << endl;  // �Ϸ������ó�����Ա����
	// myBook.setBookno("12345");  // �Ƿ������������ܵ��÷ǳ�����Ա����
	return 0;
}
*/

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::initializer_list;
typedef string::size_type sz;

//��дð������

int main()
{
	using namespace std;
	
	return 0;
}
