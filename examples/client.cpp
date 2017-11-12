#include "../includes/mClient.h"
using namespace std;
int main(int argc, char const *argv[]) {
    Client c(8000);
    string str;
    cin>>str;
    c.Send(str);
    return 0;
}
