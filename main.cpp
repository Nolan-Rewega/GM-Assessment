#include "StatisticalRequest.hpp"

int main(){
    StatisticalRequest* r = new StatisticalRequest();
    
    // -- running unit tests in main.   
    r->process("uri1");
    r->process("uri1");
    r->process("uri1");
    r->process("uri1");
    
    // -- unit tests getUriMeans()
    std::vector<double> means = r->getUriMeans();
    for(unsigned int i = 0; i < means.size(); i++){
        std::cout << "Mean " << i+1 << ": " << means[i] << std::endl;
    };

    
    // -- Debug print().
    r->printUriData();



}
