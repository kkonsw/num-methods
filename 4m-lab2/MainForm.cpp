#include "MainForm.h"
#include "TableTestU.h"
#include "ErrorsTest.h"
#include "ErrorsMain.h"
#include "TableMainVS2.h"

#define _USE_MATH_DEFINES
#include <cmath>

using namespace My4mlab2;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    My4mlab2::MainForm form;
    Application::Run(%form);
}

System::Void My4mlab2::MainForm::button_testU_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    if (u != nullptr)
    {
        My4mlab2::TableTestU form_testU(u, test_n, test_m);
        form_testU.ShowDialog();
    }
    else
    {
        My4mlab2::TableTestU form_testU;
        form_testU.ShowDialog();
    }   
}

System::Void My4mlab2::MainForm::button_testErrors_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    if (test_err != nullptr)
    {
        My4mlab2::ErrorsTest form_testErrors(test_err, test_n, test_m);
        form_testErrors.ShowDialog();
    }
    else
    {
        My4mlab2::ErrorsTest form_testErrors;
        form_testErrors.ShowDialog();
    }
}

System::Void My4mlab2::MainForm::button_mainVS2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    if (vs2 != nullptr)
    {
        My4mlab2::TableMainVS2 form_mainVS2(vs2, 2*main_n, 2*main_m);
        form_mainVS2.ShowDialog();
    }
    else
    {
        My4mlab2::TableMainVS2 form_mainVS2;
        form_mainVS2.ShowDialog();
    }
}

System::Void My4mlab2::MainForm::button_mainErrors_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    if (main_diff != nullptr)
    {
        My4mlab2::ErrorsMain form_mainErrors(main_diff, main_n, main_m);
        form_mainErrors.ShowDialog();
    }
    else
    {
        My4mlab2::ErrorsMain form_mainErrors;
        form_mainErrors.ShowDialog();
    }
}

// решение основной задачи
System::Void My4mlab2::MainForm::button_mainSolve_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    main_n = System::Convert::ToInt32(textBox_main_n->Text);
    main_m = System::Convert::ToInt32(textBox_main_m->Text);
    main_Nmax = System::Convert::ToInt32(textBox_mainNmax->Text);
    main_eps = System::Convert::ToDouble(textBox_mainEps->Text);
    main_w = System::Convert::ToDouble(textBox_main_w->Text);

    double h = (b - a) / main_n;
    double k = (d - c) / main_m;

    if (vs1 != nullptr)
        deleteMatrix<double>(vs1);
    if (vs2 != nullptr)
        deleteMatrix<double>(vs2);
    if (f2 != nullptr)
        deleteMatrix<double>(f2);
    if (main_diff != nullptr)
        deleteMatrix<double>(main_diff);

    vs1 = createMatrix<double>(main_n + 1, main_m + 1);
    f2 = createMatrix<double>(main_n + 1, main_m + 1);
    main_diff = createMatrix<double>(main_n + 1, main_m + 1);

    // считаем значения правой части (разбиение s1)
    for (int i = 0; i < main_n + 1; i++)
        for (int j = 0; j < main_m + 1; j++)
        {
            f2[i][j] = func_f2(a + h * i, c + k * j);
        }

    // считаем граничные условия s1:
    // нулевое начальное приближение
    setVS(vs1, main_n, main_m);

    // считаем (разбиение s1)
    int s = main_Solve(vs1, f2, main_n, main_m, main_Nmax, 0);
    textBox_main_stepsS1->Text = System::Convert::ToString(s);

    // теперь необходимо рассчитать разбиение s2
    // сгущаем сетку в 2 раза
    vs2 = createMatrix<double>(2 * main_n + 1, 2 * main_m + 1);
    deleteMatrix<double>(f2);
    f2 = createMatrix<double>(2 * main_n + 1, 2 * main_m + 1);

    // пересчитываем шаг
    h = (b - a) / (2 * main_n);
    k = (d - c) / (2 * main_m);

    // считаем значения правой части (разбиение s2)
    for (int i = 0; i < 2 * main_n + 1; i++)
        for (int j = 0; j < 2 * main_m + 1; j++)
        {
            f2[i][j] = func_f2(a + h * i, c + k * j);
        }

    // считаем граничные условия s2:
    // нулевое начальное приближение
    setVS(vs2, 2 * main_n, 2 * main_m);

    // считаем (разбиение s2)
    s = main_Solve(vs2, f2, 2 * main_n, 2 * main_m, main_Nmax, 1);
    textBox_main_stepsS2->Text = System::Convert::ToString(s);

    // заполняем таблицу с разбиением s1
    dataGridView_mainVS1->Rows->Clear();
    dataGridView_mainVS1->Columns->Clear();

    cli::array< DataGridViewTextBoxColumn^ >^ arr;
    arr = gcnew cli::array< DataGridViewTextBoxColumn^ >(main_n + 1);

    for (int i = 0; i < main_n + 1; i++)
    {
        arr[i] = gcnew DataGridViewTextBoxColumn();
    }

    dataGridView_mainVS1->Columns->AddRange(arr);

    for (int j = main_m; j >= 0; j--)
    {
        dataGridView_mainVS1->Rows->Add();
        for (int i = 0; i < main_n + 1; i++)
        {
            dataGridView_mainVS1->Rows[main_m - j]->Cells[i]->Value = System::Convert::ToString(vs1[i][j]);
        }
    }

    dataGridView_mainVS1->ClearSelection();

    // готовы 2 матрицы vs1 и vs2
    // считаем разницы в узлах
    double diff = 0.0;
    double maxDiff = 0.0;
    for (int i = 0; i < main_n + 1; i++)
        for (int j = 0; j < main_m + 1; j++)
        {
            diff = fabs(vs1[i][j] - vs2[2*i][2*j]);
            main_diff[i][j] = diff;
            if (diff > maxDiff)
                maxDiff = diff;
        }

    textBox_mainMaxDiff->Text = System::Convert::ToString(maxDiff);
}

