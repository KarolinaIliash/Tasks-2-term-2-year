#define CATCH_CONFIG_MAIN
#include"../Tasks_2_term/catch.hpp"

#include"faculty.h"

//int main() {
//	Teacher* t = new Teacher("John");
//	t->CreateCourse("Algebra", 30);
//	Student* s1 = new Student("M");
//	Student* s2 = new Student("N");
//	s1->ChooseCourse("Algebra", "John");
//	std::vector<int> marks(1, 5);
//	t->SetMarks("Algebra", marks);
//	return 0;
//}

TEST_CASE("All courses") {
	AllCourses* all = AllCourses::GetInstance();
	std::vector<Course*> c = all->GetAllCourses();
	REQUIRE(c.size() == 0);
	Teacher* t = new Teacher("bon");
	t->CreateCourse("A", 1);
	c = all->GetAllCourses();
	REQUIRE(c.size() == 1);
	REQUIRE(c == t->GetCourses());
}

TEST_CASE("Teacher") {
	Teacher* t = new Teacher("John Bon");
	std::string nameCourse1 = "Algebra";
	std::string nameCourse2 = "Geometry";
	SECTION("Create course") {
		t->CreateCourse(nameCourse1, 30);
		std::vector<Course*> c = t->GetCourses();
		REQUIRE(c.size() == 1);
		REQUIRE(c[0]->GetTeacher() == t);
		REQUIRE(c[0]->GetName() == nameCourse1);
		t->CreateCourse(nameCourse2, 2);
		c = t->GetCourses();
		REQUIRE(c.size() == 2);
		SECTION("set marks") {
			Student* s1 = new Student("Mark");
			SECTION("true or false") {
				REQUIRE(t->SetMarks("Algebra", std::vector<int>(1, 5)) == false);
				REQUIRE(t->SetMarks("Algebra", std::vector<int>(0)) == true);
				s1->ChooseCourse("Algebra", "John Bon");
				REQUIRE(t->SetMarks("Algebra", std::vector<int>(1, 2)) == false); // course was finished in second require in current section
/*!!!!!!!!*/		SECTION("file check") { // this test clean file 
					s1->ChooseCourse("Geometry", "John Bon");
					Student* s2 = new Student("Anna");
					s2->ChooseCourse("Geometry", "John Bon");
					std::ofstream arch("archive.txt", std::ofstream::trunc); // file should be empty to great test
					arch.close();
					std::vector<int> marks(2, 5);
					t->SetMarks("Geometry", marks);
					std::ifstream in("archive.txt");
					std::string temp;
					std::getline(in, temp);
					REQUIRE(temp == "Course: Geometry Teacher: John Bon");
					std::getline(in, temp);
					REQUIRE(temp == "Mark 5");
					std::getline(in, temp);
					REQUIRE(temp == "Anna 5");
					std::getline(in, temp);
					REQUIRE(temp == "");
					REQUIRE(in.eof() == true);
				}
			}
		}
	}	
}


TEST_CASE("Course") {
	Teacher* t = new Teacher("John");
	t->CreateCourse("Algebra", 1);
	Student* s = new Student("Anna");
	Student* s1 = new Student("b");
	SECTION("Add students") {
		REQUIRE(t->GetCourses()[0]->AddStudent(s) == true);
		REQUIRE(t->GetCourses()[0]->AddStudent(s) == false);
		REQUIRE(t->GetCourses()[0]->AddStudent(s1) == false);
		SECTION("finished course") {
			t->CreateCourse("G", 2);
			t->SetMarks("G", std::vector<int>(0));
			REQUIRE(t->GetCourses()[0]->AddStudent(s) == false);
		}
	}
}

TEST_CASE("Student") {
	SECTION("ChooseCourse") {
		Teacher* t = new Teacher("T");
		t->CreateCourse("Math", 5);
		Student* s = new Student("S");
		REQUIRE(s->ChooseCourse("Math", "T") == true);
		REQUIRE(t->GetCourses()[0]->GetStudents().size() == 1);
		REQUIRE(t->GetCourses()[0]->GetStudents()[0] == s);
	}
}