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
信号与槽函数存在重载时，需要使用qoverload进行指定：
QOverload<int>::of(&QSpinBox::valueChanged)

signals：自定义信号，返回值为void，只需要声明，不需要定义，可以有参数，重载
如何自定义信号与槽：
在类中写signals，在signals下定义信号函数，然后在public定义槽函数，最后在private定义信号触发函数，记得写connect
自定义信号遇到重载：
需要使用函数指针确认使用哪个函数例如：
hungry();
hungry(QString s);//我要使用第二个函数
void(teacher:: *teachersignals)(QString)=&teacher::hungry;

qt中使用lambda：
connect(ui.clearButton, &QPushButton::clicked, this, [=]() {this->qsml->removeRows(0, this->qsml->rowCount()); });
可以让信号函数对应多个槽函数

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
QListView（数据列表）、QPlanTextEdit（文本编辑框，处理大文件）、OpenGlWidget、QGraphicView（显示和编辑图形项）
QLabel、QPushButton、QLineEdit
QTextEdit、QCheckBox、QRadioBUtton
QComboBox（组合控件，可支持下拉选择）、QListWidget、QTableWidget（表格控件）、QTreeWidget
QListView（列表视图/单列）、QTableView（表格视图/多列）、QTreeView（树形视图）
QMenuBar（菜单控件，支持创建菜单和子菜单）、QToolBar（工具栏控件，支持创建常用工具按钮）
QSpinBox（微调框控件，支持数字输入）、QCalendarWidget（日历控件，支持日期选择）、
QCalendarWidget、QSpinBox、QDoubleSpinBox
QSlider、DateEdit、DateTimeEdit、Dial
QtSql

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

常用高级控件：
QWebEngineView（嵌套网页）
StackedWidget、ToolBox、
DociWidget
GraphicsView、LCD Number
OpenGL Widget、QQuickWidget

view和widget的关系：
view是更基础的视图控件，需要使用数据模型来管理和显示数据，更灵活
widget继承自view，不需要手动创建数据模型，可以直接添加Item(项)

UIC（User Interface Compiler）：Qt UIC 工具将 .ui 文件（通过 Qt Designer 创建的界面）转换为 C++ 源代码。
RCC（Resource Compiler）：Qt RCC 工具将 .qrc 资源文件编译成 C++ 代码，使资源能够嵌入到应用程序中。

元对象系统：
Qt 框架中用于支持动态特性（如信号和槽、属性系统和运行时类型信息）的机制。
Qobject类是所有使用元对象系统的类的基类
必须在一个类的开头部分插入宏Q OBJECT，才可以使用元对象系统的特性。当MOC发现类中定义了Q_OBJECT宏时，会为其生成相应的C++源文件
元对象编译器 （ Meta-Object Compiler，  Moc）是一个预处理器，先将Qt的特性程序转换为标准C++程序，在由标准C++编译器进行编译

QObject类：
元对象（meta object）：每个Qobject及其子类的实例都有一个元对象（静态变量 staticMetaObject ）函数metaObject()可以返回它的指针 。
类型信息：QObject的inherits（函数可以判断继承关系。
动态翻译：函数tr（返回一个字符串的翻译版本。
对象树：表示对象间从属关系的树状结构。 Qobject提供了 parent()、 children()、 findChildren（）等函数。对象树中的某个对象被删除时，它的子对象也将被删除
信号和槽：对象间的通信机制。
属性系统：可以使用宏Q_PROPERTY定义属性，QObject的setPropertyO会设置属性的值或定义动态属性；property函数会返回属性的值。

元对象（meta object）：是单独的一个类，包含QObject子类相关的元数据
包含类的附加信息的数据结构
这些信息由元对象编译器（moc）生成，并使某些高级特性得以实现，比如信号与槽机制、属性系统和动态类型信息。
qobject_cast的作用类似于dynamic_cast，但无需RTTI支持

属性系统：
是元对象系统的一部分，允许开发者在对象中定义属性，并在运行时动态地读取和修改这些属性
动态访问属性：可以在运行时通过属性名访问对象的属性，而不需要编译时的类型信息。这对于构建动态UI和数据绑定非常有用。
信号和槽机制：属性系统与信号和槽机制集成，可以在属性值变化时自动发出信号，通知相关对象进行响应。
简化序列化：属性系统使得对象序列化和反序列化更加简便，可以轻松地将对象保存到文件或通过网络传输。

信号与槽：
connect：qOverload<>解决重载；第五个参数分为同一线程和不同线程
disconnect：解除信号连接，有4种
sender()函数：槽函数种使用该函数获得信号发射者的指针
自定义信号：signals里，只需要声明不需要定义

