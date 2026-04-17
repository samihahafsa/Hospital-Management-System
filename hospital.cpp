#include<iostream>
#include<string>
using namespace std;

//Patient
struct Patient
{
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

//Linked list
Patient* head = NULL;
//Add Patient
void addPatient(int id,string name,int age,string disease)
{
    Patient* p = new Patient;
    p->id = id;
    p->name = name;
    p->age = age;
    p->disease = disease;
    p->next = head;
    head = p;
    cout<<"Patient Added\n";
}

//Delete Patient
void deletePatient(int id)
{
    Patient* p = head;
    Patient* prev = NULL;

    while (p != NULL)
    {
        if (p->id == id)
        {
            if (prev == NULL)
            {
                head = p->next;
            }
            else
            {
                prev->next = p->next;
            }

            delete p;
            cout<<"Patient Deleted\n";
            return;
        }

        prev =p;
        p =p->next;
    }

    cout<<"Not Found\n";
}

//Show patient list
void showPatients()
{
    Patient* p = head;

    if (p ==NULL)
    {
        cout<<"No Patients\n";
        return;
    }

    while (p !=NULL)
    {
        cout<<"\nID: "<<p->id<<endl;
        cout<< "Name: " << p->name<<endl;
        cout<<"Age: "<<p->age<<endl;
        cout<<"Disease: "<<p->disease<<endl;
        cout<<endl;
        p = p->next;
    }
}

//Queue
int q[100];
int front = 0, rear = -1;

//Add Appointment
void addAppointment(int id)
{
    q[++rear] = id;
    cout<<"Added to Appointment Queue\n";
}

//Serve patient
void servePatient()
{
    if (front > rear)
    {
        cout<<"Queue Empty\n";
        return;
    }

    cout<<"Serving Patient ID: "<<q[front++]<<endl;
}
//Stack
struct Action
{
    int type;
    Patient data;
};
Action st[100];
int top = -1;

//Undo last action
void undo()
{
    if (top == -1)
    {
        cout<<"Nothing to Undo\n";
        return;
    }
    Action last = st[top--];
    if (last.type == 1)
    {
        deletePatient(last.data.id);
    }
    else
    {
        addPatient(last.data.id, last.data.name, last.data.age, last.data.disease);
    }
}

//Main Function
int main()
{
    int ch, id, age;
    string name, disease;

    while (true)
    {
        cout<<"Hospital Management System"<<endl;
        cout << "\n1. Add Patient" << endl;
        cout << "2. Delete Patient" << endl;
        cout << "3. Show Patients" << endl;
        cout << "4. Add Appointment" << endl;
        cout << "5. Serve Patient" << endl;
        cout << "6. Undo Last Action" << endl;
        cout << "0. Exit" << endl;

        cout << "\nEnter Choice: ";
        cin >> ch;

        if (ch == 0)
            break;

        switch (ch)
        {
        case 1:
            cout<<"Enter ID: ";
            cin>>id;
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Age: ";
            cin>>age;
            cout<<"Enter Disease: ";
            cin>>disease;

            addPatient(id, name, age, disease);
            break;

        case 2:
            cout<<"Enter ID to Delete: ";
            cin>>id;
            deletePatient(id);
            break;

        case 3:
            showPatients();
            break;

        case 4:
            cout<<"Enter Patient ID: ";
            cin>>id;
            addAppointment(id);
            break;

        case 5:
            servePatient();
            break;

        case 6:
            undo();
            break;

        default:
            cout<<"Invalid Choice"<<endl;

        }
    }
}





