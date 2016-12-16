
#include <iostream>
#include <iomanip>

using namespace std;

int Menu (float assignWghtAvg, float labWghtAvg,float lectureWghtAvg, float postWghtAvg,float quizWghtAvg, float clickWghtAvg,float finalGrade); // should be called to display the menu option and this function will return the choice
void DisplayGrades (float assignWghtAvg, float labWghtAvg, float lectureWghtAvg, float postWghtAvg, float quizWghtAvg, float clickWghtAvg);// this function should be called to display the Grades in a Tabular Format. This table should contain the category name and the weighted average for that category. Ex: 		Clickers		3.4 %
void OverAllGrade(float assignWghtAvg, float labWghtAvg,float lectureWghtAvg, float postWghtAvg,float quizWghtAvg, float clickWghtAvg,float finalGrade); // should be called for option 2 of menu which will display the overall grade and the letter grade
float AssignmentGrade (float asgnmnt1, float asgnmnt2, float asgnmnt3, float asgnmnt4, float& assignWghtAvg); // This function is used to calculate total weight of assignment towards final grade
float LabTestGrade (float ltest1,float ltest2,float ltest3, float& labWghtAvg);// this function will calculate total weight of lab test grades towards final grade
float LectureTestGrade(float test1,float test2,float test3,float test4,float& lectureWghtAvg); // This function will calculate total weight of lecture test grades towards final grade
float PostLabGrade (float postLab1,float postLab2,float postLab3,float postLab4,float postLab5,float postLab6,float postLab7,float postLab8,float  postLab9,float& postWghtAvg); // This function will accept 9 inputs from user as his postlab grade and  calculate total weight of Post lab grades towards final grade
float QuizGrade (float quiz1,float quiz2,float quiz3,float quiz4,float quiz5,float quiz6,float quiz7,float quiz8,float quiz9,float& quizWghtAvg ); // this function should ask the user to enter his grades for 9 quiz and based on that calculate the total weight of quiz towards final grade
float ClickerGrade (float click,float& clickWghtAvg ) ;// this function should ask the user to enter his clicker score and calculate weight based on it towards the final grade.
bool gradeIsValid (float grade); // This function should make sure that user entered grades are valid
bool menuChoiceIsValid (int choice); //This function should make sure that the entered menu choice is valid

int main()
{
    float asgnmnt1, asgnmnt2, asgnmnt3, asgnmnt4, assignWghtAvg;
    float ltest1, ltest2, ltest3,labWghtAvg;
    float test1,test2,test3, test4,lectureWghtAvg;
    float postlab1,postlab2, postlab3,postlab4,postlab5, postlab6, postlab7,postlab8,postlab9,postWghtAvg;
    float quiz1,quiz2, quiz3,quiz4,quiz5,quiz6,quiz7, quiz8, quiz9,quizWghtAvg;
    float click,clickWghtAvg;
    float finalGrade;
    int choice;
    float grade;

    AssignmentGrade(asgnmnt1, asgnmnt2, asgnmnt3,asgnmnt4, assignWghtAvg);
    LabTestGrade (ltest1,ltest2, ltest3,labWghtAvg);
    LectureTestGrade(test1,test2,test3, test4, lectureWghtAvg);
    PostLabGrade( postlab1,postlab2, postlab3,postlab4,postlab5, postlab6, postlab7,postlab8,postlab9, postWghtAvg);
    QuizGrade(quiz1,quiz2, quiz3,quiz4,quiz5,quiz6,quiz7, quiz8, quiz9,quizWghtAvg);
    ClickerGrade(click, clickWghtAvg);
    Menu(assignWghtAvg, labWghtAvg,lectureWghtAvg,postWghtAvg, quizWghtAvg, clickWghtAvg,finalGrade);
    return 0;
}