对象树： QMenu* menu = new QMenu(this);创建一个子对象放在对象树中
每个 QObject 可以有一个父对象和多个子对象，通过这种树形结构管理对象的关系和生命周期。
1自动内存管理：当父对象被销毁时，所有子对象也会被自动销毁。这种机制避免了内存泄漏，简化了内存管理。
2层次化管理：对象树使得对象之间的关系直观清晰，便于层次化管理。例如，一个窗口对象可以是多个子控件对象的父对象。
3信号和槽传播：父子关系也可以用于信号和槽机制。信号可以从子对象传播到父对象或更高层次的对象中，简化事件处理。



容器类：
QList<QString>|QStringList
qt种QList就等于vector
顺序：QList QStack QQueue
关联：QMap QMultiMap QHash QMultiHash Qset  map.value(key,默认值)
隐式共享：值传递指向数据的指针，只有当函数写入数据时，数据才会被复制 

QVariant类：
是 Qt 中的一个通用数据类型，它可以存储多种类型的值，包括基本数据类型（如 int、double、bool）、Qt 的核心数据类型（如 QString、QDateTime）以及自定义类型。
QVariant 类提供了一种方便的方法来存储和传递任意类型的数据，而无需显式地声明变量的类型。
通过toT()(例如toString())将QVariant转换为具体的类型
var.toString();|var.value<QString>();

QFlags类：QFlags<Enum>
用于存储枚举值的或运算组合
组合标志：允许组合多个枚举值，使代码更加简洁和易于理解。
按位操作：支持按位与（&）、按位或（|）等操作，方便地对标志进行操作。
类型安全：QFlags 提供了类型安全的方式来处理标志，避免了直接使用整数的缺点
// 定义文件权限的枚举类型
enum FilePermission {
	Read    = 0x01,  // 0001
	Write   = 0x02,  // 0010
	Execute = 0x04   // 0100
};
Q_DECLARE_FLAGS(FilePermissions, FilePermission)
Q_DECLARE_OPERATORS_FOR_FLAGS(FilePermissions)

QRandomGenerator类：
随机数生成器
QRandomGenerator::global()->generate()//已经做好的
fillRange();//生成一组随机数
bounded();//生成指定范围内的随机数


界面组件：
1.widget：object的子类，在其功能基础上增加了GUI的一些功能（图形化）
2.window：可以等于窗口，独立存在的组件，没有嵌入到父组件，主要函数就show() hide() raise() lower()等 3都有

QGroupBox：容器组件，存放其他组件（批量移动）
splitter：分割条

QString用法：
QString("lalal:%1 %2").arg(a).arg(b);//输出：lalal:a,b
s.mid(1,2);//从第1个位置开始，两个字符
s.replace(1,2"abc");//替换
s.section(':', 1, 2);//从一个字符串中获取某部分
int index = str.indexOf("world", 0, Qt::CaseInsensitive);//查找第一次出现的函数 忽略大小写版
lastIndexOf;//查找最后一次出现
contains();//查询是否包含某个字符
startsWith();endsWith();//检查字符串是否以特定的子字符串或字符开始或结束
simplified();//移除字符串开头和结尾的空白字符，并将字符串内部的多余空白字符压缩为一个空格。
trimmed();//仅移除字符串开头和结尾的空白字符，不改变字符串内部的空白字符
QString::number(int n, int base = 10)|//将整数 n 转换为指定进制的字符串。
number(double n, char format = 'g', int precision = 6)//将浮点数 n 转换为字符串，可以指定格式和精度。

autoExclusive 和 flat 属性用于调整 QPushButton 控件的外观和行为
checkable：相当于复选框
autoExclusive：几选1，与checkable配合使用

lineEdit->setAlignment(Qt::Alignleft);//设置格式为左居中
setClearButtonEnabled(true);//lineedit多一个×，可以清空
setReadOnly(true);//字面意思
setEnabled(true);

设置字体颜色
QPalette plet = ui.str1lineEdit->palette();
plet.setColor(QPalette::Text, Qt::red);
ui.str1lineEdit->setPalette(plet);

Qsilder和Qprogressbar：滑动块和进度条 %p%表示百分比显示
datetime、QCalendarWidget：日期时间和日历 格式字符：d为天，M为月，yy为年，h为小时|H表示24进制，m为分钟，s为秒，z为毫秒 toString("yyyy-MM-dd hh:mm:ss")

