#include "StatisticalRequest.hpp"

int main(){
    StatisticalRequest* r = new StatisticalRequest(20);
    
    // -- running unit tests in main.   
    for(int i = 0; i < 10; i++){
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
   

    // -- unit tests getUriNormalizedhistogram()
    std::vector<std::vector<double>> histograms = r->getUriNormalizedHistograms();
    for(std::vector<double> h : histograms){
        std::cout << "NormalizedHistogram: ";
        for(unsigned int i = 0; i < h.size(); i++){
            std::cout << h[i] << " ";
        };
        std::cout << std::endl;
    };

    // -- Debug print().
    //r->printUriData();



}
