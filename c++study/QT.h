/*
int main(int argc,char argv[],envp)
argc：表示命令行参数的个数，包含程序名本身。
argv：一个字符指针数组，存储了程序名和命令行传递的每一个参数。
envp：可选的第三个参数，用于获取系统环境变量，支持情况依赖于操作系统。

基础
控件：
1标签：
2按钮：
3行编辑框：
4窗口

QMainWindow:带菜单的界面
QWidget:不带菜单的界面
QDialog:对话框
xxx.ui:ui界面

ui界面介绍
layout：布局
①vertical 垂直
②horizontal 水平
③grid 表格
④form 组合
spacers：垫子？外边距
①horizontal
②vertical
buttons 按键
①push 
②tool
③radio 超链接
④check box 勾选
Item Views：数据库，实现数据显示的分离
Item Widgets：单元控件，文件管理系统会用
Containers：容器，容纳别的控件
input widgets：输入控件
display widgets：显示控件

信号与槽
信号：比如点击按键，输入数据
槽：也就是程序，有信号就触发槽函数
如何建立槽：
1.在对应class类中声明函数(.h文件)
private：slots：
	void on_commitButton_clicked();
	void on_cancelButton_clicked();
2.在.c文件中定义函数
void QtTest2::on_commitButton_clicked()
{
	//获取lineedit数据
	QString program = ui.cmdlineEdit->text();
	//创建process对象，这里是鼠标点击触发确认，是用的向导提供的QProcess函数
	QProcess* myProcess = new QProcess(this);
	myProcess->start(program);
}

void QtTest2::on_cancelButton_clicked()
{
	this->close();
}
3.在class类的构造函数中连接信号与槽 谁发出信号，发出什么信号，谁处理信号，怎么处理信号SIGNAL这些都是宏
	connect(ui.cmdlineEdit,SIGNAL(returnPressed()), this, SLOT(on_commitButton_clicked()));//运行时进行类型检查，容易出错
	ui：是一个指针，指向界面文件
	ui.cmdlineEdit：选择发出信号的控件
	SIGNAL(returnPressed())：选择发出的信号类型，这里是按下回车
	this：对象处理信号
	SLOT(on_commitButton_clicked())：怎么处理信号，相当于点击确认按钮，跳转到上面//创建process对象哪里去

	connect(ui.cancelButton, &QPushButton::clicked, this, &QtTest2::on_cancelButton_clicked);//编译时进行类型检查，更安全高效
	通过取地址的方式处理


	connect(ui.browseButton, &QPushButton::clicked, [this]()
	{
		QMessageBox::information(this, QString::fromUtf8("信息"), QString::fromUtf8("浏览"));
	});
	通过lambda表达式实现
*/