ui.startButton->setEnabled(false);//设置按钮状态

定时器和计时器
定时器：QTimer
m_timer->start();//开始定时器
&QTimer::timeout//信号函数
m_timer->setTimerType(Qt::PreciseTimer);//设置定时器精度 定时器三种精度：PreciseTimer CoarseTimer VeryCoarseTimer
m_timer->stop();//体制定时器，计时器不需要
QTimer::singleShot("触发时间",Qt::PreciseTimer,this,&timerTest::"槽函数");//单次触发定时器
计时器：QElapsedTimer
m_counter->start();//开始计时器
int tmMsec = m_counter->elapsed();//用于返回从上次调用 start() 或 restart() 以来经过的时间（以毫秒为单位）
设计逻辑：1.确认定时器触发模式（单次多次？），确认定时器精度，触发定时器和计时器，设置按钮状态 2.停止定时器，获得计时器数据 3.connect函数的信号函数为timeout

QComboBox:就是下拉选项
信号函数多了几个：currentIndexChanged(int); currentTextChanged(QString str); 
addItems(QString);//增加选项
addItem(const QString &atext, const QVariant &auserData);//在上面的基础上同时在增加一个索引
setCurrentText(str);//设置当前项

QMainWindow：多了菜单栏
QAction动作编辑器：进行创建QAction，用于表示和管理用户界面行为的类，可以将其与菜单项和工具栏按钮关联（所用信号函数为：triggered()）
信号/槽编辑器：将某些操作串联一起无需手动编写代码
on_textEdit_copyAvailable(bool a);//文本控件中有可复制内容时发出，主要对使用复制粘贴等操作时使用
on_textEdit_selectionChanged();//文本控件中选择内容变化时发出信号，主要对光标选择内容时使用
QTextCursor cursor = ui.textEdit->textCursor//复制光标内容
QTextCharFormat format = ui.textEdit->currentCharFormat();//获取当前文本的格式

toolBar:ui界面中存放action等组件的工具栏（第二行）
statusBar:ui界面中的状态栏（最下面）
通过addAction();和addWidget()添加相应控件


QToolButton:
通过setDefaultAction()函数，可以与Action关联//ui.tBtnListIni->setDefaultAction(ui.actListInit);
通过popupMode属性描述如何弹出菜单
enum ToolButtonPopupMode{DelayedPopup,MenuButtonPopup,InstantPopup}


QListWidget:
void setData(int role, const QVariant &value);
QVariant data(int role) const;

QListWidgetItem* aItem = new QListWidgetItem();//新建一个项指针，从而可以进行相关操作
aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsEditable);//设置项状态
 ui.listWidget->addItem(aItem);//添加一项
delete ui.listWidget->takeItem(row);//移除listwidget的某一行，删除还是要靠delete
ui.listWidget->sortItems(Qt::DescendingOrder);//所有项排序
item->setData(Qt::DisplayRole, "Cell Text"); // 设置显示文本（三个widget都有setdata函数）
item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled); // 设置项的标志
创建右键快捷菜单
on_listWidget_customContextMenuRequested(const QPoint &pos);//发送右键信号
QMenu*menu=new QMenu(this);//创建菜单
ui.listWidget->setContextMenuPolicy(Qt::CustomContextMenu);//设置模式为用户自定义菜单
menu->addAction(ui.actListInit);//添加菜单项
menu->exec(QCursor::pos());//在鼠标光标位置显示
delete menu;

QTreeWidget:分为表头和目录树两部分 
void setData(int column, int role, const QVariant &value);
QVariant data(int column, int role) const;（每一列就代表一个数据）
- 文件夹1 - 文件1（列1：名称，列2：大小，列3：类型） - 文件2（列1：名称，列2：大小，列3：类型） 
- 文件夹2 - 文件3（列1：名称，列2：大小，列3：类型）

ui.treeWidget->setHeaderItem(header);//添加表头header
ui.treeWidget->addTopLevelItem(rootItem);//添加顶层节点
parItem->addChild(item);//添加次级节点
QTreeWidgetItem* item = new QTreeWidgetItem(1000/1001/1002);//设置类型标识符，比如1000为顶层节点，1001为其中一个子项类型
item->setData(colItem, Qt::UserRole, QVariant(filename));//设置项的数据，第一个：列索引（第0列，即第一列） 第二个：UserRole 用于存储用户自定义数据 第三个：实际数据（项的文本内容）
其中：第二个参数可以设置成很多中，比如DisplayRole（显示文本），ToolTipRole（工具提示），DecorationRole（图标设置）等等
配合函数有item->data(colItem, Qt::UserRole);//这个返回的是QVariant类型（只针对UserRole），需要tostring进行转换
item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled); // 设置项的标志

