#include <iostream>

void helloFriend();
void addNum();

int main() {

    helloFriend();
    addNum();

    return 0;

} // end of main

void helloFriend() {std::cout <<"Hello friend";}

void addNum() {
    int x, y;
    std::cout << "Please enter number 1";
    std::cin >> x;

    std::cout << "Please enter number 2";
    std::cin >> y;

    int sum = x + y;
    std::cout << sum;

} // end of addNum