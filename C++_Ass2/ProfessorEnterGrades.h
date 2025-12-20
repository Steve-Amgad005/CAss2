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
		void LoadProfessorCourses()
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
					"WHERE pc.professor_id = @profId";

				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@profId", professorId);

				SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				comboBox1->DisplayMember = "course_name";
				comboBox1->ValueMember = "id";
				comboBox1->DataSource = dt;

				conn->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
		void LoadStudentsForCourse(int courseId)
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
					"SELECT s.code AS [Student Code], "
					"s.name AS [Student Name], "
					"g.assignment1 AS [Assignment 1], "
					"g.assignment2 AS [Assignment 2], "
					"g.cw AS [CW], "
					"g.final AS [Final] "
					"FROM Students s "
					"INNER JOIN StudentCourses sc ON s.id = sc.student_id "
					"LEFT JOIN Grades g ON s.id = g.student_id AND g.course_id = sc.course_id "
					"WHERE sc.course_id = @courseId";

				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				cmd->Parameters->AddWithValue("@courseId", courseId);

				SqlDataAdapter^ da = gcnew SqlDataAdapter(cmd);
				DataTable^ dt = gcnew DataTable();
				da->Fill(dt);

				dataGridView1->DataSource = dt;

				conn->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
		void EnterGrades(int courseId)
		{
			String^ connStr = "Server=localhost\\SQLEXPRESS;Database=MyDB;Trusted_Connection=True;TrustServerCertificate=True;";
			SqlConnection^ conn = gcnew SqlConnection(connStr);

			try
			{
				conn->Open();
				for each (DataGridViewRow ^ row in dataGridView1->Rows)
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
				LoadStudentsForCourse(courseId); // refresh grid
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
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;






	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
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
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->panel2->Controls->Add(this->textBox5);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Location = System::Drawing::Point(22, 146);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1122, 419);
			this->panel2->TabIndex = 3;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ProfessorEnterGrades::panel2_Paint);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(184, 280);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(214, 33);
			this->textBox5->TabIndex = 12;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(184, 229);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(214, 33);
			this->textBox4->TabIndex = 12;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(184, 181);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(214, 33);
			this->textBox3->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(184, 132);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(214, 33);
			this->textBox2->TabIndex = 12;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(184, 85);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(214, 33);
			this->textBox1->TabIndex = 12;
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
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::DarkGray;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(454, 17);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Size = System::Drawing::Size(643, 380);
			this->dataGridView1->TabIndex = 10;
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
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(235, 39);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ProfessorEnterGrades::comboBox1_SelectedIndexChanged);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	if (comboBox1->SelectedValue != nullptr)
	{
		int courseId = Convert::ToInt32(comboBox1->SelectedValue);
		LoadStudentsForCourse(courseId);

	}
}

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ProfessorEnterGrades_Load(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Professor ID = " + professorId.ToString());
		LoadProfessorCourses();
	}

	// declaration for back button handler
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	 if (comboBox1->SelectedValue != nullptr)
    {
        int courseId = Convert::ToInt32(comboBox1->SelectedValue);
        EnterGrades(courseId);
    }
}
};
}
