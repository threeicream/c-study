/*
int main(int argc,char argv[],envp)
argc����ʾ�����в����ĸ�������������������
argv��һ���ַ�ָ�����飬�洢�˳������������д��ݵ�ÿһ��������
envp����ѡ�ĵ��������������ڻ�ȡϵͳ����������֧����������ڲ���ϵͳ��

����
�ؼ���
1��ǩ��
2��ť��
3�б༭��
4����

QMainWindow:���˵��Ľ���
QWidget:�����˵��Ľ���
QDialog:�Ի���
xxx.ui:ui����

ui�������
layout������
��vertical ��ֱ
��horizontal ˮƽ
��grid ���
��form ���
spacers�����ӣ���߾�
��horizontal
��vertical
buttons ����
��push 
��tool
��radio ������
��check box ��ѡ
Item Views�����ݿ⣬ʵ��������ʾ�ķ���
Item Widgets����Ԫ�ؼ����ļ�����ϵͳ����
Containers�����������ɱ�Ŀؼ�
input widgets������ؼ�
display widgets����ʾ�ؼ�

�ź����
�źţ���������������������
�ۣ�Ҳ���ǳ������źžʹ����ۺ���
��ν����ۣ�
1.�ڶ�Ӧclass������������(.h�ļ�)
private��slots��
	void on_commitButton_clicked();
	void on_cancelButton_clicked();
2.��.c�ļ��ж��庯��
void QtTest2::on_commitButton_clicked()
{
	//��ȡlineedit����
	QString program = ui.cmdlineEdit->text();
	//����process�������������������ȷ�ϣ����õ����ṩ��QProcess����
	QProcess* myProcess = new QProcess(this);
	myProcess->start(program);
}

void QtTest2::on_cancelButton_clicked()
{
	this->close();
}
3.��class��Ĺ��캯���������ź���� ˭�����źţ�����ʲô�źţ�˭�����źţ���ô�����ź�SIGNAL��Щ���Ǻ�
	connect(ui.cmdlineEdit,SIGNAL(returnPressed()), this, SLOT(on_commitButton_clicked()));//����ʱ�������ͼ�飬���׳���
	ui����һ��ָ�룬ָ������ļ�
	ui.cmdlineEdit��ѡ�񷢳��źŵĿؼ�
	SIGNAL(returnPressed())��ѡ�񷢳����ź����ͣ������ǰ��»س�
	this���������ź�
	SLOT(on_commitButton_clicked())����ô�����źţ��൱�ڵ��ȷ�ϰ�ť����ת������//����process��������ȥ

	connect(ui.cancelButton, &QPushButton::clicked, this, &QtTest2::on_cancelButton_clicked);//����ʱ�������ͼ�飬����ȫ��Ч
	ͨ��ȡ��ַ�ķ�ʽ����

	connect(ui.browseButton, &QPushButton::clicked, [this]()
	{
		QMessageBox::information(this, QString::fromUtf8("��Ϣ"), QString::fromUtf8("���"));
	});
	ͨ��lambda���ʽʵ��

	this->setWindowTitle("������");

	QFont f("����", 20);//�������
	ui.mainLineEdit->setFont(f);

	//��ť�Ϸ�ͼƬ
	QIcon con("D:\\Vs\\project\\calculator\\tt.png");
	ui.delButton->setIcon(con);

	//�ı䰴ť����ɫ
	ui.equalButton->setStyleSheet("background:green;color:white");

�ź�������ӷ�ʽ��
�ź����ź�������
ͬһ�ź�������������
һ������Ӧ����źţ�
�ź���ۻ��Ƶ��ŵ㣺���Ͱ�ȫ����ɢ��ϣ�һ����Ҫ֧���ź���ۣ������QObject������������̳�
�ź���ۻ��Ƶ�Ч�ʣ����ֱ�ӵ��÷��麯�������ٶ���10�������߳��źſ���Ҫ�Ŷӣ�����/���鴫�ݵĲ���������all��������Ҫ��λ����
�źŵĶ���
�ź���ۺ�����������ʱ����Ҫʹ��qoverload����ָ����
QOverload<int>::of(&QSpinBox::valueChanged)

signals���Զ����źţ�����ֵΪvoid��ֻ��Ҫ����������Ҫ���壬�����в���������
����Զ����ź���ۣ�
������дsignals����signals�¶����źź�����Ȼ����public����ۺ����������private�����źŴ����������ǵ�дconnect
�Զ����ź��������أ�
��Ҫʹ�ú���ָ��ȷ��ʹ���ĸ��������磺
hungry();
hungry(QString s);//��Ҫʹ�õڶ�������
void(teacher:: *teachersignals)(QString)=&teacher::hungry;

qt��ʹ��lambda��
connect(ui.clearButton, &QPushButton::clicked, this, [=]() {this->qsml->removeRows(0, this->qsml->rowCount()); });
�������źź�����Ӧ����ۺ���

QObject��ʱ����startTimer killTimer ���������¼�����������Ҫ�ź���ۻ��ƣ���дtimerEvent����������ʱ����ʱ���Զ�����timerEvent
QTImer��ʱ����start����������ʱ��������timeout�źţ���Ҫ�ź���ۻ��ƣ�stop��������

�ļ���д���棺
getOpenFileName����ȡ��ת����
getSaveFileName��д����ת����
���̸�c++һ���������ļ����󣬴��ļ�����ȡ/д���ļ����ر��ļ�

�¼���QEvent��
�����¼�����ݼ��������������ɿ� keyPressEvent�麯������д��
����¼�������ƶ�����갴���İ��º��ɿ� mousePressEvent�麯��
�Ϸ��¼������������Ϸ�
�����¼��������ֹ���
�����¼����ػ���Ļ��ĳЩ����
��ʱ�¼�����ʱ����ʱ
�����¼������̽����ƶ�
������뿪�¼�:�������widget֮�ڣ������Ƴ�
�ƶ��¼���widget��λ�øı�
��С�ı��¼� ��widget�Ĵ�С�ı�
��ʾ�������¼���widget��ʾ������
�����¼��������Ƿ�Ϊ��ǰ����

TCP���ӣ�
1.��Ҫip��ַ�Ͷ˿ں�
2.����socket����
3.���ӷ��������£��������ӳɹ��������쳣������

QMessageBox5���÷���
1. ��Ϣ�� (information)
������ʾ��ͨ����Ϣ��֪ͨ��
QMessageBox::information(this, "Information", "This is an information message.");
2. ����� (warning)
������ʾ������Ϣ����ʾ�û�ĳ���������ܻ��з��ա�
QMessageBox::warning(this, "Warning", "This is a warning message.");
3. ����� (critical)
������ʾ����������������Ϣ��
QMessageBox::critical(this, "Error", "An error has occurred.");
4. ����� (question)
�������û����һ�����⣬���ṩ�����ť���û�ѡ��
QMessageBox::StandardButton reply;
reply = QMessageBox::question(this, "Question", "Are you sure?",
							  QMessageBox::Yes | QMessageBox::No);
if (reply == QMessageBox::Yes) {
	qDebug() << "Yes was clicked";
} else {
	qDebug() << "No was clicked";
}
5. �Զ�����Ϣ�� (custom)
�����������Ҫ�Զ�����Ϣ��İ�ť����Ϊ��
QMessageBox msgBox;
msgBox.setWindowTitle("Custom Message Box");
msgBox.setText("This is a custom message.");
msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
msgBox.setDefaultButton(QMessageBox::Ok);//Ĭ��enter������λ��
msgBox.setEscapeButton(QMessageBox::Cancel);//Ĭ��esc������λ��
int ret = msgBox.exec();

switch (ret) {
case QMessageBox::Ok:
	qDebug() << "OK clicked";
	break;
case QMessageBox::Cancel:
	qDebug() << "Cancel clicked";
	break;
}

Qt�е��㷨��
<QtAlgorithms><QtGlobal>
qAbs();//����ֵ
qMax();//���������ֵ
qRound();//��������ȡ��

�ؼ���
QListView�������б���QPlanTextEdit���ı��༭�򣬴�����ļ�����OpenGlWidget��QGraphicView����ʾ�ͱ༭ͼ���
QLabel��QPushButton��QLineEdit
QTextEdit��QCheckBox��QRadioBUtton
QComboBox����Ͽؼ�����֧������ѡ�񣩡�QListWidget��QTableWidget�����ؼ�����QTreeWidget
QListView���б���ͼ/���У���QTableView�������ͼ/���У���QTreeView��������ͼ��
QMenuBar���˵��ؼ���֧�ִ����˵����Ӳ˵�����QToolBar���������ؼ���֧�ִ������ù��߰�ť��
QSpinBox��΢����ؼ���֧���������룩��QCalendarWidget�������ؼ���֧������ѡ�񣩡�
QCalendarWidget��QSpinBox��QDoubleSpinBox
QSlider��DateEdit��DateTimeEdit��Dial
QtSql

QRegExp��Ϊ������ʽ���ɱ��ʽ�����ʡ��������
����ʵ�֣���Ч�Լ�顢���ҡ��滻���ַ����ָ�
Ԫ�ַ���
.ƥ�����ⵥ���ַ�
^ƥ���ַ�����
$ƥ���ַ���β
[]ƥ������������������ַ�
*ƥ������������ǰ���ַ�
+ƥ������һ��ǰ���ַ�
��ƥ��һ��ǰ���ַ���Ϊ��

���ø߼��ؼ���
QWebEngineView��Ƕ����ҳ��
StackedWidget��ToolBox��
DociWidget
GraphicsView��LCD Number
OpenGL Widget��QQuickWidget

view��widget�Ĺ�ϵ��
view�Ǹ���������ͼ�ؼ�����Ҫʹ������ģ�����������ʾ���ݣ������
widget�̳���view������Ҫ�ֶ���������ģ�ͣ�����ֱ�����Item(��)

UIC��User Interface Compiler����Qt UIC ���߽� .ui �ļ���ͨ�� Qt Designer �����Ľ��棩ת��Ϊ C++ Դ���롣
RCC��Resource Compiler����Qt RCC ���߽� .qrc ��Դ�ļ������ C++ ���룬ʹ��Դ�ܹ�Ƕ�뵽Ӧ�ó����С�

Ԫ����ϵͳ��
Qt ���������֧�ֶ�̬���ԣ����źźͲۡ�����ϵͳ������ʱ������Ϣ���Ļ��ơ�
Qobject��������ʹ��Ԫ����ϵͳ����Ļ���
������һ����Ŀ�ͷ���ֲ����Q OBJECT���ſ���ʹ��Ԫ����ϵͳ�����ԡ���MOC�������ж�����Q_OBJECT��ʱ����Ϊ��������Ӧ��C++Դ�ļ�
Ԫ��������� �� Meta-Object Compiler��  Moc����һ��Ԥ���������Ƚ�Qt�����Գ���ת��Ϊ��׼C++�������ɱ�׼C++���������б���

QObject�ࣺ
Ԫ����meta object����ÿ��Qobject���������ʵ������һ��Ԫ���󣨾�̬���� staticMetaObject ������metaObject()���Է�������ָ�� ��
������Ϣ��QObject��inherits�����������жϼ̳й�ϵ��
��̬���룺����tr������һ���ַ����ķ���汾��
����������ʾ����������ϵ����״�ṹ�� Qobject�ṩ�� parent()�� children()�� findChildren�����Ⱥ������������е�ĳ������ɾ��ʱ�������Ӷ���Ҳ����ɾ��
�źźͲۣ�������ͨ�Ż��ơ�
����ϵͳ������ʹ�ú�Q_PROPERTY�������ԣ�QObject��setPropertyO���������Ե�ֵ���嶯̬���ԣ�property�����᷵�����Ե�ֵ��

Ԫ����meta object�����ǵ�����һ���࣬����QObject������ص�Ԫ����
������ĸ�����Ϣ�����ݽṹ
��Щ��Ϣ��Ԫ�����������moc�����ɣ���ʹĳЩ�߼����Ե���ʵ�֣������ź���ۻ��ơ�����ϵͳ�Ͷ�̬������Ϣ��
qobject_cast������������dynamic_cast��������RTTI֧��

����ϵͳ��
��Ԫ����ϵͳ��һ���֣����������ڶ����ж������ԣ���������ʱ��̬�ض�ȡ���޸���Щ����
��̬�������ԣ�����������ʱͨ�����������ʶ�������ԣ�������Ҫ����ʱ��������Ϣ������ڹ�����̬UI�����ݰ󶨷ǳ����á�
�źźͲۻ��ƣ�����ϵͳ���źźͲۻ��Ƽ��ɣ�����������ֵ�仯ʱ�Զ������źţ�֪ͨ��ض��������Ӧ��
�����л�������ϵͳʹ�ö������л��ͷ����л����Ӽ�㣬�������ɵؽ����󱣴浽�ļ���ͨ�����紫�䡣

�ź���ۣ�
connect��qOverload<>������أ������������Ϊͬһ�̺߳Ͳ�ͬ�߳�
disconnect������ź����ӣ���4��
sender()�������ۺ�����ʹ�øú�������źŷ����ߵ�ָ��
�Զ����źţ�signals�ֻ��Ҫ��������Ҫ����

�������� QMenu* menu = new QMenu(this);����һ���Ӷ�����ڶ�������
ÿ�� QObject ������һ��������Ͷ���Ӷ���ͨ���������νṹ�������Ĺ�ϵ���������ڡ�
1�Զ��ڴ����������������ʱ�������Ӷ���Ҳ�ᱻ�Զ����١����ֻ��Ʊ������ڴ�й©�������ڴ����
2��λ�����������ʹ�ö���֮��Ĺ�ϵֱ�����������ڲ�λ��������磬һ�����ڶ�������Ƕ���ӿؼ�����ĸ�����
3�źźͲ۴��������ӹ�ϵҲ���������źźͲۻ��ơ��źſ��Դ��Ӷ��󴫲������������߲�εĶ����У����¼�����



�����ࣺ
QList<QString>|QStringList
qt��QList�͵���vector
˳��QList QStack QQueue
������QMap QMultiMap QHash QMultiHash Qset  map.value(key,Ĭ��ֵ)
��ʽ����ֵ����ָ�����ݵ�ָ�룬ֻ�е�����д������ʱ�����ݲŻᱻ���� 

QVariant�ࣺ
�� Qt �е�һ��ͨ���������ͣ������Դ洢�������͵�ֵ�����������������ͣ��� int��double��bool����Qt �ĺ����������ͣ��� QString��QDateTime���Լ��Զ������͡�
QVariant ���ṩ��һ�ַ���ķ������洢�ʹ����������͵����ݣ���������ʽ���������������͡�
ͨ��toT()(����toString())��QVariantת��Ϊ���������
var.toString();|var.value<QString>();

QFlags�ࣺQFlags<Enum>
���ڴ洢ö��ֵ�Ļ��������
��ϱ�־��������϶��ö��ֵ��ʹ������Ӽ���������⡣
��λ������֧�ְ�λ�루&������λ��|���Ȳ���������ضԱ�־���в�����
���Ͱ�ȫ��QFlags �ṩ�����Ͱ�ȫ�ķ�ʽ�������־��������ֱ��ʹ��������ȱ��
// �����ļ�Ȩ�޵�ö������
enum FilePermission {
	Read    = 0x01,  // 0001
	Write   = 0x02,  // 0010
	Execute = 0x04   // 0100
};
Q_DECLARE_FLAGS(FilePermissions, FilePermission)
Q_DECLARE_OPERATORS_FOR_FLAGS(FilePermissions)

QRandomGenerator�ࣺ
�����������
QRandomGenerator::global()->generate()//�Ѿ����õ�
fillRange();//����һ�������
bounded();//����ָ����Χ�ڵ������


���������
1.widget��object�����࣬���书�ܻ�����������GUI��һЩ���ܣ�ͼ�λ���
2.window�����Ե��ڴ��ڣ��������ڵ������û��Ƕ�뵽���������Ҫ������show() hide() raise() lower()�� 3����

QGroupBox����������������������������ƶ���
splitter���ָ���

QString�÷���
QString("lalal:%1 %2").arg(a).arg(b);//�����lalal:a,b
s.mid(1,2);//�ӵ�1��λ�ÿ�ʼ�������ַ�
s.replace(1,2"abc");//�滻
s.section(':', 1, 2);//��һ���ַ����л�ȡĳ����
int index = str.indexOf("world", 0, Qt::CaseInsensitive);//���ҵ�һ�γ��ֵĺ��� ���Դ�Сд��
lastIndexOf;//�������һ�γ���
contains();//��ѯ�Ƿ����ĳ���ַ�
startsWith();endsWith();//����ַ����Ƿ����ض������ַ������ַ���ʼ�����
simplified();//�Ƴ��ַ�����ͷ�ͽ�β�Ŀհ��ַ��������ַ����ڲ��Ķ���հ��ַ�ѹ��Ϊһ���ո�
trimmed();//���Ƴ��ַ�����ͷ�ͽ�β�Ŀհ��ַ������ı��ַ����ڲ��Ŀհ��ַ�
QString::number(int n, int base = 10)|//������ n ת��Ϊָ�����Ƶ��ַ�����
number(double n, char format = 'g', int precision = 6)//�������� n ת��Ϊ�ַ���������ָ����ʽ�;��ȡ�

autoExclusive �� flat �������ڵ��� QPushButton �ؼ�����ۺ���Ϊ
checkable���൱�ڸ�ѡ��
autoExclusive����ѡ1����checkable���ʹ��

lineEdit->setAlignment(Qt::Alignleft);//���ø�ʽΪ�����
setClearButtonEnabled(true);//lineedit��һ�������������
setReadOnly(true);//������˼
setEnabled(true);

����������ɫ
QPalette plet = ui.str1lineEdit->palette();
plet.setColor(QPalette::Text, Qt::red);
ui.str1lineEdit->setPalette(plet);

Qsilder��Qprogressbar��������ͽ����� %p%��ʾ�ٷֱ���ʾ
datetime��QCalendarWidget������ʱ������� ��ʽ�ַ���dΪ�죬MΪ�£�yyΪ�꣬hΪСʱ|H��ʾ24���ƣ�mΪ���ӣ�sΪ�룬zΪ���� toString("yyyy-MM-dd hh:mm:ss")

ui.startButton->setEnabled(false);//���ð�ť״̬

��ʱ���ͼ�ʱ��
��ʱ����QTimer
m_timer->start();//��ʼ��ʱ��
&QTimer::timeout//�źź���
m_timer->setTimerType(Qt::PreciseTimer);//���ö�ʱ������ ��ʱ�����־��ȣ�PreciseTimer CoarseTimer VeryCoarseTimer
m_timer->stop();//���ƶ�ʱ������ʱ������Ҫ
QTimer::singleShot("����ʱ��",Qt::PreciseTimer,this,&timerTest::"�ۺ���");//���δ�����ʱ��
��ʱ����QElapsedTimer
m_counter->start();//��ʼ��ʱ��
int tmMsec = m_counter->elapsed();//���ڷ��ش��ϴε��� start() �� restart() ����������ʱ�䣨�Ժ���Ϊ��λ��
����߼���1.ȷ�϶�ʱ������ģʽ�����ζ�Σ�����ȷ�϶�ʱ�����ȣ�������ʱ���ͼ�ʱ�������ð�ť״̬ 2.ֹͣ��ʱ������ü�ʱ������ 3.connect�������źź���Ϊtimeout

QComboBox:��������ѡ��
�źź������˼�����currentIndexChanged(int); currentTextChanged(QString str); 
addItems(QString);//����ѡ��
addItem(const QString &atext, const QVariant &auserData);//������Ļ�����ͬʱ������һ������
setCurrentText(str);//���õ�ǰ��

QMainWindow�����˲˵���
QAction�����༭�������д���QAction�����ڱ�ʾ�͹����û�������Ϊ���࣬���Խ�����˵���͹�������ť�����������źź���Ϊ��triggered()��
�ź�/�۱༭������ĳЩ��������һ�������ֶ���д����
on_textEdit_copyAvailable(bool a);//�ı��ؼ����пɸ�������ʱ��������Ҫ��ʹ�ø���ճ���Ȳ���ʱʹ��
on_textEdit_selectionChanged();//�ı��ؼ���ѡ�����ݱ仯ʱ�����źţ���Ҫ�Թ��ѡ������ʱʹ��
QTextCursor cursor = ui.textEdit->textCursor//���ƹ������
QTextCharFormat format = ui.textEdit->currentCharFormat();//��ȡ��ǰ�ı��ĸ�ʽ

toolBar:ui�����д��action������Ĺ��������ڶ��У�
statusBar:ui�����е�״̬���������棩
ͨ��addAction();��addWidget()�����Ӧ�ؼ�


QToolButton:
ͨ��setDefaultAction()������������Action����//ui.tBtnListIni->setDefaultAction(ui.actListInit);
ͨ��popupMode����������ε����˵�
enum ToolButtonPopupMode{DelayedPopup,MenuButtonPopup,InstantPopup}


QListWidget:
void setData(int role, const QVariant &value);
QVariant data(int role) const;

QListWidgetItem* aItem = new QListWidgetItem();//�½�һ����ָ�룬�Ӷ����Խ�����ز���
aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsEditable);//������״̬
 ui.listWidget->addItem(aItem);//���һ��
delete ui.listWidget->takeItem(row);//�Ƴ�listwidget��ĳһ�У�ɾ������Ҫ��delete
ui.listWidget->sortItems(Qt::DescendingOrder);//����������
item->setData(Qt::DisplayRole, "Cell Text"); // ������ʾ�ı�������widget����setdata������
item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled); // ������ı�־
�����Ҽ���ݲ˵�
on_listWidget_customContextMenuRequested(const QPoint &pos);//�����Ҽ��ź�
QMenu*menu=new QMenu(this);//�����˵�
ui.listWidget->setContextMenuPolicy(Qt::CustomContextMenu);//����ģʽΪ�û��Զ���˵�
menu->addAction(ui.actListInit);//��Ӳ˵���
menu->exec(QCursor::pos());//�������λ����ʾ
delete menu;

QTreeWidget:��Ϊ��ͷ��Ŀ¼�������� 
void setData(int column, int role, const QVariant &value);
QVariant data(int column, int role) const;��ÿһ�оʹ���һ�����ݣ�
- �ļ���1 - �ļ�1����1�����ƣ���2����С����3�����ͣ� - �ļ�2����1�����ƣ���2����С����3�����ͣ� 
- �ļ���2 - �ļ�3����1�����ƣ���2����С����3�����ͣ�

ui.treeWidget->setHeaderItem(header);//��ӱ�ͷheader
ui.treeWidget->addTopLevelItem(rootItem);//��Ӷ���ڵ�
parItem->addChild(item);//��Ӵμ��ڵ�
QTreeWidgetItem* item = new QTreeWidgetItem(1000/1001/1002);//�������ͱ�ʶ��������1000Ϊ����ڵ㣬1001Ϊ����һ����������
item->setData(colItem, Qt::UserRole, QVariant(filename));//����������ݣ���һ��������������0�У�����һ�У� �ڶ�����UserRole ���ڴ洢�û��Զ������� ��������ʵ�����ݣ�����ı����ݣ�
���У��ڶ��������������óɺܶ��У�����DisplayRole����ʾ�ı�����ToolTipRole��������ʾ����DecorationRole��ͼ�����ã��ȵ�
��Ϻ�����item->data(colItem, Qt::UserRole);//������ص���QVariant���ͣ�ֻ���UserRole������Ҫtostring����ת��
item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled); // ������ı�־

widgetɾ��ĳһ�����ݣ�
if (watched == ui.listSource)
		delete ui.listSource->takeItem(ui.listSource->currentRow()); //ui.listSource->currentItem();���Ƽ� ��Ϊ QListWidget ��Ȼ��Ϊ������ڡ�
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
			delete currentItem;  // ɾ����ǰ���ֹ�ڴ�й©
		}
	}
	else if (watched == ui.tableWidget)
		delete ui.tableWidget->takeItem(ui.tableWidget->currentRow(), ui.tableWidget->currentColumn());// ui.tableWidget->currentItem();



QDockWidget:ͣ�����
ui.dockWidget->setVisible(checked);//�ɼ�
ui.dockWidget->setFloating(checked);//�ɸ���

QPixmap:
m_pixmap.load(filename);//���ļ��м���ͼƬ
ui.labelPic->setPixmap(pix);//����ͼƬ
ui.labelPic->show();//��ʾͼƬ
ui.actZoomFitH->trigger();//�����źţ�������زۺ���
ui.actZoomFitH->setEnabled(true);
ui.actZoomFitW->setEnabled(true);
ui.actZoommIn->setEnabled(true);
ui.actZoomOut->setEnabled(true);
ui.actZoomRealSize->setEnabled(true);


QFileDialog:
QFileDialog::getExistingDirectory(this, "ѡ��Ŀ¼", QDir::currentPath());//���û�ѡ��һ��Ŀ¼���ļ��У�������·����Ϊ QString ����
this����ʾ�����ڣ�ͨ�����ݵ�ǰ���ڵ�ָ�롣
"ѡ��Ŀ¼"���Ի���ı��⡣
QDir::currentPath()���Ի���Ĭ�ϴ򿪵�·��������Ϊ����ĵ�ǰ����Ŀ¼��

QFileDialog::getOpenFileNames(nullptr,
		"Select one or more files to open",
		"",
		"All Files (*);;Text Files (*.txt);;Image Files (*.png *.jpg)")//�����û�ѡ��һ�������ļ�������·����Ϊ QStringList ���ء�
QFileDialog::getOpenFileNames ������һ���ļ�ѡ��Ի���
nullptr ��ʾû�и����ڡ�
"Select one or more files to open" �ǶԻ���ı��⡣
"" ��ʾ��ʼĿ¼�����Ըĳ�����Ҫ��·����
"All Files (*);;Text Files (*.txt);;Image Files (*.png *.jpg)" ���ļ��������������޶��û�ֻ��ѡ���ض����͵��ļ�
void TformDoc::on_actOpen_triggered()
{
	QString curpath = QCoreApplication::applicationDirPath();
	QString filename = QFileDialog::getOpenFileName(this, "��һ���ļ�", curpath, "�����ļ�(*.*);;�ı��ļ�(*.txt);;ͼƬ(*.png *.jpg);;����ļ�(*.cpp *.h)");
	if (filename.isEmpty()) {
		QMessageBox::warning(this, "����", "�򿪳�ʼ�ļ�Ϊ�գ�", QMessageBox::NoButton);
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

QTableWidgetItem *item = new QTableWidgetItem(query.value("����").toString(), 1000);//��һ����������ʾ�ı����ڶ������������ͱ�ʶ��
query.value("����").toString()�����ñ�������ʾ�ı��������Ǵ����ݿ��ѯ�л�ȡ��"����"�ֶε�ֵ��
1000�����ͱ�ʶ����������Զ��������ʶ���������ڴ�����ʶ��ʹ����ض����͵ı�����������widgetҲ��������� item->type()
QListWidgetItem *item = new QListWidgetItem("Item Text", 2000);
QTreeWidgetItem *item = new QTreeWidgetItem(3000);//treewidgetҪ���ǲ�ͬ�е����⣬���Բ���ֱ��������ʾ�ı�
item->setText(0, "Item Text");

ģ��/��ͼ�ṹ��
���ݣ������ݿ��һ�����ݱ��SQL��ѯ���
ģ�ͣ�������ͨ�ţ���Ϊ��ͼ����ṩ���ݽӿ�
��ͼ����Ļ�ϵĽ����������������ģ�ͻ��ÿ���������ģ��������model index����ͨ��ģ��������ȡ����
��������ͼ��ģ��֮�佻������ʱ�ṩ����ʱ�༭����ģ������ͼ�ṩ����Ϊ����ġ�����Ҫ����ͼ�ϱ༭����ʱ��������ṩһ���༭��

ģ�ͣ�
���л����item����ģ���඼����QAbstractItemModel��parent��QObject��
ģ��ֻ�����ڴ�����ʱ�洢���ݣ�������Դ�����������ࡢ���ݿ��

��ͼ�����
��ʾ����ʱ����Ҫ������ͼ���setModel()����
widget�Ķ��Ǳ����࣬Ϊ�����ÿ���ڵ��Ԫ�񴴽�һ���item��������洢���ݡ���ʽ���õȣ���û������ģ�ͣ������������ݰ�
ͨ�� setModel ���������Խ���ͼ (view) ��ģ�� (model) �����������Ӷ�ʹ��ͼ��ģ�͵����ݱ���ʵʱͬ����

����
������table����б༭һ����Ԫ������ʱ��Ĭ��ʹ��һ��QLineEdit�༭��
QAbstractItemDelegate�������

����ģ���д洢���ݵĻ�����Ԫ�����item����ÿ�����һ���кţ��кţ����и������ֻ��tree model�У�
QModelIndex indexA=model->index(0,0,QModelIndex());//�У��У�����
��Ľ�ɫ��role������Ϊ����ģ�͵�һ������������ʱ�����Ը����䲻ͬ��Ľ�ɫ������ Qt::DisplayRole  Qt::EditRole Qt::ToolTipRole

QListview:�ʺ���QStringListModel���ʹ��
QStringListModel�������ڼ򵥵�һά�ַ����б������򵥡���������
m_strlist = { "����","�Ϻ�","�Ͼ�" };//stringlist����
m_model = new QStringListModel(this);//QStringListModel��ʼ��
m_model->setStringList(m_strlist);//���ݴ�����model
ui.listView->setModel(m_model);//model��viewʵʱ����

QTableview:�ʺ���QStandardItemModel��QItemSelectionModel���ʹ��
QStandardItemModel�������ڸ��ӵĽṹ���ݣ����Դ������νṹ��������ݵȡ�
m_model = new QStandardItemModel(2, 6,this);//�������ģ���࣬��ʼ����ͬʱ������������
m_model->setHorizontalHeaderLabels(header);//��ʼ����ͷ
m_selection = new QItemSelectionModel(m_model,this);ѡ��ģ�ͣ����ڸ�����ͼ�齨�ĵ�Ԫ��ѡ��״̬
ui.tableView->setModel(m_model);model��viewʵʱ����  ��Ҫ���ڴ洢�͹�������
ui.tableView->setSelectionModel(m_selection);model��viewʵʱ����  ��Ҫ���ڹ�����ͼ����Ŀ��ѡ��״̬����Ҫ�Զ������չѡ����Ϊ������ʵ�ֶ�ѡ����Χѡ��ȣ�
�洢���ݵ�model��
aItem = new QStandardItem(tmpList[j]);//������ݵ�item
m_model->setItem(i - 1, j, aItem);//��model������item

�Զ������
Ĭ�ϵĴ���༭����QLineEdit�༭�򣬿���ʹ������input����
QAbstractItemDelegate�ǻ��࣬�Ƽ�ʹ��������QStyledItemDelegate�࣬��Ϊ������ʹ�õ�ǰ����ʽ���������������
ʹ��ʱ����ʵ�����º�����
createEditor()���������ڱ༭ģ�����ݵ�widget�������spinBox��combobox
setEditorDate()��������ģ���л�ȡ���ݣ���widget������б༭
setModelDate()����widget�ϵ����ݸ��µ�����ģ��
updateEditGeometry()�����ڸ�widget�������һ�����ʵĴ�С

QModelIndex�ࣺ����ָʾģ���е�һ���ض�λ�á����Խ������Ϊģ�����ݵ�ָ�롣��������һ��ģ���е��кš��к��Լ�������Ϣ����˿��Ծ�ȷ��λ��ģ���е��κ�һ�������
bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)
data(const QModelIndex &index, int role = Qt::DisplayRole)


QFileSystemModel��QTreeview
QFileSystemModel:Ϊ�������ļ�ϵͳ�ṩһ��ģ�ͣ������ڷ��ʱ������ļ�ϵͳ��
���ṩ��һЩ�ӿں�������Щ�ӿں�������������ʾѡ���ȡĿ¼���ļ���Ϣ���Լ�������ɾ���ļ��еȡ�
m_model->setRootPath(QDir::currentPath());//����һ����Ŀ¼��һ��Ҫ����һ�Σ�
ui.treeView->setRootIndex(m_model->index((QDir::currentPath())));//����Ϊ��ǰĿ¼

m_model->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);//����ģ�������������
m_model->setNameFilterDisables(!checked);//�����������Ƿ������ʾ


�¼�����
�¼�����
1.�����¼����ɴ���ϵͳ��������QKyeEvent��QMouseEvent �����ϵͳ���У��ȴ��¼�ѭ���Ĵ���
2.�����¼�����QtӦ�ó����������QTimerEvent ͨ��QCoreApplication����psotEvent()���������¼����ȴ��¼�ѭ���Ĵ���
3.�����¼�����Qt�������������ͣ�ͨ��QCoreApplication����sendEvent()���������¼����ɶ����event()��������
void QtEvent::mousePressEvent(QMouseEvent* event)//���
QPoint pt = event->pos();//���widgetλ��
QPointF GlobPt = event->globalPosition();//�����Ļ�ľ���λ��
ui.labelMove->move(event->pos());//��label�ƶ���ָ��λ��
void QtEvent::keyPressEvent(QKeyEvent* event)//����
QPoint pt = ui.pushButton->pos();//��ť��ʱ���widgetλ��
ui.pushButton->move(pt.x() - 20, pt.y());//����ť�ƶ���ָ��λ��

�¼����źţ�(�¼��ĺ�������Ҫ��д��
�źž��Ƕ�ĳЩ�¼��ķ�װ������QpushButton��clicked()�źţ����Ƕ�QEvent::MouseButtonRelease�����¼��ķ�װ
����һ����ǩ���������һ��������TMyLabel
signals:
	void DoubleClicked();//Ϊ�վ���
protected:
	virtual void mouseDoubleClickEvent(QMouseEvent* event){emit DoubleClicked();};//ͨ���¼����������źź���
connect(ui.doubleClikcedLabel, &TMyLabel::DoubleClicked, this, &QtEvent::doubleClicked);//����������ͨ��connect����
ͨ���¼��������źţ��ٸ��ۺ����������¼������߼��Ƶ��������������������չ��

setAttribute(Qt::WA_Hover, true);//��ʹ��һ�������ܹ�������ͣ�¼�

�¼������������Բ���Ҫ����һ�������ʵ����������
����һ��������¼�ί�и���һ�����������Ӳ�����
�׷���void Qobject::installEventFilter(Qobject *filterObj) //filterObj �ҷ�
�ҷ���[virtual] bool Qobject::eventFilter(Qobject * watched, QEvent * event)//watched���� event����

�Ϸţ�drag&drop���¼����ϷŲ�����
void dragEnterEvent(QDragEnterEvent*event)override;//����drag����ȡMIMe����  ����¼��������϶�����Ŀ������ʱ������
void dropEvent(QDropEvent*event)override;//����drog��ʹ��MIMe����  ����¼��������϶��Ķ��󱻷���ʱ��������
QMimeData���������ɴ洢�ڼ������е���Ϣ����֧��ͨ���ϷŻ��ƴ��䣻
QMimeData�������������е���������Ӧ��MIME�������������ȷ����Ϣ������Ӧ�ó����ڡ�Ӧ�ó���֮�䰲ȫ����
���� �� ���� MIME��������ʱ����������ƥ��
tester		getter		setter		MIME Types
has Text()	text()		setText()	text/plain
has Html()	heml()		setHtml()	text/html
has Urls()							text/uri-list
has Image()							image/*
has Color()							application/x-color
event->mimeData()->hasUrls();//ȷ���Ƿ���urls text/uri-list
QString filename = event->mimeData()->urls()[0].fileName();//����ļ���
QString ex = fileinfo.suffix();//��ȡ��׺

�ϷŹ��ܵ����
dragDropMode:���������ڿ�����ͼ�Ϸ��¼��Ĵ���ʽ ���ϲ��ɷš������Ͽɷš����Ͽɷš������ϲ��ɷš�ֻ׼���ڲ��Ϸ� dragdrop dragonly...
defaultDropAciton:���������ڿ�����ͼ���Ϸ�ʱ�����µ�Ĭ�ϲ��� ���ơ��ƶ������ӡ����� copyaciton moveaciton LinkAction ignoreaciton
ע�����widget��view����������Ҫͳһ��ʾ���������Դ���һ��QAbstractItemView* m_item = nullptr;ͨ��m_item����ͳһ����

QtԤ�����׼�Ի���
�Ի���							���þ�̬��������						��������
QFileDialog �ļ��Ի���			QString getOpenFileName()				ѡ���һ���ļ�
								QStringList getOpenFileNames()			ѡ��򿪶���ļ�
								QString getSaveFileName()				ѡ�񱣴�һ���ļ�
								QString getExistingDirectory()			ѡ��һ�����е�Ŀ¼ 
								QUrl getOpenFileUrl()					ѡ���һ���ļ�,��ѡ��Զ�������ļ�
QColorDialog ��ɫ�Ի���			QColorDialog getColor(color)			ѡ����ɫ
QFontDialog ����Ի���			QFontDialog getFont(&ok, font,this,"ѡ������")ѡ������ ͨ������ֵok�ж��Ƿ�ִ����������
QinputDialog ����Ի���			QString getText()						���뵥������
								int getlnt()							��������
								double getDouble()						���븡���� 
								QString getltem()						��һ�������б����ѡ��
								QString getMultiLineText()				������������ַ���
QMessageBox��Ϣ��				StandardButton information()			��Ϣ��ʾ�Ի��������Ϣ  
								StandardButton question()				ѯ�ʲ���ȡ�Ƿ�ȷ�ϵĶԻ���
								StandardButton waming()					������Ϣ��ʾ�Ի���
								StandardButton critical()				��ʾ�Ի���
								void about() void						�����Զ�����Ϣ�Ĺ��ڶԻ���
								aboutQt()								����Qt�ĶԻ���

�Զ���Ի���ֱ�ӿ�CustomizeDialogBox�����Ŀ
������������TDialogSize����̬������ģ̬��ʾ����Ҫ��ȡ����ֵ���ú�ɾ��
���ñ�ͷ��ͷ����TDialogHeaders��ֻ����һ�Σ�ģ̬��ʾ����Ҫ��ȡ����ֵ���ú�����
��λ��Ԫ����������TDialogLocate����̬����,��ģָ̬����ʾ���Ի���������ڿɽ����������رպ��Զ�ɾ��
accept�ۺ��������������ݣ�reject�ۺ��������ܾ�����
m_selection->setCurrentIndex(index,QItemSelectionModel::Select);//ѡ�����������  QItemSelectionModel
QDialog����execѭ������

Ƕ�������widget
������ѡ��Qwidget�����ࣩ��Qdialog��Qmainwindow
QSplashScreen������Ӧ�ó�������ʱ��splash���ڣ�û�б߿�
QMdiSubwindow������ΪQMdiArea�ṩһ���Ӵ��壬���ڶ��ĵ������
������ʾ���������Ե����ú�����
setattribute��һ���������ô������Եĺ��� Qt::WA_DeleteOnClose�����ڱ��ر�ʱ���Զ�ɾ���ô��ڶ��󣬴Ӷ��ͷ��ڴ�
setwindowflag�������ô��ڵı�־��window flags������Щ��־���ƴ��ڵ���Ϊ����ۡ�Qt::FramelessWindowHint���ޱ߿򴰿ڡ�Qt::WindowStaysOnTopHint����������λ����������֮�ϡ�
setwindowstate�������ô��ڵ�״̬��������󻯡���С����ȫ��״̬��Qt::WindowNoState������״̬��Qt::WindowMinimized����С��״̬��Qt::WindowMaximized�����״̬��Qt::WindowFullScreen��ȫ��״̬��

Doc->setAttribute(Qt::WA_DeleteOnClose);//������Ե���Ҫ�����ǣ������ڱ��ر�ʱ���Զ�ɾ���ô��ڶ��󣬴Ӷ��ͷ��ڴ档

MDIӦ�ó������
���Ƕ���Ӵ��ڣ�ʹ��setViewMode()����������ģʽѡ��
1.QMdiArea::SubWindowView ��ͳ���Ӵ���ģʽ
2.QMdiArea::TabbedView ��ҳ����ʾģʽ
QMdiArea��һ���ź�subWindowActivated(QMdiSubWindow&argl)���ڵ�ǰ������л�ʱ����\

Splash�����ƶ���
event->globalPosition();//��ȡ�����Ļ���Ͻǵ����λ��
pos();//��ȡ�����Ļ���ϽǺ�������������Ͻ�֮���λ��
��ȡ�ƶ����̣�
QPoint eventPos=event->globalPosition(.toPointO):
move(eventPos-m _lastPos);
m lastPos = eventPos - this->pos();
��ʹ�������¼���
virtual void mousePressEvent(QMouseEvent* event);
virtual void mouseReleaseEvent(QMouseEvent* event);
virtual void mouseMoveEvent(QMouseEvent* event);

����ע���Ͷ�ȡ��
QApplication::setOrganizationName("AXB_QT");//����һ��ע���Ҳͨ����������ȡλ��
QApplication::setApplicationName("MDItest");//ע�����Ŀ¼
���ܣ�
QCryptographicHash hash(QCryptographicHash::Md5);//�������ܶ���ʹ��MD5�㷨
hash.addData(str.toLocal8Bit());
��ȡע������ݣ�
QSettings settings;
bool saved = settings.value("saved", false).toBool();//�����ȡ����saved���͸�ֵע����еģ�����Ϊfalse
m_user = settings.value("username", "qwer").toString();
m_password = encrypt("12346");
д��ע������ݣ�
QSettings settings;
settings.setValue("username", m_user);
settings.setValue("pswd", m_password);
settings.setValue("saved", ui.saveNameBox->isChecked());

�ļ�ϵͳ�������ļ���д
QIODeviceΪ֧�ֶ�д���ݿ���豸����QFile��QBuffer��QTcpSocket���ṩ��һ��ͨ�õ�ʵ�ֺ�һ������ӿڣ��䲻��ʵ����������ʹ�����Ľӿ��ṩI/O����
���ࣺ
QCoreApplication��������ȡӦ�ó���·�������ֵ��ļ���Ϣ
QFile�����ļ��������ļ���ɾ���ļ�
QFileInfo����ȡ�ļ���Ϣ������·�������֣���׺
QDir����ȡĿ¼���ļ���Ϣ����ȡһ��Ŀ¼�µ��ļ���Ŀ¼�б�������ɾ��Ŀ¼���ļ����ļ�������(���Ե���ǰ������ϣ�
QTemporaryDir��QTemporaryFile�����ڴ�����ʱĿ¼����ʱ�ļ�
QFileSystemWatcher������Ŀ¼���ļ�����ӡ�ɾ���ȱ仯

�ļ���д��
QFile��ֱ�Ӷ�д������QTextStream��д
QFileDialog::getOpenFileName(this, curpath, curpath, filter);//���ļ�
QFileDialog::getSaveFileName(this, curpath, curpath, filter);//�����ļ�
ֱ�Ӷ�д��
QFile afile(afilename);
afile.open(QIODevice::ReadOnly | QIODevice::Text);
ui.plainTextEditfile->appendPlainText(afile.readAll());//��ȡ�ļ�
afile.close();

QString str = ui.plainTextEditfile->toPlainText();
afile.write(str.toUtf8(), str.toUtf8().length());//д���ļ�

QSaveFile afile(afilename);//�ȱ����ļ�����ʱ�ļ������ⷢ�����󣬵���Դ�ļ���
afile.setDirectWriteFallback(false);//ʹ����ʱ�ļ�
	try{
		QString str = ui.plainTextEditfile->toPlainText();
		afile.write(str.toUtf8(), str.toUtf8().length());
		afile.commit();
	}
	catch (QException& e) {
		QMessageBox::warning(this, "����", "�����ļ��쳣��");
		afile.cancelWriting();
	}

Stream��
QFile afile(afilename);
afile.open(QIODevice::ReadOnly | QIODevice::Text);
QTextStream aStream(&afile);
	aStream.setAutoDetectUnicode(true);//����ַ������Ƿ�ΪUnicode
	while (!aStream.atEnd()) {
		QString str = aStream.readLine();
		ui.plainTextEditstream->appendPlainText(str);
	}

afile.setDirectWriteFallback(false);//ʹ����ʱ�ļ�
	try {
		QTextStream aStream(&afile);
		aStream.setAutoDetectUnicode(true);//����ַ������Ƿ�ΪUnicode
		QTextDocument *doc = ui.plainTextEditstream->document();
		for (int i = 0; i < doc->blockCount(); ++i) {
			aStream << doc->findBlockByLineNumber(i).text();
			aStream << "\n";
		}
		afile.commit();
	}

�ļ���д�����ƣ�Ԥ������룩
QFile��QDataStream����ʹ��
�ֽ��򣺶��ֽ��������ڴ��еĴ洢˳��

qtSQL:
����moduleview
���ݿ����ݣ�����QTableView
��ʾ�����
QSqlQueryModel��ͨ������SELECT����ѯ��ȡ���ݿ����ݣ�����Ϊֻ��
QSqlTableModel��ֱ������һ�����ݱ�����ƣ����Ի�ȡ���ݱ��ȫ����¼���ɱ༭
QSqlRelationalTableModel��Ϊ���ŵ����ݿ���ṩ��һ���ɱ༭������ģ�ͣ�֧�����


QDataWidgetMapper:ӳ�����ݿ�����

���ݿ�
��
��
QSqlTableModel����QDataWidgetMapper����������ʾ�����lineedit��spinbox��combobox�ȣ�
��
��
tableview��ʾ


QSqlTableModel��ز���������qtSQL�����ݿ���ص�model�඼��Ҫ�����ύģʽ���������ݵķ�ʽ��
//��ʼ��
QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
QSqlTableModel* tabmodel = nullptr;

DB = QSqlDatabase::addDatabase("QSQLITE");//�������
DB.setDatabaseName(aFile);//�������ݿ�����
DB.open()//�����ݿ�

//����ģ�ͣ������ݿ������ñ������
tabmodel = new QSqlTableModel(this, DB);
tabmodel->setTable("employee");
tabmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);//�ֶ��ύģʽ
tabmodel->setSort(tabmodel->fieldIndex("empNo"), Qt::AscendingOrder);//��������

tabmodel->select()//ˢ��ģ��  ���಻��ʵʱͬ�����ݿ�����ݣ�������Ҫˢ��

//���ñ���
tabmodel->setHeaderData(tabmodel->fieldIndex("empNo"), Qt::Horizontal, "����");

//modelview
ui.tableView->setModel(tabmodel);// ��������ͼ��ģ��
ui.tableView->setColumnHidden(tabmodel->fieldIndex("Memo"), true);//���ز�������

//�ֶ���widgetӳ��
datamapper = new QDataWidgetMapper(this);
datamapper->setModel(tabmodel);
datamapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);//�����ύ��ʽ���Զ��ύ
datamapper->addMapping(ui.spinBoxnum, tabmodel->fieldIndex("empNo"));

//��ȡ�ֶ�����������combobox
QSqlRecord emptyRec = tabmodel->record();
for (int i = 0; i < emptyRec.count(); ++i) {
	ui.comboBoxsort->addItem(emptyRec.fieldName(i));
}


QSqlQueryModel��ʹ�ã���ֻ�ܶ�ȡ�����ܱ��棬��table���ࣩ
tabmodel->setQuery("select empNo,Name,Gender,Birthday,Province,Department,""Salary FROM employee ORDER BY empNo");//ѡ��ʹ�õ�������
tabmodel->setQuery(tabmodel->query().executedQuery());//ˢ��ģ��
//�����ͷ
QSqlRecord rec = tabmodel->record();
tabmodel->setHeaderData(rec.indexOf("empNo"), Qt::Horizontal, "����");

QSqlQuery ����ʹ�ã�
QSqlQuery query;
query.prepare("select Memo,Photo from employee where EmpNo= :ID");//ֻ�� EmpNo �е��ڰ󶨲��� :ID �ļ�¼�� Memo �� Photo �е����ݻᱻ��ȡ
query.bindValue(":ID",empNo);//������ :ID �󶨵�һ�������ֵ empNo
query.exec();//ִ���Ѿ�׼���õ� SQL ��ѯ
*/
 