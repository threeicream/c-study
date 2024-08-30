#include"test.h"

typedef string::size_type sz;
using namespace std;//һ���Ͱ�����usingȫ��Ч��

int xyz()
{
	static int a = -1;
	return ++a;
}

void diaohuan(int* i, int* j)
{
	int a;
	a = *i;
	*i = *j;
	*j = a;
}

void diaohuan_1(int &i, int &j)
{
	int a;
	a = i;
	i = j;
	j = a;
}

size_t find_char(const string& a, char b, size_t& c)
{
	auto ret = a.size();
	c = 0;
	for (decltype(ret)i = 0; i != a.size(); i++)
	{
		if (a[i] == b)
		{
			if (ret == a.size())
				ret = i;
			++c;
		}
	}
	return ret;
}

int daxie(const string& a)
{
	for (auto i = a.begin(); i != a.end(); i++)
		if (isupper(*i))
		{
			return 1;
		}
	return 0;
}

void bianxiaoxie(string& a)
{
	for (auto i = a.begin(); i != a.end(); i++)
		*i = tolower(*i);
}

int daxiao(int a, int* b)
{
	if (a > *b)
		return a;
	else
		return *b;
}

void jiaohuan_zhizhen(int*& a, int*& b)
{
	int *i = a;
	a = b;
	b = i;
}

void print(int(&a)[2])
{
	for (auto b : a)
		cout << b << endl;
}

void msg(initializer_list<string> a)
{
	for (auto x = a.begin(); x != a.end(); ++x)
		cout << *x << endl;
}

int sum_int(initializer_list<int> a)
{
	int i = 0;
	for (auto x = a.begin(); x != a.end(); ++x)
		i += *x;
	return i;
}

char &get_val(string& str, rsize_t ix)//���&���Ŵ����ص�������char &�����������ͣ������޸ĵ�
{
	return str[ix];
}

bool str_subrange(const string& str1, const string& str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(size)i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return i;
	}
}

void fac(vector<int>x,unsigned y)
{
	unsigned vz = x.size();
	if (!x.empty() && y < vz)
	{
		cout << x[y] << endl;
		fac(x, y + 1);
	}
}

string(&funct())[10]
{
		string a[10] = { "f"};
		return a;
}

using act = string[10];
act& funct_1(int i)
{
	string a[10] = { "f" };
	return a;
}

auto funct_2(int i) -> string(&)[10]
	{
		string a[10] = { "f" };
		return a;
	}

string biemingtest[10] = { "f" };
decltype(biemingtest)& funct_3(int i)
{
	string a[10] = { "f" };
	return a;
}

string make_plural(size_t ctr, const string& word, const string& ending)
{
	return (ctr > 1) ? word + ending : word;
}

