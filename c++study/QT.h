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
QListView��QPlanTextEdit��OpenGlWidget��QGraphicView
QLabel��QPushButton��QLineEdit
QTextEdit��QCheckBox��QRadioBUtton
QComboBox��QListWidget��QTableWidget
QCalendarWidget��QSpinBox��QDoubleSpinBox
QSlider��DateEdit��DateTimeEdit��Dial

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
*/
