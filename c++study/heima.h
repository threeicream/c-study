/*
�ַ�����������"Hello, World!" ��һ���ַ����������������ڴ��д洢Ϊһ���Կ��ַ� '\0' ��β���ַ����顣
����char��
const char*p="love";
cout<<p<<endl;//p��ָ�룬ֱ�����p��ָ��������ַ�����ֱ������\0
cout << *p << endl;//p ָ���ַ��� "love" �ĵ�һ���ַ� 'l'
const char* p[] = {"love", "you"};//����c����ַ������� char p[]="love"���ַ����� "love"�������Ϊָ�����ַ���ָ�� string s[] = {"abc", "def", "ghi"};  // C++����ַ�������
cout << p << endl;   // ��� p �ĵ�ַ,p��һ�����飬�����Ա����char���͵�ָ�룬ָ��ֱ�ָ���ַ���
cout << *p << endl;  // ��� p[0] ָ����ַ��� "love"
cout << p[0] << endl; // ��� "love"
cout << p[1] << endl; // ��� "you"
cout << **p << endl;  // ��� p[0][0]���� 'l'
�ַ����飺�����������ַ��ļ��ϣ���һ���Կ��ַ� '\0' ��β��
�ַ����������������Կ��ַ� '\0' ��β����˿��Ա���Ϊһ��������ַ����顣

�� C++ �У�������������ʱ��һ�����ȼ����򣬰���������ȷ��������ĺ��塣��������Щ�������ϸ˵����
�ӱ�ʶ����ʼ��
�����Ľ����ӱ�ʶ��������������ʼ��
���ȴ������ţ�
�����ʶ������������ ()���ȴ��������ڵ����ݡ���ͨ����ʾ���������б�
�����׺��������
�����������׺���������������±� [] �ͺ������� ()����Щ�����������ȼ�����ָ�� *��
����ǰ׺��������
�����ǰ׺����������ָ�� * �����η� const��
���ﵽ�������
������������ʱ��ͨ�������ڲ�����ſ�ʼ��Ȼ����������չ��
�ٸ����ӣ����� int(*p[10])(int)��
�ҵ���ʶ�� p��
p �����������֡�
�����׺������ []��
p ��һ������ 10 ��Ԫ�ص����顣
����ǰ׺������ *��
�����е�ÿ��Ԫ�ض���һ��ָ�롣
�������� ()��
��Щָ��ָ��һ������ int ���������� int ���͵ĺ�����
ͨ����Щ���裬���ǿ���ȷ�� int(*p[10])(int) ��һ������ 10 ��ָ������ָ������飬ÿ����������һ�� int ����������һ�� int ���͵�ֵ��

��̬�����ڴ棺ʵ�������У������޷�Ԥ��ȷ���ַ�����Ĵ�С����̬�����ڴ����������Ҫ��������Ĵ�С���Ӷ������ع����ڴ档
int main() {
    // ��̬�����ڴ�
    char* arr = (char*)malloc(6 * sizeof(char));
    if (arr == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
        return 1;
    }

    // ��ֵ��ʹ��
    strcpy(arr, "hello");
    std::cout << "�ַ�����: " << arr << std::endl;

    // �ͷ��ڴ�
    free(arr);

    return 0;
}

 union�Ĵ�Сȡ������ռ�ռ����ı����Ĵ�С �����Ǳ���  int a32λռ4�ֽڣ�����uni�Ĵ�С����4�ֽ�
 struct�Ĵ�С�����ڴ�������⣬int a�ĸ��ֽ�,char b��Ȼ��1���ֽ� ����Ϊ�˴�ȡЧ�ʣ�char
 bҲ��������һ��4�ֽڵĿռ䣬���������ṹ����ռ�ռ�Ϊ8�ֽ�


�ڴ����ģ�ͣ����� ��ͬ�����ŵ����ݣ����費ͬ���������ڣ������
1��2�ڳ�������֮ǰ�ʹ���
1.����������ź��������ƴ��룬ϵͳ����
���cpuִ�еĻ���ָ�1�ǹ����ֻ����
2.ȫ���������ȫ�ֱ�/��������̬�������ַ���������ϵͳ�����ͷ�
3.ջ������ź�������ֵ���βΣ����ֲ���/�����ȣ�ϵͳ�����ٺ��ͷ�
4.����������Ա������ͷţ��������ʱϵͳ�Զ��ͷ�
new��
����new�����������Խ����ݿ��ٵ�����
int *p=new int(10);//new���ص���һ��int���͵�ָ��
delete p;
int*p=new int[10];//new��̬������һ������ 10 �� int Ԫ�ص����飬������һ��ָ���������Ԫ�ص�ָ��
delete[]p;//�ͷ��ڴ�
new��malloc������
1.new�ǲ�������malloc��c�ĺ���
2.new��delete���������ʹ�ã�malloc��free�������ʹ��
3.new ����ָ�����͵�ָ�룬����Ҫ����ת����malloc ���� void*����Ҫ��ʽ����ת��

�����߼�Ӧ�ã�
������Ĭ�ϲ�����int asf(int a=0,int b=0);//Ĭ�ϲ���������û��Ĭ�ϲ����βε��ұߣ�������������Ĭ�Ϻ�������������Ͳ�����Ĭ�ϲ���
������ռλ������int asf(int,int);//ֻ��һ��int
�������أ�ͬһ�������£�����������ͬ�������������Ͳ�ͬor������ͬor˳��ͬ

��ķ�װ��
���е����Ժ���Ϊͳһ��Ϊ��Ա
���ԣ���Ա���� ��Ա����
��Ϊ����Ա���� ��Ա����
����Ȩ�ޣ�������������˽��  �������е���������Է��ʸ���ı�������
��Ա����ͨ��������Ա���������������
����ĳ�ʼ��������ͨ�� ���캯������������ʱ���г�Ա������ֵ���������Զ����ã���������������������ǰϵͳ�Զ����ã���������������
���캯����1.û�з���ֵ��дvoid��2.��������=������3.���캯�������в������������أ�4.�Զ�����һ��
����������1.û�з���ֵ��дvoid��2.��������=������������ǰ��~��3.�����в������������أ�4.��������ǰ�Զ�����һ��

���캯�����ࣺ
1.1�вι��� Circle(const double& x, const double& y, const double& r){}
1.2�޲ι��죨Ĭ�Ϲ��캯����Person()=default;
2.1��ͨ����
2.2�������� Circle(const Circle& p) { circle_point_x = p.circle_point_x; }
���캯�����÷�����
1.���ŷ� Circle x(1,2,3);Cricle y(x); 
2.��ʾ�� Circle x=Circle(1,2,3);Circle y=Circle(x);//Circle(1,2,3)��Ϊ��������ִ�н�����ᱻϵͳ��������
3.��ʽת���� Circle x={1,2,3};
�������캯������ʱ����
1.��ʼ���¶���
Circle p1(1,2,3);
Circle p2(p1);
2.ֵ���ݵķ�ʽ������������ֵ
void works1(Circle p){}
void test1(){Circle p3;works1(p3);}//p3����Ĭ�Ϲ��캯��������works1ʱ����һ���µ�Circleֵ���ݸ������β�
3.ֵ��ʽ���ؾֲ�����
void works2(){Circle p4;return p4}//p4����Ĭ�Ϲ��캯������returnʱ����һ���µ�Circleֵ���ݸ�p5
void test1(){Circle p5=work2();}
���캯�����ù���
ϵͳĬ�����1���캯����2����������3�������캯���Զ����˿������캯������ϵͳ���ṩ�������캯��
������ڶ�����������ռ䣬���п�������
ǳ�������򵥵ĸ�ֵ��������
�Լ�ʵ�ֿ������캯�������ǳ��������������//Circle ��һ��int *height��Ա
Circle(const Circle &p)//�������캯��
{
    //height=p.height;//������Ĭ��ǳ����
    height=new int(*p.height);//����������������������е�delete���������ظ�����ɾ��ͬһ����ַ
    //Ϊʲô���*�����ò�������Ϊheight��һ��ָ�룬������Ҫ��ָ���ֵ��������Ҫ������
}
~Circle() //��������
{
    if(height!=NULL)
    {delete height; height=NULL;}// �ͷ��ڴ�
}
Circle& operator=(Circle& p)//��ֵ���������
{
    if(height!=nullptr){delete height; height=nullptr;}
    height=new int(*p.height);
    return *this;
}
�����ܽ᣺���������ڶ������٣�һ��Ҫ�Լ��ṩ�����������������캯������ֵ��������أ��������ǳ��������
��ʼ���б���ʼ����Ա����
�﷨ ���캯��():����1(ֵ1),����2(ֵ2){}
�������Ϊ���Ա������ʱ���ȹ������Ա���ٹ�����������ʱ�������������������Ա
��̬��Ա����Ա�������Ա�������Ϲؼ���static
��̬��Ա������1.���ж�����һ������2.����׶η����ڴ�3.���������������ʼ�� ���ʷ�ʽ��1.ͨ��������ʣ�Circle p;p.m_A��2.����ͨ���������з���Circle::m_A
��̬��Ա������1.���г�Ա����һ������2.��̬��Ա����֮���ܷ��ʾ�̬��Ա���� ���ʷ�ʽ��1.ͨ��������ʣ�2.����ͨ���������з���
��Ա���� �� ��Ա�����Ƿֿ������
thisָ��ָ�򱻵��õĳ�Ա���������Ķ���return *this��ҪӦ���ڳ�Ա��������ʽ��̣�thisָ�뱾���Ͼ���ָ�볣���������޸�ָ��ĵ�ַ�����ǿ����޸�ָ���ַ��ֵ
��ָ����ʳ�Ա������ע���Ա�����Ƿ�ʹ��thisָ��
const���γ�Ա����==�������� void asd()const{this->age=100;}//�����޸�age  
1.�������ڲ����޸ĳ�Ա����  ���const��ʱthisָ����˶���const��ָ���ַ�͵�ַ��ֵ�Բ����޸�
2.����ʱ��mutable�ؼ��ֺ󣬾Ϳ����ڳ��������޸ĳ�Ա mutable int age;//�����ڳ��������޸�age
������ const Circle p;
1.��������ǰ��const�Ƹö���Ϊ������
2.������ֻ�ܵ��ó�����
��Ԫ��
1.ȫ�ֺ�������Ԫ ���Է�������˽�г�Ա����
2.������Ԫ  friend class x;
3.���г�Ա��������Ԫ  friend void x::visit();//ʹ��2��3ʱ��Ա������Ҫ���ⶨ��
��������أ������е���������¶��壬������һ�ֹ��ܣ�����Ӧ��ͬ���������ͣ�����������ȫ�ֺ�����������о����ԣ�
1.�Ӻ����� 
ͨ����Ա��������+��
Circle operator+(Circle &p)
Circle p3=p1.operator+(p2)->��Ϊp3=p1+p2;
ͨ��ȫ�ֺ�������+��
Circle operator+(Circle &p1,Circle& p2)
Circle p3=operator+(p1,p2)->��Ϊp3=p1+p2;
2.��������
ֻ��ȫ�ֺ�������
ostream& operator<<(ostream& os,Circle& p);//û��&��ֻ��Զ������һ�Σ�����ʽ����ʱ�Ķ���Ͳ��Ǹö�����
3.��������
ǰ�õ���
cir& operator++()
    {
        num++;
        return *this;
    }
���õ���
cir_proxy cir::operator++(int)
{
    cir_proxy temp(*this);//cir���͵���cir_proxy���캯����ʼ��cir_proxy
    num++;
    return temp;
}

cir_proxy cir_proxy::operator++(int)
{
    cir_proxy temp(*this);//cir_proxy�������ŷ���ʼ��cir_proxy
    ref_.num++;
    return temp;
}
4.��ֵ����
Circle& operator=(Circle& p)//��ֵ��������أ��������
{
    if(height!=nullptr){delete height; height=nullptr;}
    height=new int(*p.height);
    return *this;
}
5.��ϵ����
bool operator==(pp& p)
    {
        if (m_name == p.m_name && m_age == p.m_age)
            return true;
        else
            return false;
    }
6.�������������()����
�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º�������ǳ���û�й̶�д��
�����
void operator()(string test)
{
    cout << test << endl;
}
Myprint x;
x("hello world");
�ӷ���
int operator()(int num1,int num2)
{
    retrun num1+num2;
}
Myadd x;
int a = x(10,20);
cout << Myadd()(10,20);//������������

�̳�  �¼����Ա����ӵ����һ���Ĺ��ԣ������Լ������ԣ�����ʹ�ü̳м����������ظ�����
�����﷨
class Java :public Base{};
class ���ࣺ�̳з�ʽ ����
����Ҳ�������� 1.�̳��ڻ��࣬����Ϊ����2.�Լ����ӵĳ�Ա������Ϊ����
����Ҳ�ƻ���
�������������ࣺclass A{public:int a;protected:int b;private:int c;};
1.�����̳� public:int a; protected: int b; ���ɷ���:int c;
2.�����̳� protected:int a; protected: int b; ���ɷ���:int c;
3.˽�м̳� private:int a; private: int b; ���ɷ���:int c;
�̳��еĶ���ģ��
���˾�̬��Ա����/�����������Ķ���̳е����ࣨ����˽�г�Ա�� ���ù��߲鿴��ṹ��1.F: ;2.cd ����·�� ;3.cl / dl reportSingleClassLayout���� Դ�ļ�
�̳��й���������ĵ���˳��
�ȹ��츸�࣬�ٹ�������ٹ�������
���������࣬��������������������
ͬ����Ա����
��������඼��ͬ����Ա����ma������ma=1������ma=2
son s;
cout<<s.ma<<endl;//���2
cout<<s.base::ma<<endl;//���1
��������඼��ͬ����Ա����func()
s.func();//�������
s.base::func();//�������
ͬ����̬��Ա�����������������ⶨ��
1.ͨ���������
s.ma
s.base::ma
2.ͨ����������
son::ma
son::base::ma//��һ��::����ͨ�������ķ�ʽ���ʣ��ڶ���::������ʸ�����������
��̳��﷨
class ���ࣺ�̳з�ʽ ����1���̳з�ʽ������2...//ʵ�ʿ����в�����ʹ��
���μ̳У�
������̳� ������μ̳�����
����ࣨVirtual Base Class����C++�����ڽ�����ؼ̳�ʱ���ܳ��ֵĶ����Ժ����������һ�ֻ��ơ���һ��������Ӷ������̳У�����Щ��������һ����ͬ�Ļ���ʱ����������ȷ�������ͬ��������������ֻ��һ��ʵ��
�̳�֮ǰ ���Ϲؼ��� virtual ��Ϊ��̳� vbptr ��ָ������ָ�루Virtual Base Table Pointer�� vbtable
class animal{}; 
class sheep :virtual public animal{};
class tuo :virtual public animal{};
class sheeptuo :public sheep,public tuo{};

��̬:
1.��̬��̬���������ء�������������ھ�̬��̬
2.��̬��̬����������麯��ʵ������ʱ��̬ ��������1.�м̳й�ϵ 2.������д������麯������д�����������ĺ�����ȫһ�£�   ʹ�������������ָ���������ָ���������
�������𣺾�̬��̬�ĺ�����ַ���-����׶�ȷ�Ϻ�����ַ����̬��̬�ĺ�����ַ���-���н׶�ȷ�Ϻ�����ַ
�麯����vfptr�麯����ָ�� vftable
�ܽ᣺��������д������麯��ʱ���Ḳ�Ǹ����е��麯��
���麯����virtual ����ֵ���� �������������б�=0; ���������˴��麯�������Ϊ������
�������ص㣺
1.�޷�ʵ��������
2.���������д�������еĴ��麯��������Ҳ���ڳ�����
�������ʹ����������ԣ�     �﷨��virtual ~����(){}        virtual ~����(){}=0 
1.�������ָ���ͷ��������
2.��Ҫ����ʵ�ֵĺ��� ����������������ʵ����ã�
3.����Ǵ���������������ڳ����࣬�޷�ʵ��������

�̳е����ã�ͨ���̳У��������ʹ�ø�������з�˽�г�Ա�����ҿ�������µĳ�Ա����д����ķ�����
��̬�����ã���̬��ָͬһ�������򷽷��ڲ�ͬ�������в�ͬ��ʵ�֡�
�̳кͶ�̬�Ĺ�ϵ
�̳���ʵ�ֶ�̬�Ļ�����ֻ���ڴ��ڼ̳й�ϵ������£�����ʵ�ֶ�̬��������˵����̬����������������
1.�̳й�ϵ��������һ�������һ�����������ࡣ
2.�麯���������еķ�����������Ϊ�麯����virtual����
3.����ָ������ã�ͨ�������ָ������õ���������ķ�����
class Base {
public:
    virtual void show() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class" << endl;
    }
};

void display(Base* obj) {//ͨ�������ָ������õ���������
    obj->show(); // ��̬���࣬���ݶ����ʵ�����͵�����Ӧ�ĺ���
}

int main() {
    Base b;
    Derived d;
    display(&b); // ���: Base class
    display(&d); // ���: Derived class
    return 0;
}


�ļ��򿪷�ʽ��
ios::in         ��
ios::out        д
ios::ate        ��ʼλ�ã��ļ�ĩβ
ios::app        ׷�ӷ�ʽд�ļ�
ios::trunc      ɾ��Դ�ļ����ڴ���
ios:binary      �����Ʒ�ʽ

���ͱ�̣���Ҫ����Ϊģ�壬ģ���Ŀ������߸����ԣ������Ͳ�����
һ.����ģ�壺
����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ�����ָ������һ���������ʹ���
�﷨��template<typename T>
����
template:��������ģ��
typename:���������ķ�����һ���������ͣ�������class����
T:ͨ���������ͣ�ͨ��Ϊ��д��ĸ
���Զ������Ƶ���myswap(a,b)
����ʽָ�����ͣ�myswap<int>(a,b)
����ģ��ע�����
���Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
��ģ�����ȷ����T���������ͣ��ſ���ʹ��

��ͨ�����뺯��ģ�������
1.��ͨ�������ÿ��Է�����ʽ����ת��
2.����ģ�� ���Զ������Ƶ� �����Է�����ʽ����ת�� myadd(a,b);//����û�з�����ʽת��
3.����ģ�� ����ʾָ������ ���Է�����ʽ����ת�� myadd<int>(a,b);//��ȷ����������ʽת��int a, char b
��ͨ�����뺯��ģ��ĵ��ù���
1.������߶���ʵ�֣����ȵ�����ͨ����
2.����ͨ����ģ������б�ǿ�Ƶ��ú���ģ��  myadd<>(a,b);//��ģ��
3.����ģ��Ҳ���Է�������
4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��//������������Ϊchar�ͣ���ͨ�����β���int�ͣ���ʱ�����ȵ��ú���ģ��

��.��ģ��
����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ�����ָ������һ���������ʹ���
�﷨��template<class nametype,class agetype>
��
����ʽָ�����ͣ�Person<string,int> p1("qwe",999);
��ģ��û���Զ��Ƶ�ʹ�÷�ʽ
��ģ����ģ������б��п�����Ĭ�ϲ���template<class nametype=string, class agetype=int> ��������ppp <>x(15, "erw");�Ͳ���Ҫд���ͽ�ȥ
��ģ��ĳ�Ա����ֻ���ڵ���ʱ�Ŵ�������Ϊû��ȷ�����ͣ�
*/