widget删除某一项数据：
if (watched == ui.listSource)
		delete ui.listSource->takeItem(ui.listSource->currentRow()); //ui.listSource->currentItem();不推荐 因为 QListWidget 仍然认为该项存在。
	else if (watched == ui.listWidget)
		delete ui.listWidget->takeItem(ui.listWidget->currentRow());
	else if (watched == ui.treeWidget) {
		QTreeWidgetItem* currentItem = ui.treeWidget->currentItem();
		QTreeWidgetItem* parentItem = currentItem ? currentItem->parent() : nullptr;
		if (currentItem) {
			if (parentItem) {
				parentItem->removeChild(currentItem);
			}
			else {
				int index = ui.treeWidget->indexOfTopLevelItem(currentItem);
				if (index != -1) {
					ui.treeWidget->takeTopLevelItem(index);
				}
			}
			delete currentItem;  // 删除当前项，防止内存泄漏
		}
	}
	else if (watched == ui.tableWidget)
		delete ui.tableWidget->takeItem(ui.tableWidget->currentRow(), ui.tableWidget->currentColumn());// ui.tableWidget->currentItem();



QDockWidget:停靠组件
ui.dockWidget->setVisible(checked);//可见
ui.dockWidget->setFloating(checked);//可浮空

QPixmap:
m_pixmap.load(filename);//从文件中加载图片
ui.labelPic->setPixmap(pix);//设置图片
ui.labelPic->show();//显示图片
ui.actZoomFitH->trigger();//触发信号，运行相关槽函数
ui.actZoomFitH->setEnabled(true);
ui.actZoomFitW->setEnabled(true);
ui.actZoommIn->setEnabled(true);
ui.actZoomOut->setEnabled(true);
ui.actZoomRealSize->setEnabled(true);


QFileDialog:
QFileDialog::getExistingDirectory(this, "选择目录", QDir::currentPath());//让用户选择一个目录（文件夹），并将路径作为 QString 返回
this：表示父窗口，通常传递当前窗口的指针。
"选择目录"：对话框的标题。
QDir::currentPath()：对话框默认打开的路径，设置为程序的当前工作目录。

QFileDialog::getOpenFileNames(nullptr,
		"Select one or more files to open",
		"",
		"All Files (*);;Text Files (*.txt);;Image Files (*.png *.jpg)")//允许用户选择一个或多个文件，并将路径作为 QStringList 返回。
QFileDialog::getOpenFileNames 弹出了一个文件选择对话框。
nullptr 表示没有父窗口。
"Select one or more files to open" 是对话框的标题。
"" 表示初始目录，可以改成你想要的路径。
"All Files (*);;Text Files (*.txt);;Image Files (*.png *.jpg)" 是文件过滤器，可以限定用户只能选择特定类型的文件
void TformDoc::on_actOpen_triggered()
{
	QString curpath = QCoreApplication::applicationDirPath();
	QString filename = QFileDialog::getOpenFileName(this, "打开一个文件", curpath, "所有文件(*.*);;文本文件(*.txt);;图片(*.png *.jpg);;编程文件(*.cpp *.h)");
	if (filename.isEmpty()) {
		QMessageBox::warning(this, "警告", "打开初始文件为空！", QMessageBox::NoButton);
		return;
	}
	QFile afile = filename;
	if (afile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		ui.plainTextEdit->clear();
		QTextStream astream(&afile);
		while (!astream.atEnd()) {
			QString str = astream.readLine();
			ui.plainTextEdit->appendPlainText(str);
		}
		afile.close();
	}
}


QTableWidget:
void setData(int role, const QVariant &value);
QVariant data(int role) const;

QTableWidgetItem *item = new QTableWidgetItem(query.value("姓名").toString(), 1000);//第一个参数是显示文本，第二个参数是类型标识符
query.value("姓名").toString()：设置表格项的显示文本，这里是从数据库查询中获取的"姓名"字段的值。
1000：类型标识符。你可以自定义这个标识符，用于在代码中识别和处理特定类型的表格项。另外两个widget也可以用这个 item->type()
QListWidgetItem *item = new QListWidgetItem("Item Text", 2000);
QTreeWidgetItem *item = new QTreeWidgetItem(3000);//treewidget要考虑不同列的问题，所以不能直接设置显示文本
item->setText(0, "Item Text");

