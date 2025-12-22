#include "ProfessorPage.h"
#include "Login.h"
#include "ProfessorEnterGrades.h"
#include "ProfessorAttendanceSet.h"

using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {
	// implement the back button click to return to Login
	System::Void ProfessorPage::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::Login^ loginForm = gcnew CAss2::Login();
		loginForm->Show();
		this->Hide();
	}

	System::Void ProfessorPage::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int codeInt = this->ProfID;
		CAss2::ProfessorEnterGrades^ gradesForm = gcnew CAss2::ProfessorEnterGrades(codeInt);
		gradesForm->Show();
		this->Hide();
	}

	System::Void ProfessorPage::button7_Click(System::Object^ sender, System::EventArgs^ e) {
		int codeInt = this->ProfID;
		CAss2::ProfessorAttendanceSet^ attendForm = gcnew CAss2::ProfessorAttendanceSet(codeInt);
		attendForm->Show();
		this->Hide();
	}
}

