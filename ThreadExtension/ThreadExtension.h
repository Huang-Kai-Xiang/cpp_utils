//
// Created by hkx on 22-8-11.
//

#ifndef UTILS_THREADEXTENSION_THREADEXTENSION_H_
#define UTILS_THREADEXTENSION_THREADEXTENSION_H_

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

class ThreadExtension {
  typedef enum  {
    Stoped = 0,
    Running = 1,
    Paused = 2
  }ThreadState;
 public:
  ThreadExtension();
  virtual~ThreadExtension();

 public:
  void StartThread();
  void PauseThread();
  void ResumeThread();
  void StopThread();

  int GetThreadState() const;

 private:
  void Run();

 protected:
  virtual void CustomRun() {};

 private:
  ThreadState m_Thread_State;
  std::shared_ptr<std::thread> m_pThread;
  std::mutex m_Mutex;
  std::condition_variable m_Condition_Variable;
  std::atomic<bool> m_Thread_Pause_Flag;
  std::atomic<bool> m_Thread_Stop_Flag;

};

#endif //UTILS_THREADEXTENSION_THREADEXTENSION_H_
