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
	/// Summary for ProfessorAttendanceSet
	/// </summary>
	public ref class ProfessorAttendanceSet : public System::Windows::Forms::Form
	{
	private:
			int professorCode;

			void LoadAttendanceByCourse(int courseId)
			{
				String^ connStr =
					"Server=localhost\\SQLEXPRESS;"
					"Database=MyDB;"
					"Trusted_Connection=True;"
					"TrustServerCertificate=True;";

				SqlConnection^ conn = gcnew SqlConnection(connStr);

				try
				{
					conn->Open();

					String^ query =
						"SELECT "
						"s.code AS [Student Code], "
						"s.name AS [Student Name], "
						"10 AS [Total Lectures], "
						"ISNULL(a.attended_lectures, 0) AS [Attended Lectures] "
						"FROM StudentCourses sc "
						"INNER JOIN Students s ON sc.student_id = s.id "
						"LEFT JOIN Attendance a "
						"ON a.student_id = s.id AND a.course_id = sc.course_id "
						"WHERE sc.course_id = @courseId "
						"ORDER BY s.name";

					SqlCommand^ cmd = gcnew SqlCommand(query, conn);
					cmd->Parameters->AddWithValue("@courseId", courseId);

					SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
					DataTable^ dt = gcnew DataTable();
					da->Fill(dt);

					dataGridViewAttendance->DataSource = dt;
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


		void LoadProfessorCourses(int profCode)
		{
			String^ connStr =
				"Server=localhost\\SQLEXPRESS;"
				"Database=MyDB;"
				"Trusted_Connection=True;"
				"TrustServerCertificate=True;";

			SqlConnection^ conn = gcnew SqlConnection(connStr);

			try
			{
				conn->Open();

				String^ query =
					"SELECT c.id, c.course_name "
					"FROM Courses c "
					"INNER JOIN ProfessorCourses pc ON c.id = pc.course_id "
					"INNER JOIN Professors p ON pc.professor_id = p.id "
					"WHERE p.code = @code";

				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@code", profCode);

				SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				comboBoxCourses->DataSource = dt;
				comboBoxCourses->DisplayMember = "course_name";
				comboBoxCourses->ValueMember = "id";
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

	public:
		ProfessorAttendanceSet(int code)
		{
			InitializeComponent();
			professorCode = code;
			LoadProfessorCourses(professorCode);
			LoadAttendanceByCourse(professorCode);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProfessorAttendanceSet()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;





private: System::Windows::Forms::DataGridView^ dataGridViewAttendance;














	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBoxCourses;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProfessorAttendanceSet::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridViewAttendance = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxCourses = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAttendance))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AccessibleName = L"back";
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(1176, 56);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(41, 39);
			this->button1->TabIndex = 16;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ProfessorAttendanceSet::button1_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->dataGridViewAttendance);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->comboBoxCourses);
			this->panel2->Location = System::Drawing::Point(25, 152);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1122, 419);
			this->panel2->TabIndex = 15;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ProfessorAttendanceSet::panel2_Paint);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Purple;
			this->button3->Location = System::Drawing::Point(110, 197);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(226, 48);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Attend";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ProfessorAttendanceSet::button3_Click);
			// 
			// dataGridViewAttendance
			// 
			this->dataGridViewAttendance->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			this->dataGridViewAttendance->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewAttendance->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::DarkGray;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewAttendance->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewAttendance->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAttendance->Location = System::Drawing::Point(454, 17);
			this->dataGridViewAttendance->Name = L"dataGridViewAttendance";
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			this->dataGridViewAttendance->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewAttendance->Size = System::Drawing::Size(643, 380);
			this->dataGridViewAttendance->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(17, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Select Course";
			// 
			// comboBoxCourses
			// 
			this->comboBoxCourses->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCourses->FormattingEnabled = true;
			this->comboBoxCourses->Location = System::Drawing::Point(235, 39);
			this->comboBoxCourses->Name = L"comboBoxCourses";
			this->comboBoxCourses->Size = System::Drawing::Size(121, 21);
			this->comboBoxCourses->TabIndex = 0;
			this->comboBoxCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &ProfessorAttendanceSet::comboBox1_SelectedIndexChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(25, 27);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1122, 100);
			this->panel1->TabIndex = 14;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(21, 18);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(69, 63);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(262, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(599, 39);
			this->label1->TabIndex = 2;
			this->label1->Text = L"New Cairo Technological University";
			// 
			// ProfessorAttendanceSet
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(1242, 599);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"ProfessorAttendanceSet";
			this->Text = L"ProfessorAttendanceSet";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAttendance))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

	// back button handler declaration
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBoxCourses->SelectedValue == nullptr)
		return;

	if (comboBoxCourses->SelectedValue->GetType() == DataRowView::typeid)
		return;

	int courseId = Convert::ToInt32(comboBoxCourses->SelectedValue);
	LoadAttendanceByCourse(courseId);
}
	  
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridViewAttendance->SelectedRows->Count == 0)
	{
		MessageBox::Show("Select a student first");
		return;
	}

	int courseId = Convert::ToInt32(comboBoxCourses->SelectedValue);

	int studentCode =
		Convert::ToInt32(dataGridViewAttendance->SelectedRows[0]
			->Cells["Student Code"]->Value);

	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	try
	{
		conn->Open();

		// 🔹 Get student_id
		SqlCommand^ cmdGetStudent = gcnew SqlCommand(
			"SELECT id FROM Students WHERE code = @code", conn);

		cmdGetStudent->Parameters->AddWithValue("@code", studentCode);
		int studentId = Convert::ToInt32(cmdGetStudent->ExecuteScalar());

		// 🔹 Check attendance exists
		SqlCommand^ cmdCheck = gcnew SqlCommand(
			"SELECT COUNT(*) FROM Attendance "
			"WHERE student_id=@sid AND course_id=@cid", conn);

		cmdCheck->Parameters->AddWithValue("@sid", studentId);
		cmdCheck->Parameters->AddWithValue("@cid", courseId);

		int exists = Convert::ToInt32(cmdCheck->ExecuteScalar());

		if (exists == 0)
		{
			// 🟢 First lecture
			SqlCommand^ cmdInsert = gcnew SqlCommand(
				"INSERT INTO Attendance "
				"(student_id, course_id, total_lectures, attended_lectures) "
				"VALUES (@sid,@cid,1,1)", conn);

			cmdInsert->Parameters->AddWithValue("@sid", studentId);
			cmdInsert->Parameters->AddWithValue("@cid", courseId);
			cmdInsert->ExecuteNonQuery();
		}
		else
		{
			// 🔵 Update attendance
			SqlCommand^ cmdUpdate = gcnew SqlCommand(
				"UPDATE Attendance SET "
				"total_lectures = total_lectures + 1, "
				"attended_lectures = attended_lectures + 1 "
				"WHERE student_id=@sid AND course_id=@cid", conn);

			cmdUpdate->Parameters->AddWithValue("@sid", studentId);
			cmdUpdate->Parameters->AddWithValue("@cid", courseId);
			cmdUpdate->ExecuteNonQuery();
		}

		MessageBox::Show("Attendance marked ✔");

		// 🔄 Reload grid
		LoadAttendanceByCourse(courseId);
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
};
}
