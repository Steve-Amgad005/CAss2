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
	/// Summary for ProfessorEnterGrades
	/// </summary>
	public ref class ProfessorEnterGrades : public System::Windows::Forms::Form
	{
		int CalculateTotal(int a1, int a2, int cw, int final)
{
	return a1 + a2 + cw + final;
}

String^ CalculateGrade(int total)
{
	if (total >= 90) return "A";
	else if (total >= 80) return "B";
	else if (total >= 70) return "C";
	else if (total >= 60) return "D";
	else return "F";
}

		void LoadProfessorCourses(int professorCode)
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

				// =========================
				// 1️⃣ Get Professor ID by Code
				// =========================
				SqlCommand^ cmdGetId = gcnew SqlCommand(
					"SELECT id FROM Professors WHERE code = @code",
					conn);

				cmdGetId->Parameters->AddWithValue("@code", professorCode);

				Object^ result = cmdGetId->ExecuteScalar();

				if (result == nullptr)
				{
					MessageBox::Show("Professor not found");
					return;
				}

				int professorId = Convert::ToInt32(result);

				// =========================
				// 2️⃣ Load Professor Courses
				// =========================
				String^ query =
					"SELECT c.id, c.course_name "
					"FROM Courses c "
					"INNER JOIN ProfessorCourses pc ON c.id = pc.course_id "
					"WHERE pc.professor_id = @profId";

				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@profId", professorId);

				SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				cmbCourses->DisplayMember = "course_name";
				cmbCourses->ValueMember = "id";
				cmbCourses->DataSource = dt;
				cmbCourses->SelectedIndex = -1; // مفيش اختيار افتراضي
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

		void LoadStudentsByCourse(int courseId)
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
					"d.name AS [Department], "

					"CASE s.year "
					" WHEN 1 THEN 'First' "
					" WHEN 2 THEN 'Second' "
					" WHEN 3 THEN 'Third' "
					" WHEN 4 THEN 'Fourth' "
					"END AS [Year], "

					"ISNULL(g.assignment1, '') AS [A1], "
					"ISNULL(g.assignment2, '') AS [A2], "
					"ISNULL(g.cw, '') AS [CW], "
					"ISNULL(g.final, '') AS [Final], "
					"ISNULL(g.total, '') AS [Total], "
					"ISNULL(g.grade, '') AS [Grade] "

					"FROM StudentCourses sc "
					"INNER JOIN Students s ON sc.student_id = s.id "
					"INNER JOIN Departments d ON s.department_id = d.id "
					"LEFT JOIN Grades g ON "
					"   g.student_id = s.id AND g.course_id = sc.course_id "
					"WHERE sc.course_id = @courseId "
					"ORDER BY s.name";

				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@courseId", courseId);

				SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				dataGridViewStudents->DataSource = dt;
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


		void EnterGrades(int courseId)
		{
			String^ connStr = "Server=localhost\\SQLEXPRESS;Database=MyDB;Trusted_Connection=True;TrustServerCertificate=True;";
			SqlConnection^ conn = gcnew SqlConnection(connStr);

			try
			{
				conn->Open();
				for each (DataGridViewRow ^ row in dataGridViewStudents->Rows)
				{
					if (row->IsNewRow) continue;

					int studentCode = Convert::ToInt32(row->Cells["Student Code"]->Value);

					Object^ a1 = row->Cells["Assignment 1"]->Value;
					Object^ a2 = row->Cells["Assignment 2"]->Value;
					Object^ cw = row->Cells["CW"]->Value;
					Object^ final = row->Cells["Final"]->Value;

					String^ query =
						"IF EXISTS (SELECT * FROM Grades WHERE student_id = (SELECT id FROM Students WHERE code=@code) AND course_id=@courseId) " +
						"UPDATE Grades SET " +
						"assignment1 = ISNULL(@a1, assignment1), " +
						"assignment2 = ISNULL(@a2, assignment2), " +
						"cw = ISNULL(@cw, cw), " +
						"final = ISNULL(@final, final) " +
						"WHERE student_id = (SELECT id FROM Students WHERE code=@code) AND course_id=@courseId " +
						"ELSE " +
						"INSERT INTO Grades(student_id, course_id, assignment1, assignment2, cw, final) " +
						"VALUES((SELECT id FROM Students WHERE code=@code), @courseId, @a1, @a2, @cw, @final)";

					SqlCommand^ cmd = gcnew SqlCommand(query, conn);
					cmd->Parameters->AddWithValue("@code", studentCode);
					cmd->Parameters->AddWithValue("@courseId", courseId);
					cmd->Parameters->AddWithValue("@a1", a1 == nullptr ? DBNull::Value : a1);
					cmd->Parameters->AddWithValue("@a2", a2 == nullptr ? DBNull::Value : a2);
					cmd->Parameters->AddWithValue("@cw", cw == nullptr ? DBNull::Value : cw);
					cmd->Parameters->AddWithValue("@final", final == nullptr ? DBNull::Value : final);

					cmd->ExecuteNonQuery();
				}

				MessageBox::Show("Grades entered successfully!");
				LoadStudentsByCourse(courseId); // refresh grid
				conn->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}


	private:
		int professorId;
	public:
		ProfessorEnterGrades(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ProfessorEnterGrades(int profID)
		{
			InitializeComponent();
			professorId = profID;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProfessorEnterGrades()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::ComboBox^ cmbCourses;

private: System::Windows::Forms::DataGridView^ dataGridViewStudents;







	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::TextBox^ txtFinal;

private: System::Windows::Forms::TextBox^ txtCW;

private: System::Windows::Forms::TextBox^ txtA2;

private: System::Windows::Forms::TextBox^ txtA1;

private: System::Windows::Forms::TextBox^ txtStudentCode;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProfessorEnterGrades::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->txtFinal = (gcnew System::Windows::Forms::TextBox());
			this->txtCW = (gcnew System::Windows::Forms::TextBox());
			this->txtA2 = (gcnew System::Windows::Forms::TextBox());
			this->txtA1 = (gcnew System::Windows::Forms::TextBox());
			this->txtStudentCode = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridViewStudents = (gcnew System::Windows::Forms::DataGridView());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cmbCourses = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(22, 21);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1122, 100);
			this->panel1->TabIndex = 2;
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
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel2->Controls->Add(this->txtFinal);
			this->panel2->Controls->Add(this->txtCW);
			this->panel2->Controls->Add(this->txtA2);
			this->panel2->Controls->Add(this->txtA1);
			this->panel2->Controls->Add(this->txtStudentCode);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->dataGridViewStudents);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->cmbCourses);
			this->panel2->Location = System::Drawing::Point(22, 146);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1122, 419);
			this->panel2->TabIndex = 3;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ProfessorEnterGrades::panel2_Paint);
			// 
			// txtFinal
			// 
			this->txtFinal->Location = System::Drawing::Point(184, 280);
			this->txtFinal->Multiline = true;
			this->txtFinal->Name = L"txtFinal";
			this->txtFinal->Size = System::Drawing::Size(214, 33);
			this->txtFinal->TabIndex = 12;
			// 
			// txtCW
			// 
			this->txtCW->Location = System::Drawing::Point(184, 229);
			this->txtCW->Multiline = true;
			this->txtCW->Name = L"txtCW";
			this->txtCW->Size = System::Drawing::Size(214, 33);
			this->txtCW->TabIndex = 12;
			// 
			// txtA2
			// 
			this->txtA2->Location = System::Drawing::Point(184, 181);
			this->txtA2->Multiline = true;
			this->txtA2->Name = L"txtA2";
			this->txtA2->Size = System::Drawing::Size(214, 33);
			this->txtA2->TabIndex = 12;
			// 
			// txtA1
			// 
			this->txtA1->Location = System::Drawing::Point(184, 132);
			this->txtA1->Multiline = true;
			this->txtA1->Name = L"txtA1";
			this->txtA1->Size = System::Drawing::Size(214, 33);
			this->txtA1->TabIndex = 12;
			// 
			// txtStudentCode
			// 
			this->txtStudentCode->Location = System::Drawing::Point(184, 85);
			this->txtStudentCode->Multiline = true;
			this->txtStudentCode->Name = L"txtStudentCode";
			this->txtStudentCode->Size = System::Drawing::Size(214, 33);
			this->txtStudentCode->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(96, 336);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Enter";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ProfessorEnterGrades::button2_Click);
			// 
			// dataGridViewStudents
			// 
			this->dataGridViewStudents->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			this->dataGridViewStudents->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewStudents->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::DarkGray;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewStudents->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewStudents->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStudents->Location = System::Drawing::Point(454, 17);
			this->dataGridViewStudents->Name = L"dataGridViewStudents";
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			this->dataGridViewStudents->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridViewStudents->Size = System::Drawing::Size(643, 380);
			this->dataGridViewStudents->TabIndex = 10;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(17, 286);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(51, 24);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Final";
			this->label7->Click += gcnew System::EventHandler(this, &ProfessorEnterGrades::label2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(17, 237);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 24);
			this->label6->TabIndex = 1;
			this->label6->Text = L"CW";
			this->label6->Click += gcnew System::EventHandler(this, &ProfessorEnterGrades::label2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(17, 186);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 24);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Assignmnet 2";
			this->label5->Click += gcnew System::EventHandler(this, &ProfessorEnterGrades::label2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(17, 131);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(124, 24);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Assignment 1";
			this->label4->Click += gcnew System::EventHandler(this, &ProfessorEnterGrades::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(17, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(165, 24);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Enter Grades For: ";
			this->label3->Click += gcnew System::EventHandler(this, &ProfessorEnterGrades::label2_Click);
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
			this->label2->Click += gcnew System::EventHandler(this, &ProfessorEnterGrades::label2_Click);
			// 
			// cmbCourses
			// 
			this->cmbCourses->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCourses->FormattingEnabled = true;
			this->cmbCourses->Location = System::Drawing::Point(235, 39);
			this->cmbCourses->Name = L"cmbCourses";
			this->cmbCourses->Size = System::Drawing::Size(121, 21);
			this->cmbCourses->TabIndex = 0;
			this->cmbCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &ProfessorEnterGrades::comboBox1_SelectedIndexChanged);
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
			this->button1->Location = System::Drawing::Point(1173, 50);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(41, 39);
			this->button1->TabIndex = 13;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ProfessorEnterGrades::button1_Click_1);
			// 
			// ProfessorEnterGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(1242, 599);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"ProfessorEnterGrades";
			this->Text = L"ProfessorEnterGrades";
			this->Load += gcnew System::EventHandler(this, &ProfessorEnterGrades::ProfessorEnterGrades_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudents))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	if (cmbCourses->SelectedIndex == -1)
		return;

	int courseId = Convert::ToInt32(cmbCourses->SelectedValue);//System.InvalidCastException: 'Unable to cast object of type 'System.Data.DataRowView' to type 'System.IConvertible',
	LoadStudentsByCourse(courseId);
}

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ProfessorEnterGrades_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadProfessorCourses(professorId);
	}

	// declaration for back button handler
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// ================= Validation =================
	if (String::IsNullOrWhiteSpace(txtStudentCode->Text))
	{
		MessageBox::Show("Enter student code");
		return;
	}

	if (cmbCourses->SelectedIndex == -1)
	{
		MessageBox::Show("Select course");
		return;
	}

	int a1 = Convert::ToInt32(txtA1->Text);
	int a2 = Convert::ToInt32(txtA2->Text);
	int cw = Convert::ToInt32(txtCW->Text);
	int final = Convert::ToInt32(txtFinal->Text);

	int total = CalculateTotal(a1, a2, cw, final);
	String^ grade = CalculateGrade(total);

	String^ connStr =
		"Server=localhost\\SQLEXPRESS;"
		"Database=MyDB;"
		"Trusted_Connection=True;"
		"TrustServerCertificate=True;";

	SqlConnection^ conn = gcnew SqlConnection(connStr);

	try
	{
		conn->Open();

		// ================= Get Student ID =================
		SqlCommand^ cmdGetStudent = gcnew SqlCommand(
			"SELECT id FROM Students WHERE code = @code",
			conn);

		cmdGetStudent->Parameters->AddWithValue("@code", txtStudentCode->Text);

		Object^ result = cmdGetStudent->ExecuteScalar();
		if (result == nullptr)
		{
			MessageBox::Show("Student not found");
			return;
		}

		int studentId = Convert::ToInt32(result);
		int courseId = Convert::ToInt32(cmbCourses->SelectedValue);

		// ================= Insert / Update Grades =================
		SqlCommand^ cmd = gcnew SqlCommand(
			"IF EXISTS (SELECT 1 FROM Grades WHERE student_id=@sid AND course_id=@cid) "
			"UPDATE Grades SET "
			"assignment1=@a1, assignment2=@a2, cw=@cw, final=@final, total=@total, grade=@grade "
			"WHERE student_id=@sid AND course_id=@cid "
			"ELSE "
			"INSERT INTO Grades "
			"(student_id, course_id, assignment1, assignment2, cw, final, total, grade) "
			"VALUES (@sid,@cid,@a1,@a2,@cw,@final,@total,@grade)",
			conn);

		cmd->Parameters->AddWithValue("@sid", studentId);
		cmd->Parameters->AddWithValue("@cid", courseId);
		cmd->Parameters->AddWithValue("@a1", a1);
		cmd->Parameters->AddWithValue("@a2", a2);
		cmd->Parameters->AddWithValue("@cw", cw);
		cmd->Parameters->AddWithValue("@final", final);
		cmd->Parameters->AddWithValue("@total", total);
		cmd->Parameters->AddWithValue("@grade", grade);

		cmd->ExecuteNonQuery();

		MessageBox::Show("Grades entered successfully ✅");
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
