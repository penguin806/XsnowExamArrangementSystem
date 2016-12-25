// ѩ���ſ�ϵͳ - Xuefeng.cpp
// Copyright (c) ѩ�� 2016
// 2016-12-25
// Website: www.xsnow.moe
// E-mail: admin@xsnow.moe

#include "Xuefeng.h"

XFExamSystem::XFExamSystem()
{
	int n;		//n: �γ�����

	cout << "����: �γ�����" << endl;
	cin >> n;

	cout << "����: �γ̴��� �γ�����" << endl;
	for (int i = 0; i < n; i++)
	{
		this->InputCoursesInfo();
	}
	cout << "�γ���Ϣ�������" << endl <<endl;


	int m;		//m: ��������

	cout << "����: ��������" << endl;
	cin >> m;

	cout << "����: ������� ��������" << endl;
	for (int i = 0; i < m; i++)
	{
		this->InputRoomsInfo();
	}
	cout << "������Ϣ�������" << endl << endl;

	int s;		// s: ѧ����
	cout << "����ѧ����:" << endl;
	cin >> s;

	cout << "����: \tѧ��\t����\t�����γ�1\t�����γ�2 -- \
�����γ�n #" << endl;
	cout << "Eg: \t001\tѩ��\t����\t��ѧ\tӢ��\t#(�س�)" << endl;

	for (int i = 0; i < s; i++)
	{
		this->InputStudentsInfo();
	}
	cout << "ѧ����Ϣ�������" << endl << endl;
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

void XFExamSystem::ExamArrange()		// �ſ�
{										// �Ƚ��� ע�;Ͳ�д��
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

void XFExamSystem::OutputExamSchedule()		// ������
{
	this->curSession = 1;

	do
	{
		this->ExamArrange();
		this->curSession++;
	} while (this->AreAllStudentsFinished() == false);
	
	cout << endl << "���԰��ű�: " << endl;

	for (auto res = this->Results.begin();
		res != this->Results.end();
		res++)
	{
		cout << "��" << res->Session << "��" << "\t"
			<< "����: " << res->RoomId << "\t"
			<< "ѧ������: " << res->StudentName << "\t"
			<< "��Ŀ: " << res->CourseName << endl << endl;
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
