#include <bits/stdc++.h>
using namespace std;
struct Task{
    string title;
    bool status;
};
void addTask(vector<Task>& tasks){
    Task t;
    cout<<"Enter your task!";
    cin.ignore();
    getline(cin,t.title);
    t.status=false;
    tasks.push_back(t);
    cout<<"task added";
}
void deleteTask(vector<Task>& tasks){
    if(tasks.empty()){
        cout<<"no task left";
        return;
    }
    int idx;
    cout<<"enter index of task to be deleted";
    cin>>idx;
    if(idx<1||idx>tasks.size()-1){
        cout<<"Invalid";
        return;
    }
    tasks.erase(tasks.begin()+idx-1);
    cout<<"Task deleted!";
}
void completeTask(vector<Task>& tasks){
    if(tasks.empty()){
        cout<<"No task left to be completed";
        return;
    }
    int idx;
    cout<<"enter index of task to be completed";
    cin>>idx;
    if(idx<1||idx>tasks.size()-1){
        cout<<"Invalid";
        return;
    }
    tasks[idx-1].status=true;
    cout<<"Task completed";
}
void viewTasks(const vector<Task>& tasks){
    if(tasks.empty()){
        cout<<"No tasks to be displayed";
        return;
    }
    for(int i=0;i<tasks.size();i++){
        cout<<i+1<<"."<<tasks[i].title<<endl;
        if(tasks[i].status){
            cout<<"Completed"<<endl;
        }
        else{
            cout<<"Unfinished"<<endl;
        }
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    while(true){
        cout << "\n====== TO-DO LIST MENU ======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice==1)
            addTask(tasks);
        else if (choice==2)
            viewTasks(tasks);
        else if (choice == 3)
            completeTask(tasks);
        else if (choice == 4)
            deleteTask(tasks);
        else if (choice == 5) {
            cout << "Exiting program \n";
            break;
        }
        else
            cout << "Invalid choice. Try again!\n";
    }

    return 0;
}