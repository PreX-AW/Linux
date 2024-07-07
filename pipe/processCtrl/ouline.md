# 流程
父进程通过创建五个匿名管道来与五个子进程进行通信

# main.cc
## 创建进程
通过循环创建五个匿名管道,并创建五个子进程,完成进程创建之后,关闭对应的文件描述符,并将子进程的读端通过`dup2`函数映射到`stdin`,再循环执行下的任务,直到用户选择退出,之后关闭子进程对匿名管道的读文件描述符,退出进程.

父进程此时将创建的子进程中的相关属性进行保存,并关闭对应的匿名管道读端
通过定义一个类来表明子进程
```cpp
class EndPoint
{
public:
pid_t _child_pid;
int   _write_fd;
std::string _processName;
public:
  EndPoint(pid_t child_pid,int write_fd)
  :_child_pid(child_pid),
  _child_pid(write_fd)
{

}
  ~EndPoint()
{
  }
private:
  static int cnt;
}
int EndPoint::cnt=0;

```
## 控制进程
## 关闭进程



