// ѩ���ſ�ϵͳ - Xuefeng.h
// Copyright (c) ѩ�� 2016
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
	int Id;				//�γ̴���
	string Name;		//�γ�����
};

class STUDENT
{
public:
	string Id;			//ѧ��
	string Name;		//ѧ������
	vector<string> ExamCourseName;		//Ҫ���Ŀ�Ŀ
	int CurSession;		//Ŀǰ�ڽ��еĿ��Գ���
};

class ROOM
{
public:
	int Id;				//������
	string Name;		//��������
};

class RESULT
{
public:
	int Session;		//�ڼ���
	int RoomId;			//���ĸ����ҿ�
	string CourseName;	//��ʲô
	string StudentName;	//ѧ������
};

class XFExamSystem
{
public:
	XFExamSystem();				// ���캯�����ó�Ա�������������Ϣ
	~XFExamSystem();

	void InputCoursesInfo();	// ����γ���Ϣ
	void InputStudentsInfo();	// ����ѧ����Ϣ
	void InputRoomsInfo();		// ���뿼����Ϣ
	void ExamArrange();			// ���ſ���
	void OutputExamSchedule();	// ����ſ����
	bool AreAllStudentsFinished();	// ����Ƿ�����ѧ���ѿ���

private:
	vector<COURSE> Courses;
	vector<STUDENT> Students;
	vector<ROOM> Rooms;

	int curSession;					// ��ǰ�ڽ�����һ������
	vector<RESULT>Results;			// �ſ����
};