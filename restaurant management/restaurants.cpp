#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<string, int>> cart;
vector<pair<string, int>> menu = {{"Burger", 80}, {"Pizza", 1200}, {"Fries", 60}, {"Coca cola", 110}, {"Coffes", 150}, {"Biscuts", 15}};

void menuList()
{
    cout << "MENU LIST:" << endl;
    for (size_t i = 0; i < menu.size(); i++)
    {
        cout << i + 1 << " " << menu[i].first << "     -/" << menu[i].second << endl;
    }
}
void showKey()
{
    cout << "----------------------------" << endl;
    cout << "Press -1 to calculate bill " << endl;
    cout << "----------------------------" << endl;
}
int main()
{

    int itemNumber;
    int bill = 0;
    cout << "\033[2J\033[1;1H";

    while (1)
    {
        menuList();
        showKey();

        cout << "\033[1;31mYour Cart:\033[0m\n";
        // cout<<"Your cart: "<<endl;
        for (size_t i = 0; i < cart.size(); i++)
        {
            cout << " " << cart[i].first << endl;
        }
        cout << endl;
        cout << "---------------------------" << endl;
        cout << endl;

        cout << "Select your order: ";
        cin >> itemNumber;

        cart.push_back(menu[itemNumber - 1]);
        cout << "\033[2J\033[1;1H";

        if (itemNumber == -1)
        {

            cout << "\033[1;31mYour order is:\033[0m\n";
            for (size_t i = 0; i < cart.size(); i++)
            {
                cout << " " << cart[i].first << endl;
                bill = bill + cart[i].second;
            }
            cout << "---------------------------" << endl;
            cout << endl;
            cout << "Your Bill : " << bill << endl;
            break;
        }
    }
}
