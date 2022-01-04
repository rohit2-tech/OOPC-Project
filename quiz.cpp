
#include <iostream>
#include <windows.h>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <string>
#include <iomanip>
#include <cstdio>
#include <stdlib.h>

using namespace std;
class Intro;
class quiz;
class Add; /* different classes used*/
class rect;
class compare;
class Complex;
int j;
int score = 0;
class Intro
{
public:
    string FF;
    Intro() /* constructor is made*/
    {

        /* Introduction : */

        Beep(0, 300);
        Beep(2000, 100); /* beep(note,time in msec)    to generate a note or frequency in Hertz*/
        cout << " \nWelcome to";
        Beep(0, 600);
        cout << " MATH QUIZ GAME!                                           ";
        Beep(2000, 100);
        Beep(1500, 100);
        Beep(2000, 100);
        Beep(1500, 100);
        Beep(2000, 700);
        Beep(0, 400);
        cout << "\n\n=========================\n\nPlease enter your name : ";
        cin >> FF;
        cout << "\n\n=========================\n\nHello " << FF << " !\n\n";
        Beep(0, 700);
        for (int a = 5; a > 0; a--)
        {
            cout << "\rGet ready to play in :  " << a;
            Beep(2000, 300);
            Beep(0, 700);
        }
        cout << "\r=========================\n\n";
        Beep(0, 500);
    }
};

/* PARENT CLASS : */

class quiz
{
public:
    int i;
    time_t start = time(0); /* as  soon timer function is called start collects the value returned by time(0)  */
    int numInput;           /* answer typed by user*/

    int A = rand() % 10 + 1; /* generates random integers*/
    int B = rand() % 10 + 1;

    int Timer() /* TIMER  to check time limit*/
    {
        while (!kbhit()) /*  kbhit() generates random positive integers as soon as we hit the keyboard */
        {
            if (abs(time(0) - start) > 5) /* time() returns number  of seconds elapsed from jan 1970 to till now, of the type time_t;
                                                                                                                                            */
            {
                j = 1;
                break;
            }
        }
        if (j == 1)
        {
            cout << "\nTime's Up!!\n";
            j = 2;
        }
        else
        {
            cin >> numInput;
            if ((time(0) - start) > 5) /* here we check the time difference is less than 5 sec or not*/
            {
                cout << "\nTime's Up!!\n";
                j = 2;
            }
        }
        if (j == 2)
            return (0);
        else
            return (1);
    }
};

class Complex : public quiz /* inherited class */
{
public:
    Complex operator+(Complex &C2) /* Operator overloading*/
    {
        Complex C3;
        cout << "(" << A << "+i" << B << ")\t";
        cout << " + (" << C2.A << "+i" << C2.B << ")\n";
        C3.A = A + C2.A;
        C3.B = B + C2.B;
        return (C3);
    }

    int Check(Complex &D) /* check funtion will decide wheather user typed correct answer or not */
    {
        if (A == D.A && B == D.B)
            return (10);
        else
        {
            cout << "WRONG!!!!";
            return (0);
        }
    }

    int Timer() /* Funtion overriding*/
    {
        while (!kbhit())
        {
            if (abs(time(0) - start) > 10)

            {
                j = 1;
                break;
            }
        }
        if (j == 1)
        {
            cout << "\nTime's Up!!";
            j = 2;
        }
        else
        {
            cin >> A >> B;
            if ((time(0) - start) > 10)
            {
                cout << "\nTime's Up!!";
                j = 2;
            }
        }
        if (j == 2)
            return (0);
        else
            return (1);
    }
};

class compare : public quiz
{
public:
    void operation() /* this will show which operation is going to be performed by user */
    {
        cout << " which one is larger between  " << A << " and " << B << " = ";
    }

    int Check(int w)
    {
        if (numInput == w)
            return (10);
        else
        {
            cout << "\n wrong!!!!";
            return 0;
        }
    }
    friend int large(int m, int n); /* FRIEND FUNCTION application */
};

int large(int m, int n)
{
    if (m > n)
        return (m);
    else
        return (n);
}

