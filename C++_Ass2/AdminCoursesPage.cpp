#include "AdminCoursesPage.h"
#include "AdminPage.h"

using namespace System;
using namespace System::Windows::Forms;

namespace CAss2 {
	System::Void AdminCoursesPage::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CAss2::AdminPage^ admin = gcnew CAss2::AdminPage(AdminCode);
		AdminCoursesPage::CloseCurrentPopup();
		admin->Show();
		this->Hide();
	}
}

