namespace cpp TaskService
namespace py task_service

struct Task {
  1: string title,
  2: string description
}

service TaskService {
  Task getTaskById(1: i32 id),
  void addTask(1: Task t)
}