// решение тестовой задачи
System::Void My4mlab2::MainForm::button_testSolve_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    test_n = System::Convert::ToInt32(textBox_test_n->Text);
    test_m = System::Convert::ToInt32(textBox_test_m->Text);
    test_Nmax = System::Convert::ToInt32(textBox_testNmax->Text);
    test_eps = System::Convert::ToDouble(textBox_testEps->Text);
    test_w = System::Convert::ToDouble(textBox_test_w->Text);

    double h = (b - a) / test_n;
    double k = (d - c) / test_m;

    if (u != nullptr)
        deleteMatrix<double>(u);
    if (v != nullptr)
        deleteMatrix<double>(v);
    if (f1 != nullptr)
        deleteMatrix<double>(f1);
    if (test_err != nullptr)
        deleteMatrix<double>(test_err);

    u = createMatrix<double>(test_n + 1, test_m + 1);
    v = createMatrix<double>(test_n + 1, test_m + 1);
    f1 = createMatrix<double>(test_n + 1, test_m + 1);
    test_err = createMatrix<double>(test_n + 1, test_m + 1);

    // считаем значения тестовой функции
    for (int i = 0; i < test_n + 1; i++)
        for (int j = 0; j < test_m + 1; j++)                    
        {
            u[i][j] = func_u(a + h * i, c + k * j);
        }

    // считаем значения правой части
    for (int i = 0; i < test_n + 1; i++)
        for (int j = 0; j < test_m + 1; j++)
        {
            f1[i][j] = func_f1(a + h * i, c + k * j);
        }

    // считаем граничные условия:
    // нулевое начальное приближение
    for (int j = 0; j < test_m + 1; j++)
        for (int i = 0; i < test_n + 1; i++)      
            v[i][j] = 0.0;

    // заполнение массива v значениями: слева направо по x 
    for (int i = 0; i < test_n + 1; i++)
    {
        v[i][0] = func_u(a + h * i, c);	        // нижняя строка	
        v[i][test_m] = func_u(a + h * i, d);	// верхняя строка
    }

    // заполнение массива v значениями: снизу вверх по y
    for (int j = 0; j < test_m + 1; j++)
    {
        v[0][j] = func_u(a, c + k * j);	        //левый столбец
        v[test_n][j] = func_u(b, c + k * j);	//правый столбец
    }

    // считаем численно
    test_Solve();

    // заполняем таблицу
    dataGridView_testV->Rows->Clear();
    dataGridView_testV->Columns->Clear();

    cli::array< DataGridViewTextBoxColumn^ >^ arr;
    arr = gcnew cli::array< DataGridViewTextBoxColumn^ >(test_n + 1);

    for (int i = 0; i < test_n + 1; i++)
    {
        arr[i] = gcnew DataGridViewTextBoxColumn();
    }

    dataGridView_testV->Columns->AddRange(arr);

    for (int j = test_m; j >= 0; j--)
    {
        dataGridView_testV->Rows->Add();
        for (int i = 0; i < test_n + 1; i++)
        {
            dataGridView_testV->Rows[test_m - j]->Cells[i]->Value = System::Convert::ToString(v[i][j]);
        }
    }

    dataGridView_testV->ClearSelection();

    // вычисление макс. погрешности
    double err = 0.0;
    double maxErr = 0.0;    
    for (int i = 0; i < test_n + 1; i++)
        for (int j = 0; j < test_m + 1; j++)
        {
            err = fabs(u[i][j] - v[i][j]);
            test_err[i][j] = err;
            if (err > maxErr)
                maxErr = err;
        }

    textBox_test_MaxErr->Text = System::Convert::ToString(maxErr);
}

