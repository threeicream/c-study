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
*/
