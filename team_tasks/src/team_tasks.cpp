#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
using namespace std;


class TeamTasks {
public:
  // ѕолучить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
	  return data.at(person);
  }

  // ƒобавить новую задачу (в статусе NEW) дл€ конкретного разработчитка
  void AddNewTask(const string& person) {
	  data[person][TaskStatus::NEW] += 1;
  }

  void RemoveZeroes(const Taskinfo& taskinfo) {
	  if (taskinfo[TaskStatus::NEW] == 0) {
		  taskinfo.erase(TaskStatus::NEW);
	  }
	  if (taskinfo[TaskStatus::IN_PROGRESS] == 0) {
		  taskinfo.erase(TaskStatus::IN_PROGRESS);
	  }
	  if (taskinfo[TaskStatus::TESTING] == 0) {
		  taskinfo.erase(TaskStatus::TESTING);
	  }
	  if (taskinfo[TaskStatus::DONE] == 0) {
		  taskinfo.erase(TaskStatus::DONE);
	  }
  }

  // ќбновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
	  TasksInfo updated, untouched, copy = data[person];
	  if (data.count(person) == 0) {
		  return {updated, untouched};
	  }
	  while (task_count > 0) {
		  --task_count;
		  if (copy[TaskStatus::NEW] > 0) {
			  --copy[TaskStatus::NEW];
			  ++updated[TaskStatus::IN_PROGRESS];
		  } else if (copy[TaskStatus::IN_PROGRESS] > 0) {
			  --copy[TaskStatus::IN_PROGRESS];
			  ++updated[TaskStatus::TESTING];
		  } else if (copy[TaskStatus::TESTING] > 0) {
			  --copy[TaskStatus::TESTING];
			  ++updated[TaskStatus::DONE];
		  }
	  }
	  data[person][TaskStatus::NEW] = copy[TaskStatus::NEW] + updated[TaskStatus::NEW];
	  data[person][TaskStatus::IN_PROGRESS] = copy[TaskStatus::IN_PROGRESS] + updated[TaskStatus::IN_PROGRESS];
	  data[person][TaskStatus::TESTING] = copy[TaskStatus::TESTING] + updated[TaskStatus::TESTING];
	  data[person][TaskStatus::DONE] = copy[TaskStatus::DONE] + updated[TaskStatus::DONE];

	  if (copy[TaskStatus::NEW] == 0) {
		  copy.erase(TaskStatus::NEW);
	  }
	  if (copy[TaskStatus::IN_PROGRESS] == 0) {
		  copy.erase(TaskStatus::IN_PROGRESS);
	  }
	  if (copy[TaskStatus::TESTING] == 0) {
		  copy.erase(TaskStatus::TESTING);
	  }
	  copy.erase(TaskStatus::DONE);

	  if (updated[TaskStatus::NEW] == 0) {
		  updated.erase(TaskStatus::NEW);
	  }
	  if (updated[TaskStatus::IN_PROGRESS] == 0) {
		  updated.erase(TaskStatus::IN_PROGRESS);
	  }
	  if (updated[TaskStatus::TESTING] == 0) {
		  updated.erase(TaskStatus::TESTING);
	  }
	  if (updated[TaskStatus::DONE] == 0) {
		  updated.erase(TaskStatus::DONE);
	  }

	  if (data[person][TaskStatus::NEW] == 0) {
		  data[person].erase(TaskStatus::NEW);
	  }
	  if (data[person][TaskStatus::IN_PROGRESS] == 0) {
		  data[person].erase(TaskStatus::IN_PROGRESS);
	  }
	  if (data[person][TaskStatus::TESTING] == 0) {
		  data[person].erase(TaskStatus::TESTING);
	  }
	  if (data[person][TaskStatus::DONE] == 0) {
		  data[person].erase(TaskStatus::DONE);
	  }

	  return {updated, copy};
  }

private:
  map<string, TasksInfo> data;
};