// метод верхней релаксации для решения тестовой задачи
void My4mlab2::MainForm::test_Solve()
{ 
    int s = 0;							// счетчик итераций
    double eps_max = 0;					// текущее значение прироста
    double eps_cur = 0;					// для подсчета текущего значения прироста
    double a2 = 0, k2 = 0, h2 = 0;		// ненулевые элементы матрицы 

    h2 = -pow((test_n / (b - a)), 2);
    k2 = -pow((test_m / (d - c)), 2);
    a2 = -2 * (h2 + k2);

    double v_old;		// старое значение преобразуемой компоненты вектора 
    double v_new;		// новое значение преобразуемой компоненты вектора 
    bool flag = false;	// условие остановки 

    // метод верхней релаксации
    while (!flag)
    {
        eps_max = 0;
        for (int j = 1; j < test_m; j++)
            for (int i = 1; i < test_n; i++)
            {
                v_old = v[i][j];
                v_new = -test_w * (h2*(v[i + 1][j] + v[i - 1][j]) + k2 * (v[i][j + 1] + v[i][j - 1]));
                v_new = v_new + (1 - test_w)*a2*v[i][j] + test_w * f1[i][j];
                v_new = v_new / a2;
                eps_cur = fabs(v_old - v_new);
                if (eps_cur > eps_max)
                    eps_max = eps_cur;
                v[i][j] = v_new;
            }
        s++;

        if ((eps_max < test_eps) || (s >= test_Nmax))
            flag = true;
    }

    textBox_testResEps->Text = System::Convert::ToString(eps_max);
    textBox_test_steps->Text = System::Convert::ToString(s);
}

// метод верхней релаксации для решения основной задачи
int My4mlab2::MainForm::main_Solve(double **vs, double **fs, int n, int m, int nmax, bool index)
{
    int s = 0;							// счетчик итераций
    double eps_max = 0;					// текущее значение прироста
    double eps_cur = 0;					// для подсчета текущего значения прироста
    double a2 = 0, k2 = 0, h2 = 0;		// ненулевые элементы матрицы 

    h2 = -pow((n / (b - a)), 2);
    k2 = -pow((m / (d - c)), 2);
    a2 = -2 * (h2 + k2);

    double v_old;		// старое значение преобразуемой компоненты вектора 
    double v_new;		// новое значение преобразуемой компоненты вектора 
    bool flag = false;	// условие остановки 

    // метод верхней релаксации
    while (!flag)
    {
        eps_max = 0;
        for (int j = 1; j < m; j++)
            for (int i = 1; i < n; i++)
            {
                v_old = vs[i][j];
                v_new = -main_w * (h2*(vs[i + 1][j] + vs[i - 1][j]) + k2 * (vs[i][j + 1] + vs[i][j - 1]));
                v_new = v_new + (1 - main_w)*a2*vs[i][j] + main_w * fs[i][j];
                v_new = v_new / a2;
                eps_cur = fabs(v_old - v_new);
                if (eps_cur > eps_max)
                    eps_max = eps_cur;
                vs[i][j] = v_new;
            }
        s++;

        if ((eps_max < main_eps) || (s >= nmax))
            flag = true;
    }

    if (index == 0) textBox_mainResEps1->Text = System::Convert::ToString(eps_max);
    if (index == 1) textBox_mainResEps2->Text = System::Convert::ToString(eps_max);
    return s;
}

// для матрицы vs - задать нулевое начальное приближение и ГУ
void My4mlab2::MainForm::setVS(double ** vs, int n, int m)
{
    double h = (b - a) / n;
    double k = (d - c) / m;

    // считаем граничные условия:
    // нулевое начальное приближение
    for (int j = 0; j < m + 1; j++)
        for (int i = 0; i < n + 1; i++)
            vs[i][j] = 0.0;

    // заполнение массива vs значениями: слева направо по x 
    for (int i = 0; i < n + 1; i++)
    {
        vs[i][0] = nu3(a + h * i);	// нижняя строка	
        vs[i][m] = nu4(a + h * i);	// верхняя строка
    }

    // заполнение массива vs значениями: снизу вверх по y
    for (int j = 0; j < m + 1; j++)
    {
        vs[0][j] = nu1(c + k * j);	//левый столбец
        vs[n][j] = nu2(c + k * j);	//правый столбец
    }
}
