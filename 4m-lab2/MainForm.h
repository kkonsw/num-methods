#pragma once

namespace My4mlab2 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

    private: System::Windows::Forms::TabControl^  tabControl;
    private: System::Windows::Forms::TabPage^  tabPage_test;
    private: System::Windows::Forms::TabPage^  tabPage_main;
    private: System::Windows::Forms::GroupBox^  groupBox_testResults;
    private: System::Windows::Forms::GroupBox^  groupBox_testSettings;
    private: System::Windows::Forms::TextBox^  textBox_test_m;
    private: System::Windows::Forms::TextBox^  textBox_test_n;
    private: System::Windows::Forms::Label^  label_test_m;
    private: System::Windows::Forms::Label^  label_test_n;
    private: System::Windows::Forms::GroupBox^  groupBox_mainResults;
    private: System::Windows::Forms::GroupBox^  groupBox_mainSettings;
    private: System::Windows::Forms::TextBox^  textBox_main_m;
    private: System::Windows::Forms::TextBox^  textBox_main_n;
    private: System::Windows::Forms::Label^  label_main_m;
    private: System::Windows::Forms::Label^  label_main_n;
    private: System::Windows::Forms::DataGridView^  dataGridView_testV;
    private: System::Windows::Forms::DataGridView^  dataGridView_mainVS1;
    private: System::Windows::Forms::Button^  button_testU;
    private: System::Windows::Forms::Button^  button_testErrors;
    private: System::Windows::Forms::Button^  button_mainErrors;
    private: System::Windows::Forms::Button^  button_mainVS2;
    private: System::Windows::Forms::Button^  button_testSolve;
    private: System::Windows::Forms::Button^  button_mainSolve;
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
            this->tabControl = (gcnew System::Windows::Forms::TabControl());
            this->tabPage_test = (gcnew System::Windows::Forms::TabPage());
            this->button_testErrors = (gcnew System::Windows::Forms::Button());
            this->button_testU = (gcnew System::Windows::Forms::Button());
            this->dataGridView_testV = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_testResults = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox_testSettings = (gcnew System::Windows::Forms::GroupBox());
            this->textBox_test_m = (gcnew System::Windows::Forms::TextBox());
            this->textBox_test_n = (gcnew System::Windows::Forms::TextBox());
            this->label_test_m = (gcnew System::Windows::Forms::Label());
            this->label_test_n = (gcnew System::Windows::Forms::Label());
            this->tabPage_main = (gcnew System::Windows::Forms::TabPage());
            this->button_mainErrors = (gcnew System::Windows::Forms::Button());
            this->button_mainVS2 = (gcnew System::Windows::Forms::Button());
            this->dataGridView_mainVS1 = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_mainResults = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox_mainSettings = (gcnew System::Windows::Forms::GroupBox());
            this->textBox_main_m = (gcnew System::Windows::Forms::TextBox());
            this->textBox_main_n = (gcnew System::Windows::Forms::TextBox());
            this->label_main_m = (gcnew System::Windows::Forms::Label());
            this->label_main_n = (gcnew System::Windows::Forms::Label());
            this->button_testSolve = (gcnew System::Windows::Forms::Button());
            this->button_mainSolve = (gcnew System::Windows::Forms::Button());
            this->tabControl->SuspendLayout();
            this->tabPage_test->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_testV))->BeginInit();
            this->groupBox_testSettings->SuspendLayout();
            this->tabPage_main->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainVS1))->BeginInit();
            this->groupBox_mainSettings->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabControl
            // 
            this->tabControl->Controls->Add(this->tabPage_test);
            this->tabControl->Controls->Add(this->tabPage_main);
            this->tabControl->Location = System::Drawing::Point(2, 3);
            this->tabControl->Name = L"tabControl";
            this->tabControl->SelectedIndex = 0;
            this->tabControl->Size = System::Drawing::Size(1179, 792);
            this->tabControl->TabIndex = 0;
            // 
            // tabPage_test
            // 
            this->tabPage_test->BackColor = System::Drawing::Color::WhiteSmoke;
            this->tabPage_test->Controls->Add(this->button_testErrors);
            this->tabPage_test->Controls->Add(this->button_testU);
            this->tabPage_test->Controls->Add(this->dataGridView_testV);
            this->tabPage_test->Controls->Add(this->groupBox_testResults);
            this->tabPage_test->Controls->Add(this->groupBox_testSettings);
            this->tabPage_test->Location = System::Drawing::Point(4, 29);
            this->tabPage_test->Name = L"tabPage_test";
            this->tabPage_test->Padding = System::Windows::Forms::Padding(3);
            this->tabPage_test->Size = System::Drawing::Size(1171, 759);
            this->tabPage_test->TabIndex = 0;
            this->tabPage_test->Text = L"Тестовая";
            // 
            // button_testErrors
            // 
            this->button_testErrors->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_testErrors->Location = System::Drawing::Point(759, 636);
            this->button_testErrors->Name = L"button_testErrors";
            this->button_testErrors->Size = System::Drawing::Size(339, 40);
            this->button_testErrors->TabIndex = 4;
            this->button_testErrors->Text = L"Таблица погрешностей";
            this->button_testErrors->UseVisualStyleBackColor = false;
            this->button_testErrors->Click += gcnew System::EventHandler(this, &MainForm::button_testErrors_Click);
            // 
            // button_testU
            // 
            this->button_testU->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_testU->Location = System::Drawing::Point(374, 636);
            this->button_testU->Name = L"button_testU";
            this->button_testU->Size = System::Drawing::Size(362, 40);
            this->button_testU->TabIndex = 3;
            this->button_testU->Text = L"Таблица с точными значениями";
            this->button_testU->UseVisualStyleBackColor = false;
            this->button_testU->Click += gcnew System::EventHandler(this, &MainForm::button_testU_Click);
            // 
            // dataGridView_testV
            // 
            this->dataGridView_testV->BackgroundColor = System::Drawing::SystemColors::Control;
            this->dataGridView_testV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_testV->Location = System::Drawing::Point(374, 67);
            this->dataGridView_testV->Name = L"dataGridView_testV";
            this->dataGridView_testV->RowTemplate->Height = 28;
            this->dataGridView_testV->Size = System::Drawing::Size(724, 545);
            this->dataGridView_testV->TabIndex = 2;
            // 
            // groupBox_testResults
            // 
            this->groupBox_testResults->Location = System::Drawing::Point(48, 346);
            this->groupBox_testResults->Name = L"groupBox_testResults";
            this->groupBox_testResults->Size = System::Drawing::Size(267, 266);
            this->groupBox_testResults->TabIndex = 1;
            this->groupBox_testResults->TabStop = false;
            this->groupBox_testResults->Text = L"Результаты";
            // 
            // groupBox_testSettings
            // 
            this->groupBox_testSettings->Controls->Add(this->button_testSolve);
            this->groupBox_testSettings->Controls->Add(this->textBox_test_m);
            this->groupBox_testSettings->Controls->Add(this->textBox_test_n);
            this->groupBox_testSettings->Controls->Add(this->label_test_m);
            this->groupBox_testSettings->Controls->Add(this->label_test_n);
            this->groupBox_testSettings->Location = System::Drawing::Point(48, 57);
            this->groupBox_testSettings->Name = L"groupBox_testSettings";
            this->groupBox_testSettings->Size = System::Drawing::Size(267, 266);
            this->groupBox_testSettings->TabIndex = 0;
            this->groupBox_testSettings->TabStop = false;
            this->groupBox_testSettings->Text = L"Параметры";
            // 
            // textBox_test_m
            // 
            this->textBox_test_m->Location = System::Drawing::Point(106, 94);
            this->textBox_test_m->Name = L"textBox_test_m";
            this->textBox_test_m->Size = System::Drawing::Size(100, 26);
            this->textBox_test_m->TabIndex = 3;
            this->textBox_test_m->Text = L"10";
            // 
            // textBox_test_n
            // 
            this->textBox_test_n->Location = System::Drawing::Point(106, 52);
            this->textBox_test_n->Name = L"textBox_test_n";
            this->textBox_test_n->Size = System::Drawing::Size(100, 26);
            this->textBox_test_n->TabIndex = 2;
            this->textBox_test_n->Text = L"10";
            // 
            // label_test_m
            // 
            this->label_test_m->AutoSize = true;
            this->label_test_m->Location = System::Drawing::Point(65, 97);
            this->label_test_m->Name = L"label_test_m";
            this->label_test_m->Size = System::Drawing::Size(39, 20);
            this->label_test_m->TabIndex = 1;
            this->label_test_m->Text = L"m = ";
            // 
            // label_test_n
            // 
            this->label_test_n->AutoSize = true;
            this->label_test_n->Location = System::Drawing::Point(65, 55);
            this->label_test_n->Name = L"label_test_n";
            this->label_test_n->Size = System::Drawing::Size(35, 20);
            this->label_test_n->TabIndex = 0;
            this->label_test_n->Text = L"n = ";
            // 
            // tabPage_main
            // 
            this->tabPage_main->BackColor = System::Drawing::Color::WhiteSmoke;
            this->tabPage_main->Controls->Add(this->button_mainErrors);
            this->tabPage_main->Controls->Add(this->button_mainVS2);
            this->tabPage_main->Controls->Add(this->dataGridView_mainVS1);
            this->tabPage_main->Controls->Add(this->groupBox_mainResults);
            this->tabPage_main->Controls->Add(this->groupBox_mainSettings);
            this->tabPage_main->Location = System::Drawing::Point(4, 29);
            this->tabPage_main->Name = L"tabPage_main";
            this->tabPage_main->Padding = System::Windows::Forms::Padding(3);
            this->tabPage_main->Size = System::Drawing::Size(1171, 759);
            this->tabPage_main->TabIndex = 1;
            this->tabPage_main->Text = L"Основная";
            // 
            // button_mainErrors
            // 
            this->button_mainErrors->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_mainErrors->Location = System::Drawing::Point(758, 627);
            this->button_mainErrors->Name = L"button_mainErrors";
            this->button_mainErrors->Size = System::Drawing::Size(346, 43);
            this->button_mainErrors->TabIndex = 4;
            this->button_mainErrors->Text = L"Таблица погрешностей";
            this->button_mainErrors->UseVisualStyleBackColor = false;
            this->button_mainErrors->Click += gcnew System::EventHandler(this, &MainForm::button_mainErrors_Click);
            // 
            // button_mainVS2
            // 
            this->button_mainVS2->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_mainVS2->Location = System::Drawing::Point(382, 627);
            this->button_mainVS2->Name = L"button_mainVS2";
            this->button_mainVS2->Size = System::Drawing::Size(370, 43);
            this->button_mainVS2->TabIndex = 3;
            this->button_mainVS2->Text = L"Таблица с более точным решением";
            this->button_mainVS2->UseVisualStyleBackColor = false;
            this->button_mainVS2->Click += gcnew System::EventHandler(this, &MainForm::button_mainVS2_Click);
            // 
            // dataGridView_mainVS1
            // 
            this->dataGridView_mainVS1->BackgroundColor = System::Drawing::SystemColors::Control;
            this->dataGridView_mainVS1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_mainVS1->Location = System::Drawing::Point(382, 56);
            this->dataGridView_mainVS1->Name = L"dataGridView_mainVS1";
            this->dataGridView_mainVS1->RowTemplate->Height = 28;
            this->dataGridView_mainVS1->Size = System::Drawing::Size(722, 547);
            this->dataGridView_mainVS1->TabIndex = 2;
            // 
            // groupBox_mainResults
            // 
            this->groupBox_mainResults->Location = System::Drawing::Point(48, 346);
            this->groupBox_mainResults->Name = L"groupBox_mainResults";
            this->groupBox_mainResults->Size = System::Drawing::Size(264, 257);
            this->groupBox_mainResults->TabIndex = 1;
            this->groupBox_mainResults->TabStop = false;
            this->groupBox_mainResults->Text = L"Результаты";
            // 
            // groupBox_mainSettings
            // 
            this->groupBox_mainSettings->Controls->Add(this->button_mainSolve);
            this->groupBox_mainSettings->Controls->Add(this->textBox_main_m);
            this->groupBox_mainSettings->Controls->Add(this->textBox_main_n);
            this->groupBox_mainSettings->Controls->Add(this->label_main_m);
            this->groupBox_mainSettings->Controls->Add(this->label_main_n);
            this->groupBox_mainSettings->Location = System::Drawing::Point(48, 47);
            this->groupBox_mainSettings->Name = L"groupBox_mainSettings";
            this->groupBox_mainSettings->Size = System::Drawing::Size(264, 266);
            this->groupBox_mainSettings->TabIndex = 0;
            this->groupBox_mainSettings->TabStop = false;
            this->groupBox_mainSettings->Text = L"Параметры";
            // 
            // textBox_main_m
            // 
            this->textBox_main_m->Location = System::Drawing::Point(106, 91);
            this->textBox_main_m->Name = L"textBox_main_m";
            this->textBox_main_m->Size = System::Drawing::Size(100, 26);
            this->textBox_main_m->TabIndex = 3;
            this->textBox_main_m->Text = L"10";
            // 
            // textBox_main_n
            // 
            this->textBox_main_n->Location = System::Drawing::Point(106, 51);
            this->textBox_main_n->Name = L"textBox_main_n";
            this->textBox_main_n->Size = System::Drawing::Size(100, 26);
            this->textBox_main_n->TabIndex = 2;
            this->textBox_main_n->Text = L"10";
            // 
            // label_main_m
            // 
            this->label_main_m->AutoSize = true;
            this->label_main_m->Location = System::Drawing::Point(65, 94);
            this->label_main_m->Name = L"label_main_m";
            this->label_main_m->Size = System::Drawing::Size(39, 20);
            this->label_main_m->TabIndex = 1;
            this->label_main_m->Text = L"m = ";
            // 
            // label_main_n
            // 
            this->label_main_n->AutoSize = true;
            this->label_main_n->Location = System::Drawing::Point(65, 54);
            this->label_main_n->Name = L"label_main_n";
            this->label_main_n->Size = System::Drawing::Size(35, 20);
            this->label_main_n->TabIndex = 0;
            this->label_main_n->Text = L"n = ";
            // 
            // button_testSolve
            // 
            this->button_testSolve->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_testSolve->Location = System::Drawing::Point(69, 198);
            this->button_testSolve->Name = L"button_testSolve";
            this->button_testSolve->Size = System::Drawing::Size(137, 40);
            this->button_testSolve->TabIndex = 4;
            this->button_testSolve->Text = L"Решить";
            this->button_testSolve->UseVisualStyleBackColor = false;
            // 
            // button_mainSolve
            // 
            this->button_mainSolve->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_mainSolve->Location = System::Drawing::Point(69, 198);
            this->button_mainSolve->Name = L"button_mainSolve";
            this->button_mainSolve->Size = System::Drawing::Size(137, 37);
            this->button_mainSolve->TabIndex = 4;
            this->button_mainSolve->Text = L"Решить";
            this->button_mainSolve->UseVisualStyleBackColor = false;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1181, 794);
            this->Controls->Add(this->tabControl);
            this->Name = L"MainForm";
            this->Text = L"Решение задачи Дирихле для уравнения Пуассона";
            this->tabControl->ResumeLayout(false);
            this->tabPage_test->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_testV))->EndInit();
            this->groupBox_testSettings->ResumeLayout(false);
            this->groupBox_testSettings->PerformLayout();
            this->tabPage_main->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainVS1))->EndInit();
            this->groupBox_mainSettings->ResumeLayout(false);
            this->groupBox_mainSettings->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void button_testU_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_testErrors_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_mainVS2_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_mainErrors_Click(System::Object^  sender, System::EventArgs^  e);
};
}
