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
	/// Summary for AdminDeleteAssistants
	/// </summary>
	public ref class AdminDeleteAssistants : public System::Windows::Forms::Form
	{
	public:
		AdminDeleteAssistants(void)
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
		~AdminDeleteAssistants()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtAssistantCode;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;

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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtAssistantCode = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->txtAssistantCode);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(40, 94);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(429, 174);
			this->panel1->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(43, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(134, 24);
			this->label6->TabIndex = 35;
			this->label6->Text = L"Assistant Code";
			// 
			// txtAssistantCode
			// 
			this->txtAssistantCode->Location = System::Drawing::Point(192, 25);
			this->txtAssistantCode->Multiline = true;
			this->txtAssistantCode->Name = L"txtAssistantCode";
			this->txtAssistantCode->Size = System::Drawing::Size(214, 33);
			this->txtAssistantCode->TabIndex = 36;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Purple;
			this->button2->Location = System::Drawing::Point(101, 92);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminDeleteAssistants::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(112, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(285, 39);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Delete Assistant";
			// 
			// AdminDeleteAssistants
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Purple;
			this->ClientSize = System::Drawing::Size(508, 290);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Name = L"AdminDeleteAssistants";
			this->Text = L"AdminDeleteAssistants";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
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

			// ================= Get Assistant ID =================
			SqlCommand^ cmdGet = gcnew SqlCommand(
				"SELECT id FROM Assistants WHERE code=@code",
				conn);

			cmdGet->Parameters->AddWithValue("@code", txtAssistantCode->Text);

			Object^ result = cmdGet->ExecuteScalar();

			if (result == nullptr)
			{
				MessageBox::Show("Assistant not found");
				return;
			}

			int assistantId = Convert::ToInt32(result);

			// ================= Confirm =================
			if (MessageBox::Show(
				"Are you sure you want to delete this assistant?",
				"Confirm Delete",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::No)
			{
				return;
			}

			// ================= Delete Assignments =================
			SqlCommand^ cmdDelAssign = gcnew SqlCommand(
				"DELETE FROM AssistantAssignments WHERE assistant_id=@id",
				conn);

			cmdDelAssign->Parameters->AddWithValue("@id", assistantId);
			cmdDelAssign->ExecuteNonQuery();

			// ================= Delete Assistant =================
			SqlCommand^ cmdDelAssistant = gcnew SqlCommand(
				"DELETE FROM Assistants WHERE id=@id",
				conn);

			cmdDelAssistant->Parameters->AddWithValue("@id", assistantId);
			cmdDelAssistant->ExecuteNonQuery();

			MessageBox::Show("Assistant deleted successfully ✅");

			// ================= Clear Form =================
			txtAssistantCode->Clear();
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
