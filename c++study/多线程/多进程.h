/*
���̣����еĳ���
�̣߳������еĽ��̣��̵߳�����ȡ����cpu����

�����̣߳�
#include<thread>
std::thread t(function_name,args...);
function_name���߳���ڵ�ĺ�����ɵ��ö���
args...�����ݸ������Ĳ���
thread t(printHelloWorld,"heloo,fuck");
t.join();//����߳��Ƿ���������������߳��ڼ�������
t.detach();//�����̣߳���ʹ���߳̽������߳�Ҳ�����ں�ִ̨��
bool in = t.joinable();//joinable()��������һ������ֵ������߳̿��Ա�join()��detach()���򷵻�true�����򷵻�false

��������
1. ������ʱ���������⣺�߳�Ҫ�������ͣ�ȴ������ʱ����(threadĬ��ֵ���ݣ�ֻ������ֵ)
std::ref()��������������
2. ����ָ�������ָ��ֲ����������⣺���е��߳�ʱ���ֲ������Ѿ����ͷŵ��ˣ���ʱ�̵߳��ÿ�ָ��
ȫ�ֱ������
3. ����ָ�������ָ�����ͷŵ��ڴ�����⣺��2��࣬���Ǳ���ֶ��ͷ�
�ֶ��ͷ�ʱ��Ҫ���߳̽����󣬻���������ָ��
4. ���Ա������Ϊ��ں������������ǰ�ͷţ���3��࣬���Ǵ��α����������߳����е�return���ͷ���
thread t(&A::foo,&a);
&A::foo���Ǻ���ָ�룬��ʾҪ���߳������е��� A �ĳ�Ա���� foo��
&a����ָ����� a ��ָ�룬���� thread ʹ�� a ������� foo��
5.��ں���Ϊ���˽�г�Ա����
����һ����Ԫ��������˽�г�Ա�����Ž�ȥ

������������߳����ݹ������⣺
����߳�ͬʱ����ͬһ��������������д�������ͻᷢ�����ݾ�������
ͨ��mutex���������ͽ�����������һ���߳̽��в���ʱ�������̲߳��������
std::mutex mtx;
void func() {
	for (int i = 0; i < 10000000; ++i) {
		mtx.lock();
		ttttt += 1;
		mtx.unlock();
	}
}

lock_guard���unique_lock��
lock_guard�������캯��������ʱ���û������ᱻ�Զ����� ����������������ʱ���û������ᱻ�Զ����� ���Ķ����ܸ��ƻ��ƶ�������ֻ���ھֲ���������ʹ��
unique_lock���Ի��������и������Ĺ��������ӳټ�����������������ʱ��
��Ա����
lock():���ԶԻ��������м������������������Ѿ��������̳߳��У���ǰ�̱߳�������ֱ�������������ɹ�
try_lock():���ԶԻ��������м������������������Ѿ��������̳߳��У���������false�����򷵻�true
try_lock_for(const std::chrono::duration<Rep,Period>&erl_time):���ԶԻ��������м������������������Ѿ��������̳߳��У���ǰ�̱߳�������ֱ�������������ɹ������߳���ָ��ʱ��
try_lock_until(const std::chrono::time_point<Clock,Duration>&abs_time):���ԶԻ��������м������������������Ѿ��������̳߳��У���ǰ�̱߳�������ֱ�������������ɹ������߳���ָ��ʱ���
unlock():����
int ttttt = 0;
std::timed_mutex mtx;
void func() {
	for (int i = 0; i < 2; ++i) {
		std::unique_lock<std::timed_mutex>lg(mtx, std::defer_lock);//����ʱ���Զ�����lock����
		if (lg.try_lock_for(std::chrono::seconds(2))) {
			std::this_thread::sleep_for(std::chrono::seconds(3));
			ttttt += 1;
		}

	}
}


call_once����ʹ�ó�����
Ҳ�ǵ������ģʽ��ȷ��ĳ����ֻ�ܴ���һ��ʵ��
//����ģʽ
class Log {
public:
	Log(const Log&) = delete;
	Log& operator=(const Log&) = delete;

	static Log& getInstance() {
		std::call_once(once, &Log::init);
		return *instance;
	}

	void showMessage(const string&s) const {
		std::cout << __TIME__ << ' ' << s << std::endl;
	}

private:
	Log() {}

	static void init() {
		instance = new Log();
	}

	static Log *instance;//����ģʽ ��̬��Ա����ֻ���������������ⶨ��
	static std::once_flag once;
};
Log* Log::instance = nullptr;
std::once_flag Log::once;

conditon_variable����ʹ�ó�����
����������ʹ��
��������������ģ��
�����߸�����������м����������߸���ȡ������ɣ��������кܶࣨ����̣߳�
std::condition_variable q_cv;
q_cv.notify_all();//֪ͨ����������ȡ����
q_cv.notify_once();//֪ͨһ��������ȡ����
q_cv.wait(lock,[](){return !q_queue.empty(); });//�������Ϊ�գ����еȴ�

std::queue<int>q_queue;
std::condition_variable q_cv;
std::mutex Mtx;
void producer() {
	for (int i = 0; i < 10; ++i) {
		std::unique_lock<std::mutex>lock(Mtx);
		q_queue.emplace(i);
		std::this_thread::sleep_for(std::chrono::microseconds(2000000));
		q_cv.notify_all();
		//֪ͨ������ȡ����
		std::cout << "producer:" << i << std::endl;
	}
}

void consumer() {
	while (true) {
		std::unique_lock<std::mutex>lock(Mtx);

		bool isempty = q_queue.empty();
		q_cv.wait(lock,[](){return !q_queue.empty(); });
		//�������Ϊ�գ����еȴ�
		int value = q_queue.front();
		q_queue.pop();
		lock.unlock();
		std::cout << "customer1:" << value << std::endl;
		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}
}

*/
