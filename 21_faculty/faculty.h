#pragma once
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>

class Student;
class Teacher;
class AllCoursesTeachers;

class Course {
	friend class Teacher;
	std::string name = "";
	Teacher* teacher;
	bool isFinished = false;
	int maxStudents;
	std::vector<Student*> students;
private:
	Course(std::string _name, Teacher* _teacher, int max);
	//std::vector<int> marks;
public:
	
	bool SetFinished() { if (!isFinished) { isFinished = true; return true; } return false; }
	bool AddStudent(Student* student);
	std::vector<Student*> GetStudents() { return students; }
	std::string GetName() { return name; }
	Teacher* GetTeacher() { return teacher; }
};


class Student {
	std::string name;
	std::vector<Course*> courses;
public:
	Student(std::string _name) : name(_name) {}
	bool ChooseCourse(std::string nameCourse, std::string nameTeacher);
	std::string GetName() { return name; }
};

class Teacher {
	std::string name;
	std::vector<Course*> courses;
public:
	Teacher(std::string _name) : name(_name){}
	void CreateCourse(std::string name, int max);
	bool SetMarks(std::string courseName, std::vector<int> marks);
	std::string GetName() { return name; }
	std::vector<Course*> GetCourses() { return courses; }
};


class AllCourses {
	std::vector<Course*> courses;
private:
	static AllCourses* instance;
	AllCourses() {}
	AllCourses(const AllCourses&);
	AllCourses& operator=(AllCourses&);
public:
	void AddCourse(Course* course) { courses.push_back(course); }
	std::vector<Course*> GetAllCourses() { return courses; }
	static AllCourses* GetInstance();
};