/*
��̬��
//��ͨд��
class Calculator
{
public:

    int getresult(string oper)
    {
        if (oper == "+")
            return num1 + num2;
        else if (oper == "-")
            return num1 - num2;
        else if (oper == "*")
            return num1 * num2;
    }

    int num1;
    int num2;
};

void test1()
{
    Calculator c;
    c.num1 = 2;
    c.num2 = 3;
    cout << c.num1 << "+" << c.num2 << "=" << c.getresult("+") << endl;
}

//��̬ʵ�ּ�����
//��̬�ô���
// 1.��֯�ṹ����
// 2.�ɶ���ǿ
// 3.����ǰ�ںͺ�����չ�Լ�ά���Ը�
//ʵ�ּ�����������
class Abstractcalculator
{
public:

    virtual int getresult()
    {
        return 0;
    }

    int num1;
    int num2;
};

//�ӷ���������
class addcalculator :public Abstractcalculator
{
public:

    virtual int getresult()
    {
        return num1 + num2;
    }
};

//������������
class subcalculator :public Abstractcalculator
{
public:

    virtual int getresult()
    {
        return num1 - num2;
    }
};

//�˷���������
class mulcalculator :public Abstractcalculator
{
public:

    virtual int getresult()
    {
        return num1 * num2;
    }
};

void test2()
{
    //��̬ʹ������
    //����ָ�������ָ���������

    //�ӷ�����
    Abstractcalculator* abc = new addcalculator;
    abc->num1 = 12;
    abc->num2 = 23;
    cout << abc->getresult() << endl;
    //�����ǵ�����
    delete abc;

    //��������
abc = new subcalculator;
abc->num1 = 12;
abc->num2 = 23;
cout << abc->getresult() << endl;
delete abc;

//�˷�����
abc = new mulcalculator;
abc->num1 = 12;
abc->num2 = 23;
cout << abc->getresult() << endl;
delete abc;

}

class drink//ʹ�ö�̬ʱ�������൱��ģ��
{
public:
    //virtual void boil() = 0;
    virtual void boil()
    {
        cout << "��ˮ" << endl;
    }
    virtual void brew() = 0;
    virtual void putcup() = 0;
    virtual void putcamel() = 0;
    void makedrink()
    {
        boil();
        brew();
        putcup();
        putcamel();
    }
};

class coffee :public drink
{
public:
    void boil()
    {
        cout << "��ʥˮ" << endl;
    }
    virtual void brew()
    {
        cout << "���ݿ���" << endl;
    }
    virtual void putcup()
    {
        cout << "���뱭��" << endl;
    }
    virtual void putcamel()
    {
        cout << "����ţ�̺���" << endl;
    }
};

class tea :public drink
{
public:
    virtual void boil()
    {
        cout << "��ˮ" << endl;
    }
    virtual void brew()
    {
        cout << "���ݲ�Ҷ" << endl;
    }
    virtual void putcup()
    {
        cout << "���뱭��" << endl;
    }
    virtual void putcamel()
    {
        cout << "�������" << endl;
    }
};

void dowork(drink* abs)
{
    abs->makedrink();
    delete abs;//�ͷ�
}

void test1()
{
    //��������
    dowork(new coffee);
    cout << endl;
    dowork(new tea);
    coffee x;
    x.drink::boil();
}

*/

