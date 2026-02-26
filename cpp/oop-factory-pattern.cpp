//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 06/07/25.
//

#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <list>
using namespace std;


// abstract class
class Notification {
private:
    string ipAddress;
    string sender;
    int priority;
public:
    virtual void send() = 0;
    Notification(const string &ip, const string &sender, const int &priority): ipAddress(ip), sender(sender), priority(priority) {}
    virtual ~Notification() {}
protected:
    string getSender() {
        return this->sender;
    }
    int getPriority() {
        return this->priority;
    }
};


class EmailNotification: public Notification {
private:
    void makeEmailWork();
public:
    void send() override {
        cout << "sending email notification from: " << getSender() <<  " with priority " << getPriority() << endl;
    }
    EmailNotification(const string &ip, const string &sender, const int &priority): Notification(ip,sender,priority) {}
};

class SMSNotification: public Notification {
public:
    void send() override {
        cout << "sending SMS notification " << endl;
    };
    SMSNotification(): Notification("124","sender SMS",1) {}
};


class PushNotification: public Notification {
public:
    void send() override {
        cout << "sending Push notification " << endl;
    };
    PushNotification(): Notification("125","sender push",2) {}
};

class NotificationFactory {
public:
    static unique_ptr<Notification> createNotification(const string &type) {
        if(type == "sms") return make_unique<SMSNotification>();
        if(type == "email") return make_unique<EmailNotification>("120", "Email Sender", -1);
        if(type == "push") return make_unique<PushNotification>();
        
        return nullptr;
    }
};



int main(int argc, const char * argv[]) {
    vector<string> notificationTypes = {"email", "sms", "push"};
    vector<unique_ptr<Notification>> results;
    
    for(const string &type:notificationTypes){
        auto result = NotificationFactory::createNotification(type);
        results.push_back(std::move(result));
    }
    
    for(const auto &notification:results){
        notification->send();
    }
    
    return 0;
}

