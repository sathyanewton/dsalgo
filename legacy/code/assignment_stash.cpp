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