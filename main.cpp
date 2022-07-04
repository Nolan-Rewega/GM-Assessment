#include "StatisticalRequest.hpp"

int main(){
    StatisticalRequest* r = new StatisticalRequest(10);
    
    // -- running unit tests in main.   
    for(int i = 0; i < 100; i++){
        r->process("uri1");
    }
    
    // -- unit tests getUriMeans()
    std::vector<double> means = r->getUriMeans();
    for(unsigned int i = 0; i < means.size(); i++){
        std::cout << "Mean " << i+1 << ": " << means[i] << std::endl;
    };

    
    // -- unit tests getUriStandardDeviations()
    std::vector<double> sd = r->getUriStandardDeviations();
    for(unsigned int i = 0; i < means.size(); i++){
        std::cout << "Standard Deviation " << i+1 << ": " << sd[i] << std::endl;
    };
    

    // -- Debug print().
    r->printUriData();



}