class rect : public quiz /* DERIVED CLASS*/
{
public:
    void operation(int l, int b) /* function OVERLOADING    2 arguments */
    {
        cout << "Area of Rectangle with Length=" << l << " & Breadth= " << b << "\n";
    }
    void operation(int l) /* function OVERLOADING   1 arguments */
    {
        cout << "Area of Square with  side Length=" << l << " is : "
             << "\n";
    }
    int Check(int l, int b) /* funtion OVERLOADING */
    {
        if (numInput == l * b)
            return (10);
        else
        {
            cout << "\n wrong!!!!";
            return 0;
        }
    }
    int Check(int l) /* funtion OVERLOADING */
    {
        if (numInput == l * l)
            return (10);
        else
        {
            cout << "\n wrong!!!!";
            return 0;
        }
    }
};

class Add : public quiz /* SIMPLE CHILD CLASS*/
{
public:
    void operation()
    {
        cout << " Sum of " << A << " + " << B << " = ";
    }
    int Check()
    {
        if (numInput == A + B)
        {

            return (10);
        }
        else
        {
            cout << "\n wrong !!!!";
            return (0);
        }
    }
};

class Sub : public quiz /* SIMPLE CHILD CLASS*/
{
public:
    void Operation()
    {
        cout << " Subtraction  of " << A << " - " << B << " = ";
    }
    int Check()
    {
        if (numInput == A - B)
        {

            return (10);
        }
        else
        {
            cout << "\n wrong !!!!";
            return (0);
        }
    }
};

