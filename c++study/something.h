/*
C++ �� C �����ֹ㷺ʹ�õı�����ԣ������ڶ����������������

### 1. **��������� (OOP)**
- **C++**: ֧����������̡�����������Ͷ���ĸ�����Է�װ���ݺͺ�������֧�ּ̳кͶ�̬��
- **C**: ��������̵ı�����ԣ���֧����Ͷ���ĸ��

### 2. **�����ͷ���**
- **C++**: �������������һ���֣���Ϊ��������C++ ֧�ֺ������غ���������ء�
- **C**: ���еĺ�������ȫ�ֵģ���֧�ֺ������غ���������ء�

### 3. **��׼��**
- **C++**: ӵ�зḻ�ı�׼ģ��� (STL)�����������ࡢ�㷨�͵�������
- **C**: ��׼����Լ򵥣���Ҫ��������/����������ַ����������ڴ����Ȼ������ܡ�

### 4. **�ڴ����**
- **C++**: ���˴�ͳ�� C �����ڴ����`malloc` �� `free`������֧���µĺ�ɾ����������`new` �� `delete`������������ RAII����Դ��ȡ����ʼ�����ȸ߼����������ڴ����
- **C**: ��Ҫ�����ֶ������ڴ棬ʹ�� `malloc` �� `free` ������

### 5. **ģ��**
- **C++**: ֧��ģ���̣������д���ʹ��룬���Դ���ͨ�õ����ݽṹ���㷨��
- **C**: ��֧��ģ���̡�

### 6. **�쳣����**
- **C++**: ֧���쳣������ƣ�ʹ�� `try`��`catch` �� `throw` �ؼ��֡�
- **C**: ��֧���쳣������ƣ�������ͨ��ͨ������ֵ��ȫ�ֱ������� `errno`����ʵ�֡�

### 7. **�����ռ�**
- **C++**: �����������ռ䣨`namespace`���Ա���������ͻ��
- **C**: û�������ռ�ĸ��������ͻ��һ�����������⡣

### 8. **������֧��**
- **C++**: �ִ����������� g++, clang++��֧�� C++ ���������ԣ����������¡�
- **C**: ��ͳ���������� gcc��clang��֧�� C ���������ԣ�������ȶ���

### 9. **ʹ������**
- **C++**: �㷺Ӧ����ϵͳ�������Ϸ������ʵʱϵͳ��������Ŀ����Ҫ�����ܺ͸����Ե�����
- **C**: ��Ҫ����ϵͳ��̣������ϵͳ��Ƕ��ʽϵͳ�����ײ��̺�����Ҫ�󼫸ߵ�����

### 10. **������**
- **C++**: �������� C �ĳ������������� C ���򶼿����� C++ �������±������У�����֮��������
- **C**: ��֧�� C++ ���ԣ���� C++ ���벻��ֱ���� C �������±��롣

ͨ����Щ������Կ�����C++ �ṩ�˸���ĸ߼����Ժͱ�̹��ߣ�ʹ�ñ�д����Ӧ�ó�����ӷ��㣬�� C ������򵥺͸�Ч���㷺Ӧ���ڵײ�ϵͳ�����ܹؼ��ĳ�����





��������� (OOP) ��������̱�� (POP) �����ֲ�ͬ�ı�̷�ʽ���������ص�����ó�������������ǽ�����ϸ���ͣ�

### ������̱�� (Procedural Programming)
������̱����һ���Թ��̣����������ӳ���Ϊ���ĵı�̷�ʽ����Ҫ��ע���ǽ������Ĳ�����߼���

#### ��Ҫ�ص㣺
1. **ģ�黯**��������ֽ�����ɸ�������ÿ����������ض�������
2. **��������**��ͨ�����ú�����ִ���ض������񣬺������Ի�����á�
3. **˳��ִ��**�������մ����˳����ִ�С�
4. **ȫ������**�����ݿ����ں���֮�乲��ͨ��ͨ��ȫ�ֱ�����
5. **������**��ͨ�������ĸ��ã���ߴ���������ԡ�

#### �ŵ㣺
- ��ֱ�ӣ���������ʵ�֡�
- ����С�͡��򵥵ĳ���ǳ���Ч��
- ִ��Ч�ʸߣ��ڴ�ռ���١�

#### ȱ�㣺
- ���ų����ģ�����󣬴���ά����ø��ӡ�
- ���ݺͺ���֮��Ĺ�ϵ��Ϊ��ɢ�����Խ������ݱ��������ء�
- ȱ������ͷ�װ������Ӧ�Ը��ӵ�Ӧ�ó�����

### ��������� (Object-Oriented Programming)
�����������һ���Զ���Ϊ���ĵı�̷�ʽ����Ҫ��ע�������ݼ�����������ķ�װ�ͳ���

#### ��Ҫ�ص㣺
1. **����**�������ݺͲ�����Щ���ݵķ�����װ��һ�𣬳�Ϊ����
2. **��**�������ģ�����ͼ��ͨ������Դ������������ͬ���Ժ���Ϊ�Ķ���
3. **��װ**��ͨ�������ݺͷ�����װ�ڶ����ڲ���ʵ����Ϣ���ء�
4. **�̳�**������̳и�������Ժͷ��������������Ըߡ�
5. **��̬**��ͨ���ӿڻ�̳У�ʵ�ֲ�ͬ�����ͬһ�����Ĳ�ͬʵ�֡�
6. **����**��ͨ��������ͽӿڣ���������ͨ����Ϊ��

#### �ŵ㣺
- ��ߴ���Ŀ�ά���ԺͿ���չ�ԡ�
- ͨ����װʵ����Ϣ���أ���ߴ���İ�ȫ�ԡ�
- ͨ���̳кͶ�̬ʵ�ִ�������ú�����ԡ�
- ������ʵ�ָ��ӵ�Ӧ�ó����ʹ�����Ŀ��

#### ȱ�㣺
- ��ѧ��ѧϰ���߽϶��ͣ�����ʵ�ָ��ӡ�
- ����ִ��Ч�ʿ��ܵ���������̱�̡�
- ��Ҫ������ڴ�ʹ���������

### �ܽ�
- **������̱��**��������С�͡��򵥵ĳ���ǿ�����̺ͺ�������ע�������Ĳ��衣
- **���������**�������ڴ��͡����ӵĳ���ǿ��������࣬��ע���ݺͲ��������ķ�װ�ͳ���

�����ֱ�̷�ʽ���������ó����������߿��Ը��ݾ�������ѡ����ʵı�̷�����

int main()//��Զ�ȡ�е�һ�ַ�������һ�ַ�����ʹ��istringstream L(s)�����ַ���������ʹ��while(L>>word)��ȡ����
{
	using namespace std;
	vector<string>v1 ;
	string s;
	while (getline(cin, s))
		v1.push_back(s);
	for (auto it = v1.begin(); it != v1.end() && !it->empty(); it++)
	{
		for (auto it2 = it->begin(); it2 != it->end(); it2++)
			*it2 = toupper(*it2);
	}
	for (auto a : v1)
		cout << a << endl;

	return 0;
}
//���У�v1.begin() ���ص���һ��ָ�� vector<string> �е�һ�� string Ԫ�صĵ��������� it->begin() ���ص���һ��ָ�� string �е�һ���ַ��ĵ�������
����Ĵ����У�it ��һ�� vector<string>::iterator����� it->begin() ��һ�� string::iterator��
�����������������ͺ�������ȫ��ͬ�����Բ��ܽ� v1.begin() ֱ���滻Ϊ it->begin()��

{
int it[3][4];
	size_t cnt = 0;
	for(auto &row:it)
		for (auto& col : row)
		{
			col = cnt;
			cnt++;
		}
	/*for (int(&a)[4] : it)
		for (int b : a)
			cout << b << ' ';*/

	/*for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 4; j++)
			cout << it[i][j] << ' ';*/

	//for (int_arry* p = begin(it); p != end(it); p++)
		//for (int* q = begin(*p); q != end(*p); q++)
			//cout << *q << ' ';

	/*for (auto p = it; p != it + 3; p++)
		for (auto q = *p; q != *p+4; q++)
			cout << *q << ' ';*/
