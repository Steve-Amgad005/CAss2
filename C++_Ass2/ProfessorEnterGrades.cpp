#include "ProfessorEnterGrades.h"
#include "ProfessorPage.h"

using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {

	System::Void ProfessorEnterGrades::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show ProfessorPage and hide this form
		CAss2::ProfessorPage^ profPage = gcnew CAss2::ProfessorPage();
		profPage->Show();
		this->Hide();
	}

	// some designer code wired button to button1_Click_1; implement the same behavior
	System::Void ProfessorEnterGrades::button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		CAss2::ProfessorPage^ profPage = gcnew CAss2::ProfessorPage();
		profPage->Show();
		this->Hide();
	}

}

