#pragma once

namespace CAss2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Drawing::Imaging;
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Summary for AdminAddStudent
	/// </summary>
	public ref class AdminAddStudent : public System::Windows::Forms::Form
	{
		void LoadDeptsInCMB() {
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlConnection^ conn = gcnew SqlConnection(connStr);

			try
			{
				conn->Open();

				SqlDataAdapter^ da = gcnew SqlDataAdapter(
					"SELECT id, name FROM Departments",
					conn);

				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				cmbDepartment->DataSource = dt;
				cmbDepartment->DisplayMember = "name"; // اللي هيظهر
				cmbDepartment->ValueMember = "id";     // اللي هيتخزن
				cmbDepartment->SelectedIndex = -1;     // مفيش اختيار افتراضي

				conn->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Error");
			}
		}

	public:
		AdminAddStudent(void)
		{
			InitializeComponent();
			LoadDeptsInCMB();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminAddStudent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;


	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtNID;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtName;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ cmbDepartment;

	private: System::Windows::Forms::ComboBox^ cmbYear;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ ChoosePicture;


	private: System::Windows::Forms::TextBox^ txtFees;
	private: System::Windows::Forms::PictureBox^ picStudent;
	private: System::Windows::Forms::ComboBox^ cmbFeesStatus;





	protected:

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtFees = (gcnew System::Windows::Forms::TextBox());
			this->ChoosePicture = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbYear = (gcnew System::Windows::Forms::ComboBox());
			this->cmbDepartment = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtNID = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->picStudent = (gcnew System::Windows::Forms::PictureBox());
			this->cmbFeesStatus = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picStudent))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->cmbFeesStatus);
			this->panel1->Controls->Add(this->txtFees);
			this->panel1->Controls->Add(this->ChoosePicture);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->cmbYear);
			this->panel1->Controls->Add(this->cmbDepartment);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtNID);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->txtName);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Location = System::Drawing::Point(40, 147);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 451);
			this->panel1->TabIndex = 0;
			// 
			// txtFees
			// 
			this->txtFees->Location = System::Drawing::Point(190, 300);
			this->txtFees->Multiline = true;
			this->txtFees->Name = L"txtFees";
			this->txtFees->Size = System::Drawing::Size(214, 33);
			this->txtFees->TabIndex = 28;
			// 
			// ChoosePicture
			// 
			this->ChoosePicture->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ChoosePicture->ForeColor = System::Drawing::Color::Purple;
			this->ChoosePicture->Location = System::Drawing::Point(190, 250);
			this->ChoosePicture->Name = L"ChoosePicture";
			this->ChoosePicture->Size = System::Drawing::Size(214, 33);
			this->ChoosePicture->TabIndex = 27;
			this->ChoosePicture->Text = L"Choose Picture";
			this->ChoosePicture->UseVisualStyleBackColor = true;
			this->ChoosePicture->Click += gcnew System::EventHandler(this, &AdminAddStudent::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(23, 250);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 24);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Picture";
			this->label1->Click += gcnew System::EventHandler(this, &AdminAddStudent::label1_Click);
			// 
			// cmbYear
			// 
			this->cmbYear->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbYear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbYear->FormattingEnabled = true;
			this->cmbYear->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"First Year", L"Second Year", L"Third Year", L"Fourth Year" });
			this->cmbYear->Location = System::Drawing::Point(190, 192);
			this->cmbYear->Name = L"cmbYear";
			this->cmbYear->Size = System::Drawing::Size(214, 33);
			this->cmbYear->TabIndex = 25;
			// 
			// cmbDepartment
			// 
			this->cmbDepartment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDepartment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbDepartment->FormattingEnabled = true;
			this->cmbDepartment->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ICT", L"Petrol", L"Mechatronics", L"Autotronics",
					L"Renewable Energy"
			});
			this->cmbDepartment->Location = System::Drawing::Point(190, 141);
			this->cmbDepartment->Name = L"cmbDepartment";
			this->cmbDepartment->Size = System::Drawing::Size(214, 33);
			this->cmbDepartment->TabIndex = 24;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(23, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Full Name";
			this->label3->Click += gcnew System::EventHandler(this, &AdminAddStudent::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(23, 90);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 24);
			this->label4->TabIndex = 16;
			this->label4->Text = L"NID";
			this->label4->Click += gcnew System::EventHandler(this, &AdminAddStudent::label4_Click);
			// 
			// txtNID
			// 
			this->txtNID->Location = System::Drawing::Point(190, 91);
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
			this->label5->Location = System::Drawing::Point(23, 145);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(107, 24);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Department";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(190, 44);
			this->txtName->Multiline = true;
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(214, 33);
			this->txtName->TabIndex = 23;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(23, 196);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 24);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Year";
			this->label6->Click += gcnew System::EventHandler(this, &AdminAddStudent::label6_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(102, 359);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminAddStudent::button2_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(23, 309);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 24);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Fees";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(164, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(217, 39);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Add Student";
			this->label2->Click += gcnew System::EventHandler(this, &AdminAddStudent::label2_Click);
			// 
			// picStudent
			// 
			this->picStudent->Location = System::Drawing::Point(40, 23);
			this->picStudent->Name = L"picStudent";
			this->picStudent->Size = System::Drawing::Size(100, 104);
			this->picStudent->TabIndex = 2;
			this->picStudent->TabStop = false;
			// 
			// cmbFeesStatus
			// 
			this->cmbFeesStatus->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbFeesStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbFeesStatus->FormattingEnabled = true;
			this->cmbFeesStatus->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Paid", L"Unpaid" });
			this->cmbFeesStatus->Location = System::Drawing::Point(92, 300);
			this->cmbFeesStatus->Name = L"cmbFeesStatus";
			this->cmbFeesStatus->Size = System::Drawing::Size(82, 33);
			this->cmbFeesStatus->TabIndex = 29;
			// 
			// AdminAddStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 621);
			this->Controls->Add(this->picStudent);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Name = L"AdminAddStudent";
			this->Text = L"AdminAddStudent";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picStudent))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ ofd = gcnew OpenFileDialog();

	// Allow only PNG & JPG
	ofd->Filter = "Image Files (*.png;*.jpg;*.jpeg)|*.png;*.jpg;*.jpeg";
	ofd->Title = "Select Student Image";

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// Free old image (important)
		if (picStudent->Image != nullptr)
		{
			delete picStudent->Image;
			picStudent->Image = nullptr;
		}

		picStudent->Image = Image::FromFile(ofd->FileName);
		picStudent->SizeMode = PictureBoxSizeMode::StretchImage;
	}

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	// ==========================
	// Validation
	// ==========================

	if (String::IsNullOrWhiteSpace(txtName->Text))
	{
		MessageBox::Show("Please enter student name");
		return;
	}

	if (String::IsNullOrWhiteSpace(txtNID->Text) || txtNID->Text->Length != 14)
	{
		MessageBox::Show("National ID must be 14 digits");
		return;
	}

	int year = 0;
	if (cmbYear->Text == "First Year") year = 1;
	else if (cmbYear->Text == "Second Year") year = 2;
	else if (cmbYear->Text == "Third Year") year = 3;
	else if (cmbYear->Text == "Fourth Year") year = 4;
	else
	{
		MessageBox::Show("Select valid year");
		return;
	}

	if (cmbDepartment->SelectedIndex == -1)
	{
		MessageBox::Show("Select department");
		return;
	}

	if (cmbFeesStatus->SelectedIndex == -1)
	{
		MessageBox::Show("Select fees status");
		return;
	}

	int fees = 0;
	if (cmbFeesStatus->Text != "Not Paid")
	{
		if (String::IsNullOrWhiteSpace(txtFees->Text))
		{
			MessageBox::Show("Enter fees amount");
			return;
		}

		fees = Convert::ToInt32(txtFees->Text);
		if (fees <= 0 || fees > 155000)
		{
			MessageBox::Show("Invalid fees amount");
			return;
		}
	}

	// ==========================
	// Convert Image to byte[]
	// ==========================

	array<Byte>^ imageBytes = nullptr;

	if (picStudent->Image != nullptr)
	{
		System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
		picStudent->Image->Save(ms, System::Drawing::Imaging::ImageFormat::Png);
		imageBytes = ms->ToArray();
	}

	try
	{
		conn->Open();

		// ==========================
		// Generate Code & Seat
		// ==========================

		SqlCommand^ cmdGen = gcnew SqlCommand(
			"SELECT ISNULL(MAX(code),20240000)+1, ISNULL(MAX(seatnumber),1000)+1 FROM Students",
			conn);

		SqlDataReader^ r = cmdGen->ExecuteReader();
		r->Read();
		int code = Convert::ToInt32(r[0]);
		int seat = Convert::ToInt32(r[1]);
		r->Close();

		// ==========================
		// Insert Student WITH Image
		// ==========================

		String^ insertStudent =
			"INSERT INTO Students "
			"(code, seatnumber, NationalNumber, name, year, current_term, department_id, ProfileImage) "
			"OUTPUT INSERTED.id "
			"VALUES (@code,@seat,@nid,@name,@year,1,@dept,@img)";

		SqlCommand^ cmdStudent = gcnew SqlCommand(insertStudent, conn);

		cmdStudent->Parameters->AddWithValue("@code", code);
		cmdStudent->Parameters->AddWithValue("@seat", seat);
		cmdStudent->Parameters->AddWithValue("@nid", txtNID->Text);
		cmdStudent->Parameters->AddWithValue("@name", txtName->Text);
		cmdStudent->Parameters->AddWithValue("@year", year);
		cmdStudent->Parameters->AddWithValue("@dept", cmbDepartment->SelectedValue);
		cmdStudent->Parameters->AddWithValue("@img",
			imageBytes != nullptr ? (Object^)imageBytes : DBNull::Value);

		int studentId = Convert::ToInt32(cmdStudent->ExecuteScalar());

		// ==========================
		// Insert Courses
		// ==========================

		SqlCommand^ cmdCourses = gcnew SqlCommand(
			"INSERT INTO StudentCourses (student_id, course_id) "
			"SELECT @sid, c.id "
			"FROM Courses c "
			"INNER JOIN CourseDepartments cd ON c.id = cd.course_id "
			"WHERE cd.department_id = @dept AND c.year = @year",
			conn);

		cmdCourses->Parameters->AddWithValue("@sid", studentId);
		cmdCourses->Parameters->AddWithValue("@dept", cmbDepartment->SelectedValue);
		cmdCourses->Parameters->AddWithValue("@year", year);
		cmdCourses->ExecuteNonQuery();

		// ==========================
		// Insert Fees
		// ==========================

		SqlCommand^ cmdFees = gcnew SqlCommand(
			"INSERT INTO Payments (student_id, amount, status) "
			"VALUES (@sid,@amount,@status)", conn);

		cmdFees->Parameters->AddWithValue("@sid", studentId);
		cmdFees->Parameters->AddWithValue("@amount", fees);
		cmdFees->Parameters->AddWithValue("@status", cmbFeesStatus->Text);
		cmdFees->ExecuteNonQuery();

		MessageBox::Show("Student added successfully ✔");

		conn->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, "Error");
	}

}
};
}
