//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 30/06/25.
//

#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
using namespace std;

/**
 Repaso estructuras de datos, STL.
 
 arrays, --> vector
 hashmap --> unordered_map
 hashset --> unordered_set
 Trees --> ??
 Stack/Queue
 Heaps --> priority_queue
 Set
 */

void test_array(){
    // arrays
    vector<int> myarr = {};
    myarr.push_back(1);
    myarr.push_back(2);
    myarr.push_back(3);
    myarr.push_back(4);
    myarr.pop_back();
    myarr.insert(myarr.begin()+1,-1);
    myarr.erase(myarr.begin()+1);
    
    for(auto x:myarr){
        cout << x << " ";
    }
    cout << endl;
    
}

void test_unordered_map(){
    unordered_map<string,int> freq;
    
    freq["adolfo"] = 1;
    int count = freq["adolfo"];
    cout << count << endl;
    if(freq.count("key") == 1) {
        cout << "exists" << endl;
    }
    else{
        cout << "not exists " << endl;
    }
    
    for(auto kv: freq){
        cout << kv.first << " , " << kv.second << endl;
    }
    
    freq.erase("adolfo");
    
    for(auto kv: freq){
        cout << kv.first << " , " << kv.second << endl;
    }
}

void test_map() {
    map<string,int> freq;
    
    freq["adolfo"] = 1;
    int count = freq["adolfo"];
    
    if(freq.count("adolfo")){
        cout << "exists " << endl;
    }
    else{
        cout << "not exists " << endl;
        
    }
    cout << count << endl;
    
    for(auto kv: freq){
        cout << kv.first << " , " << kv.second << endl;
    }
}

void test_unordered_set(){
    unordered_set<int> s;
    
    s.insert(4);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    
    
    for(auto x:s){
        cout << x << " , ";
    }
    cout << endl;
    
    int first = *s.begin();
    cout << first << endl;
    
    if(s.find(3) != s.end()){
        cout << "exists " << endl;
    }
    else{
        cout << "not exists " << endl;
    }
    if(s.count(3)){
        cout << "exists " << endl;
    }
    else{
        cout << "not exists " << endl;
    }
    
    s.erase(3);
    
    for(auto x:s){
        cout << x << " , ";
    }
}

void test_set(){
    set<int> s;
    
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(2);
    
    for(auto x:s){
        cout << x << " , ";
    }
    cout << endl;
    
    if(s.find(3) != s.end()){
        cout << "exists " << endl;
    }
    else{
        cout << "not exists " << endl;
    }
    
    int min = *s.begin();
    cout << min << endl;
}

void test_priority_queue(){
    priority_queue<int> pq;
    // min priority queue
    struct intcomparator {
        bool operator()(const int &a, const int &b) const {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, intcomparator > mpq;
    // priority_queue<int, vector<int>, greater<int> > mpq;
    // custom pq:
    
    struct Employee {
        string name;
        int age;
        bool married;
    };
    
    struct comparator {
        bool operator()(const Employee &a, const Employee &b){
            return a.age > b.age;
        }
    };
    
    priority_queue<Employee, vector<Employee>, comparator> cpq;
    
    pq.push(1);
    pq.push(4);
    pq.push(3);
    pq.push(2);
    
    mpq.push(1);
    mpq.push(4);
    mpq.push(3);
    mpq.push(2);
    
    cpq.push({"adolfo", 28, true});
    cpq.push({"esteban", 27, false});
    cpq.push({"fragoso", 29, true});
    
    int mini = cpq.top().age;
    
    // priority_queue uses top and queue uses front
    int max = pq.top();
    int min = mpq.top();
    
    cout << max << endl;
    cout << min << endl;
    cout << mini << endl;
    
    pq.pop();
    mpq.pop();
    
}

void test_sort(){
    // Define a dummy struct
    
    struct Employee{
        string name;
        int age;
        bool married;
    };
    
    vector<Employee> employees;
    
    employees.push_back({"adolfo", 28, true});
    employees.push_back({"esteban", 27, false});
    employees.push_back({"fragoso", 29, true});
    
    for(auto employee: employees){
        cout << employee.name << " , ";
    }
    cout << endl;
    
    // I can define custom comparator as a lambda, it does not work for priority_queues as I need to convert it.
    sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b){
        return a.age > b.age;
    });
    
    for(auto employee: employees){
        cout << employee.name << " , ";
    }
    cout << endl;
}

class Human{
public:
    string name;
    int age;
    bool isMaried;
    
    Human(string name, int age,bool isMaried) {
        this->name = name;
        this->age = age;
        this->isMaried = isMaried;
    }
};

void test_vector_class(){
    vector<Human> humans;
    humans.push_back({"adolfo", 26, true});
    humans.push_back({"esteban", 28, true});
    humans.push_back({"fragoso", 27, true});
    
    sort(humans.begin(), humans.end(), [](const Human &a, const Human &b){
        return a.age < b.age;
    });
    
    for(auto human: humans){
        cout << human.name << " , ";
    }
}

void test_stack_queue(){
    stack<int> s;
    queue<int> q;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    int tp = s.top();
    int top = q.front();
    
    cout << tp << " , " << top << endl;
    
    stack<Human> ss;
    
    ss.push({"adolfo", 24, false});
    ss.push({"loco", 25, false});
    ss.push({"magallanes", 26, false});
    
    Human ts = ss.top();
    cout << ts.name << endl;
}

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root){
    if(root){
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
    }
}

int main(int argc, const char * argv[]) {
    cout << "hello" << endl;
    //test_stack_queue();
    TreeNode* root = new TreeNode(1);
    root->left =new TreeNode(2);
    root->right =new TreeNode(3);
    inorder(root);
    return 0;
}