//}
/*
 __func__
 __FILE__
 __TIME__
 __DATE__
 NDEBUG ��һ��Ԥ����꣬���ڿ��� C++ �еĶ��ԣ�assertions����
 �������� NDEBUG ʱ�����е� assert ����ö��ᱻ���ԣ������Իᱻ���á�
 ��ͨ���ڷ�����release���汾��ʹ�ã�����߳��������Ч�ʣ���Ϊ�ڷ����汾�в���Ҫ���ж��Լ�顣
*/



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
 ����const�����󣬳���ָ��			    ������ı� ��������ֵ��ָ�룺�����ǳ��������޸�ָ������ֵ�����ǲ������޸�ָ��ĵ�ַ�����������ǳ����������޸ġ���ζ��ָ��/��������һ������
 �ײ�const��ָ������ָ��,����         ����ı�   ����������ֵ��ָ�룺ͨ��ָ���������ָ�����������޸�ָ������ֵ�����ǿ����޸�ָ��ĵ�ַ��ָ���������ָ��Ķ����ǳ���������ͨ��ָ��������޸Ķ���
 1.����	                            const=���� ���Ϸ������Ǳ���=const �Ϸ�        ���ԣ���Ҫ���
 2.ָ������ָ��or���ã�			    ����=const ���Ϸ�������const=���� �Ϸ�//����  ���ԣ���Ҫ���
	int i = 10;
	const int a = 5;//���ǳ�ʼ��
	i = a;//�Ϸ������ǿ�����ֵ
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
 // ����һ����������
typedef int (PTypeFun1)(int, int);

