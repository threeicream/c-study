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

	this->setWindowTitle("计算器");

	QFont f("仿宋", 20);//字体对象
	ui.mainLineEdit->setFont(f);

	//按钮上放图片
	QIcon con("D:\\Vs\\project\\calculator\\tt.png");
	ui.delButton->setIcon(con);

	//改变按钮背景色
	ui.equalButton->setStyleSheet("background:green;color:white");

信号与槽连接方式：
信号与信号相连；
同一信号与多个槽相连；
一个槽相应多个信号；
信号与槽机制的优点：类型安全；松散耦合；一个类要支持信号与槽，必须从QObject、和它的子类继承
信号与槽机制的效率：会比直接调用非虚函数运行速度慢10倍（多线程信号可能要排队；编组/结组传递的参数；遍历all关联；需要定位接收
信号的对象）


QObject定时器：startTimer killTimer 这两个是事件函数，不需要信号与槽机制；重写timerEvent函数，当定时器超时后，自动调用timerEvent
QTImer定时器：start函数启动定时器，发出timeout信号，需要信号与槽机制；stop函数结束

文件读写保存：
getOpenFileName：读取跳转窗口
getSaveFileName：写入跳转窗口
流程跟c++一样，创建文件对象，打开文件，读取/写入文件，关闭文件

事件：QEvent类
键盘事件（快捷键）：按键按下松开 keyPressEvent虚函数（重写）
鼠标事件：鼠标移动，鼠标按键的按下和松开 mousePressEvent虚函数
拖放事件：用鼠标进行拖放
滚轮事件：鼠标滚轮滚动
绘屏事件：重绘屏幕的某些部分
定时事件：定时器到时
焦点事件：键盘焦点移动
进入和离开事件:鼠标移入widget之内，或是移出
移动事件：widget的位置改变
大小改变事件 ：widget的大小改变
显示和隐藏事件：widget显示和隐藏
窗口事件：窗口是否为当前窗口

TCP连接：
1.需要ip地址和端口号
2.创建socket对象
3.连接服务器完事（弹出连接成功和连接异常弹窗）

QMessageBox5种用法：
1. 信息框 (information)
用于显示普通的消息或通知。
QMessageBox::information(this, "Information", "This is an information message.");
2. 警告框 (warning)
用于显示警告信息，提示用户某个操作可能会有风险。
QMessageBox::warning(this, "Warning", "This is a warning message.");
3. 错误框 (critical)
用于显示错误或严重问题的信息。
QMessageBox::critical(this, "Error", "An error has occurred.");
4. 问题框 (question)
用于向用户提出一个问题，并提供多个按钮让用户选择。
QMessageBox::StandardButton reply;
reply = QMessageBox::question(this, "Question", "Are you sure?",
							  QMessageBox::Yes | QMessageBox::No);
if (reply == QMessageBox::Yes) {
	qDebug() << "Yes was clicked";
} else {
	qDebug() << "No was clicked";
}
5. 自定义消息框 (custom)
允许你根据需要自定义消息框的按钮和行为。
QMessageBox msgBox;
msgBox.setWindowTitle("Custom Message Box");
msgBox.setText("This is a custom message.");
msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
msgBox.setDefaultButton(QMessageBox::Ok);//默认enter按键的位置
msgBox.setEscapeButton(QMessageBox::Cancel);//默认esc按键的位置
int ret = msgBox.exec();

switch (ret) {
case QMessageBox::Ok:
	qDebug() << "OK clicked";
	break;
case QMessageBox::Cancel:
	qDebug() << "Cancel clicked";
	break;
}

Qt中的算法：
<QtAlgorithms><QtGlobal>
qAbs();//绝对值
qMax();//两个中最大值
qRound();//四舍五入取整

控件：
QListView、QPlanTextEdit、OpenGlWidget、QGraphicView
QLabel、QPushButton、QLineEdit
QTextEdit、QCheckBox、QRadioBUtton
QComboBox、QListWidget、QTableWidget
QCalendarWidget、QSpinBox、QDoubleSpinBox
QSlider、DateEdit、DateTimeEdit、Dial

QRegExp类为正则表达式，由表达式、量词、断言组成
可以实现：有效性检查、查找、替换、字符串分割
元字符：
.匹配任意单个字符
^匹配字符串首
$匹配字符串尾
[]匹配括号内输入的任意字符
*匹配任意数量的前导字符
+匹配至少一个前导字符
？匹配一个前导字符或为空
*/
