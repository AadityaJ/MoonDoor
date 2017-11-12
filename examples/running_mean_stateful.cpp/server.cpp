#include "../../includes/mServer.h"
#include <vector>
using namespace std;
int avg(std::vector<int> v){
    int sum=0;
    for(int i=0;i<v.size();i++) sum+=v[i];
    return (sum/v.size());
}
int main(int argc, char const *argv[]) {
    Server s;
    s.listen_(8000);
    std::vector<int> data_collection;
    while(1){
        string val=s.receive();
        data_collection.push_back(stoi(val));
        s.send_(to_string(avg(data_collection)));
    }
    return 0;
}