/*
float AssignmentGrade (float asgnmnt1, float asgnmnt2, float asgnmnt3, float asgnmnt4, float& assignWghtAvg)
{
    bool grade_Valid=false;
    int grade;
    while(grade_Valid==false)
    {
    cout << "What is your grade for Assignment 1?" << endl;
    cin >> asgnmnt1;
    grade_Valid=gradeIsValid(asgnmnt1);
    if (grade_Valid==true)
    {
        break;
    }
    if(grade_Valid==false)
    {
     cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
    }
    }
    while(grade_Valid==false)
    {
    cout << "What is your grade for Assignment 2?" << endl;
    cin >> asgnmnt2;
    grade_Valid=gradeIsValid(asgnmnt2);
    if (grade_Valid==true)
    {
        break;
    }
    if (gradeIsValid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
    }
    }
    while(grade_Valid==false)
    {
    cout << "What is your grade for Assignment 3?" << endl;
    cin >> asgnmnt3;
    grade_Valid=gradeIsValid(asgnmnt3);
    if (grade_Valid==true)
    {
        break;
    }
    if (gradeIsValid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
    }
    }
    while(grade_Valid==false)
    {
    cout << "What is your grade for Assignment 4?" << endl;
    cin >> asgnmnt4;
    grade_Valid=gradeIsValid(asgnmnt2);
    if (grade_Valid==true)
    {
        break;
    }
    if (gradeIsValid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
    }
    }
    double ag=(asgnmnt1+asgnmnt2+asgnmnt3+asgnmnt4)/400*100;
    double weight=ag*.2;
    assignWghtAvg=weight;
    return (assignWghtAvg);
}

*/


/*
float AssignmentGrade (float asgnmnt1, float asgnmnt2, float asgnmnt3, float asgnmnt4, float& assignWghtAvg)
{
    bool grade_Valid;
    int grade;
    bool assignment1=false;
    bool assignment2=false;
    bool assignment3=false; 
    bool assignment4=false;



    while(assignment1==false)
    {
    cout << "What is your grade for Assignment 1?" << endl;
    cin >> asgnmnt1;

    grade_Valid=gradeIsValid(asgnmnt1);
    if(grade_Valid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
        assignment1=false;   
    }
    else
    {
        assignment1=true; 
    }
    }

    while(assignment2==false)
    {
    cout << "What is your grade for Assignment 2?" << endl;
    cin >> asgnmnt2;
    grade_Valid=gradeIsValid(asgnmnt2);
    if(grade_Valid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
        assignment2=false;   
    }
    else
    {
        assignment2=true; 
    }
    }

    while(assignment3==false)
    {
    cout << "What is your grade for Assignment 3?" << endl;
    cin >> asgnmnt3;
    grade_Valid=gradeIsValid(asgnmnt3);
    if(grade_Valid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
        assignment3=false;   
    }
    else
    {
        assignment3=true; 
    }
    }
    
    while(assignment4==false)
    {
    cout << "What is your grade for Assignment 4?" << endl;
    cin >> asgnmnt4;
    grade_Valid=gradeIsValid(asgnmnt4);
    if(grade_Valid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
        assignment4=false;   
    }
    else
    {
        assignment4=true; 
    }
    }


    double ag=(asgnmnt1+asgnmnt2+asgnmnt3+asgnmnt4)/400*100;
    double weight=ag*.2;
    assignWghtAvg=weight;
    return (assignWghtAvg);
}
*/

float AssignmentGrade (float asgnmnt1, float asgnmnt2, float asgnmnt3, float asgnmnt4, float& assignWghtAvg)
{
    bool grade_Valid;
    int grade;
    bool assignment=false;
    while(assignment==false)
    {
    cout << "What is your grade for Assignment 1?" << endl;
    cin >> asgnmnt1;

    grade_Valid=gradeIsValid(asgnmnt1);
    if(grade_Valid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
        assignment=false;   
    }
    else
    {
        assignment=true; 
    }
    }

    assignment=false;  
    while(assignment==false)
    {
    cout << "What is your grade for Assignment 2?" << endl;
    cin >> asgnmnt2;
    grade_Valid=gradeIsValid(asgnmnt2);
    if(grade_Valid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
        assignment=false;   
    }
    else
    {
        assignment=true; 
    }
    }


    assignment=false;  
    while(assignment==false)
    {
    cout << "What is your grade for Assignment 3?" << endl;
    cin >> asgnmnt3;
    grade_Valid=gradeIsValid(asgnmnt3);
    if(grade_Valid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
        assignment=false;   
    }
    else
    {
        assignment=true; 
    }
    }
    

    assignment=false;  
    while(assignment==false)
    {
    cout << "What is your grade for Assignment 4?" << endl;
    cin >> asgnmnt4;
    grade_Valid=gradeIsValid(asgnmnt4);
    if(grade_Valid==false)
    {
        cout<<"Invalid input. Please enter a valid grade 0 and 100."<<"\n";
        assignment=false;   
    }
    else
    {
        assignment=true; 
    }
    }


    double ag=(asgnmnt1+asgnmnt2+asgnmnt3+asgnmnt4)/400*100;
    double weight=ag*.2;
    assignWghtAvg=weight;
    return (assignWghtAvg);
}



