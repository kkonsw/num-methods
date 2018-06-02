#pragma once
#include "test_functions.h"
#include "main_functions.h"

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
    protected:

        double **u;         // точные значения в узлах сетки
        double **v;         // посчитанные значения в узлах сетки
        double **f1;        // f(x,y) - правая часть
        double **test_err;  // разности численного и точного решения в узлах сетки

        double **vs1;       // численное решение с разбиением s1
        double **vs2;       // численное решение с разбиением s2
        double **f2;
        double **main_diff; // разности решений s1 и s2

        double a, b, c, d;  // границы области
        int test_n, test_m; // число разбиений
        int main_n, main_m;

        double test_w;      // параметр метода
        double main_w;           
        int test_Nmax;      // макс. число шагов
        int main_Nmax;
        double test_eps;    // макс. погрешность 
        double main_eps;

        // выделение памяти под матрицы
        template <typename T>
        T **createMatrix(int nRows, int nCols)
        {
            T **data = new T*[nRows];
            T *buffer = new T[nRows * nCols];

            for (int i = 0; i < nRows; i++)
            {
                data[i] = buffer;
                buffer += nCols;
            }

            return data;
        }

        // освобождение памяти
        template <typename T>
        void deleteMatrix(T** matrix)
        {
            delete[] * matrix;
            delete[] matrix;
        }

	public:
		MainForm(void)
		{
            a = 0.0;
            b = 2.0;
            c = 0.0;
            d = 1.0;
            
            test_w = main_w = 1.8;
            test_Nmax = main_Nmax = 1000;
            test_eps = main_eps = 1e-6;

            test_n = test_m = 10;
            main_n = main_m = 10;

            u = nullptr;
            v = nullptr;
            f1 = nullptr;
            test_err = nullptr;

            double **vs1 = nullptr;
            double **vs2 = nullptr;
            double **f2 = nullptr;
            double **main_diff = nullptr;

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
            if (u != nullptr)
                deleteMatrix<double>(u);
            if (v != nullptr)
                deleteMatrix<double>(v);
            if (f1 != nullptr)
                deleteMatrix<double>(f1);
            if (test_err != nullptr)
                deleteMatrix<double>(test_err);

            if (vs1 != nullptr)
                deleteMatrix<double>(vs1);
            if (vs2 != nullptr)
                deleteMatrix<double>(vs2);
            if (f2 != nullptr)
                deleteMatrix<double>(f2);
            if (main_diff != nullptr)
                deleteMatrix<double>(main_diff);

			if (components)
			{
				delete components;
			}
		}

    private: System::Windows::Forms::Label^  label_mainEps;
    private: System::Windows::Forms::Label^  label_mainNmax;
    private: System::Windows::Forms::TextBox^  textBox_main_stepsS1;
    private: System::Windows::Forms::TextBox^  textBox_mainMaxDiff;
    private: System::Windows::Forms::Label^  label_main_stepsS1;
    private: System::Windows::Forms::Label^  label_mainMaxDiff;
    private: System::Windows::Forms::TextBox^  textBox_main_w;
    private: System::Windows::Forms::TextBox^  textBox_mainEps;
    private: System::Windows::Forms::TextBox^  textBox_mainNmax;
    private: System::Windows::Forms::Label^  label_main_w;
    private: System::Windows::Forms::TextBox^  textBox_test_steps;
    private: System::Windows::Forms::TextBox^  textBox_test_MaxErr;
    private: System::Windows::Forms::Label^  label_test_steps;
    private: System::Windows::Forms::Label^  label_testMaxErr;
    private: System::Windows::Forms::TextBox^  textBox_test_w;
    private: System::Windows::Forms::Label^  label_test_w;
    private: System::Windows::Forms::TextBox^  textBox_testEps;
    private: System::Windows::Forms::TextBox^  textBox_testNmax;
    private: System::Windows::Forms::Label^  label_testEps;
    private: System::Windows::Forms::Label^  label_testNmax;
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
    private: System::Windows::Forms::TextBox^  textBox_main_stepsS2;
    private: System::Windows::Forms::Label^  label_main_stepsS2;
    private: System::Windows::Forms::TextBox^  textBox_testResEps;
    private: System::Windows::Forms::Label^  label_testResEps;
    private: System::Windows::Forms::TextBox^  textBox_mainResEps2;
    private: System::Windows::Forms::TextBox^  textBox_mainResEps1;
    private: System::Windows::Forms::Label^  label_mainResEps2;
    private: System::Windows::Forms::Label^  label_mainResEps1;

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
            this->textBox_testResEps = (gcnew System::Windows::Forms::TextBox());
            this->label_testResEps = (gcnew System::Windows::Forms::Label());
            this->textBox_test_steps = (gcnew System::Windows::Forms::TextBox());
            this->textBox_test_MaxErr = (gcnew System::Windows::Forms::TextBox());
            this->label_test_steps = (gcnew System::Windows::Forms::Label());
            this->label_testMaxErr = (gcnew System::Windows::Forms::Label());
            this->groupBox_testSettings = (gcnew System::Windows::Forms::GroupBox());
            this->textBox_test_w = (gcnew System::Windows::Forms::TextBox());
            this->label_test_w = (gcnew System::Windows::Forms::Label());
            this->textBox_testEps = (gcnew System::Windows::Forms::TextBox());
            this->textBox_testNmax = (gcnew System::Windows::Forms::TextBox());
            this->label_testEps = (gcnew System::Windows::Forms::Label());
            this->label_testNmax = (gcnew System::Windows::Forms::Label());
            this->button_testSolve = (gcnew System::Windows::Forms::Button());
            this->textBox_test_m = (gcnew System::Windows::Forms::TextBox());
            this->textBox_test_n = (gcnew System::Windows::Forms::TextBox());
            this->label_test_m = (gcnew System::Windows::Forms::Label());
            this->label_test_n = (gcnew System::Windows::Forms::Label());
            this->tabPage_main = (gcnew System::Windows::Forms::TabPage());
            this->button_mainErrors = (gcnew System::Windows::Forms::Button());
            this->button_mainVS2 = (gcnew System::Windows::Forms::Button());
            this->dataGridView_mainVS1 = (gcnew System::Windows::Forms::DataGridView());
            this->groupBox_mainResults = (gcnew System::Windows::Forms::GroupBox());
            this->textBox_mainResEps2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox_mainResEps1 = (gcnew System::Windows::Forms::TextBox());
            this->label_mainResEps2 = (gcnew System::Windows::Forms::Label());
            this->label_mainResEps1 = (gcnew System::Windows::Forms::Label());
            this->textBox_main_stepsS2 = (gcnew System::Windows::Forms::TextBox());
            this->label_main_stepsS2 = (gcnew System::Windows::Forms::Label());
            this->textBox_main_stepsS1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox_mainMaxDiff = (gcnew System::Windows::Forms::TextBox());
            this->label_main_stepsS1 = (gcnew System::Windows::Forms::Label());
            this->label_mainMaxDiff = (gcnew System::Windows::Forms::Label());
            this->groupBox_mainSettings = (gcnew System::Windows::Forms::GroupBox());
            this->textBox_main_w = (gcnew System::Windows::Forms::TextBox());
            this->textBox_mainEps = (gcnew System::Windows::Forms::TextBox());
            this->textBox_mainNmax = (gcnew System::Windows::Forms::TextBox());
            this->label_main_w = (gcnew System::Windows::Forms::Label());
            this->label_mainEps = (gcnew System::Windows::Forms::Label());
            this->label_mainNmax = (gcnew System::Windows::Forms::Label());
            this->button_mainSolve = (gcnew System::Windows::Forms::Button());
            this->textBox_main_m = (gcnew System::Windows::Forms::TextBox());
            this->textBox_main_n = (gcnew System::Windows::Forms::TextBox());
            this->label_main_m = (gcnew System::Windows::Forms::Label());
            this->label_main_n = (gcnew System::Windows::Forms::Label());
            this->tabControl->SuspendLayout();
            this->tabPage_test->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_testV))->BeginInit();
            this->groupBox_testResults->SuspendLayout();
            this->groupBox_testSettings->SuspendLayout();
            this->tabPage_main->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainVS1))->BeginInit();
            this->groupBox_mainResults->SuspendLayout();
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
            this->button_testU->Size = System::Drawing::Size(355, 40);
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
            this->groupBox_testResults->Controls->Add(this->textBox_testResEps);
            this->groupBox_testResults->Controls->Add(this->label_testResEps);
            this->groupBox_testResults->Controls->Add(this->textBox_test_steps);
            this->groupBox_testResults->Controls->Add(this->textBox_test_MaxErr);
            this->groupBox_testResults->Controls->Add(this->label_test_steps);
            this->groupBox_testResults->Controls->Add(this->label_testMaxErr);
            this->groupBox_testResults->Location = System::Drawing::Point(48, 346);
            this->groupBox_testResults->Name = L"groupBox_testResults";
            this->groupBox_testResults->Size = System::Drawing::Size(267, 266);
            this->groupBox_testResults->TabIndex = 1;
            this->groupBox_testResults->TabStop = false;
            this->groupBox_testResults->Text = L"Результаты";
            // 
            // textBox_testResEps
            // 
            this->textBox_testResEps->Location = System::Drawing::Point(106, 127);
            this->textBox_testResEps->Name = L"textBox_testResEps";
            this->textBox_testResEps->Size = System::Drawing::Size(100, 26);
            this->textBox_testResEps->TabIndex = 5;
            // 
            // label_testResEps
            // 
            this->label_testResEps->AutoSize = true;
            this->label_testResEps->Location = System::Drawing::Point(24, 127);
            this->label_testResEps->Name = L"label_testResEps";
            this->label_testResEps->Size = System::Drawing::Size(76, 20);
            this->label_testResEps->TabIndex = 4;
            this->label_testResEps->Text = L"resEps = ";
            // 
            // textBox_test_steps
            // 
            this->textBox_test_steps->Location = System::Drawing::Point(106, 90);
            this->textBox_test_steps->Name = L"textBox_test_steps";
            this->textBox_test_steps->Size = System::Drawing::Size(100, 26);
            this->textBox_test_steps->TabIndex = 3;
            // 
            // textBox_test_MaxErr
            // 
            this->textBox_test_MaxErr->Location = System::Drawing::Point(106, 55);
            this->textBox_test_MaxErr->Name = L"textBox_test_MaxErr";
            this->textBox_test_MaxErr->Size = System::Drawing::Size(100, 26);
            this->textBox_test_MaxErr->TabIndex = 2;
            // 
            // label_test_steps
            // 
            this->label_test_steps->AutoSize = true;
            this->label_test_steps->Location = System::Drawing::Point(35, 93);
            this->label_test_steps->Name = L"label_test_steps";
            this->label_test_steps->Size = System::Drawing::Size(65, 20);
            this->label_test_steps->TabIndex = 1;
            this->label_test_steps->Text = L"steps = ";
            // 
            // label_testMaxErr
            // 
            this->label_testMaxErr->AutoSize = true;
            this->label_testMaxErr->Location = System::Drawing::Point(24, 58);
            this->label_testMaxErr->Name = L"label_testMaxErr";
            this->label_testMaxErr->Size = System::Drawing::Size(76, 20);
            this->label_testMaxErr->TabIndex = 0;
            this->label_testMaxErr->Text = L"maxErr = ";
            // 
            // groupBox_testSettings
            // 
            this->groupBox_testSettings->Controls->Add(this->textBox_test_w);
            this->groupBox_testSettings->Controls->Add(this->label_test_w);
            this->groupBox_testSettings->Controls->Add(this->textBox_testEps);
            this->groupBox_testSettings->Controls->Add(this->textBox_testNmax);
            this->groupBox_testSettings->Controls->Add(this->label_testEps);
            this->groupBox_testSettings->Controls->Add(this->label_testNmax);
            this->groupBox_testSettings->Controls->Add(this->button_testSolve);
            this->groupBox_testSettings->Controls->Add(this->textBox_test_m);
            this->groupBox_testSettings->Controls->Add(this->textBox_test_n);
            this->groupBox_testSettings->Controls->Add(this->label_test_m);
            this->groupBox_testSettings->Controls->Add(this->label_test_n);
            this->groupBox_testSettings->Location = System::Drawing::Point(48, 59);
            this->groupBox_testSettings->Name = L"groupBox_testSettings";
            this->groupBox_testSettings->Size = System::Drawing::Size(267, 281);
            this->groupBox_testSettings->TabIndex = 0;
            this->groupBox_testSettings->TabStop = false;
            this->groupBox_testSettings->Text = L"Параметры";
            // 
            // textBox_test_w
            // 
            this->textBox_test_w->Location = System::Drawing::Point(106, 180);
            this->textBox_test_w->Name = L"textBox_test_w";
            this->textBox_test_w->Size = System::Drawing::Size(100, 26);
            this->textBox_test_w->TabIndex = 10;
            this->textBox_test_w->Text = L"1,6";
            // 
            // label_test_w
            // 
            this->label_test_w->AutoSize = true;
            this->label_test_w->Location = System::Drawing::Point(63, 183);
            this->label_test_w->Name = L"label_test_w";
            this->label_test_w->Size = System::Drawing::Size(37, 20);
            this->label_test_w->TabIndex = 9;
            this->label_test_w->Text = L"w = ";
            // 
            // textBox_testEps
            // 
            this->textBox_testEps->Location = System::Drawing::Point(106, 148);
            this->textBox_testEps->Name = L"textBox_testEps";
            this->textBox_testEps->Size = System::Drawing::Size(100, 26);
            this->textBox_testEps->TabIndex = 8;
            this->textBox_testEps->Text = L"1e-6";
            // 
            // textBox_testNmax
            // 
            this->textBox_testNmax->Location = System::Drawing::Point(106, 116);
            this->textBox_testNmax->Name = L"textBox_testNmax";
            this->textBox_testNmax->Size = System::Drawing::Size(100, 26);
            this->textBox_testNmax->TabIndex = 7;
            this->textBox_testNmax->Text = L"1000";
            // 
            // label_testEps
            // 
            this->label_testEps->AutoSize = true;
            this->label_testEps->Location = System::Drawing::Point(48, 151);
            this->label_testEps->Name = L"label_testEps";
            this->label_testEps->Size = System::Drawing::Size(52, 20);
            this->label_testEps->TabIndex = 6;
            this->label_testEps->Text = L"eps = ";
            // 
            // label_testNmax
            // 
            this->label_testNmax->AutoSize = true;
            this->label_testNmax->Location = System::Drawing::Point(27, 119);
            this->label_testNmax->Name = L"label_testNmax";
            this->label_testNmax->Size = System::Drawing::Size(73, 20);
            this->label_testNmax->TabIndex = 5;
            this->label_testNmax->Text = L"n_max = ";
            // 
            // button_testSolve
            // 
            this->button_testSolve->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_testSolve->Location = System::Drawing::Point(69, 223);
            this->button_testSolve->Name = L"button_testSolve";
            this->button_testSolve->Size = System::Drawing::Size(137, 40);
            this->button_testSolve->TabIndex = 4;
            this->button_testSolve->Text = L"Решить";
            this->button_testSolve->UseVisualStyleBackColor = false;
            this->button_testSolve->Click += gcnew System::EventHandler(this, &MainForm::button_testSolve_Click);
            // 
            // textBox_test_m
            // 
            this->textBox_test_m->Location = System::Drawing::Point(106, 84);
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
            this->label_test_m->Location = System::Drawing::Point(61, 87);
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
            this->button_mainErrors->Location = System::Drawing::Point(759, 636);
            this->button_mainErrors->Name = L"button_mainErrors";
            this->button_mainErrors->Size = System::Drawing::Size(339, 40);
            this->button_mainErrors->TabIndex = 4;
            this->button_mainErrors->Text = L"Таблица разностей";
            this->button_mainErrors->UseVisualStyleBackColor = false;
            this->button_mainErrors->Click += gcnew System::EventHandler(this, &MainForm::button_mainErrors_Click);
            // 
            // button_mainVS2
            // 
            this->button_mainVS2->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_mainVS2->Location = System::Drawing::Point(374, 636);
            this->button_mainVS2->Name = L"button_mainVS2";
            this->button_mainVS2->Size = System::Drawing::Size(355, 40);
            this->button_mainVS2->TabIndex = 3;
            this->button_mainVS2->Text = L"Таблица с более точным решением";
            this->button_mainVS2->UseVisualStyleBackColor = false;
            this->button_mainVS2->Click += gcnew System::EventHandler(this, &MainForm::button_mainVS2_Click);
            // 
            // dataGridView_mainVS1
            // 
            this->dataGridView_mainVS1->BackgroundColor = System::Drawing::SystemColors::Control;
            this->dataGridView_mainVS1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView_mainVS1->Location = System::Drawing::Point(374, 67);
            this->dataGridView_mainVS1->Name = L"dataGridView_mainVS1";
            this->dataGridView_mainVS1->RowTemplate->Height = 28;
            this->dataGridView_mainVS1->Size = System::Drawing::Size(724, 545);
            this->dataGridView_mainVS1->TabIndex = 2;
            // 
            // groupBox_mainResults
            // 
            this->groupBox_mainResults->Controls->Add(this->textBox_mainResEps2);
            this->groupBox_mainResults->Controls->Add(this->textBox_mainResEps1);
            this->groupBox_mainResults->Controls->Add(this->label_mainResEps2);
            this->groupBox_mainResults->Controls->Add(this->label_mainResEps1);
            this->groupBox_mainResults->Controls->Add(this->textBox_main_stepsS2);
            this->groupBox_mainResults->Controls->Add(this->label_main_stepsS2);
            this->groupBox_mainResults->Controls->Add(this->textBox_main_stepsS1);
            this->groupBox_mainResults->Controls->Add(this->textBox_mainMaxDiff);
            this->groupBox_mainResults->Controls->Add(this->label_main_stepsS1);
            this->groupBox_mainResults->Controls->Add(this->label_mainMaxDiff);
            this->groupBox_mainResults->Location = System::Drawing::Point(48, 346);
            this->groupBox_mainResults->Name = L"groupBox_mainResults";
            this->groupBox_mainResults->Size = System::Drawing::Size(264, 257);
            this->groupBox_mainResults->TabIndex = 1;
            this->groupBox_mainResults->TabStop = false;
            this->groupBox_mainResults->Text = L"Результаты";
            // 
            // textBox_mainResEps2
            // 
            this->textBox_mainResEps2->Location = System::Drawing::Point(106, 189);
            this->textBox_mainResEps2->Name = L"textBox_mainResEps2";
            this->textBox_mainResEps2->Size = System::Drawing::Size(100, 26);
            this->textBox_mainResEps2->TabIndex = 10;
            // 
            // textBox_mainResEps1
            // 
            this->textBox_mainResEps1->Location = System::Drawing::Point(106, 157);
            this->textBox_mainResEps1->Name = L"textBox_mainResEps1";
            this->textBox_mainResEps1->Size = System::Drawing::Size(100, 26);
            this->textBox_mainResEps1->TabIndex = 9;
            // 
            // label_mainResEps2
            // 
            this->label_mainResEps2->AutoSize = true;
            this->label_mainResEps2->Location = System::Drawing::Point(19, 192);
            this->label_mainResEps2->Name = L"label_mainResEps2";
            this->label_mainResEps2->Size = System::Drawing::Size(85, 20);
            this->label_mainResEps2->TabIndex = 8;
            this->label_mainResEps2->Text = L"resEps2 = ";
            // 
            // label_mainResEps1
            // 
            this->label_mainResEps1->AutoSize = true;
            this->label_mainResEps1->Location = System::Drawing::Point(19, 160);
            this->label_mainResEps1->Name = L"label_mainResEps1";
            this->label_mainResEps1->Size = System::Drawing::Size(85, 20);
            this->label_mainResEps1->TabIndex = 7;
            this->label_mainResEps1->Text = L"resEps1 = ";
            // 
            // textBox_main_stepsS2
            // 
            this->textBox_main_stepsS2->Location = System::Drawing::Point(106, 125);
            this->textBox_main_stepsS2->Name = L"textBox_main_stepsS2";
            this->textBox_main_stepsS2->Size = System::Drawing::Size(100, 26);
            this->textBox_main_stepsS2->TabIndex = 6;
            // 
            // label_main_stepsS2
            // 
            this->label_main_stepsS2->AutoSize = true;
            this->label_main_stepsS2->Location = System::Drawing::Point(18, 128);
            this->label_main_stepsS2->Name = L"label_main_stepsS2";
            this->label_main_stepsS2->Size = System::Drawing::Size(86, 20);
            this->label_main_stepsS2->TabIndex = 5;
            this->label_main_stepsS2->Text = L"steps s2 = ";
            // 
            // textBox_main_stepsS1
            // 
            this->textBox_main_stepsS1->Location = System::Drawing::Point(106, 90);
            this->textBox_main_stepsS1->Name = L"textBox_main_stepsS1";
            this->textBox_main_stepsS1->Size = System::Drawing::Size(100, 26);
            this->textBox_main_stepsS1->TabIndex = 4;
            // 
            // textBox_mainMaxDiff
            // 
            this->textBox_mainMaxDiff->Location = System::Drawing::Point(106, 55);
            this->textBox_mainMaxDiff->Name = L"textBox_mainMaxDiff";
            this->textBox_mainMaxDiff->Size = System::Drawing::Size(100, 26);
            this->textBox_mainMaxDiff->TabIndex = 3;
            // 
            // label_main_stepsS1
            // 
            this->label_main_stepsS1->AutoSize = true;
            this->label_main_stepsS1->Location = System::Drawing::Point(18, 93);
            this->label_main_stepsS1->Name = L"label_main_stepsS1";
            this->label_main_stepsS1->Size = System::Drawing::Size(86, 20);
            this->label_main_stepsS1->TabIndex = 2;
            this->label_main_stepsS1->Text = L"steps s1 = ";
            // 
            // label_mainMaxDiff
            // 
            this->label_mainMaxDiff->AutoSize = true;
            this->label_mainMaxDiff->Location = System::Drawing::Point(24, 58);
            this->label_mainMaxDiff->Name = L"label_mainMaxDiff";
            this->label_mainMaxDiff->Size = System::Drawing::Size(80, 20);
            this->label_mainMaxDiff->TabIndex = 1;
            this->label_mainMaxDiff->Text = L"maxDiff = ";
            // 
            // groupBox_mainSettings
            // 
            this->groupBox_mainSettings->Controls->Add(this->textBox_main_w);
            this->groupBox_mainSettings->Controls->Add(this->textBox_mainEps);
            this->groupBox_mainSettings->Controls->Add(this->textBox_mainNmax);
            this->groupBox_mainSettings->Controls->Add(this->label_main_w);
            this->groupBox_mainSettings->Controls->Add(this->label_mainEps);
            this->groupBox_mainSettings->Controls->Add(this->label_mainNmax);
            this->groupBox_mainSettings->Controls->Add(this->button_mainSolve);
            this->groupBox_mainSettings->Controls->Add(this->textBox_main_m);
            this->groupBox_mainSettings->Controls->Add(this->textBox_main_n);
            this->groupBox_mainSettings->Controls->Add(this->label_main_m);
            this->groupBox_mainSettings->Controls->Add(this->label_main_n);
            this->groupBox_mainSettings->Location = System::Drawing::Point(48, 59);
            this->groupBox_mainSettings->Name = L"groupBox_mainSettings";
            this->groupBox_mainSettings->Size = System::Drawing::Size(267, 281);
            this->groupBox_mainSettings->TabIndex = 0;
            this->groupBox_mainSettings->TabStop = false;
            this->groupBox_mainSettings->Text = L"Параметры";
            // 
            // textBox_main_w
            // 
            this->textBox_main_w->Location = System::Drawing::Point(106, 180);
            this->textBox_main_w->Name = L"textBox_main_w";
            this->textBox_main_w->Size = System::Drawing::Size(100, 26);
            this->textBox_main_w->TabIndex = 13;
            this->textBox_main_w->Text = L"1,6";
            // 
            // textBox_mainEps
            // 
            this->textBox_mainEps->Location = System::Drawing::Point(106, 148);
            this->textBox_mainEps->Name = L"textBox_mainEps";
            this->textBox_mainEps->Size = System::Drawing::Size(100, 26);
            this->textBox_mainEps->TabIndex = 12;
            this->textBox_mainEps->Text = L"1e-6";
            // 
            // textBox_mainNmax
            // 
            this->textBox_mainNmax->Location = System::Drawing::Point(106, 116);
            this->textBox_mainNmax->Name = L"textBox_mainNmax";
            this->textBox_mainNmax->Size = System::Drawing::Size(100, 26);
            this->textBox_mainNmax->TabIndex = 11;
            this->textBox_mainNmax->Text = L"1000";
            // 
            // label_main_w
            // 
            this->label_main_w->AutoSize = true;
            this->label_main_w->Location = System::Drawing::Point(63, 183);
            this->label_main_w->Name = L"label_main_w";
            this->label_main_w->Size = System::Drawing::Size(37, 20);
            this->label_main_w->TabIndex = 10;
            this->label_main_w->Text = L"w = ";
            // 
            // label_mainEps
            // 
            this->label_mainEps->AutoSize = true;
            this->label_mainEps->Location = System::Drawing::Point(48, 151);
            this->label_mainEps->Name = L"label_mainEps";
            this->label_mainEps->Size = System::Drawing::Size(52, 20);
            this->label_mainEps->TabIndex = 7;
            this->label_mainEps->Text = L"eps = ";
            // 
            // label_mainNmax
            // 
            this->label_mainNmax->AutoSize = true;
            this->label_mainNmax->Location = System::Drawing::Point(27, 119);
            this->label_mainNmax->Name = L"label_mainNmax";
            this->label_mainNmax->Size = System::Drawing::Size(73, 20);
            this->label_mainNmax->TabIndex = 6;
            this->label_mainNmax->Text = L"n_max = ";
            // 
            // button_mainSolve
            // 
            this->button_mainSolve->BackColor = System::Drawing::Color::WhiteSmoke;
            this->button_mainSolve->Location = System::Drawing::Point(69, 223);
            this->button_mainSolve->Name = L"button_mainSolve";
            this->button_mainSolve->Size = System::Drawing::Size(137, 40);
            this->button_mainSolve->TabIndex = 4;
            this->button_mainSolve->Text = L"Решить";
            this->button_mainSolve->UseVisualStyleBackColor = false;
            this->button_mainSolve->Click += gcnew System::EventHandler(this, &MainForm::button_mainSolve_Click);
            // 
            // textBox_main_m
            // 
            this->textBox_main_m->Location = System::Drawing::Point(106, 84);
            this->textBox_main_m->Name = L"textBox_main_m";
            this->textBox_main_m->Size = System::Drawing::Size(100, 26);
            this->textBox_main_m->TabIndex = 3;
            this->textBox_main_m->Text = L"10";
            // 
            // textBox_main_n
            // 
            this->textBox_main_n->Location = System::Drawing::Point(106, 52);
            this->textBox_main_n->Name = L"textBox_main_n";
            this->textBox_main_n->Size = System::Drawing::Size(100, 26);
            this->textBox_main_n->TabIndex = 2;
            this->textBox_main_n->Text = L"10";
            // 
            // label_main_m
            // 
            this->label_main_m->AutoSize = true;
            this->label_main_m->Location = System::Drawing::Point(61, 87);
            this->label_main_m->Name = L"label_main_m";
            this->label_main_m->Size = System::Drawing::Size(39, 20);
            this->label_main_m->TabIndex = 1;
            this->label_main_m->Text = L"m = ";
            // 
            // label_main_n
            // 
            this->label_main_n->AutoSize = true;
            this->label_main_n->Location = System::Drawing::Point(65, 55);
            this->label_main_n->Name = L"label_main_n";
            this->label_main_n->Size = System::Drawing::Size(35, 20);
            this->label_main_n->TabIndex = 0;
            this->label_main_n->Text = L"n = ";
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
            this->groupBox_testResults->ResumeLayout(false);
            this->groupBox_testResults->PerformLayout();
            this->groupBox_testSettings->ResumeLayout(false);
            this->groupBox_testSettings->PerformLayout();
            this->tabPage_main->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_mainVS1))->EndInit();
            this->groupBox_mainResults->ResumeLayout(false);
            this->groupBox_mainResults->PerformLayout();
            this->groupBox_mainSettings->ResumeLayout(false);
            this->groupBox_mainSettings->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void button_testU_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_testErrors_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_mainVS2_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_mainErrors_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_mainSolve_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void button_testSolve_Click(System::Object^  sender, System::EventArgs^  e);

    protected:
             void test_Solve();
             int main_Solve(double **vs, double **fs, int n, int m, int nmax, bool index);

             // для матрицы vs - задать нулевое начальное приближение и ГУ
             void setVS(double **vs, int n, int m);
};
}
