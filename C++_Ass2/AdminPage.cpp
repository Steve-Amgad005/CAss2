#include "AdminPage.h"
#include "Login.h"
#include "AdminStudentsPage.h"
#include "AdminDepartmentPage.h"

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
		CAss2::AdminStudentsPage^ studentsPage = gcnew CAss2::AdminStudentsPage();
		studentsPage->Show();
		this->Hide();
	}

	// implement Departments button handler: open AdminDepartmentPage
	System::Void AdminPage::button3_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::AdminDepartmentPage^ deptPage = gcnew CAss2::AdminDepartmentPage();
		deptPage->Show();
		this->Hide();
	}
}

