#include "ProfessorAttendanceSet.h"
#include "ProfessorPage.h"

using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {

	System::Void ProfessorAttendanceSet::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::ProfessorPage^ profPage = gcnew CAss2::ProfessorPage();
		profPage->Show();
		this->Hide();
	}

}

