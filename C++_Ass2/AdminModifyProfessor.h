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
	/// Summary for AdminModifyProfessor
	/// </summary>
	public ref class AdminModifyProfessor : public System::Windows::Forms::Form
	{
		void LoadDepartments()
		{
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlDataAdapter^ da =
				gcnew SqlDataAdapter("SELECT id, name FROM Departments", connStr);

			DataTable^ dt = gcnew DataTable();
			da->Fill(dt);

			checkedListBoxDepartments->DataSource = dt;
			checkedListBoxDepartments->DisplayMember = "name";
			checkedListBoxDepartments->ValueMember = "id";

			checkedListBoxDepartments->ClearSelected();
		}

		void LoadCourses()
		{
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlDataAdapter^ da =
				gcnew SqlDataAdapter("SELECT id, course_name FROM Courses", connStr);

			DataTable^ dt = gcnew DataTable();
			da->Fill(dt);

			checkedListBoxCourses->DataSource = dt;
			checkedListBoxCourses->DisplayMember = "course_name";
			checkedListBoxCourses->ValueMember = "id";

			checkedListBoxCourses->ClearSelected();
		}

	public:
		AdminModifyProfessor(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminModifyProfessor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picStudent;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtNID;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtProfCode;


	private: System::Windows::Forms::CheckedListBox^ checkedListBoxDepartments;

	private: System::Windows::Forms::Button^ ChoosePicture;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::CheckedListBox^ checkedListBoxCourses;

	private: System::Windows::Forms::Label^ label7;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->picStudent = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtNID = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkedListBoxCourses = (gcnew System::Windows::Forms::CheckedListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtProfCode = (gcnew System::Windows::Forms::TextBox());
			this->checkedListBoxDepartments = (gcnew System::Windows::Forms::CheckedListBox());
			this->ChoosePicture = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picStudent))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// picStudent
			// 
			this->picStudent->Location = System::Drawing::Point(14, 17);
			this->picStudent->Name = L"picStudent";
			this->picStudent->Size = System::Drawing::Size(100, 104);
			this->picStudent->TabIndex = 8;
			this->picStudent->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(24, 404);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 24);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Picture";
			this->label1->Click += gcnew System::EventHandler(this, &AdminModifyProfessor::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(24, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Full Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(24, 187);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 24);
			this->label4->TabIndex = 16;
			this->label4->Text = L"NID";
			// 
			// txtNID
			// 
			this->txtNID->Location = System::Drawing::Point(191, 188);
			this->txtNID->Multiline = true;
			this->txtNID->Name = L"txtNID";
			this->txtNID->Size = System::Drawing::Size(214, 33);
			this->txtNID->TabIndex = 22;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(24, 247);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(107, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Department";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(191, 141);
			this->txtName->Multiline = true;
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(214, 33);
			this->txtName->TabIndex = 23;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(105, 463);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Modify";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminModifyProfessor::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(120, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(324, 39);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Modify Professors ";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->checkedListBoxCourses);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->txtProfCode);
			this->panel1->Controls->Add(this->checkedListBoxDepartments);
			this->panel1->Controls->Add(this->ChoosePicture);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtNID);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->txtName);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(52, 141);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 577);
			this->panel1->TabIndex = 6;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AdminModifyProfessor::panel1_Paint);
			// 
			// checkedListBoxCourses
			// 
			this->checkedListBoxCourses->FormattingEnabled = true;
			this->checkedListBoxCourses->Location = System::Drawing::Point(191, 312);
			this->checkedListBoxCourses->Name = L"checkedListBoxCourses";
			this->checkedListBoxCourses->Size = System::Drawing::Size(214, 49);
			this->checkedListBoxCourses->TabIndex = 37;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(24, 328);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(80, 24);
			this->label7->TabIndex = 38;
			this->label7->Text = L"Courses";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Purple;
			this->button3->Location = System::Drawing::Point(233, 81);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 33);
			this->button3->TabIndex = 32;
			this->button3->Text = L"Show";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdminModifyProfessor::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(24, 32);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(94, 24);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Prof Code";
			// 
			// txtProfCode
			// 
			this->txtProfCode->Location = System::Drawing::Point(191, 29);
			this->txtProfCode->Multiline = true;
			this->txtProfCode->Name = L"txtProfCode";
			this->txtProfCode->Size = System::Drawing::Size(214, 33);
			this->txtProfCode->TabIndex = 29;
			// 
			// checkedListBoxDepartments
			// 
			this->checkedListBoxDepartments->FormattingEnabled = true;
			this->checkedListBoxDepartments->Location = System::Drawing::Point(191, 237);
			this->checkedListBoxDepartments->Name = L"checkedListBoxDepartments";
			this->checkedListBoxDepartments->Size = System::Drawing::Size(214, 49);
			this->checkedListBoxDepartments->TabIndex = 6;
			// 
			// ChoosePicture
			// 
			this->ChoosePicture->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ChoosePicture->ForeColor = System::Drawing::Color::Purple;
			this->ChoosePicture->Location = System::Drawing::Point(191, 401);
			this->ChoosePicture->Name = L"ChoosePicture";
			this->ChoosePicture->Size = System::Drawing::Size(214, 33);
			this->ChoosePicture->TabIndex = 27;
			this->ChoosePicture->Text = L"Choose Picture";
			this->ChoosePicture->UseVisualStyleBackColor = true;
			this->ChoosePicture->Click += gcnew System::EventHandler(this, &AdminModifyProfessor::ChoosePicture_Click);
			// 
			// AdminModifyProfessor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 730);
			this->Controls->Add(this->picStudent);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminModifyProfessor";
			this->Text = L"AdminModifyProfessor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picStudent))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(txtProfCode->Text))
		{
			MessageBox::Show("Enter Professor Code");
			return;
		}

		if (String::IsNullOrWhiteSpace(txtName->Text))
		{
			MessageBox::Show("Enter professor name");
			return;
		}

		if (String::IsNullOrWhiteSpace(txtNID->Text) || txtNID->Text->Length != 14)
		{
			MessageBox::Show("Enter valid National ID (14 digits)");
			return;
		}

		if (checkedListBoxDepartments->CheckedItems->Count == 0)
		{
			MessageBox::Show("Select at least one department");
			return;
		}

		if (checkedListBoxCourses->CheckedItems->Count == 0)
		{
			MessageBox::Show("Select at least one course");
			return;
		}

		int profCode = Convert::ToInt32(txtProfCode->Text);
		int professorId = 0;

		String^ connStr =
			"Server=localhost\\SQLEXPRESS;"
			"Database=MyDB;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conn = gcnew SqlConnection(connStr);

		try
		{
			conn->Open();

			// =========================
			// 1️⃣ Get Professor ID by Code
			// =========================
			SqlCommand^ cmdGetId = gcnew SqlCommand(
				"SELECT id FROM Professors WHERE code = @code",
				conn);

			cmdGetId->Parameters->AddWithValue("@code", profCode);

			Object^ result = cmdGetId->ExecuteScalar();
			if (result == nullptr)
			{
				MessageBox::Show("Professor not found");
				return;
			}

			professorId = Convert::ToInt32(result);

			// =========================
			// 2️⃣ Update Professor basic data
			// =========================
			SqlCommand^ cmdUpdateProf = gcnew SqlCommand(
				"UPDATE Professors SET name = @name, NationalNumber = @nid WHERE id = @id",
				conn);

			cmdUpdateProf->Parameters->AddWithValue("@name", txtName->Text);
			cmdUpdateProf->Parameters->AddWithValue("@nid", txtNID->Text);
			cmdUpdateProf->Parameters->AddWithValue("@id", professorId);
			cmdUpdateProf->ExecuteNonQuery();

			// =========================
			// 3️⃣ Update Departments
			// =========================
			SqlCommand^ cmdDeleteDepts = gcnew SqlCommand(
				"DELETE FROM ProfessorDepartments WHERE professor_id = @pid",
				conn);

			cmdDeleteDepts->Parameters->AddWithValue("@pid", professorId);
			cmdDeleteDepts->ExecuteNonQuery();

			for each (DataRowView ^ item in checkedListBoxDepartments->CheckedItems)
			{
				SqlCommand^ cmdInsertDept = gcnew SqlCommand(
					"INSERT INTO ProfessorDepartments (professor_id, department_id) VALUES (@pid, @did)",
					conn);

				cmdInsertDept->Parameters->AddWithValue("@pid", professorId);
				cmdInsertDept->Parameters->AddWithValue("@did", item["id"]);
				cmdInsertDept->ExecuteNonQuery();
			}

			// =========================
			// 4️⃣ Update Courses
			// =========================
			SqlCommand^ cmdDeleteCourses = gcnew SqlCommand(
				"DELETE FROM ProfessorCourses WHERE professor_id = @pid",
				conn);

			cmdDeleteCourses->Parameters->AddWithValue("@pid", professorId);
			cmdDeleteCourses->ExecuteNonQuery();

			for each (DataRowView ^ item in checkedListBoxCourses->CheckedItems)
			{
				SqlCommand^ cmdInsertCourse = gcnew SqlCommand(
					"INSERT INTO ProfessorCourses (professor_id, course_id) VALUES (@pid, @cid)",
					conn);

				cmdInsertCourse->Parameters->AddWithValue("@pid", professorId);
				cmdInsertCourse->Parameters->AddWithValue("@cid", item["id"]);
				cmdInsertCourse->ExecuteNonQuery();
			}

			MessageBox::Show("Professor updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Error");
		}
		finally
		{
			conn->Close();
		}

	}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(txtProfCode->Text))
	{
		MessageBox::Show("Enter Professor Code");
		return;
	}

	int profCode = Convert::ToInt32(txtProfCode->Text);
	int professorId = 0;

	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	try
	{
		conn->Open();

		// =======================
		// 1️⃣ Professor main data (BY CODE)
		// =======================
		SqlCommand^ cmdProf = gcnew SqlCommand(
			"SELECT id, name, NationalNumber FROM Professors WHERE code = @code",
			conn);

		cmdProf->Parameters->AddWithValue("@code", profCode);

		SqlDataReader^ dr = cmdProf->ExecuteReader();

		if (!dr->Read())
		{
			MessageBox::Show("Professor not found");
			dr->Close();
			return;
		}

		professorId = Convert::ToInt32(dr["id"]);
		txtName->Text = dr["name"]->ToString();
		txtNID->Text = dr["NationalNumber"]->ToString();
		dr->Close();

		// =======================
		// 2️⃣ Load Departments
		// =======================
		LoadDepartments();

		SqlCommand^ cmdDept = gcnew SqlCommand(
			"SELECT department_id FROM ProfessorDepartments WHERE professor_id = @pid",
			conn);

		cmdDept->Parameters->AddWithValue("@pid", professorId);

		SqlDataReader^ drDept = cmdDept->ExecuteReader();

		while (drDept->Read())
		{
			int deptId = Convert::ToInt32(drDept["department_id"]);

			for (int i = 0; i < checkedListBoxDepartments->Items->Count; i++)
			{
				DataRowView^ row =
					safe_cast<DataRowView^>(checkedListBoxDepartments->Items[i]);

				if (Convert::ToInt32(row["id"]) == deptId)
				{
					checkedListBoxDepartments->SetItemChecked(i, true);
				}
			}
		}
		drDept->Close();

		// =======================
		// 3️⃣ Load Courses
		// =======================
		LoadCourses();

		SqlCommand^ cmdCourse = gcnew SqlCommand(
			"SELECT course_id FROM ProfessorCourses WHERE professor_id = @pid",
			conn);

		cmdCourse->Parameters->AddWithValue("@pid", professorId);

		SqlDataReader^ drCourse = cmdCourse->ExecuteReader();

		while (drCourse->Read())
		{
			int courseId = Convert::ToInt32(drCourse["course_id"]);

			for (int i = 0; i < checkedListBoxCourses->Items->Count; i++)
			{
				DataRowView^ row =
					safe_cast<DataRowView^>(checkedListBoxCourses->Items[i]);

				if (Convert::ToInt32(row["id"]) == courseId)
				{
					checkedListBoxCourses->SetItemChecked(i, true);
				}
			}
		}
		drCourse->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Error");
	}
	finally
	{
		conn->Close();
	}
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ChoosePicture_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
