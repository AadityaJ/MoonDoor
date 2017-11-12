#include "../../includes/mClient.h"
using namespace std;
int main(int argc, char const *argv[]) {
    int num;
    while(1){
        cin>>num;
        string str=to_string(num);
        Client cli(8000);
        cli.Send(str);
        string avg=cli.receive();
        cout<<"Computed average : "<<avg<<endl;
    }
    return 0;
}
