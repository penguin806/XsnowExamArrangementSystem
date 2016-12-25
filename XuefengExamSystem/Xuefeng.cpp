// 雪峰排考系统 - Xuefeng.cpp
// Copyright (c) 雪峰 2016
// 2016-12-25
// Website: www.xsnow.moe
// E-mail: admin@xsnow.moe

#include "Xuefeng.h"

XFExamSystem::XFExamSystem()
{
	int n;		//n: 课程数量

	cout << "输入: 课程数量" << endl;
	cin >> n;

	cout << "输入: 课程代码 课程名称" << endl;
	for (int i = 0; i < n; i++)
	{
		this->InputCoursesInfo();
	}
	cout << "课程信息输入完成" << endl <<endl;


	int m;		//m: 考场数量

	cout << "输入: 考场数量" << endl;
	cin >> m;

	cout << "输入: 考场编号 考场名称" << endl;
	for (int i = 0; i < m; i++)
	{
		this->InputRoomsInfo();
	}
	cout << "考场信息输入完成" << endl << endl;

	int s;		// s: 学生数
	cout << "输入学生数:" << endl;
	cin >> s;

	cout << "输入: \t学号\t姓名\t报考课程1\t报考课程2 -- \
报考课程n #" << endl;
	cout << "Eg: \t001\t雪峰\t语文\t数学\t英语\t#(回车)" << endl;

	for (int i = 0; i < s; i++)
	{
		this->InputStudentsInfo();
	}
	cout << "学生信息输入完成" << endl << endl;
}

XFExamSystem::~XFExamSystem()
{

}

void XFExamSystem::InputCoursesInfo()
{
	COURSE Temp;
	cin >> Temp.Id;
	cin >> Temp.Name;

	this->Courses.push_back(Temp);
}

void XFExamSystem::InputRoomsInfo()
{
	ROOM Temp;
	cin >> Temp.Id;
	cin >> Temp.Name;

	this->Rooms.push_back(Temp);
}

void XFExamSystem::InputStudentsInfo()
{
	STUDENT Temp;
	string Buffer;

	Temp.CurSession = -1;
	cin >> Temp.Id;
	cin >> Temp.Name;
	do
	{
		cin >> Buffer;
		if (Buffer != "#")
		{
			Temp.ExamCourseName.push_back(Buffer);
		}
		else
		{
			break;
		}
	} while (true);

	this->Students.push_back(Temp);
}

void XFExamSystem::ExamArrange()		// 排考
{										// 比较懒 注释就不写了
	auto curRoom = this->Rooms.begin();
	for (auto cour = this->Courses.begin();
		cour != this->Courses.end();
		)
	{
		for (auto stu = this->Students.begin();
			stu != this->Students.end();
			stu++)
		{
			for (auto stuCour = stu->ExamCourseName.begin();
				stuCour != stu->ExamCourseName.end();)
			{
				if (*stuCour == cour->Name)
				{
					if (stu->CurSession == this->curSession)
					{
						break;
					}
					else
					{
						RESULT Temp;
						Temp.Session = this->curSession;
						Temp.RoomId = curRoom->Id;
						Temp.CourseName = cour->Name;
						Temp.StudentName = stu->Name;
						this->Results.push_back(Temp);
						stu->CurSession = this->curSession;

						stu->ExamCourseName.erase(stuCour);
						break;
					}
				}
				else
				{
					stuCour++;
				}
			}
		}

		curRoom++;
		if (curRoom == this->Rooms.end())
		{
			this->curSession++;
			curRoom = this->Rooms.begin();
		}

		cour++;
	}

}

void XFExamSystem::OutputExamSchedule()		// 输出结果
{
	this->curSession = 1;

	do
	{
		this->ExamArrange();
		this->curSession++;
	} while (this->AreAllStudentsFinished() == false);
	
	cout << endl << "考试安排表: " << endl;

	for (auto res = this->Results.begin();
		res != this->Results.end();
		res++)
	{
		cout << "第" << res->Session << "场" << "\t"
			<< "考室: " << res->RoomId << "\t"
			<< "学生姓名: " << res->StudentName << "\t"
			<< "科目: " << res->CourseName << endl << endl;
	}
}

bool XFExamSystem::AreAllStudentsFinished()
{
	for (auto cour = this->Courses.begin();
		cour != this->Courses.end();
		cour++)
	{
		for (auto stu = this->Students.begin();
			stu != this->Students.end();
			stu++)
		{
			for (auto stuCour = stu->ExamCourseName.begin();
				stuCour != stu->ExamCourseName.end();
				stuCour++)
			{
				if (*stuCour == cour->Name)
				{
					return false;
				}
			}
		}
	}

	return true;
}