// ����һ������ָ������
typedef int (*PTypeFun2)(int, int);


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
��װ���̳С���̬������������ԣ��������ȿ����װ�ĺ��塣
��װ��ָ������ĳ�Ա����������ʵ�������ͨ�������ʵ��ϸ������Ϊprivate�����Ǿ��������ķ�װ����װʵ������Ľӿں�ʵ�ֵķ��롣
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

 ���캯����
 1.Ĭ�Ϲ��캯������û���ṩ���캯��ʱ�����������Զ�����һ��Ĭ�Ϲ��캯����Ĭ�Ϲ��캯���������Ǵ���һ�����󣬲�������ĳ�Ա������ʼ��ΪĬ��ֵ��
 2.�в����Ĺ��캯�����в����Ĺ��캯���������Ǵ���һ�����󣬲�������ĳ�Ա������ʼ��Ϊ�ṩ�Ĳ���ֵ��
 3.�������캯�����������캯���������Ǵ���һ�����󲢽����ĳ�Ա������ʼ��Ϊһ���Ѵ��ڶ���ĳ�Ա������ֵ��
 ������const��������constexpr��û��return
 ���ڵ��ⲿ���幹�캯����
 Person1::Person1(istream &is)
 {
	read(is, *this);//����Person���е�read��������is�ж�ȡ���ݵ�*this
 }

 const screen& display(ostream& os) const { do_display(os); return *this; }
 1.��һ�� const������ֵǰ�� const����
 ��� const ���η���ֵ���� screen&������ʾ���ص� screen ������һ���������á�����ζ�ţ�
 ���صĶ����ܱ��޸�
 ͨ���������ֵֻ�ܵ��� const ��Ա����
 �Ᵽ֤�˺������ú���ͨ�����ص��������޸Ķ����״̬��
 2.�ڶ��� const�����������б��� const����
 ��� const ����������Ա����������ʾ����һ��������Ա����������ζ�ţ�
 �ú��������޸ĵ������Ķ�����κη� mutable ��Ա����
 �ú���ֻ�ܵ��������� const ��Ա����
 �ú������Ա� const �������
 �Ᵽ֤�˺�������ı�����״̬�������˴���İ�ȫ�ԺͿɶ��ԡ�
 ������ const �����ʹ�ã�
 �������Ա� const screen �������
 ���������޸ĵ������� screen ����
 ��������һ�������޸ĵ� screen ����

 ��Ԫ������friend istream& read(istream& is, Person& item);//read�������Ե���Person���item��Ա
 ���ͳ�Ա��using pos=std::string::size_type;
 Person���ͳ�Ա������Person(const string &n, const string &a) :Name(n), Address(a) {}//��ʵҲ�ǹ��캯������ʼ��������Ա
 ����������inline pos re_height()const { return height; }//Ҳ����ʾ����ʽ
 ���س�Ա������Person(const string &n, const string &a) :Name(n), Address(a) {}   Person(istream& is) { read(is, *this); }//����constҲ�����س�Ա���� const{...}
 �ɱ����ݳ�Ա��mutable size_t a;//��ʹ��const������Ҳ�����޸�
 ��ʽ���ã�myscreen.move(4, 0).set('#').display(cout);//��������&��Ӱ�첻��ԭ���󣬱���moveû��&�����ص�ֵ����myscreen��һ�����ƣ�set���޷��ı�ԭmyscreen����
 �����ͣ�screen*x;//ָ��screen���͵�ָ��x
 ��Ԫ���ͥ
 ��Ԫ�ࣺfriend Person��//Person����Ե���screen���private����
 ��Ԫ��Ա����:
 1ǰ���������ڶ���Window_mgr��֮ǰ���Ƚ���screen���ǰ��������
 2��Ԫ������������screen��������Window_mgr���clear����Ϊ��Ԫ������
 3����˳��ȷ���ڶ���Window_mgr��ĳ�Ա����clearʱ��screen���Ѿ���ȫ����
 ����������Ԫ��ÿ��������������һ�Σ���Ȼû��
 ��Ԫ������ʹ������ڲ��������ҲҪ������ⲿ�ṩ��������Ȼ���ɵ���

 ��������Ҫ���⴦��һ����˵�ڲ�������������¶����������������֣������಻�����¶���
 ί�й��캯����
 screen(const pos& h, const pos& w) :screen(0,h,w,' ') {}
 screen(const pos& h, const pos& w, char c) :screen(0,h,w,'c') {}
 screen(const pos& cu,const pos& h, const pos& w, char c) :cursor(cu),height(h), width(w), contents(h* w, c) {}

 explicit screen x();//��ֹ��ʽ����ת����������˵����һ�����캯���� explicit ����ʱ���ù��캯��ֻ��ͨ����ʽ������ʹ�ã�������ͨ����ʽת�������á�
 explicit���캯��ֻ������ֱ�ӳ�ʼ������Ϊ������ʽ��ʼ���ᷢ����ʽת��
 class Number {
 public:
	 Number(int num) : value(num) {}
	 int getValue() const { return value; }
 private:
	 int value;
 };

 void printNumber(Number n) {
	 std::cout << "Number: " << n.getValue() << std::endl;
 }
	Number n1 = 10;  // ��ʽת��
	cout << n1.getValue() << endl;
	Number n2(10);stream
	cout << n2.getValue() << endl;
	printNumber(20); // ��ʽת��

 �ۺ��ࣺ
 1.���г�Աpublic
 2.û�ж��幹�캯��
 3.û�����ڳ�ʼֵ
 4.û�л��࣬û��virtual����
 struct data
 {
	int ival;
	string s;
 };

 ����ֵ�����ࣺ
 1.���ݳ�ԱΪ����ֵ����
 2.��������һ��constexpr���캯��
 3.�����ݳ�Ա�������ڳ�ʼֵ�����ʼֵ�����ǳ������ʽ������Ա����ĳ�����ͣ����ʼֵ����ʹ�ó�Ա�Լ���constexpr���캯��
 4.�����ʹ������������Ĭ�϶��壬����������Ķ���
 ��class Debug

 ��ľ�̬��Ա��
 1.�����в�������κξ�̬��Ա�йص�����
 2.��̬��Ա����������thisָ��
 3.����ʹ����������ʾ�̬��Ա��ʹ����Ķ������á�ָ����ʾ�̬��Ա����Ա��������ֱ�ӷ��ʾ�̬��Ա
 4.������ⲿ���徲̬��Աʱ�������ظ�static�ؼ��ʣ�staticֻ�ܳ��������ڲ���������
 5.һ��ֻ�������ⲿ����ͳ�ʼ����̬��Ա��ֻ��һ�Σ�
 �������ڲ���ʼ����Ҫ��һ����̬��Ա������ֵ���͵�constexpr������ʼֵΪconst��������
 6.��ʹ��̬��Ա�����ڳ�ʼ���ˣ����ⲿҲ��Ҫ����
 7.��̬��ָ�롢��Ա�����ǲ���ȫ����
 ��̬��Ա��ָ�������֮ǰ���йؼ��� static �����Ա����̬��Ա��������
 �����������ɲ��֣������ɸ����ȫ�����������
 ��̬��Ա���ŵ������������λ����ķ�Χ֮�ڣ�������������ĳ�Ա����ȫ
 ������������ֳ�ͻ��������˽�г�Ա����ȫ�ֶ��󲻿��ԣ�ͨ���Ķ�������Է�
 �����׵ؿ�����̬��Ա���ض��������ʹ�ó���ĺ����������ˡ�
 ��̬��Ա����ͨ��Ա��������Ҫ��������ͨ��Ա����Ķ����������ĳ������
 �������ɲ��֣�����̬��Ա���������κξ���Ķ������ɸ�������ж�����
 ���⣬����һ��ϸ΢�����𣬾�̬��Ա������ΪĬ��ʵ�Σ�����ͨ���ݳ�Ա������ΪĬ��ʵ�Ρ�
 class Example {
 public:
	 static constexpr double rate = 6.5; // ʹ�� constexpr
	 static const int vecSize = 20;      // �Ϸ���const ����
	 static vector<double> vec;          // ������̬��Ա
 };
 constexpr double Example::rate; // ���岢��ʼ�� rate
 vector<double> Example::vec(Example::vecSize); // ���岢��ʼ�� vec

 std::ios::iostate��4��״̬��־��
 std::ios::goodbit����ʾ����������״̬��û�д������ֵͨ��Ϊ0��
 std::ios::eofbit����ʾ���ѵ����ļ�ĩβ��EOF����
 std::ios::failbit����ʾһ������/�������ʧ�ܣ�������Ȼ����ʹ�á�
 std::ios::badbit����ʾ���ѱ������޷�����ʹ�á�
 
 istream ���������Ļ��࣬�ṩ���������빦�ܡ�
 ifstream ר�����ڴ��ļ��ж�ȡ���ݡ�
 istringstream ר�����ڴ��ַ����ж�ȡ���ݡ�

 fstream����д�Կɣ�ifstream��ֻ����ofstream��ֻд��
 fstream fstrm(s);//����fstrm������Ϊs���ļ���s������string����orָ��c����ַ�����ָ�룬�˹��캯��Ϊexplicit
 fstream fstrm(s,mode);//ָ��mode���ļ�
 fstrm.open(s);
 fstrm.close();
 fstrm.is_open();//����һ��boolֵ��ָ���������ļ��Ƿ�ɹ��򿪲�δ�ر�
 in��ֻ��
 out��ֻд
 app��д����ǰ��λ��ĩβ
 ate�����ļ���λ��ĩβ
 trunc���ض��ļ�
 binary���Զ����ƽ���IO

 stringstream��string�ж�д�Կɣ�istringstream��ʹ�� >> ������ʹ������ַ������ж�ȡ���ݣ�ostringstream:ʹ�� << ������������д���ַ�����strm<<"love"��
 stringstream strm(s);//����string s�Ŀ������˹��캯��Ϊexplicit
 strm.str();//����strm�������string���Ϳ���
 strm.str(s);//��string s������strm�У�����void
 strm.clear();//���ñ�־λ������Ӱ��strm������

 ˳��������
 vector���ɱ��С���飬����������ʣ�β������ɾ�����ݿ죬insert�������ܲ�ͷ��
 deque��˫�˶��У�����������ʣ�ͷβλ�ò���ɾ�����ݶ��ܿ죬insert��֪���첻��
 list��˫������ֻ֧��˫��˳����ʣ��κ�λ�ò���ɾ�����ݶ��ܿ�
 forward_list����������ֻ֧�ֵ���˳����ʣ��κ�λ�ò���ɾ�����ݶ��ܿ�
 array���̶���С���飬����������ʣ��������ɾ��Ԫ��
 string����vector���ƣ���ר�����ڱ����ַ�������������ʣ�β������ɾ�����ݿ죬������
 ����һ������Ϊ��һ�������Ŀ����������������͡�Ԫ�����Ͷ�һ�£�	������Χ�Ļ��Ͳ���
	vector<const char*>art = { "s","b" };
	vector<string>a{art};//����
	forward_list<string>wrods{ art.begin(),art.end() };//��
 array���壺
 array<string,10>a1;//����Ϊ:����10��string������
 �������鲻֧�ֿ���������array֧��
 a1.swap(a2);//����a1��a2֮���Ԫ��

 assign�����������ڹ���������array//���ڽ�һ�������ֵ������һ������
 s1.assign(b,e);//��s1�е�Ԫ�ظ���Ϊ������b��e��Χ�ڵ�Ԫ��

 +-�������������list��forward_list�����ǿ��Զ�ε���i++
 �����������͡�Ԫ�����Ͷ�һ�²���ʹ�ù�ϵ�����

 ���Ԫ��
 c.push_back(x);//��cβ������һ��ֵx������void  emplaceֱ�ӹ��죬push�Ǹ��ƿ���
 c.push_front(x);��cͷ������һ��ֵx������void   emplace
 c.insert(p,t);�ڵ�����pָ���Ԫ��֮ǰ����һ��ֵt������ָ����Ԫ�صĵ����� emplace
 c.insert(p,n,t);�ڵ�����pָ���Ԫ��֮ǰ����n��ֵt�����ص�һ��ָ����Ԫ�صĵ���������n=0���򷵻�p
 c.insert(p,b,e);��������b��eָ����Χ��Ԫ�ز��뵽pָ���Ԫ��֮ǰ��b��e����ָ��c�е�Ԫ�أ����ص�һ��ָ����Ԫ�صĵ�����������Χ=0���򷵻�p
 c.insert(p,i1);i1��һ�������Ű�Χ��Ԫ��ֵ�б�����Щ����ֵ���뵽������pָ���Ԫ��֮ǰ�����ص�һ��ָ����Ԫ�صĵ�����������Χ=0���򷵻�p
 ��������������Ԫ��������ͬ
 insert������ʹ����ָ�������ĵ�������ָ�롢���ö�ʧЧ��list��forward_list���⣩
 ����Ԫ��
 ����array���ڵ�˳����������front��Ա����������forward_list����back��Ա���������Ƿ�������
 c.back();
 c.front();
 c[n];//���ص�Ҳ������  n����>=c.size();ֻ������string��vector��deque��array
 c.at(0);�������Ч

 ɾ��Ԫ�أ�array��֧�֣�
 ɾ���������ᵼ��ָ�������ĵ�������ָ�롢���ö�ʧЧ��list��forward_list���⣩
 c.pop_back();ɾ��βԪ�أ�����void
 c.pop_front();ɾ��ͷԪ�أ�����void
 c.erase(p);ɾ��������pָ���Ԫ�أ����غ�һ��Ԫ�صĵ���������pָ��βԪ�أ�����β�����������pΪβ�������������
 c.erase(b,e);ɾ��������b��e��Χ�ڵ�Ԫ�أ��������һ����ɾԪ�صĺ�һ��Ԫ�صĵ���������eΪβ����������򷵻�e
 c.clear();ɾ������Ԫ�أ�����void
 forward_listר�����ɾ������
 lst.before_begin();//����ָ��������Ԫ��֮ǰ������Ԫ�صĵ�����
 lst.cbefore_begin();//���ظ�ʽ���const
 lst.insert_after(p,t);//�ڵ�����pָ���Ԫ��֮���λ�ò���һ��ֵt ����һ��ָ�����һ������Ԫ�صĵ������������ΧΪ�գ��򷵻� p���� p Ϊβ���������������Ϊδ����
 lst.insert_after(p,n,t);//nΪ��Χ
 lst.insert_after(p,b,e);//b �� e �Ǳ�ʾ��Χ��һ�Ե����� ��b �� e ����ָ�� lst �ڣ�
 lst.insert_after(p,il);//i1 ��һ���������б�
 emplace_after(p,arg);//ʹ��arg��p֮���λ�ô���һ��Ԫ�أ�����һ��ָ�����һ������Ԫ�صĵ����� emplace��ֱ�ӹ���
 lst.erase_after(p);//ɾ��pָ��֮���Ԫ�أ��������¸��ĵ�����
 lst.erase_after(b,e);

 �ı�������С��array��֧�֣�
 c.resize(n);//����c�Ĵ�СΪn������Ԫ�س�ʼ��
 c.resize(n,t);//������СΪn������Ԫ�س�ʼ��Ϊt

 ���������ĳ�Ա������
 c.shrink_to_fit();//ֻ������vector��string��deque��������capacity���ٵ���size��ͬ
 c.capacity();//ֻ������vector��string���������ڴ�ռ�ʱ���Ԫ������
 c.reserve(n);//ֻ������vector��string����������������n��Ԫ�ص��ڴ�ռ�

 ˳�����ܽ᣺
 1. vector
