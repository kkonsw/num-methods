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
    My4mlab2::TableMainVS2 form_mainVS2;
    form_mainVS2.ShowDialog();
}

System::Void My4mlab2::MainForm::button_mainErrors_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    My4mlab2::ErrorsMain form_mainErrors;
    form_mainErrors.ShowDialog();
}

System::Void My4mlab2::MainForm::button_mainSolve_Click(System::Object ^ sender, System::EventArgs ^ e)
{

}

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
    if (f != nullptr)
        deleteMatrix<double>(f);
    if (test_err != nullptr)
        deleteMatrix<double>(test_err);

    u = createMatrix<double>(test_n + 1, test_m + 1);
    v = createMatrix<double>(test_n + 1, test_m + 1);
    f = createMatrix<double>(test_n + 1, test_m + 1);
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
            f[i][j] = func_f(a + h * i, c + k * j);
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

double My4mlab2::MainForm::func_u(double x, double y)
{
    double pi = M_PI;

    return exp(pow(sin(pi*x*y), 2.0));
}

double My4mlab2::MainForm::func_f(double x, double y)
{
    double pi = M_PI;

    return -2.0*pi*pi*(x*x + y*y)*exp(pow(sin(pi*x*y), 2.0))*((2.0*pow(sin(pi*x*y), 2.0) + 1.0)*pow(cos(pi*x*y), 2.0) - pow(sin(pi*x*y), 2.0));
}

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
                v_new = v_new + (1 - test_w)*a2*v[i][j] + test_w * f[i][j];
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

    textBox_test_steps->Text = System::Convert::ToString(s);
}