模型/视图结构：
数据：如数据库的一个数据表或SQL查询结果
模型：与数据通信，并为视图组件提供数据接口
视图：屏幕上的界面组件，他从数据模型获得每个数据项的模型索引（model index），通过模型索引获取数据
代理：在视图与模型之间交互操作时提供的临时编辑器，模型向视图提供数据为单向的。当需要在视图上编辑数据时，代理会提供一个编辑器

模型：
所有基于项（item）的模型类都基于QAbstractItemModel（parent是QObject）
模型只是再内存中临时存储数据，数据来源可以是其他类、数据库等

视图组件：
显示数据时，需要调用视图类的setModel()函数
widget的都是便利类，为组件的每个节点或单元格创建一个项（item），用项存储数据、格式设置等，其没有数据模型，将界面与数据绑定
通过 setModel 函数，可以将视图 (view) 和模型 (model) 连接起来，从而使视图与模型的数据保持实时同步。

代理：
比如在table组件中编辑一个单元格数据时，默认使用一个QLineEdit编辑框
QAbstractItemDelegate是其基类

数据模型中存储数据的基本单元都是项（item），每个项都有一个行号，列号，还有父项（父项只有tree model有）
QModelIndex indexA=model->index(0,0,QModelIndex());//行，列，父项
项的角色（role）：在为数据模型的一个项设置数据时，可以赋予其不同项的角色的数据 Qt::DisplayRole  Qt::EditRole Qt::ToolTipRole

QListview:适合与QStringListModel配合使用
QStringListModel：适用于简单的一维字符串列表，操作简单、轻量级。
m_strlist = { "北京","上海","南京" };//stringlist数据
m_model = new QStringListModel(this);//QStringListModel初始化
m_model->setStringList(m_strlist);//数据传输至model
ui.listView->setModel(m_model);//model与view实时关联

QTableview:适合与QStandardItemModel和QItemSelectionModel配合使用
QStandardItemModel：适用于复杂的结构数据，可以处理树形结构、表格数据等。
m_model = new QStandardItemModel(2, 6,this);//基于项的模型类，初始化的同时设置行数列数
m_model->setHorizontalHeaderLabels(header);//初始化表头
m_selection = new QItemSelectionModel(m_model,this);选择模型，用于跟踪视图组建的单元格选择状态
ui.tableView->setModel(m_model);model与view实时关联  主要用于存储和管理数据
ui.tableView->setSelectionModel(m_selection);model与view实时关联  主要用于管理视图中项目的选择状态（需要自定义或扩展选择行为，比如实现多选、范围选择等）
存储数据到model：
aItem = new QStandardItem(tmpList[j]);//存放数据到item
m_model->setItem(i - 1, j, aItem);//在model中设置item

自定义代理：
默认的代理编辑器是QLineEdit编辑框，可以使用其他input部件
QAbstractItemDelegate是基类，推荐使用其子类QStyledItemDelegate类，因为他可以使用当前的样式表设置来绘制组件
使用时必须实现以下函数：
createEditor()：创建用于编辑模型数据的widget组件，如spinBox，combobox
setEditorDate()：从数据模型中获取数据，供widget组件进行编辑
setModelDate()：将widget上的数据更新到数据模型
updateEditGeometry()：用于给widget组件设置一个合适的大小

QModelIndex类：用于指示模型中的一个特定位置。可以将它理解为模型数据的指针。它保存了一个模型中的行号、列号以及父项信息，因此可以精确定位到模型中的任何一个数据项。
bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)
data(const QModelIndex &index, int role = Qt::DisplayRole)


QFileSystemModel和QTreeview
QFileSystemModel:为本机的文件系统提供一个模型，可用于访问本机的文件系统。
它提供了一些接口函数，这些接口函数可以设置显示选项，获取目录或文件信息，以及创建或删除文件夹等。
m_model->setRootPath(QDir::currentPath());//设置一个根目录，一定要有这一段！
ui.treeView->setRootIndex(m_model->index((QDir::currentPath())));//设置为当前目录

m_model->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);//设置模型数据项过滤器
m_model->setNameFilterDisables(!checked);//设置数据项是否可以显示