float LabTestGrade (float ltest1,float ltest2,float ltest3,float& labWghtAvg)
{
    cout << "What is your grade for Lab test 1?" << endl;
    cin >> ltest1;
    cout << "What is your grade for Lab Test 2?" << endl;
    cin >> ltest2;
    cout << "What is your grade for Lab Test 3?" << endl;
    cin >> ltest3;
    double lbg=(((ltest1+ltest2+ltest3)/300)*100);
    double weight=lbg*.3;
    labWghtAvg=weight;
    return (labWghtAvg);
}
float LectureTestGrade(float test1,float test2,float test3,float test4,float& lectureWghtAvg)
{
    cout << "What is your grade for Lecture test 1?" << endl;
    cin >> test1;
    cout << "What is your grade for Lecture Test 2?" << endl;
    cin >> test2;
    cout << "What is your grade for Lecture Test 3?" << endl;
    cin >> test3;
    cout << "What is your grade for Lecture Test 4?" << endl;
    cin >> test4;
    double ltg=(test1+test2+test3+test4)/400*100;
    double weight=ltg*.4;
    lectureWghtAvg=weight;
    return lectureWghtAvg;
}
float PostLabGrade(float postlab1,float postlab2,float postlab3,float postlab4,float postlab5,float postlab6,float postlab7,float postlab8,float postlab9, float& postWghtAvg)
{
    cout << "What is your grade for Post lab 1?" << endl;
    cin >> postlab1;
    cout << "What is your grade for Post lab 2?" << endl;
    cin >> postlab2;
    cout << "What is your grade for Post lab 3?" << endl;
    cin >> postlab3;
    cout << "What is your grade for Post lab 4?" << endl;
    cin >> postlab4;
    cout << "What is your grade for Post lab 5?" << endl;
    cin >> postlab5;
    cout << "What is your grade for Post lab 6?" << endl;
    cin >> postlab6;
    cout << "What is your grade for Post lab 7?" << endl;
    cin >> postlab7;
    cout << "What is your grade for Post lab 8?" << endl;
    cin >> postlab8;
    cout << "What is your grade for Post lab 9?" << endl;
    cin >> postlab9;
    double plg=(postlab1+postlab2+postlab3+postlab4+postlab5+postlab6+postlab7+postlab8+postlab9)/900*100;
    double weight=plg*.027;
    postWghtAvg=weight;
    return(postWghtAvg);
}
float QuizGrade(float quiz1,float quiz2,float quiz3,float quiz4,float quiz5,float quiz6,float quiz7,float quiz8,float quiz9,float& quizWghtAvg)
{
    cout << "What is your grade for Quiz 1?" << endl;
    cin >> quiz1;
    cout << "What is your grade for Quiz 2?" << endl;
    cin >> quiz2;
    cout << "What is your grade for Quiz 3?" << endl;
    cin >> quiz3;
    cout << "What is your grade for Quiz 4?" << endl;
    cin >> quiz4;
    cout << "What is your grade for Quiz 5?" << endl;
    cin >> quiz5;
    cout << "What is your grade for Quiz 6?" << endl;
    cin >> quiz6;
    cout << "What is your grade for Quiz 7?" << endl;
    cin >> quiz7;
    cout << "What is your grade for Quiz 8?" << endl;
    cin >> quiz8;
    cout << "What is your grade for Quiz 9?" << endl;
    cin >> quiz9;
    double qg=(quiz1+quiz2+quiz3+quiz4+quiz5+quiz6+quiz7+quiz8+quiz9)/900*100;
    double weight=qg*.036;
    quizWghtAvg=weight;
    return (quizWghtAvg);
}
float ClickerGrade(float click,float& clickWghtAvg)
{
    cout << "What is your Clicker grade?" << endl;
    cin >> click;
    double cg=click;
    double weight=cg*.037;
    clickWghtAvg=weight;
    return (clickWghtAvg);
}
bool gradeIsValid(float grade)
{
    if (grade>=0 && grade<=100)
        return true;
    else
        return false;
}
int Menu(float assignWghtAvg, float labWghtAvg,float lectureWghtAvg, float postWghtAvg,float quizWghtAvg, float clickWghtAvg,float finalGrade)
{
    int choice;
    do{
    cout<<"::Menu::"<<endl;
    cout<<" 1.Show the Grades in a Tabular Format"<<endl;
    cout<<" 2.Show the Overall Grade"<<endl;
    cout<<" 3.Exit"<<endl;
    cout<<" Enter 1, 2, or 3 as your choice "<<endl;
    cin >>choice;
    bool menuChoiceIsValid (choice);
    switch(choice)
       {
        case 1:
            cout<<"Grades in Tabular Format"<<endl;
            DisplayGrades(assignWghtAvg,labWghtAvg,lectureWghtAvg,postWghtAvg,quizWghtAvg,clickWghtAvg);
            break;
        case 2:
            cout<<"Overall Grade"<<endl;
            OverAllGrade(assignWghtAvg,labWghtAvg,lectureWghtAvg, postWghtAvg,quizWghtAvg,clickWghtAvg,finalGrade);
            break;
        case 3:
            cout<<"Thank-you for using this program. Goodbye.";
            break;
        default:
            cout<<"Invalid_input"<<endl;
            cout<<"Please enter a valid input"<<endl;}
    }while(choice!=3);
   return 0;
}
void DisplayGrades(float assignWghtAvg, float labWghtAvg,float lectureWghtAvg, float postWghtAvg,float quizWghtAvg, float clickWghtAvg)
{
    cout << setw(15) << left << "Category Name" << setw(15) << left << "Weighted average" << setw(5) << endl;
	cout << setw(15) << left << "Assignments" << setw(15) << left <<setprecision(2)<<fixed<<showpoint<< assignWghtAvg << setw(5) << endl;
	cout << setw(15) << left << "Labs" <<setw(15) << left <<setprecision(2)<<fixed<<showpoint<< labWghtAvg << setw(5) << endl;
	cout << setw(15) << left << "Lectures" <<setw(15) << left <<setprecision(2)<<fixed<<showpoint<< lectureWghtAvg << setw(5) << endl;
	cout << setw(15) << left << "Post Labs" << setw(15) << left <<setprecision(2)<<fixed<<showpoint<< postWghtAvg << setw(5) << endl;
	cout << setw(15) << left << "Quizzes" <<setw(15) << left <<setprecision(2)<<fixed<<showpoint<< quizWghtAvg << setw(5) << endl;
	cout << setw(15) << left << "Clicker" <<setw(15) << left <<setprecision(2)<<fixed<<showpoint<< clickWghtAvg << setw(5) << endl;
}
void OverAllGrade(float assignWghtAvg, float labWghtAvg,float lectureWghtAvg, float postWghtAvg,float quizWghtAvg, float clickWghtAvg,float finalGrade)
{
    finalGrade=assignWghtAvg+labWghtAvg+lectureWghtAvg+postWghtAvg+quizWghtAvg+clickWghtAvg;
        if (finalGrade>=90)
            cout<<"Letter Grade: A"<<endl;
        else if (finalGrade>=80 && finalGrade<=89)
            cout<<"Letter Grade: B"<<endl;
        else if (finalGrade>=70 && finalGrade<=79)
            cout<<"Letter Grade: C"<<endl;
        else if (finalGrade>=60 && finalGrade<=69)
            cout<<"Letter Grade: D"<<endl;
        else if (finalGrade<=60)
            cout<<"Letter Grade: F"<<endl;
    cout<<"The Overall Grade is: "<<finalGrade<<endl;
}
bool menuChoiceIsValid (int choice)
{
    if (choice==1 || choice==2 || choice==3)
        return true;
    else
        return false;
}