���壺vector ��һ����̬���飬�����Զ�������С��֧�ֿ���������ʡ� ���ó�Ա������

push_back(value)����ĩβ���Ԫ��
pop_back()��ɾ��ĩβԪ��
size()������Ԫ�ظ���
empty()���ж��Ƿ�Ϊ��
at(index)������ָ��λ�õ�Ԫ�أ����߽���
c.insert(p,t);�ڵ�����pָ���Ԫ��֮ǰ����һ��ֵt������ָ����Ԫ�صĵ����� emplace
c.erase(p);ɾ��������pָ���Ԫ�أ����غ�һ��Ԫ�صĵ���������pָ��βԪ�أ�����β�����������pΪβ�������������
clear()���������Ԫ��
2. deque
���壺deque ��˫�˶��У�֧�������˿��ٲ����ɾ��Ԫ�ء� ���ó�Ա������

push_back(value)����ĩβ���Ԫ��
push_front(value)����ͷ�����Ԫ��
pop_back()��ɾ��ĩβԪ��
pop_front()��ɾ��ͷ��Ԫ��
size()������Ԫ�ظ���
c.insert(p,t);�ڵ�����pָ���Ԫ��֮ǰ����һ��ֵt������ָ����Ԫ�صĵ����� emplace
c.erase(p);ɾ��������pָ���Ԫ�أ����غ�һ��Ԫ�صĵ���������pָ��βԪ�أ�����β�����������pΪβ�������������
at(index)������ָ��λ�õ�Ԫ�أ����߽���
3. list
���壺list ��˫������֧��������λ�ÿ��ٲ����ɾ��Ԫ�أ�����֧��������ʡ� ���ó�Ա������

push_back(value)����ĩβ���Ԫ��
push_front(value)����ͷ�����Ԫ��
pop_back()��ɾ��ĩβԪ��
pop_front()��ɾ��ͷ��Ԫ��
size()������Ԫ�ظ���
insert(iterator, value)����ָ��λ�ò���Ԫ��
erase(iterator)��ɾ��ָ��λ�õ�Ԫ��
4. forward_list
���壺forward_list �ǵ�������ֻ֧�ֵ�������Ͳ���ɾ��Ԫ�ء� ���ó�Ա������

push_front(value)����ͷ�����Ԫ��
pop_front()��ɾ��ͷ��Ԫ��
insert_after(iterator, value)����ָ��λ�ú����Ԫ��
erase_after(iterator)��ɾ��ָ��λ�ú��Ԫ��
std::distance(flist.begin(), flist.end());������Ԫ�ظ�����C++17���룩
5. array
���壺array ��һ���̶���С�����飬��С�ڱ���ʱȷ���� ���ó�Ա������

at(index)������ָ��λ�õ�Ԫ�أ����߽���
size()������Ԫ�ظ���
empty()���ж��Ƿ�Ϊ��
front()�����ص�һ��Ԫ��
back()���������һ��Ԫ��
fill(value)����ָ��ֵ�����������
6. string
���壺string ��һ�����ڱ�ʾ�Ͳ����ַ�����������ʵ������һ���ػ��� vector<char>�� ���ó�Ա������

append(str)����ĩβ����ַ���
substr(pos, len)�����ش�ָ��λ�ÿ�ʼ�����ַ���
find(str)���������ַ�����λ��
replace(pos, len, str)���滻���ַ���
size()�������ַ�������
empty()���ж��Ƿ�Ϊ��
c.insert(p,t);�ڵ�����pָ���Ԫ��֮ǰ����һ��ֵt������ָ����Ԫ�صĵ����� emplace
c.erase(p);ɾ��������pָ���Ԫ�أ����غ�һ��Ԫ�صĵ���������pָ��βԪ�أ�����β�����������pΪβ�������������

