#pragma once

namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for AdminModifyAssistants
	/// </summary>
	public ref class AdminModifyAssistants : public System::Windows::Forms::Form
	{
	private:
		int currentAssistantId = -1;

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
		AdminModifyAssistants(void)
		{
			InitializeComponent(); 
			//LoadDepartments();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminModifyAssistants()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckedListBox^ checkedListBoxCourses;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtAssistantCode;



	private: System::Windows::Forms::CheckedListBox^ checkedListBoxDepartments;

	private: System::Windows::Forms::Button^ ChoosePicture;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtNID;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ picStudent;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::CheckedListBox^ checkedListBoxProfessors;
	private: System::Windows::Forms::Label^ label8;

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
			this->checkedListBoxCourses = (gcnew System::Windows::Forms::CheckedListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtAssistantCode = (gcnew System::Windows::Forms::TextBox());
			this->checkedListBoxDepartments = (gcnew System::Windows::Forms::CheckedListBox());
			this->ChoosePicture = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtNID = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->picStudent = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->checkedListBoxProfessors = (gcnew System::Windows::Forms::CheckedListBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picStudent))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkedListBoxCourses
			// 
			this->checkedListBoxCourses->FormattingEnabled = true;
			this->checkedListBoxCourses->Location = System::Drawing::Point(191, 333);
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
			this->label7->Location = System::Drawing::Point(24, 342);
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
			this->button3->Location = System::Drawing::Point(232, 80);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 33);
			this->button3->TabIndex = 32;
			this->button3->Text = L"Show";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdminModifyAssistants::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(24, 32);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(134, 24);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Assistant Code";
			// 
			// txtAssistantCode
			// 
			this->txtAssistantCode->Location = System::Drawing::Point(191, 29);
			this->txtAssistantCode->Multiline = true;
			this->txtAssistantCode->Name = L"txtAssistantCode";
			this->txtAssistantCode->Size = System::Drawing::Size(214, 33);
			this->txtAssistantCode->TabIndex = 29;
			// 
			// checkedListBoxDepartments
			// 
			this->checkedListBoxDepartments->FormattingEnabled = true;
			this->checkedListBoxDepartments->Location = System::Drawing::Point(191, 221);
			this->checkedListBoxDepartments->Name = L"checkedListBoxDepartments";
			this->checkedListBoxDepartments->Size = System::Drawing::Size(214, 49);
			this->checkedListBoxDepartments->TabIndex = 6;
			// 
			// ChoosePicture
			// 
			this->ChoosePicture->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ChoosePicture->ForeColor = System::Drawing::Color::Purple;
			this->ChoosePicture->Location = System::Drawing::Point(191, 505);
			this->ChoosePicture->Name = L"ChoosePicture";
			this->ChoosePicture->Size = System::Drawing::Size(214, 33);
			this->ChoosePicture->TabIndex = 27;
			this->ChoosePicture->Text = L"Choose Picture";
			this->ChoosePicture->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(24, 508);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 24);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Picture";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(24, 128);
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
			this->label4->Location = System::Drawing::Point(24, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 24);
			this->label4->TabIndex = 16;
			this->label4->Text = L"NID";
			// 
			// txtNID
			// 
			this->txtNID->Location = System::Drawing::Point(191, 172);
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
			this->label5->Location = System::Drawing::Point(24, 231);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(107, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Department";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(191, 125);
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
			this->button2->Location = System::Drawing::Point(96, 556);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Modify";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminModifyAssistants::button2_Click);
			// 
			// picStudent
			// 
			this->picStudent->Location = System::Drawing::Point(13, 18);
			this->picStudent->Name = L"picStudent";
			this->picStudent->Size = System::Drawing::Size(100, 104);
			this->picStudent->TabIndex = 11;
			this->picStudent->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(128, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(298, 39);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Modify Assistant ";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->checkedListBoxProfessors);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->checkedListBoxCourses);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->txtAssistantCode);
			this->panel1->Controls->Add(this->checkedListBoxDepartments);
			this->panel1->Controls->Add(this->ChoosePicture);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtNID);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->txtName);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(39, 141);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 624);
			this->panel1->TabIndex = 9;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Purple;
			this->button4->Location = System::Drawing::Point(217, 395);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(156, 33);
			this->button4->TabIndex = 42;
			this->button4->Text = L"Show Professors";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &AdminModifyAssistants::button4_Click);
			// 
			// checkedListBoxProfessors
			// 
			this->checkedListBoxProfessors->FormattingEnabled = true;
			this->checkedListBoxProfessors->Location = System::Drawing::Point(191, 450);
			this->checkedListBoxProfessors->Name = L"checkedListBoxProfessors";
			this->checkedListBoxProfessors->Size = System::Drawing::Size(214, 49);
			this->checkedListBoxProfessors->TabIndex = 40;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(24, 459);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 24);
			this->label8->TabIndex = 41;
			this->label8->Text = L"Doctor";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Purple;
			this->button1->Location = System::Drawing::Point(217, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 33);
			this->button1->TabIndex = 39;
			this->button1->Text = L"Show Courses";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminModifyAssistants::button1_Click);
			// 
			// AdminModifyAssistants
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 788);
			this->Controls->Add(this->picStudent);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminModifyAssistants";
			this->Text = L"AdminModifyAssistants";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picStudent))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (checkedListBoxDepartments->CheckedItems->Count == 0)
		{
			MessageBox::Show("Select at least one department");
			return;
		}

		List<String^>^ deptIds = gcnew List<String^>();

		for each (Object ^ obj in checkedListBoxDepartments->CheckedItems)
		{
			DataRowView^ item = safe_cast<DataRowView^>(obj);
			deptIds->Add(item["id"]->ToString());
		}

		array<String^>^ arr = deptIds->ToArray();
		String^ inClause = String::Join(",", arr);

		String^ connStr =
			"Server=localhost\\SQLEXPRESS;"
			"Database=MyDB;"
			"Trusted_Connection=True;"
			"TrustServerCertificate=True;";

		SqlConnection^ conn = gcnew SqlConnection(connStr);

		String^ query =
			"SELECT DISTINCT c.id, c.course_name "
			"FROM Courses c "
			"INNER JOIN CourseDepartments cd ON c.id = cd.course_id "
			"WHERE cd.department_id IN (" + inClause + ")";

		SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
		DataTable^ dt = gcnew DataTable();
		da->Fill(dt);

		checkedListBoxCourses->DataSource = dt;
		checkedListBoxCourses->DisplayMember = "course_name";
		checkedListBoxCourses->ValueMember = "id";
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (checkedListBoxCourses->CheckedItems->Count == 0)
	{
		MessageBox::Show("Select at least one course");
		return;
	}

	List<String^>^ courseIds = gcnew List<String^>();

	for each (Object ^ obj in checkedListBoxCourses->CheckedItems)
	{
		DataRowView^ item = safe_cast<DataRowView^>(obj);
		courseIds->Add(item["id"]->ToString());
	}

	array<String^>^ arr = courseIds->ToArray();
	String^ inClause = String::Join(",", arr);

	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	String^ query =
		"SELECT DISTINCT p.id, p.name "
		"FROM Professors p "
		"INNER JOIN ProfessorCourses pc ON p.id = pc.professor_id "
		"WHERE pc.course_id IN (" + inClause + ")";

	SqlDataAdapter^ da = gcnew SqlDataAdapter(query, conn);
	DataTable^ dt = gcnew DataTable();
	da->Fill(dt);

	checkedListBoxProfessors->DataSource = dt;
	checkedListBoxProfessors->DisplayMember = "name";
	checkedListBoxProfessors->ValueMember = "id";
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(txtAssistantCode->Text))
	{
		MessageBox::Show("Enter assistant code");
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

		// ================= Assistant Basic Info =================
		SqlCommand^ cmd = gcnew SqlCommand(
			"SELECT id, name, NationalNumber FROM Assistants WHERE code = @code",
			conn);

		cmd->Parameters->AddWithValue("@code", txtAssistantCode->Text);

		SqlDataReader^ dr = cmd->ExecuteReader();

		if (!dr->Read())
		{
			MessageBox::Show("Assistant not found");
			dr->Close();
			return;
		}

		currentAssistantId = Convert::ToInt32(dr["id"]);
		txtName->Text = dr["name"]->ToString();
		txtNID->Text = dr["NationalNumber"]->ToString();

		dr->Close();

		// ================= Load ALL Departments =================
		SqlDataAdapter^ daDepts = gcnew SqlDataAdapter(
			"SELECT id, name FROM Departments",
			conn);

		DataTable^ dtDepts = gcnew DataTable();
		daDepts->Fill(dtDepts);

		checkedListBoxDepartments->DataSource = dtDepts;
		checkedListBoxDepartments->DisplayMember = "name";
		checkedListBoxDepartments->ValueMember = "id";

		// ================= Assistant Departments =================
		SqlCommand^ cmdDeptIds = gcnew SqlCommand(
			"SELECT DISTINCT cd.department_id "
			"FROM AssistantAssignments aa "
			"INNER JOIN CourseDepartments cd ON aa.course_id = cd.course_id "
			"WHERE aa.assistant_id = @aid",
			conn);

		cmdDeptIds->Parameters->AddWithValue("@aid", currentAssistantId);

		SqlDataReader^ drDept = cmdDeptIds->ExecuteReader();

		List<int>^ deptIds = gcnew List<int>();

		while (drDept->Read())
		{
			deptIds->Add(Convert::ToInt32(drDept["department_id"]));
		}

		drDept->Close();

		for (int i = 0; i < checkedListBoxDepartments->Items->Count; i++)
		{
			DataRowView^ row = (DataRowView^)checkedListBoxDepartments->Items[i];
			int id = Convert::ToInt32(row["id"]);

			if (deptIds->Contains(id))
				checkedListBoxDepartments->SetItemChecked(i, true);
		}

		// ================= Load ALL Courses =================
		SqlDataAdapter^ daCourses = gcnew SqlDataAdapter(
			"SELECT id, course_name FROM Courses",
			conn);

		DataTable^ dtCourses = gcnew DataTable();
		daCourses->Fill(dtCourses);

		checkedListBoxCourses->DataSource = dtCourses;
		checkedListBoxCourses->DisplayMember = "course_name";
		checkedListBoxCourses->ValueMember = "id";

		// ================= Assistant Courses =================
		SqlCommand^ cmdCourseIds = gcnew SqlCommand(
			"SELECT DISTINCT course_id FROM AssistantAssignments WHERE assistant_id = @aid",
			conn);

		cmdCourseIds->Parameters->AddWithValue("@aid", currentAssistantId);

		SqlDataReader^ drCourses = cmdCourseIds->ExecuteReader();

		List<int>^ courseIds = gcnew List<int>();

		while (drCourses->Read())
		{
			courseIds->Add(Convert::ToInt32(drCourses["course_id"]));
		}

		drCourses->Close();

		for (int i = 0; i < checkedListBoxCourses->Items->Count; i++)
		{
			DataRowView^ row = (DataRowView^)checkedListBoxCourses->Items[i];
			int id = Convert::ToInt32(row["id"]);

			if (courseIds->Contains(id))
				checkedListBoxCourses->SetItemChecked(i, true);
		}

		// ================= Load ALL Professors =================
		SqlDataAdapter^ daProf = gcnew SqlDataAdapter(
			"SELECT id, name FROM Professors",
			conn);

		DataTable^ dtProf = gcnew DataTable();
		daProf->Fill(dtProf);

		checkedListBoxProfessors->DataSource = dtProf;
		checkedListBoxProfessors->DisplayMember = "name";
		checkedListBoxProfessors->ValueMember = "id";

		// ================= Assistant Professors =================
		SqlCommand^ cmdProfIds = gcnew SqlCommand(
			"SELECT DISTINCT professor_id FROM AssistantAssignments WHERE assistant_id = @aid",
			conn);

		cmdProfIds->Parameters->AddWithValue("@aid", currentAssistantId);

		SqlDataReader^ drProf = cmdProfIds->ExecuteReader();

		List<int>^ profIds = gcnew List<int>();

		while (drProf->Read())
		{
			profIds->Add(Convert::ToInt32(drProf["professor_id"]));
		}

		drProf->Close();

		for (int i = 0; i < checkedListBoxProfessors->Items->Count; i++)
		{
			DataRowView^ row = (DataRowView^)checkedListBoxProfessors->Items[i];
			int id = Convert::ToInt32(row["id"]);

			if (profIds->Contains(id))
				checkedListBoxProfessors->SetItemChecked(i, true);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
	finally
	{
		conn->Close();
	}


}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentAssistantId == -1)
	{
		MessageBox::Show("Please load assistant first");
		return;
	}

	if (String::IsNullOrWhiteSpace(txtName->Text))
	{
		MessageBox::Show("Enter assistant name");
		return;
	}

	if (String::IsNullOrWhiteSpace(txtNID->Text) || txtNID->Text->Length != 14)
	{
		MessageBox::Show("Enter valid National ID");
		return;
	}

	if (checkedListBoxCourses->CheckedItems->Count == 0 ||
		checkedListBoxProfessors->CheckedItems->Count == 0)
	{
		MessageBox::Show("Select courses and professors");
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

		// ================= Update Assistant Basic Info =================
		SqlCommand^ cmdUpdate = gcnew SqlCommand(
			"UPDATE Assistants SET name=@name, NationalNumber=@nid WHERE id=@id",
			conn);

		cmdUpdate->Parameters->AddWithValue("@name", txtName->Text);
		cmdUpdate->Parameters->AddWithValue("@nid", txtNID->Text);
		cmdUpdate->Parameters->AddWithValue("@id", currentAssistantId);
		cmdUpdate->ExecuteNonQuery();

		// ================= Delete Old Assignments =================
		SqlCommand^ cmdDelete = gcnew SqlCommand(
			"DELETE FROM AssistantAssignments WHERE assistant_id=@id",
			conn);

		cmdDelete->Parameters->AddWithValue("@id", currentAssistantId);
		cmdDelete->ExecuteNonQuery();

		// ================= Insert New Assignments =================
		for each (DataRowView ^ course in checkedListBoxCourses->CheckedItems)
		{
			for each (DataRowView ^ prof in checkedListBoxProfessors->CheckedItems)
			{
				SqlCommand^ cmdAssign = gcnew SqlCommand(
					"INSERT INTO AssistantAssignments "
					"(assistant_id, course_id, professor_id) "
					"VALUES (@aid,@cid,@pid)",
					conn);

				cmdAssign->Parameters->AddWithValue("@aid", currentAssistantId);
				cmdAssign->Parameters->AddWithValue("@cid", course["id"]);
				cmdAssign->Parameters->AddWithValue("@pid", prof["id"]);
				cmdAssign->ExecuteNonQuery();
			}
		}

		MessageBox::Show("Assistant updated successfully ✅");
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
};
}