void factorial(vector<int>x,unsigned index)
{
	unsigned i = x.size();
	if (!x.empty() && index != i)
	{
		cout << x[index] << endl;
		factorial(x, ++index);
	}
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mult(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

// ���ඨ��֮�ⶨ�� move ����
screen& screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

//clear
void windows_ctr::clear(screenindex i)
{
	screen& s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

windows_ctr::screenindex windows_ctr::addscreen(const screen&s)
{
	screens.push_back(s);
	return screens.size() - 1;

}

screen::pos screen::size_t() const
{
	return height * width;
}

istream& f(istream& in)
{
	string v;
	while (in >> v) {  // ֱ�������ļ���������ֹͣ��ȡ !v.eof()
		if (in.bad())
			throw runtime_error("IO������");
		if (in.fail()) {
			cerr << "���ݴ��������ԣ�" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << ' ';
	}
	cout << endl;
	in.clear();
	return in;
}

void forwardlist(forward_list<string>& x, const string i, const string j)
{
	int flag = 0;
	auto b = x.begin();
	auto a = x.before_begin();
	for (; b != x.end(); ++a)
	{
		if (*b == i)
		{
			b = x.insert_after(b, j);
			flag = 1;
		}
		else
			++b;
	}
	if (b == x.end() && flag == 0)
		x.insert_after(a, j);
}

void ins(string& s, const string& oldval, const string& newval)
{
	auto a = s.begin();
	auto b = oldval.begin();
	while (a != s.end())
	{
		if (*a == *b)
		{
			++a;
			++b;
			if (b == oldval.end())
			{
				/*a = s.erase(a - oldval.size(), a);
				a = s.insert(a, newval.begin(), newval.end());*/
				auto pos = distance(s.begin(), a - oldval.size());
				s.replace(pos, oldval.size(), newval);
				a = s.begin() + pos + newval.size();
				//a += newval.size();
				b = oldval.begin();
			}
		}
		else
		{
			b = oldval.begin();
			++a;
		}

	}
}

void replace_string(string& s, const string& oldVal, const string& newVal)
{
	auto l = oldVal.size();
	if (!l)
		// Ҫ���ҵ��ַ���Ϊ�� 
		return;
	auto iter = s.begin();
	while (iter <= s.end() - l) {   // ĩβ����oldVal���ȵĲ��������� 
		auto iter1 = iter;
		auto iter2 = oldVal.begin();
		// s��iter��ʼ���Ӵ�����ÿ���ַ�����oldVal��ͬ 
		while (iter2 != oldVal.end() && *iter1 == *iter2) {
			iter1++;
			iter2++;
		}
		if (iter2 == oldVal.end()) {     // oldVal�ľ������ַ������ 
			iter = s.erase(iter, iter1);   // ɾ��s����oldVal��Ȳ��� 
			if (newVal.size()) {           // �滻�Ӵ��Ƿ�Ϊ�� 
				iter2 = newVal.end();        // �ɺ���ǰ�������newVal�е��ַ� 
				do {
					iter2--;
					iter = s.insert(iter, *iter2);
				} while (iter2 > newVal.begin());
			}
			iter += newVal.size();        // �������ƶ����²�������֮�� 
		}
		else iter++;
	}
}

void replace1_string(string& s, const string& oldVal, const string& newVal)
{
	int p = 0;
	while ((p = s.find(oldVal, p)) != string::npos)// ��s�в���oldVal��string::npos ��һ����������ʾ���ַ���������û���ҵ�ƥ�������ֵͨ���� -1������ std::string �ж���Ϊһ���޷������������ֵ��std::string::size_type �����ֵ����
	{
		s.replace(p, oldVal.size(), newVal);// ���ҵ����Ӵ��滻ΪnewVal������ 
		p += newVal.size();// �±�������²�������֮�� 
	}
}

string inis(string& s, const string& n, const string& o)
{
	string i = s;
	string j;
	s = s.append(o);
	s.insert(s.begin(), n.begin(), n.end());
	j = s;
	s = i;
	return j;
}

string name_string(string& s, const string& n, const string& o)
{
	string i = s;
	string j;
	s.insert(0, " ");
	s.insert(0, n);
	s.insert(s.size(), " ");
	s.insert(s.size(), o);
	j = s;
	s = i;
	return j;
}

void find_string1(string& s, const string& chars)
{
	cout << "��" << s << "�в���" << chars << "���ַ�" << endl;
	string::size_type pos = 0;
	while ((pos = s.find_first_of(chars, pos)) !=
		string::npos)
	{  // �ҵ��ַ� 
		cout << "pos: " << pos+1 << ", char: " << s[pos] << endl;
		pos++;
		// �ƶ�����һ�ַ� 
	}
}

void find_string2(string& s, const string& chars)
{
	cout << "��" << s << "�в��ҳ�" << chars << "֮��������ַ�" << endl;
	string::size_type pos = 0;
	while ((pos = s.find_first_not_of(chars, pos)) != string::npos)
	{  // �ҵ��ַ� 
		cout << "pos: " << pos+1 << ", char: " << s[pos] << endl;
		pos++;
		// �ƶ�����һ�ַ� 
	}
}

vector<string> nn(istream& in, const string& shang, const string& xia)
{
	string s;
	string t = shang + xia;
	string::size_type pos = 0;
	vector<string>xy;
	while (in >> s)
	{
		if ((pos = s.find_first_of(t)) == string::npos)
		{
			xy.push_back(s);
		}
	}
	return xy;
}

bool five_or_more(const string& s1, string::size_type sz)
{
	return s1.size() >= sz;
}

bool isshorter1(const string& a, const string& b)
{
	return a.size() >= b.size();
}

void oneis_twoos(istream& is, ostream& os1, ostream& os2)
{
	istream_iterator<int> in(is), eof;
	vector<int>yuan(in, eof);
	ostream_iterator<int> out1(os1, " ");
	ostream_iterator<int> out2(os2, "\n");
	copy_if(yuan.begin(), yuan.end(), out1, [](int n) {if (n % 2 == 0 )return true; return false; });
	copy_if(yuan.begin(), yuan.end(), out2, [](int n) {if (!(n % 2 == 0))return true; return false; });
}

void add_family(map<string, vector<string>>& families, const string& family)
{
	/*if (families.find(family) == families.end())
		families[family] = vector<string>();*///vector<string>()�൱�ڴ���һ���ռ�
	families[family];//�����family����ֻ�ǵ��ã����û�У�ֱ�Ӵ���
}

void add_child(map<string, vector<string>>& families, const string& family, const string& child)
{
	families[family].push_back(child);//families[family] ���ص���һ�� vector<string> �����ã������ʹ��ʱ������ vector<string> һ�����������磬���Ե��� push_back��size��empty �� vector �ĳ�Ա������
}