事件处理：
事件分类
1.自生事件：由窗口系统产生，如QKyeEvent、QMouseEvent 会进入系统队列，等待事件循环的处理
2.发布事件：由Qt应用程序产生，如QTimerEvent 通过QCoreApplication：：psotEvent()产生发布事件，等待事件循环的处理
3.发送事件：由Qt或其他程序定向发送，通过QCoreApplication：：sendEvent()产生发送事件，由对象的event()函数处理
void QtEvent::mousePressEvent(QMouseEvent* event)//鼠标
QPoint pt = event->pos();//相对widget位置
QPointF GlobPt = event->globalPosition();//相对屏幕的绝对位置
ui.labelMove->move(event->pos());//将label移动到指定位置
void QtEvent::keyPressEvent(QKeyEvent* event)//键盘
QPoint pt = ui.pushButton->pos();//按钮此时相对widget位置
ui.pushButton->move(pt.x() - 20, pt.y());//将按钮移动到指定位置

事件与信号：(事件的函数都需要重写）
信号就是对某些事件的封装，例如QpushButton的clicked()信号，就是对QEvent::MouseButtonRelease类型事件的封装
对于一个标签，可以添加一个子类如TMyLabel
signals:
	void DoubleClicked();//为空就行
protected:
	virtual void mouseDoubleClickEvent(QMouseEvent* event){emit DoubleClicked();};//通过事件函数触发信号函数
connect(ui.doubleClikcedLabel, &TMyLabel::DoubleClicked, this, &QtEvent::doubleClicked);//主函数中再通过connect调用
通过事件来发送信号，再给槽函数处理，将事件处理逻辑推到后续，更加灵活容易扩展。

setAttribute(Qt::WA_Hover, true);//它使得一个部件能够接收悬停事件

事件过滤器：可以不需要新增一个类就能实现上述功能
他将一个对象的事件委托给另一个对象来监视并处理
甲方：void Qobject::installEventFilter(Qobject *filterObj) //filterObj 乙方
乙方：[virtual] bool Qobject::eventFilter(Qobject * watched, QEvent * event)//watched监视 event处理

拖放（drag&drop）事件和拖放操作：
void dragEnterEvent(QDragEnterEvent*event)override;//处理drag，获取MIMe数据  这个事件函数在拖动进入目标区域时被触发
void dropEvent(QDropEvent*event)override;//处理drog，使用MIMe数据  这个事件函数在拖动的对象被放下时被触发。
QMimeData用于描述可存储在剪贴板中的信息，并支持通过拖放机制传输；
QMimeData对象将他们所持有的数据与相应的MIME类型相关联，以确保信息可以在应用程序内、应用程序之间安全传输
发送 和 接收 MIME类型数据时，必须类型匹配
tester		getter		setter		MIME Types
has Text()	text()		setText()	text/plain
has Html()	heml()		setHtml()	text/html
has Urls()							text/uri-list
has Image()							image/*
has Color()							application/x-color
event->mimeData()->hasUrls();//确认是否含有urls text/uri-list
QString filename = event->mimeData()->urls()[0].fileName();//获得文件名
QString ex = fileinfo.suffix();//提取后缀

拖放功能的组件
dragDropMode:该属性用于控制视图拖放事件的处理方式 可拖不可放、不可拖可放、可拖可放、不可拖不可放、只准在内部拖放 dragdrop dragonly...
defaultDropAciton:该属性用于控制视图中拖放时，放下的默认操作 复制、移动、链接、忽略 copyaciton moveaciton LinkAction ignoreaciton
注意对于widget和view的组件，如果要统一显示参数，可以创建一个QAbstractItemView* m_item = nullptr;通过m_item进行统一管理

Qt预定义标准对话框：
对话框							常用静态函数名称						函数功能
QFileDialog 文件对话框			QString getOpenFileName()				选择打开一个文件
								QStringList getOpenFileNames()			选择打开多个文件
								QString getSaveFileName()				选择保存一个文件
								QString getExistingDirectory()			选择一个己有的目录 
								QUrl getOpenFileUrl()					选择打开一个文件,可选择远程网络文件
QColorDialog 颜色对话框			QColorDialog getColor(color)			选择颜色
QFontDialog 字体对话框			QFontDialog getFont(&ok, font,this,"选择字体")选择字体 通过返回值ok判断是否执行其他命令
QinputDialog 输入对话框			QString getText()						输入单行文字
								int getlnt()							输入整数
								double getDouble()						输入浮点数 
								QString getltem()						从一个下拉列表框中选择
								QString getMultiLineText()				输入输入多行字符串
QMessageBox消息框				StandardButton information()			信息提示对话框错误信息  
								StandardButton question()				询问并获取是否确认的对话框
								StandardButton waming()					警告信息提示对话框
								StandardButton critical()				提示对话框
								void about() void						设置自定义信息的关于对话框
								aboutQt()								关于Qt的对话框

自定义对话框：直接看CustomizeDialogBox这个项目
设置行数列数TDialogSize：动态创建，模态显示，需要获取返回值，用后删除
设置表头表头标题TDialogHeaders：只创建一次，模态显示，需要获取返回值，用后隐藏
定位单元格并设置文字TDialogLocate：动态创建,非模态指定显示，对话框和主窗口可交互操作，关闭后自动删除
accept槽函数表明接受数据，reject槽函数表明拒绝接收
m_selection->setCurrentIndex(index,QItemSelectionModel::Select);//选择给定的索引  QItemSelectionModel
QDialog才有exec循环函数

嵌入与独立widget
父窗口选择：Qwidget（基类）、Qdialog、Qmainwindow
QSplashScreen：用作应用程序启动时的splash窗口，没有边框
QMdiSubwindow：用于为QMdiArea提供一个子窗体，用于多文档的设计
窗口显示活运行特性的设置函数：
setattribute是一个用于设置窗口属性的函数 Qt::WA_DeleteOnClose当窗口被关闭时，自动删除该窗口对象，从而释放内存
setwindowflag用于设置窗口的标志（window flags），这些标志控制窗口的行为和外观。Qt::FramelessWindowHint：无边框窗口。Qt::WindowStaysOnTopHint：窗口总是位于其他窗口之上。
setwindowstate用于设置窗口的状态，例如最大化、最小化或全屏状态。Qt::WindowNoState：正常状态。Qt::WindowMinimized：最小化状态。Qt::WindowMaximized：最大化状态。Qt::WindowFullScreen：全屏状态。

Doc->setAttribute(Qt::WA_DeleteOnClose);//这个属性的主要作用是：当窗口被关闭时，自动删除该窗口对象，从而释放内存。

MDI应用程序设计
就是多个子窗口，使用setViewMode()函数，两种模式选择：
1.QMdiArea::SubWindowView 传统的子窗口模式
2.QMdiArea::TabbedView 多页的显示模式
QMdiArea有一个信号subWindowActivated(QMdiSubWindow&argl)，在当前活动窗口切换时发射\

Splash窗口移动：
event->globalPosition();//获取相对屏幕左上角的鼠标位置
pos();//获取相对屏幕左上角和相对主窗口左上角之间的位置
获取移动流程：
QPoint eventPos=event->globalPosition(.toPointO):
move(eventPos-m _lastPos);
m lastPos = eventPos - this->pos();
可使用三个事件：
virtual void mousePressEvent(QMouseEvent* event);
virtual void mouseReleaseEvent(QMouseEvent* event);
virtual void mouseMoveEvent(QMouseEvent* event);

创建注册表和读取：
QApplication::setOrganizationName("AXB_QT");//创建一个注册表，也通过这两个读取位置
QApplication::setApplicationName("MDItest");//注册表子目录
加密：
QCryptographicHash hash(QCryptographicHash::Md5);//创建加密对象，使用MD5算法
hash.addData(str.toLocal8Bit());
读取注册表数据：
QSettings settings;
bool saved = settings.value("saved", false).toBool();//如果读取到有saved，就赋值注册表中的，否则为false
m_user = settings.value("username", "qwer").toString();
m_password = encrypt("12346");
写入注册表数据：
QSettings settings;
settings.setValue("username", m_user);
settings.setValue("pswd", m_password);
settings.setValue("saved", ui.saveNameBox->isChecked());

文件系统操作和文件读写
QIODevice为支持读写数据块的设备（如QFile、QBuffer、QTcpSocket）提供了一个通用的实现和一个抽象接口，其不能实例化，可以使用他的接口提供I/O功能
子类：
QCoreApplication：用于提取应用程序路径、名字等文件信息
QFile：打开文件，复制文件，删除文件
QFileInfo：提取文件信息，包括路径，名字，后缀
QDir：提取目录，文件信息，获取一个目录下的文件或目录列表，创建或删除目录或文件，文件重命名(可以等于前两个结合）
QTemporaryDir、QTemporaryFile：用于创建临时目录和临时文件
QFileSystemWatcher：监听目录下文件的添加、删除等变化

文件读写：
QFile类直接读写，或结合QTextStream读写
QFileDialog::getOpenFileName(this, curpath, curpath, filter);//打开文件
QFileDialog::getSaveFileName(this, curpath, curpath, filter);//保存文件
直接读写：
QFile afile(afilename);
afile.open(QIODevice::ReadOnly | QIODevice::Text);
ui.plainTextEditfile->appendPlainText(afile.readAll());//读取文件
afile.close();

QString str = ui.plainTextEditfile->toPlainText();
afile.write(str.toUtf8(), str.toUtf8().length());//写入文件

QSaveFile afile(afilename);//先保存文件到临时文件，避免发生错误，导致源文件损坏
afile.setDirectWriteFallback(false);//使用临时文件
	try{
		QString str = ui.plainTextEditfile->toPlainText();
		afile.write(str.toUtf8(), str.toUtf8().length());
		afile.commit();
	}
	catch (QException& e) {
		QMessageBox::warning(this, "警告", "保存文件异常！");
		afile.cancelWriting();
	}

Stream：
QFile afile(afilename);
afile.open(QIODevice::ReadOnly | QIODevice::Text);
QTextStream aStream(&afile);
	aStream.setAutoDetectUnicode(true);//检测字符类型是否为Unicode
	while (!aStream.atEnd()) {
		QString str = aStream.readLine();
		ui.plainTextEditstream->appendPlainText(str);
	}

afile.setDirectWriteFallback(false);//使用临时文件
	try {
		QTextStream aStream(&afile);
		aStream.setAutoDetectUnicode(true);//检测字符类型是否为Unicode
		QTextDocument *doc = ui.plainTextEditstream->document();
		for (int i = 0; i < doc->blockCount(); ++i) {
			aStream << doc->findBlockByLineNumber(i).text();
			aStream << "\n";
		}
		afile.commit();
	}

文件读写二进制（预定义编码）
QFile和QDataStream类结合使用
字节序：多字节数据在内存中的存储顺序

qtSQL:
常用moduleview
数据库内容：常用QTableView
显示组件：
QSqlQueryModel：通过设置SELECT语句查询获取数据库内容，数据为只读
QSqlTableModel：直接设置一个数据表的名称，可以获取数据表的全部记录，可编辑
QSqlRelationalTableModel：为单张的数据库表提供了一个可编辑的数据模型，支持外键


QDataWidgetMapper:映射数据库数据

数据库
↑
↓
QSqlTableModel←→QDataWidgetMapper←→各个显示组件（lineedit、spinbox、combobox等）
↑
↓
tableview显示


QSqlTableModel相关操作：（见qtSQL）数据库相关的model类都需要设置提交模式（保存数据的方式）
//初始化
QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
QSqlTableModel* tabmodel = nullptr;

DB = QSqlDatabase::addDatabase("QSQLITE");//添加驱动
DB.setDatabaseName(aFile);//设置数据库名称
DB.open()//打开数据库

//创建模型，打开数据库表格，设置表格属性
tabmodel = new QSqlTableModel(this, DB);
tabmodel->setTable("employee");
tabmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);//手动提交模式
tabmodel->setSort(tabmodel->fieldIndex("empNo"), Qt::AscendingOrder);//升序排序

tabmodel->select()//刷新模型  该类不能实时同步数据库的数据，所以需要刷新

//设置标题
tabmodel->setHeaderData(tabmodel->fieldIndex("empNo"), Qt::Horizontal, "工号");

//modelview
ui.tableView->setModel(tabmodel);// 先设置视图的模型
ui.tableView->setColumnHidden(tabmodel->fieldIndex("Memo"), true);//隐藏部分数据

//字段与widget映射
datamapper = new QDataWidgetMapper(this);
datamapper->setModel(tabmodel);
datamapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);//数据提交方式：自动提交
datamapper->addMapping(ui.spinBoxnum, tabmodel->fieldIndex("empNo"));

//获取字段名，并更新combobox
QSqlRecord emptyRec = tabmodel->record();
for (int i = 0; i < emptyRec.count(); ++i) {
	ui.comboBoxsort->addItem(emptyRec.fieldName(i));
}


QSqlQueryModel的使用：（只能读取，不能保存，是table父类）
tabmodel->setQuery("select empNo,Name,Gender,Birthday,Province,Department,""Salary FROM employee ORDER BY empNo");//选择使用的列数据
tabmodel->setQuery(tabmodel->query().executedQuery());//刷新模型
//处理表头
QSqlRecord rec = tabmodel->record();
tabmodel->setHeaderData(rec.indexOf("empNo"), Qt::Horizontal, "工号");

QSqlQuery 语句的使用：
QSqlQuery query;
query.prepare("select Memo,Photo from employee where EmpNo= :ID");//只有 EmpNo 列等于绑定参数 :ID 的记录的 Memo 和 Photo 列的数据会被获取
query.bindValue(":ID",empNo);//将参数 :ID 绑定到一个具体的值 empNo
query.exec();//执行已经准备好的 SQL 查询
*/
 