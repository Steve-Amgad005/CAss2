#pragma once

namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for AdminAddCourse
	/// </summary>
	public ref class AdminAddCourse : public System::Windows::Forms::Form
	{
		void LoadDepartments()
		{
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlConnection^ conn = gcnew SqlConnection(connStr);
			SqlDataAdapter^ da = gcnew SqlDataAdapter("SELECT id, name FROM Departments", conn);

			DataTable^ dt = gcnew DataTable();
			da->Fill(dt);

			checkedListBoxDepartments->DataSource = dt;
			checkedListBoxDepartments->DisplayMember = "name";
			checkedListBoxDepartments->ValueMember = "id";
		}

	public:
		AdminAddCourse(void)
		{
			InitializeComponent();
			LoadDepartments();
			DataTable^ dtYear = gcnew DataTable();
			dtYear->Columns->Add("Text");
			dtYear->Columns->Add("Value", int::typeid);

			dtYear->Rows->Add("First Year", 1);
			dtYear->Rows->Add("Second Year", 2);
			dtYear->Rows->Add("Third Year", 3);
			dtYear->Rows->Add("Fourth Year", 4);

			cmbYear->DataSource = dtYear;
			cmbYear->DisplayMember = "Text";   // اللي المستخدم يشوفه
			cmbYear->ValueMember = "Value";    // اللي يتحفظ
			cmbYear->DropDownStyle = ComboBoxStyle::DropDownList;

			DataTable^ dtTerm = gcnew DataTable();
			dtTerm->Columns->Add("Text");
			dtTerm->Columns->Add("Value", int::typeid);

			dtTerm->Rows->Add("First Term", 1);
			dtTerm->Rows->Add("Second Term", 2);

			cmbTerm->DataSource = dtTerm;
			cmbTerm->DisplayMember = "Text";
			cmbTerm->ValueMember = "Value";
			cmbTerm->DropDownStyle = ComboBoxStyle::DropDownList;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminAddCourse()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtCourseName;



	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::CheckedListBox^ checkedListBoxDepartments;
	private: System::Windows::Forms::ComboBox^ cmbTerm;

	private: System::Windows::Forms::ComboBox^ cmbYear;









	private: System::Windows::Forms::Label^ label6;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->cmbTerm = (gcnew System::Windows::Forms::ComboBox());
			this->cmbYear = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->checkedListBoxDepartments = (gcnew System::Windows::Forms::CheckedListBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(21, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(21, 78);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 24);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Year";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(21, 195);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(116, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Departments";
			// 
			// txtCourseName
			// 
			this->txtCourseName->Location = System::Drawing::Point(188, 32);
			this->txtCourseName->Multiline = true;
			this->txtCourseName->Name = L"txtCourseName";
			this->txtCourseName->Size = System::Drawing::Size(214, 33);
			this->txtCourseName->TabIndex = 23;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(92, 281);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminAddCourse::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(147, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(209, 39);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Add Course";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->cmbTerm);
			this->panel1->Controls->Add(this->cmbYear);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->checkedListBoxDepartments);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->txtCourseName);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(41, 102);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 371);
			this->panel1->TabIndex = 9;
			// 
			// cmbTerm
			// 
			this->cmbTerm->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTerm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbTerm->FormattingEnabled = true;
			this->cmbTerm->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"First", L"Second" });
			this->cmbTerm->Location = System::Drawing::Point(188, 128);
			this->cmbTerm->Name = L"cmbTerm";
			this->cmbTerm->Size = System::Drawing::Size(214, 33);
			this->cmbTerm->TabIndex = 37;
			// 
			// cmbYear
			// 
			this->cmbYear->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbYear->FormattingEnabled = true;
			this->cmbYear->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1st Year", L"2nd Year", L"3rd Year", L"4th Year" });
			this->cmbYear->Location = System::Drawing::Point(188, 78);
			this->cmbYear->Name = L"cmbYear";
			this->cmbYear->Size = System::Drawing::Size(214, 33);
			this->cmbYear->TabIndex = 36;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(22, 132);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 24);
			this->label6->TabIndex = 35;
			this->label6->Text = L"Term";
			// 
			// checkedListBoxDepartments
			// 
			this->checkedListBoxDepartments->FormattingEnabled = true;
			this->checkedListBoxDepartments->Location = System::Drawing::Point(188, 185);
			this->checkedListBoxDepartments->Name = L"checkedListBoxDepartments";
			this->checkedListBoxDepartments->Size = System::Drawing::Size(214, 49);
			this->checkedListBoxDepartments->TabIndex = 6;
			// 
			// AdminAddCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 490);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminAddCourse";
			this->Text = L"AdminAddCourse";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// ==========================
	// 🔍 Validation
	// ==========================
		if (String::IsNullOrWhiteSpace(txtCourseName->Text))
		{
			MessageBox::Show("Please enter course name");
			return;
		}

		if (cmbYear->SelectedIndex == -1)
		{
			MessageBox::Show("Please select course year");
			return;
		}

		if (cmbTerm->SelectedIndex == -1)
		{
			MessageBox::Show("Please select course term");
			return;
		}

		if (checkedListBoxDepartments->CheckedItems->Count == 0)
		{
			MessageBox::Show("Please select at least one department");
			return;
		}

		String^ connStr =
			"Server=localhost\\SQLEXPRESS;"
			"Database=MyDB;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conn = gcnew SqlConnection(connStr);

		try
		{
			conn->Open();

			// ==========================
			// 1️⃣ Insert Course
			// ==========================
			String^ insertCourse =
				"INSERT INTO Courses (course_name, year, term) "
				"OUTPUT INSERTED.id "
				"VALUES (@name, @year, @term)";

			SqlCommand^ cmdCourse = gcnew SqlCommand(insertCourse, conn);
			cmdCourse->Parameters->AddWithValue("@name", txtCourseName->Text);
			int year = safe_cast<int>(cmbYear->SelectedValue);
			int term = safe_cast<int>(cmbTerm->SelectedValue);
			cmdCourse->Parameters->AddWithValue("@year", year);
			cmdCourse->Parameters->AddWithValue("@term", term);

			int courseId = Convert::ToInt32(cmdCourse->ExecuteScalar());

			// ==========================
			// 2️⃣ Insert CourseDepartments
			// ==========================
			String^ insertDept =
				"INSERT INTO CourseDepartments (course_id, department_id) "
				"VALUES (@cid, @did)";

			for each (DataRowView ^ item in checkedListBoxDepartments->CheckedItems)
			{
				SqlCommand^ cmdDept = gcnew SqlCommand(insertDept, conn);
				cmdDept->Parameters->AddWithValue("@cid", courseId);
				cmdDept->Parameters->AddWithValue("@did", item["id"]);
				cmdDept->ExecuteNonQuery();
			}

			MessageBox::Show("Course added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

			conn->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Error");
		}
	}
};
}
