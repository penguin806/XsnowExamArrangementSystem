// 雪峰排考系统 - Xuefeng.h
// Copyright (c) 雪峰 2016
// Date: 2016-12-25
// Website: www.xsnow.moe
// E-mail: admin@xsnow.moe

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_STUDENTS_PER_ROOM 30

class COURSE
{
public:
	int Id;				//课程代码
	string Name;		//课程名称
};

class STUDENT
{
public:
	string Id;			//学号
	string Name;		//学生姓名
	vector<string> ExamCourseName;		//要考的科目
	int CurSession;		//目前在进行的考试场次
};

class ROOM
{
public:
	int Id;				//考场号
	string Name;		//考场名字
};

class RESULT
{
public:
	int Session;		//第几场
	int RoomId;			//在哪个考室考
	string CourseName;	//考什么
	string StudentName;	//学生姓名
};

class XFExamSystem
{
public:
	XFExamSystem();				// 构造函数调用成员函数输入各种信息
	~XFExamSystem();

	void InputCoursesInfo();	// 输入课程信息
	void InputStudentsInfo();	// 输入学生信息
	void InputRoomsInfo();		// 输入考室信息
	void ExamArrange();			// 安排考试
	void OutputExamSchedule();	// 输出排考结果
	bool AreAllStudentsFinished();	// 检查是否所有学生已考完

private:
	vector<COURSE> Courses;
	vector<STUDENT> Students;
	vector<ROOM> Rooms;

	int curSession;					// 当前在进行哪一场考试
	vector<RESULT>Results;			// 排考结果
};