int main()
{

    cout << endl;
    while (true)
    {
        int p;
        score = 0;
        Intro Obj1;
        cout << " \n\n  #level-1 \n*----------  ADDITION TEST  ----------*    \n ...(you will be given only five sec to solve each question)...\n\n";
        Beep(0, 4000);
        for (p = 0; p < 3; p++)
        {
            cout << "\nNext question is coming......\n";
            Beep(0, 1000);
            srand(time(0));

            Add Obj;
            Obj.operation();
            if (Obj.Timer() == 0)
            {
                cout << " \n  -------   *    GAME OVER    *   ----------\n\n\n";
                cout << "\n ----------       YOUR FINAL SCORE : : " << score << "          ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 2000);
                while (kbhit)
                    exit(0);
            }
            if (!Obj.Check())
            {
                cout << " \n  ------- *     GAME OVER    *   ----------\n\n";
                cout << "\n ----------              YOUR FINAL SCORE : : " << score << "          ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 2000);
                while (kbhit)
                    exit(0);
            }
            else
            {
                score += Obj.Check();
                cout << " Good !!!!\n --------- *       YOUR SCORE SO FAR  :: " << score << "       *---------\n";
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 700);
                Beep(0, 400);
            }
        }
        cout << "\n\n  #level-2 \n *----------  SUBSTRACTION  TEST  ----------*   \n(you will be given only  5 sec to solve each question) \n\n";
        Beep(0, 4000);
        for (p = 0; p < 3; p++)
        {
            cout << "\nNext question is coming......\n";
            Beep(0, 1000);
            srand(time(0));

            Sub Obj2;
            Obj2.Operation();
            if (Obj2.Timer() == 0)
            {
                cout << " \n  ------- *    GAME OVER    *   ----------\n\n\n";
                cout << "\n ----------     YOUR FINAL SCORE : : " << score << "      ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 2000);
                while (kbhit)
                    exit(0);
            }
            if (!Obj2.Check())
            {
                cout << " \n  ------- *    GAME OVER    *   ----------\n\n\n";
                cout << "\n ----------      YOUR FINAL SCORE : : " << score << "     ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 1000);
                while (kbhit)
                    exit(0);
            }
            else
            {
                score += Obj2.Check();
                cout << " Good !!!!\n --------- *    YOUR SCORE SO FAR  :: " << score << "    *---------\n";
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 700);
                Beep(0, 400);
            }
        }

        cout << "\n\n #level-3 \n *----------   COMPARISON TEST   ----------*\n...(you have only 5 sec to solve each question)...      \n\n";
        Beep(0, 4000);
        for (p = 0; p < 3; p++)
        {
            cout << "\nNext question is coming......\n";
            Beep(0, 1000);
            srand(time(0));
            compare Obj5;
            Obj5.operation();
            if (Obj5.Timer() == 0)
            {
                cout << " \n  ------- *    GAME OVER    * --------\n\n\n";
                cout << "\n ----------     YOUR FINAL SCORE : : " << score << "      ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 1000);
                while (kbhit)
                    exit(0);
            }
            if (!Obj5.Check(large(Obj5.A, Obj5.B)))
            {
                cout << " \n  ------- *      GAME OVER    *   --------\n\n\n";
                cout << "\n ----------      YOUR FINAL SCORE : : " << score << "       ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 1000);
                while (kbhit)
                    exit(0);
            }
            else
            {
                score += Obj5.Check(large(Obj5.A, Obj5.B));
                cout << " Good !!!!\n --------- *      YOUR SCORE SO FAR  :: " << score << "     *---------\n";
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 700);
                Beep(0, 400);
            }
        }

        cout << "\n\n #level-4 \n*----------  AREA CALCULATION TEST  ----------*    \n...(you will be given only 5 sec to solve each question)...  \n\n";
        Beep(0, 4000);
        for (p = 0; p < 2; p++)
        {
            cout << "\nNext question is coming......\n";
            Beep(0, 1000);
            rect Obj3;
            Obj3.operation(Obj3.A, Obj3.B);
            if (Obj3.Timer() == 0)
            {
                cout << " \n  ------- *     GAME OVER    * --------\n\n\n";
                cout << "\n ----------     YOUR FINAL SCORE : : " << score << "     ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 1000);
                while (kbhit)
                    exit(0);
            }
            if (!Obj3.Check(Obj3.A, Obj3.B))
            {
                cout << " \n  ------- *     GAME OVER    * --------\n\n\n";
                cout << "\n ----------     YOUR FINAL SCORE : : " << score << "      ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 1000);
                while (kbhit)
                    exit(0);
            }
            else
            {
                score += Obj3.Check(Obj3.A, Obj3.B);
                cout << " Good !!!!\n --------- *      YOUR SCORE SO FAR  :: " << score << "       *---------\n";
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 700);
                Beep(0, 400);
            }

            cout << "\nNext question is coming......\n";
            Beep(0, 1000);
            rect Obj6;
            Obj6.operation(Obj6.A);
            if (Obj6.Timer() == 0)
            {
                cout << " \n  ------- *      GAME OVER    * -------\n\n\n";
                cout << "\n ----------       YOUR FINAL SCORE : : " << score << "      ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 1000);
                while (kbhit)
                    exit(0);
            }
            if (!Obj6.Check(Obj6.A))
            {
                cout << " \n  ------- *     GAME OVER    * --------\n\n\n";
                cout << "\n ----------       YOUR FINAL SCORE : : " << score << "       ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 1000);
                while (kbhit)
                    exit(0);
            }
            else
            {
                score += Obj6.Check(Obj6.A);
                cout << " Good !!!!\n --------- *     YOUR SCORE SO FAR  :: " << score << "      *---------\n";
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 700);
                Beep(0, 400);
            }
        }
        cout << "\n\n #level-5 \n*----------  COMPLEX ADDITTON TEST  ----------*  \n ...(you have only 5 sec to solve each question)...         \n\n";
        Beep(0, 4000);
        for (p = 0; p < 3; p++)
        {
            cout << "\nNext question is coming......\n";
            Beep(0, 1000);
            srand(time(0));
            Complex Obj7, Obj8, Obj9, Obj10;
            Obj9 = Obj7 + Obj8;
            cout << "\n Type your answer in A+iB form \n A & B are respectively\n";

            if (Obj10.Timer() == 0)
            {
                cout << " \n  ------- *     GAME OVER    * --------\n\n\n";
                cout << "\n ----------       YOUR FINAL SCORE : : " << score << "      ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 1000);
                while (kbhit)
                    exit(0);
            }
            if (!Obj10.Check(Obj9))
            {
                cout << " \n  ------- *     GAME OVER    * --------\n\n\n";
                cout << "\n ----------       YOUR FINAL SCORE : : " << score << "       ------------\n\n";
                Beep(2000, 300);
                Beep(1700, 300);
                Beep(1400, 300);
                Beep(1100, 1000);
                while (kbhit)
                    exit(0);
            }
            else
            {
                score += Obj10.Check(Obj9);
                cout << " Good !!!!\n --------- *       YOUR SCORE SO FAR  :: " << score << "       *---------\n";
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 100);
                Beep(1500, 100);
                Beep(2000, 700);
                Beep(0, 400);
            }
        }

        cout << "\n\n -----------------** WINNER WINNER WINNER WINNER***--------------------\n\n       ";
        while (kbhit)
            exit(0);
    }
}
