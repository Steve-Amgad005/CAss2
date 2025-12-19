#include "AdminPage.h"
#include "Login.h"
#include "AdminStudentsPage.h"
#include "AdminDepartmentPage.h"
#include "AdminBuildingsPage.h"
#include "AdminLapsPage.h"
#include "AdminHallsPage.h"

using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {
	// implement Back button handler: show Login form and hide AdminPage
	System::Void AdminPage::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::Login^ loginForm = gcnew CAss2::Login();
		loginForm->Show();
		this->Hide();
	}

	// implement Students button handler: open AdminStudentsPage
	System::Void AdminPage::button4_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::AdminStudentsPage^ studentsPage = gcnew CAss2::AdminStudentsPage(AdminCode);
		studentsPage->Show();
		this->Hide();
	}

	// implement Departments button handler: open AdminDepartmentPage
	System::Void AdminPage::button3_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::AdminDepartmentPage^ deptPage = gcnew CAss2::AdminDepartmentPage(AdminCode);
		deptPage->Show();
		this->Hide();
	}
System::Void AdminPage::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	AdminBuildingsPage^ buildingsPage = gcnew AdminBuildingsPage(AdminCode);
	buildingsPage->Show();
	this->Close();
}
System::Void AdminPage::button6_Click(System::Object^ sender, System::EventArgs^ e) {
	AdminLapsPage^ lapsPage = gcnew AdminLapsPage(AdminCode);
	lapsPage->Show();
	this->Close();
}
System::Void AdminPage::button7_Click(System::Object^ sender, System::EventArgs^ e) {
	AdminHallsPage^ hallsPage = gcnew AdminHallsPage(AdminCode);
	hallsPage->Show();
	this->Close();
}
}

