/*
进程：运行的程序
线程：进程中的进程，线程的数量取决于cpu核数

创建线程：
#include<thread>
std::thread t(function_name,args...);
function_name：线程入口点的函数或可调用对象
args...：传递给函数的参数
thread t(printHelloWorld,"heloo,fuck");
t.join();//检查线程是否结束，结束后主线程在继续运行
t.detach();//分离线程，即使主线程结束，线程也继续在后台执行
bool in = t.joinable();//joinable()方法返回一个布尔值，如果线程可以被join()或detach()，则返回true，否则返回false

常见错误
1. 传递临时变量的问题：线程要引用类型，却传递临时变量(thread默认值传递，只会是右值)
std::ref()：传递引用类型
2. 传递指针或引用指向局部变量的问题：运行到线程时，局部变量已经被释放掉了，此时线程调用空指针
全局变量解决
3. 传递指针或引用指向已释放的内存的问题：跟2差不多，就是变成手动释放
手动释放时机要在线程结束后，或者用智能指针
4. 类成员函数作为入口函数，类对象被提前释放：跟3差不多，就是传参变成类对象，主线程运行到return就释放了
thread t(&A::foo,&a);
&A::foo：是函数指针，表示要在线程中运行的类 A 的成员函数 foo。
&a：是指向对象 a 的指针，告诉 thread 使用 a 对象调用 foo。
5.入口函数为类的私有成员函数
创建一个友元函数，将私有成员函数放进去

互斥量解决多线程数据共享问题：
多个线程同时访问同一个变量，并进行写操作，就会发生数据竞争问题
通过mutex进行锁定和解锁操作，当一个线程进行操作时，其他线程不允许操作
std::mutex mtx;
void func() {
	for (int i = 0; i < 10000000; ++i) {
		mtx.lock();
		ttttt += 1;
		mtx.unlock();
	}
}

lock_guard类和unique_lock类
lock_guard：当构造函数被调用时，该互斥量会被自动锁定 当析构函数被调用时，该互斥量会被自动解锁 他的对象不能复制或移动，所以只能在局部作用域中使用
unique_lock：对互斥量进行更加灵活的管理，包括延迟加锁、条件变量、超时等
成员函数
lock():尝试对互斥量进行枷锁操作，若互斥量已经被其他线程持有，则当前线程被阻塞，直到互斥量加锁成功
try_lock():尝试对互斥量进行枷锁操作，若互斥量已经被其他线程持有，函数返回false，否则返回true
try_lock_for(const std::chrono::duration<Rep,Period>&erl_time):尝试对互斥量进行枷锁操作，若互斥量已经被其他线程持有，则当前线程被阻塞，直到互斥量加锁成功，或者超过指定时间
try_lock_until(const std::chrono::time_point<Clock,Duration>&abs_time):尝试对互斥量进行枷锁操作，若互斥量已经被其他线程持有，则当前线程被阻塞，直到互斥量加锁成功，或者超过指定时间点
unlock():解锁
int ttttt = 0;
std::timed_mutex mtx;
void func() {
	for (int i = 0; i < 2; ++i) {
		std::unique_lock<std::timed_mutex>lg(mtx, std::defer_lock);//定义时会自动调用lock函数
		if (lg.try_lock_for(std::chrono::seconds(2))) {
			std::this_thread::sleep_for(std::chrono::seconds(3));
			ttttt += 1;
		}

	}
}


call_once与其使用场景：
也是单例设计模式，确保某个类只能创建一个实例
//单例模式
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

	static Log *instance;//懒汉模式 静态成员变量只能类内声明，类外定义
	static std::once_flag once;
};
Log* Log::instance = nullptr;
std::once_flag Log::once;

conditon_variable与其使用场景：
条件变量的使用
生产者与消费者模型
生产者负责在任务队列加任务，消费者负责取任务完成，消费者有很多（多个线程）
std::condition_variable q_cv;
q_cv.notify_all();//通知所有消费者取任务
q_cv.notify_once();//通知一个消费者取任务
q_cv.wait(lock,[](){return !q_queue.empty(); });//如果队列为空，进行等待

std::queue<int>q_queue;
std::condition_variable q_cv;
std::mutex Mtx;
void producer() {
	for (int i = 0; i < 10; ++i) {
		std::unique_lock<std::mutex>lock(Mtx);
		q_queue.emplace(i);
		std::this_thread::sleep_for(std::chrono::microseconds(2000000));
		q_cv.notify_all();
		//通知消费者取任务
		std::cout << "producer:" << i << std::endl;
	}
}

void consumer() {
	while (true) {
		std::unique_lock<std::mutex>lock(Mtx);

		bool isempty = q_queue.empty();
		q_cv.wait(lock,[](){return !q_queue.empty(); });
		//如果队列为空，进行等待
		int value = q_queue.front();
		q_queue.pop();
		lock.unlock();
		std::cout << "customer1:" << value << std::endl;
		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}
}

*/