/*
class CPU
{
public:
    virtual void caculate1() = 0;
};

class GPU
{
public:
    virtual void caculate2() = 0;
};

class neicun
{
public:
    virtual void caculate3() = 0;
};

class computer
{
public:
    computer( CPU* x, GPU* y, neicun* z):c(x),g(y),n(z){}
    void computerWork()
    {
        c->caculate1();
        g->caculate2();
        n->caculate3();
    }
    virtual ~computer()//�ͷ�������������ڴ�
    {
        if (c != nullptr)
        {
            delete c;
            c = nullptr;
        }

        if (g != nullptr)
        {
            delete g;
            g = nullptr;
        }

        if (n != nullptr)
        {
            delete n;
            n = nullptr;
        }
    }
private:
    CPU* c;
    GPU* g;
    neicun* n;
};

class intelcpu :public CPU
{
public:
    virtual void caculate1()
    {
        cout << "intel CPU ������" << endl;
    }
};
class intelgpu :public GPU
{
public:
    virtual void caculate2()
    {
        cout << "intel GPU ������" << endl;
    }
};
class intelneicun :public neicun
{
public:
    virtual void caculate3()
    {
        cout << "intel �ڴ� ������" << endl;
    }
};

class weixingcpu :public CPU
{
public:
    virtual void caculate1()
    {
        cout << "weixing CPU ������" << endl;
    }
};
class weixinggpu :public GPU
{
public:
    virtual void caculate2()
    {
        cout << "weixing GPU ������" << endl;
    }
};
class weixingneicun :public neicun
{
public:
    virtual void caculate3()
    {
        cout << "weixing �ڴ� ������" << endl;
    }
};

void test1()
{
    CPU* inte = new weixingcpu;
    GPU* gp = new weixinggpu;
    neicun* nei = new weixingneicun;
    computer p1(inte, gp, nei);
    p1.computerWork();
    cout << endl;
    computer p2(new intelcpu, new weixinggpu, new intelneicun);
    p2.computerWork();
    //delete inte, gp, nei;//��һ���ͷŷ�ʽ
}

void test2()
{
    CPU* inte = new intelcpu;
    GPU* gp = new weixinggpu;
    neicun* nei = new intelneicun;
    computer p1(inte, gp, nei);
    p1.computerWork();
    //delete inte, gp, nei;
}

void test3()
{
    CPU* inte = new intelcpu;
    GPU* gp = new intelgpu;
    neicun* nei = new intelneicun;
    computer p1(inte, gp, nei);
    p1.computerWork();
    //delete inte, gp, nei;
}

int main()
{
    const char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };
    const char** cp[] = { c + 3, c + 2, c + 1, c };
    const char*** cpp = cp;
    printf("%s", **++cpp);
    printf("%s", *-- * ++cpp + 3);
    printf("%s", *cpp[-2] + 3);
    printf("%s\n", cpp[-1][-1] + 1);

    return 0;
}
*/