������ʧЧ
1. vector �� string
���Ԫ�أ�������Ԫ�ص������·����ڴ棨����������ʱ�������е����������ú�ָ�붼��ʧЧ�����û�����·����ڴ棬����λ��֮��ĵ����������ú�ָ���ʧЧ��
ɾ��Ԫ�أ�ɾ��λ�ü���֮��ĵ����������ú�ָ���ʧЧ��
2. deque
���Ԫ�أ�����β֮����κ�λ�����Ԫ�أ����е����������ú�ָ�붼��ʧЧ������β���Ԫ��ʱ����������ʧЧ�������ú�ָ�벻��ʧЧ��
ɾ��Ԫ�أ�����β֮����κ�λ��ɾ��Ԫ�أ����е����������ú�ָ�붼��ʧЧ��ɾ����βԪ��ʱ������β�������ʧЧ�⣬���������������ú�ָ�붼����Ӱ�졣
3. list �� forward_list
���Ԫ�أ�����ʹ�κε����������ú�ָ��ʧЧ��
ɾ��Ԫ�أ�ָ��ɾ��Ԫ�صĵ����������ú�ָ���ʧЧ���������Ĳ���ʧЧ��
4. array
���/ɾ��Ԫ�أ�array �ǹ̶���С�����������ܶ�̬��ӻ�ɾ��Ԫ�أ���˲����ڵ����������ú�ָ��ʧЧ�����⡣
5. ������������ map, set, multimap, multiset��
���Ԫ�أ�����ʹ�κε����������ú�ָ��ʧЧ��
ɾ��Ԫ�أ�ָ��ɾ��Ԫ�صĵ����������ú�ָ���ʧЧ���������Ĳ���ʧЧ��
6. ��������������� unordered_map, unordered_set, unordered_multimap, unordered_multiset��
���Ԫ�أ�����ʹ�κε����������ú�ָ��ʧЧ��
ɾ��Ԫ�أ�ָ��ɾ��Ԫ�صĵ����������ú�ָ���ʧЧ���������Ĳ���ʧЧ��

 string s(cp,n);//s �� cp ָ���������ǰ n ���ַ��Ŀ���������������Ӧ�ð��� n ���ַ�
 string s(s2,pos2);//s �� string s2 ���±� pos2 ��ʼ���ַ��Ŀ����� ��pos2>s2.si ze ������ ���캯������Ϊδ����
 string s(s2,pos2,len2);//s �� string s2 ���±� pos2 ��ʼ 1en2 ���ַ��Ŀ����� �� pos2>s2.si ze ���������캯������Ϊδ���塣 ���� 1en2��ֵ�Ƕ��٣� ���캯�����࿽�� s2.si ze ����-pos2 ���ַ�

 substr:����һ��string��һ���ֻ���ȫ������
 string s("hello world");
 s.substr(0,5);//hello
 s.substr(6);//world

 string���͵����������
 s1.assign(c,7);//��c��ǰ7��Ԫ�ظ��Ƶ�s1�У�����һ��ָ��s1������
 s.insert(0,c);//��s�ĵ�0���ַ��󣬲���c������Ԫ�أ������c+1��������һ��Ԫ��֮���ʣ��Ԫ�أ�������һ��ָ��s������
 s.erase(0,4);//��s�ĵ�0���ַ���ʼ��ɾ���ĸ��ַ�������һ��ָ��s������
 s.append("fjf");//��s��ĩβ���롰fjf��������һ��ָ��s������
 s.replace(11,2,"fjf");//�ڵ�11λ��ɾ��2λ�ַ����ٲ��롰fjf��������һ��ָ��s������

 string����������
 s.find(arg);//��һ�γ��ֵ�λ�� ���ص�һ�γ���λ�õ��±�ֵ  s,pos sΪ�ַ�����posΪλ��
 s.rfind(arg);//���һ�γ��ֵ�λ��
 s.find_first_of(arg);//arg������һ���ַ���һ�γ��ֵ�λ��
 s.find_last_of(arg);//arg������һ���ַ����һ�γ��ֵ�λ��
 s.find_first_not_of(arg);���ҵ�һ������arg�е��ַ�
 s.find_last_not_of(arg);�������һ������arg�е��ַ�

 string��ֵת����
 to_string(val);//������ֵval��string��ʾ
 stoi(s,p,b);//����s����ʼ�Ӵ�����ʾ�������ݣ�����ֵ���������ͷֱ�Ϊint��long��unsigned long��long long��unsigned long long��b��ʾת�����õĻ�����Ĭ��10.p��size_tָ�룬��������s�е�һ������ֵ�ַ��±꣬Ĭ��0
 stol
 stoul
 stoll
 stof(s,p);//����s����ʼ�Ӵ�����ʾ�������ݣ�����ֵ���������ͷֱ�Ϊfloat��double��long double��p����
 stod(s,p);
 stold(s,p);

 ������������
 stack��ʵ����ջ�Ĺ��ܣ���ѭ����ȳ���LIFO��ԭ��Ԫ��ֻ�ܴ�ջ�� ���� ���루push�����Ƴ���pop��
 s.pop();//�Ƴ������ض���ǰ��Ԫ�ء�
 s.push(item);//����һ����Ԫ��ѹ��ջ����ͨ���������ƶ�item������������args����
 s.emplace(args);
 s.top();//����ջ��Ԫ�أ�������Ԫ�ص���ջ

 queue��ʵ���˶��еĹ��ܣ���ѭ�Ƚ��ȳ���FIFO��ԭ��Ԫ��ֻ�ܴӶ��е� ĩβ ���루enqueue�����Ӷ��е� ǰ�� �Ƴ���dequeue��
 priority_queue��ʵ�������ȶ��еĹ��ܣ�Ԫ�ذ����ȼ�����
 q.pop();//�Ƴ������ض���ǰ��Ԫ�ء�
 q.front();//������Ԫ�ػ�βԪ�أ�����ɾ����Ԫ�أ�ֻ������queue
 q.back();
 q.top();//����������ȼ�Ԫ�أ�����ɾ����Ԫ�أ�ֻ������priority
 q.push(item);//��queueĩβ����priority��ǡ��λ�ô���һ��Ԫ�أ���ֵΪitem��������args����
 q.emplace(args);

 �㷨����������׼��ĺ��������ܶ������������/ɾ������������back_inserter,���п����Ȳ���ʱȷ����������Ŀռ��㹻��
 find(e,q,t);//e��q���ǵ����������ҷ�Χ[e,q)��δ�ҵ�����q���ҵ�t�ͷ���t��λ�ã�����ֵ�ض��ǵ���������
 count(e,q,t);//���ص���t���ֵĴ���
 ֻ���㷨��
 accumulate(e,q,t);//��ͣ��͵ĳ�ֵΪt�����������������������ͣ��Լ�+��ʹ�ã�string����Ҳ������ӣ�accumulate(x.begin(), x.end(), string("i "));
 equal(i1.begin(),i1.end(),i2.begin());//�Ƚ�i1��i2�Ƿ���ͬ��i2������>=i1�����У������������ݣ����Խ��бȽϼ��ɣ�����vector<string>��list<const char*>�������໥�Ƚ�
 д����Ԫ���㷨��
 fill(e,q,t);//��ÿ��Ԫ������Ϊt
 fill_n(e,n,t);//eָ��һ��Ԫ�أ���e��ʼn��Ԫ������Ϊt
 �����������
 auto i=back_inserter(vector<int>a);//��ʱ��*i��ֵ�������Ԫ��
 �����㷨��
 copy(a.begin(),a.end(),b.begin());//��a�����ݿ�����b�� ���뱣֤a��b������һ�����Ԫ�أ�copy�޷��������������/ɾ��������
 replace(a.begin(),a.end(),0,5);//��a��Ϊ0��ֵ��Ϊ5
 replace_copy(a.cbegin(), a.cend(), back_inserter(b), 0, 55);//��a�����ݿ�����b������b��Ϊ0��ֵ��Ϊ55
 �����㷨����׼���㷨���� std::sort��Ҫ��ȽϺ����Ĳ����� const ���á�������Ϊ��Щ�㷨���ڲ����ܻ��Ԫ�ؽ��ж�αȽϣ�����ϣ����Щ�Ƚϲ����ı�Ԫ�ص�״̬��
 sort(e,q);//����ĸ/��С�������� �ú���Ҳ�����Զ�������������sort(e,q,lambda);
 stable_sort(e,q);//��sortһ�����������Ԫ����ȣ����������������˳�򲻻�ı䡣
 unique(e,q��lambda);//�������ڵ��ظ������ָ���ظ�����֮��һ��λ�õĵ�������˵����������ʵ�ǽ����ƶ���ĩβ������Ԫ�ص���ԭ����end��
 unique_copy(e,q,result);//result�����Χ����ʼ���������
	sort(x.begin(), x.end(), [](int a, int b) {
		if (a < 5 && b >= 5) return true;
		if (a >= 5 && b < 5) return false;
		return a < b;
	});
	auto last=unique(x.begin(), x.end(), [](int a,int b) {return a%2==0&&b%2==0; });
	x.erase(last, x.end());


 partition(e,q,predicate);//���ڸ��ݸ�����ν�ʣ�predicate������Χ�ڵ�Ԫ���������У�ʹ������ν�ʵ�Ԫ��λ�ڷ�Χ��ǰ�벿�֣���������ν�ʵ�Ԫ��λ�ڷ�Χ�ĺ�벿�֡�
 ν�ʣ�predicate����
 һ���������䷵�ؽ����һ������Ϊ������ֵ����������������j���ҷ���ֵΪbool��
 bool compare(int a, int b) {
	return a < b;
}
 Lambda��
 ���ʽ��4,3  3,2 2,1 1,0  3
 capture -> return_type {
	// function body
}
 [capture](parameters){function body}
 capture�������ⲿ�����ķ�ʽ��������ֵ����=�������ò���&����//[=,&a][&,a]��ʽ����
 parameters�����������б�
 return_type���������ͣ�����ʡ�ԣ����������Զ��ƶϣ���
 function body�������壬��������Ĳ�����
 ���ڿ����ı����������Ҫ�޸ģ��������mutable(ֵ����[]( int& m)mutable ->int {--m; return m; };
 size_t v1=42
 auto f=[v1]()mutable(return ++v1;};
 v1=0
 auto j=f();//j=43
 ���ڷ�const���������ã�����ͨ�����ý����޸�
 size_t v1=42
 auto f=[v1]()mutable(return ++v1;};
 v1=0
 auto j=f();//j=1
 Ϊlambda���巵�����ͣ�
 find_if(e,q,[](int n)->int{if(n<0)return -n;else return n;};
 ������lambda�ĺ�����
 find_if(e,q,Lambda);//�����ڷ�Χ�ڲ��ҵ�һ�������ض�������Ԫ�ء�������һ��Lambda��Ϊ������������һ��ָ���һ������������Ԫ�صĵ����������û���ҵ�����������Ԫ�أ��򷵻�ָ��Χĩβ�ĵ�������
 count_if(e,q,Lambda);//��������Ҫ���Ԫ�صĸ���
 for_each(e,q,Lambda);//��e-q��Χ�ڵ�Ԫ�ؽ��в�������Lambda���ʽ���ص�ֵ
 transform(numbers.begin(), numbers.end(), results.begin(),Lambda);//�����ڶ������е�Ԫ��Ӧ��ָ���Ĳ���,��������洢����һ�������С�ȷ��results�Ŀռ�>=numbers

 bind���������find_if���㷨ֻ�ܽ���һԪν�ʵ����ƣ�����ʹ�õ����Ҳ��bind��lambdaÿ�ζ�д̫�鷳��ʹ��bind��Ҫ��std::placeholders
 auto newcallable=bind(callable,arg_list);
 callable������һ���ɵ��ö��󣬿����Ǻ���ָ�롢�������󡢻��� lambda ���ʽ��
 newcallable�������ɵĿɵ��ö���
 arg_list������һ�������б����ڰ󶨵� callable �Ĳ����ϡ�
 auto g=bind(ff,a,b,_2,c_1);
 g(X,Y)��Ч��ff(a,b,X,c,Y)
 bind(isshorter1,_2,_1)��bind(isshorter1,_1,_2)�Ľ���պ��෴

 �����������
 back_inserter(a)������һ��push_back������
 front_inserter(a)������һ��push_front�����������ɵĵ���������ָ�������ĵ�һ��Ԫ��
 inserter(a,a.begin())������һ��ʹ��insert�ĵ�����������ָ��������֮ǰ��λ�ã�ʹ�øò���ʱ������������ָ��ԭ����Ԫ��
 ��ز�����
 auto it = std::back_inserter(vec);
 it=t;//�൱����itָ����λ�ò���ֵt
 *it,++it,it++ ��ֻ�᷵��it

 iostream��������
 ���룺
 ��ز�����
 istream_iterator<T> in(is); in��������is��ȡ����ΪT��ֵ
 istream_iterator<T> end;    ��ȡ����ΪT��ֵ��istream_iterator����������ʾβ��λ��
 in1==in2					 in1��in2�����ȡ��ͬ���͡��������β����������߰���ͬ���룬���������
 in1!=in2
 *in						 ���ش����ж�ȡ��ֵ
 in->mem					 ����(in).men
 ++in,in++					 ʹ��Ԫ�������������>>��������������ж�ȡ��һ��ֵ��++in����ָ�����������������ã�in++���ؾ�ֵ
 ���������ʽ��
 1.��ȡ����
 vector<string>x;
 ifstream is("H://examtest//a.txt");
 istream_iterator<string>int_in(is);
 istream_iterator<string>eof;
 while (int_in != eof)
		x.push_back(*int_in++);//*int_in++�����ƶ�����һλ��Ȼ��ɵĲ��������x��Ҳ��˵����1�ƶ���2������1�����ݸ�x
 vector<string>y(int_in, eof);//������while������Ч
 2.�㷨����
 cout<<accumulate(is,eof,0)<<endl;
 
 �����
 ��ز�����
 ostream_iterator<T> out(os);	   out������T��ֵд�������os��
 ostream_iterator<T> out(os,d);    out������T��ֵд�������os�У�ÿ��ֵ���涼���һ��d��dָ��һ�����ַ���β���ַ�����				 
 out=val						   ��<<�������valд�뵽out���󶨵�ostream�С�val���ͱ�����out��д�����ͼ���
 *out,++out,out++				   ��ֻ�᷵��out
 ���������ʽ��
 1.��ȡ����
 ostream_iterator<string> os(cout, " ");
 for (auto e : y)
	*os++ = e;//��ЧΪos=e;
 2.�㷨����
 copy(y.begin(), y.end(), os);//������Ч��һ��

 �����������forward_list��֧�ַ�����������������������������ָ���Ԫ��ʵ��������ǰһ��λ�õ�Ԫ��
 ��ȫ�෴
 crend()��beginǰ�棬crbegin()��endǰ��
 com.base();//���һ�����������
 �������븴�Ʒ�ΧΪ3->7
  vector<int>y{ 1,2,3,4,5,6,7,8,9,10 };
	list<int>z;
	vector<int>::reverse_iterator rb(y.begin() + 2);
	vector<int>::reverse_iterator rs(y.begin() + 7);
	copy(rs, rb, back_inserter(z));

 5�����������
 ���룺			p392
 �����			p392
 ǰ��			p392
 ˫��			p392
 ������ʣ�		p392

 �㷨�β�ģʽ��
 alg(beg,end,other args);
 alg(beg,end,dest,other args);//dest�����ǲ���������������������
 alg(beg,end,beg2,other args);//Ĭ��beg2�������ռ�>=beg��
 alg(beg,end,beg2,end2,other args);

 �ض������㷨��list��forward_list��������void
 lst.merge(lst2);		ʹ��<��������кϲ�����������
 lst.merge(lst2,comp);	ʹ�ø����ıȽϲ������кϲ�
 lst.remove(val);		ɾ��һ��ֵ��ͬ��
 lst.remove_if(pred);	ɾ��һ������һԪν�ʵ�
 lst.reserve();
 lst.sort();
 lst.sort(comp);		
 lst.unique();
 lst.unique(pred);
 splice�㷨����ʽ�ṹ���У����ڽ�һ���б��Ԫ�ز��뵽��һ���б���
 lst.splice(args);
 flst.splice_after(args);
 (p,lst2)(p,lst2,p2),(p,lst2,b,e)

 �������������ؼ���������ͷ���
 ���򱣴棺map<key,valve> set<key>
 map��set �ؼ��֡���ֵ��ֻ����ؼ��� set������Ϊ����������������ʵ�ַ�ʽ
 multimap��multiset �ؼ��ֿ��ظ�����
 ��ز����ͽ��Ϳ��Կ�add_family����
 �ؼ���valve�����ܹ�֧��<=����������ϸ�����
 ͨ�����Թ�������ʹ�÷�ʽ�㷨
 pair����(Ĭ������³�ԱΪpublic��
 ֻ��ֵ�����ú���pair.first��second�����ڽ�����������ϳ�һ����һ�Ķ���
 ���ͱ�����
 key_type				�ؼ�������
 mapped_type			ֵ���ͣ�ֻ������map
 valve_type				����set���൱��key_type
						����map��Ϊpair<const key_type,mapped_type>
 ���򱣴棺
 unordered_map��unordered_set ʹ�ù�ϣ������֯
 unordered_multimap��unordered_multiset
*/

//IO��

//struct personinfo {
//	string name;
//	vector<string>phones;
//};
/*int main()
{
	string folderPath = "H://examtest//";
	string fileName = "a.txt";
	string filePath = folderPath + fileName;
	fstream in(filePath, ios::in);
	if (!in)
	{
		cerr << "�޷����ļ���" << filePath << endl;
		return -1;
	}
	string line;
	vector<string> xy;
	while (getline(in, line))
	{
		xy.push_back(line);
	}
	in.close();
	for (auto it = xy.begin(); it != xy.end() && !it->empty(); ++it)
	{
		istringstream ini(*it);
		f(ini);
	}
	ifstream in("H://examtest//a.txt");
	if (!in)
	{
		cerr << "�޷����ļ���H://examtest//a.txt" << endl;
		return -1;
	}
	string line, word;
	vector<personinfo>people;
	istringstream record;
	while (getline(in, line))
	{
		personinfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	in.close();
	ostringstream os;
	for (auto a : people)
	{
		os << a.name << ' ';
		for (auto b : a.phones)
			os << b << ' ';
		os << endl;
	}
	ofstream out("H://examtest//abc.txt");
	if (!out)
	{
		cerr << "�޷����ļ���H://examtest//abc.txt" << endl;
		return -1;
	}
	for (auto a : people)
	{
		out << a.name << ' ';
		for (auto b : a.phones)
			out << b << ' ';
		out << endl;
	}
	string result = os.str();
	out << result;
	cout << result;
	out.close();
	return 0;
}*/////IO��

//main������������

//int main(int argc, char* argv[]) //./c++study H://examtest//a.txt ���ɽ��в�������H://examtest//a.txt
//{
//    // ����Ƿ񴫵����ļ�������
//    if (argc < 3) {
//        cerr << "���ṩ�����ļ���������ļ�����Ϊ������" << endl;
//        return -1;
//    }
//
//    // ��ȡ�ļ���
//    string infile = argv[1];
//    string outfile = argv[2];
//
//    // ���ļ�
//    ifstream inFile(infile);
//    if (!inFile) {
//        cerr << "�޷����ļ�: " << infile << endl;
//        return -1;
//    }
//
//    // ������ļ�
//    ofstream OUTfile(outfile,ios::app);
//    if (!OUTfile) {
//        cerr << "�޷����ļ�: " << outfile << endl;
//        return -1;
//    }
//
//    // ��ȡ�ļ�����
//    string line;
//    vector<string> lines;
//    while (getline(inFile, line)) {
//        lines.push_back(line);
//        OUTfile << line << '\n';
//    }
//    OUTfile << "fuck you" << endl;
//    inFile.close();
//    OUTfile.close();
//
//    for (auto& l : lines) {
//        cout << l << endl;
//    }
//    return 0;
//}

//class date {
//public:
//	friend ostream& operator<<(ostream&, const date&);
//	date() = default;
//	date(string& ds);
//	unsigned y() const { return year; }
//	unsigned m() const { return month; }
//	unsigned d() const { return day; }
//
//private:
//	unsigned year, month, day;
//};
//
//// �·�ȫ�� 
//const string month_name[] = { "January", "February", "March",
//			  "April", "May", "June", "July", "August", "September",
//			  "October", "November", "December" };
//
//// �·ݼ�д 
//const string month_abbr[] = { "Jan", "Feb", "Mar", "Apr", "May",
//			  "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec" };
//
//// ÿ������ 
//const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//inline int get_month(string& ds, int& end_of_month)
//{
//	int i, j;
//	for (i = 0; i < 12; i++) {
//		// ���ÿ���ַ��Ƿ����·ݼ�д��� 
//		for (j = 0; j < month_abbr[i].size(); j++)
//			if (ds[j] != month_abbr[i][j])      // ���Ǵ��¼�д 
//				break;
//		if (j == month_abbr[i].size())    // ���дƥ�� 
//			break;
//	}
//
//	if (i == 12)           // �������·���������ͬ 
//		throw invalid_argument("���ǺϷ��·���");
//
//	if (ds[j] == ' ') {     // �հ׷��������·ݼ�д 
//		end_of_month = j + 1;
//		return i + 1;
//	}
//
//	for (; j < month_name[i].size(); j++)
//		if (ds[j] != month_name[i][j])
//			break;
//
//	if (j == month_name[i].size() && ds[j] == ' ') { // �·�ȫ�� 
//		end_of_month = j + 1;
//		return i + 1;
//	}
//
//	throw invalid_argument("���ǺϷ��·���");
//}
//
//inline int get_day(string& ds, int month, int& p)
//{
//	size_t q;
//	int day = stoi(ds.substr(p), &q); // ��p��ʼ�Ĳ���ת��Ϊ����ֵ 
//	if (day < 1 || day > days[month])
//		throw invalid_argument("���ǺϷ�����ֵ");
//	p += q;        // �ƶ�������ֵ֮�� 
//	return day;
//}
//
//inline int get_year(string& ds, int& p)
//{
//	size_t q;
//	int year = stoi(ds.substr(p), &q);  // ��p��ʼ�Ĳ���ת��Ϊ�� 
//	if (p + q < ds.size())
//		throw invalid_argument("�Ƿ���β����");
//	return year;
//}
//
//date::date(string& ds)
//{
//	int p;
//	size_t q;
//
//	if ((p = ds.find_first_of("0123456789")) == string::npos)
//		throw invalid_argument("û�����֣��Ƿ�����");
//
//	if (p > 0) {        // �·�����ʽ 
//		month = get_month(ds, p);
//		day = get_day(ds, month, p);
//		if (ds[p] != ' ' && ds[p] != ',')
//			throw invalid_argument("�Ƿ������");
//		p++;
//		year = get_year(ds, p);
//	}
//	else {         // �·�ֵ��ʽ 
//		month = stoi(ds, &q);
//		p = q;
//		if (month < 1 || month > 12)
//			throw invalid_argument("���ǺϷ��·�ֵ");
//		if (ds[p++] != '/')
//			throw invalid_argument("�Ƿ������");
//		day = get_day(ds, month, p);
//		if (ds[p++] != '/')
//			throw invalid_argument("�Ƿ������");
//		year = get_year(ds, p);
//	}
//}
//
//ostream& operator<<(ostream& out, const date& d)
//{
//	out << d.y() << "��" << d.m() << "��" << d.d() << "��" << endl;
//	return out;
//}
//
//int main()
//{
//	string dates[] = { "Jan 1,2014", "February 1 2014", "3/1/2014",
//		// "Jcn 1,2014", 
//		// "Janvary 1,2014", 
//		// "Jan 32,2014", 
//		// "Jan 1/2014", 
//		"3 1 2014 ",
//	};
//	try {
//		for (auto ds : dates) {
//			date d1(ds);
//			cout << d1;
//		}
//	}
//	catch (invalid_argument e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//enum obj_type { LP, RP, ADD, SUB, VAL, cheng, chu };
//struct obj {
//	obj(obj_type type, double val = 0) { t = type; v = val; }
//	obj_type t;
//	double v;
//};
//inline void skipws(string& exp, size_t& p)
//{
//	p = exp.find_first_not_of(" ", p);
//}
//
//inline void new_val(stack<obj>& so, double v)
//{
//	if (so.empty() || so.top().t == LP) {        // ��ջ�������� 
//		so.push(obj(VAL, v));
//		// cout << "push " << v << endl; 
//	}
//	else if (so.top().t == cheng || so.top().t == chu)
//	{
//		obj_type type = so.top().t;
//		so.pop();
//		if (type == cheng)
//			v *= so.top().v;
//		else if (type == chu)
//			v /= so.top().v;
//		so.pop();
//		so.push(obj(VAL, v));
//	}
//	else if (so.top().t == ADD || so.top().t == SUB) {
//		// ֮ǰ������� 
//		obj_type type = so.top().t;
//		so.pop();
//		/*if (type == ADD)
//		  cout << "pop +" << endl;
//		else cout << "pop -" << endl;*/
//		// cout << "pop " << so.top().v << endl; 
//		// ִ�мӼ��� 
//		if (type == ADD)
//			v += so.top().v;
//		else v = so.top().v - v;
//		so.pop();
//		so.push(obj(VAL, v));        // ������ѹջ 
//		// cout << "push " << v << endl; 
//	}
//	else throw invalid_argument("ȱ�������");
//}
//
//int main()
//{
//	stack<obj> so;
//	string exp;
//	size_t p = 0, q;
//	size_t i = 1;
//	double v;
//
//	cout << "��������ʽ��";
//	getline(cin, exp);
//
//	while (p < exp.size()) {
//		skipws(exp, p);            // �����ո� 
//		if (exp[p] == '(') {        // ������ֱ��ѹջ 
//			so.push(obj(LP));
//			p++;
//			// cout << "push LP" << endl; 
//		}
//		else if (exp[p] == '*' || exp[p] == '/')
//		{
//			if (so.empty() || so.top().t != VAL)
//				throw invalid_argument("ȱ��������");
//			if (exp[p] == '*')
//				so.push(obj(cheng));
//			else
//				so.push(obj(chu));
//			p++;
//		}
//		else if (exp[p] == '+' || exp[p] == '-') {
//			// ������� 
//			if (so.empty() || so.top().t != VAL)
//				// ��ջ��֮ǰ���������� 
//				throw invalid_argument("ȱ��������");
//
//			if (exp[p] == '+')          // �����ѹջ 
//				so.push(obj(ADD));
//			else so.push(obj(SUB));
//			p++;
//			i++;
//			// cout << "push " << exp[p - 1] << endl; 
//		}
//		else if (exp[p] == ')') {   // ������ 
//			p++;
//			if (so.empty())        // ֮ǰ����Ե������� 
//				throw invalid_argument("δƥ��������");
//
//			if (so.top().t == LP)        // һ������֮�������� 
//				throw invalid_argument("������");
//
//			if (so.top().t == VAL) {     // ��ȷ�������������� 
//				//v = so.top().v;
//				//so.pop();
//				// cout << "pop " << v << endl; 
//
//				while (i > 0)
//				{
//					v = so.top().v;
//					so.pop();
//
//					// cout << "pop LP" << endl; 
//					new_val(so, v);      // �����������߼�һ�� 
//					--i;
//				}
//				so.pop();
//				if (so.empty() || so.top().t != LP)
//					throw invalid_argument("δƥ��������");
//
//				so.pop();
//				if (so.size() != 1 || so.top().t != VAL)
//					new_val(so, v);
//
//			}
//			else        // ջ���ض�������� 
//				throw invalid_argument("ȱ��������");
//		}
//		else {        // Ӧ���������� 
//			v = stod(exp.substr(p), &q);
//			p += q;
//			if (so.empty() || so.top().t == chu || so.top().t == cheng)
//				new_val(so, v);
//			else
//				so.push(obj(VAL, v));
//		}
//	}
//	//5 * (3 + 2 * 2 + 2)
//
//	if (so.size() != 1 || so.top().t != VAL)
//		throw invalid_argument("�Ƿ����ʽ");
//
//	cout << so.top().v << endl;
//	return 0;
//}

//���ʹ��operator<<

// ����һ���Զ�������
//class Person {
//public:
//	Person(const std::string& name, int age) : name_(name), age_(age) {}
//
//	// ��Ԫ������ʹ��operator<<���Է���˽�г�Ա
//	friend std::ostream& operator<<(std::ostream& out, const Person& person);
//
//private:
//	std::string name_;
//	int age_;
//};
//
//// ����operator<<
//std::ostream& operator<<(std::ostream& out, const Person& person) {
//	out << "Name: " << person.name_ << ", Age: " << person.age_;
//	return out;
//}
//
//int main() {
//	Person person("Alice", 30);
//	std::cout << person << std::endl; // ʹ�����ص�operator<<���Person����
//	return 0;
//}
//
// 
// 
// class Empty {
//public:
//	Empty& operator=(const Empty& rhs) {
//		if (this != &rhs) {
//			// ִ�и�ֵ����
//		}
//		return *this;
//	}
//};
// 
//��ֵ�����(= )����ֵ��������ڽ�һ�������ֵ������һ����������һ����Ա������ͨ�����ضԵ�ǰ��������ã�* this�����Ա�֧����ʽ��ֵ�����磺
//class Empty {
//public:
//	Empty& operator=(const Empty& rhs) {
//		// ��ֵ����
//		return *this;
//	}
//};
// 
//���������(<< )�����������ͨ��������������������罫������������������̨���ļ�����ͨ����һ���ǳ�Ա���������ҷ�������������á����磺
//std::ostream& operator<<(std::ostream& os, const Empty& obj) {
//	// �������
//  os << "Empty object";
//	return os;
//}
// 
//int main() {
//Empty e1, e2;
//e1 = e2; // ʹ�ø�ֵ�����
//std::cout << e1 << std::endl; // ʹ�ò��������
//return 0;
//}