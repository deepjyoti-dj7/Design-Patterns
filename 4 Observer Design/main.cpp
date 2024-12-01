#include <iostream>
#include <list>

class ISubscriber {
public:
    virtual void notify(std::string message) = 0;
};

class User : public ISubscriber {
private:
    int userId;
public:
    User(int userId) {
        this->userId = userId;
    }
    void notify(std::string message) {
        std::cout << "User " << userId << " received message " << message << std::endl;
    }
};

class Group {
private:
    std::list<ISubscriber*> users;
public:
    void subscribe(ISubscriber* user) {
        users.push_back(user);
    }
    void unsubscribe(ISubscriber* user) {
        users.remove(user);
    }
    void notify(std::string message) {
        for(auto& user : users) {
            user->notify(message);
        }
    }
};

int main() {
    Group* group = new Group;

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("new msg");
    group->unsubscribe(user1);
    group->notify("new msg again");

    return 0;
}