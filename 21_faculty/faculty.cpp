#include"faculty.h"

AllCourses* AllCourses::instance = nullptr;

Course::Course(std::string _name, Teacher* _teacher, int max) : name(_name), teacher(_teacher), maxStudents(max) {}

bool Course::AddStudent(Student* student) {
	if (students.size() < maxStudents && !isFinished) {
		//std::vector<Student*>::iterator it = std::find_if(students.begin(), students.end(), [&](auto x) {return x->GetName() == student->GetName(); });
		students.push_back(student);
			//marks.resize(marks.size() + 1);
		return true;
	}
	return false;
}

bool Student::ChooseCourse(std::string nameCourse, std::string nameTeacher) {
	AllCourses* all = AllCourses::GetInstance();
	std::vector<Course*> courses= all->GetAllCourses();
	//std::vector<Teacher*> teachers= all->GetAllTeachers();
	//std:::vector<Teacher*>::iterator teachIt = std::find_if(teachers.begin(), teachers.end(), 
										//	[&](auto x) {return x->GetName() == nameTeacher; });
	//if (teachIt == teachers.end()) return false;
	std::vector<Course*>::iterator courseIt = std::find_if(courses.begin(), courses.end(),
		[&](auto x) {return x->GetName() == nameCourse && x->GetTeacher()->GetName() == nameTeacher; });
	if (courseIt == courses.end()) { return false; }
	if ((*courseIt)->AddStudent(this)) {
		this->courses.push_back(*courseIt);
		return true;
	}
	return false;
}

void Teacher::CreateCourse(std::string name, int max) {
	Course* c = new Course(name, this, max);
	courses.push_back(c);
	AllCourses* all = AllCourses::GetInstance();
	all->AddCourse(c);
}

bool Teacher::SetMarks(std::string courseName, std::vector<int> marks) {
	std::vector<Course*>::iterator it = std::find_if(courses.begin(), courses.end(),
		[&](auto x) {return x->GetName() == courseName; });
	if (it == courses.end()) return false;
	Course* course = *it;
	std::vector<Student*> students = course->GetStudents();
	if (marks.size() != students.size() || !course->SetFinished()) return false;
	std::ofstream archive("archive.txt", std::ofstream::app);
	archive <<"Course: "<< course->GetName() << " Teacher: " << course->GetTeacher()->GetName() << std::endl;
	for (int i = 0; i < marks.size(); i++) {
		archive << students[i]->GetName() << " " << marks[i] << std::endl;
	}
	archive.close();
	return true;
}

AllCourses* AllCourses::GetInstance() {
	if (!instance) {
		instance = new AllCourses();
	}
	return instance;
}