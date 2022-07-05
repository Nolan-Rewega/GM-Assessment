#include "StatisticalRequest.hpp"

/** helper function decleration */
void printHistograms(std::vector<std::vector<double>> histograms);
void printVector(std::vector<double> vec);


int main(){
// ~~~~~~~~~~~~~~~~~ TESTING StatisticalRequest.cpp ~~~~~~~~~~~~~~~~~~~
    // -- Request objects
    StatisticalRequest* r1 = new StatisticalRequest(6);
    StatisticalRequest* r2 = new StatisticalRequest(100);
    StatisticalRequest* r3 = new StatisticalRequest(1);
    StatisticalRequest* r4 = new StatisticalRequest(6);
    
    // -- Sample size of 30 requests theoretically should give no errors.   
    for(int i = 0; i < 32; i++){
        r1->process("uri1");
        r2->process("uri2");
        r3->process("URI");

        r4->process("uri1");
        r4->process("uri2");
        r4->process("URI");
    }
    
    // -- Hardcoded unit tests for getUriMeans()
    double m1 = r1->getUriMeans()[0];
    double m2 = r2->getUriMeans()[0];
    double m3 = r3->getUriMeans()[0];
    std::vector<double> m4 = r4->getUriMeans();
    double meanErrUri1 = 10.0 - (10.0 * 0.90); 
    double meanErrUri2 = 20.0 - (20.0 * 0.90); 
    double meanErrUri3 = 15.0 - (15.0 * 0.90); 

    if( !(m1 > 10.0 - meanErrUri1 && m1 < 10.0 + meanErrUri1) ){
        std::cout << "error in mean Uri1, r1. \n";
    }
    if( !(m2 > 20.0 - meanErrUri2 && m2 < 20.0 + meanErrUri2) ){
        std::cout << "error in mean Uri2, r2. \n";
    }
    if( !(m3 > 15.0 - meanErrUri3 && m3 < 15.0 + meanErrUri3) ){
        std::cout << "error in mean URI, r3. \n";
    }
    if( !(m4[1] > 10.0 - meanErrUri1 && m4[1] < 10.0 + meanErrUri1) ){
        std::cout << "error in mean Uri1, r4. \n";
    }
    if( !(m4[2] > 20.0 - meanErrUri2 && m4[2] < 20.0 + meanErrUri2) ){
        std::cout << "error in mean Uri2, r4. \n";
    }
    if( !(m4[0] > 15.0 - meanErrUri3 && m4[0] < 15.0 + meanErrUri3) ){
        std::cout << "error in mean URI, r4. \n";
    }
   

    // -- Hardcoded unit tests getUriStandardDeviations()
    double sd1 = r1->getUriStandardDeviations()[0];
    double sd2 = r2->getUriStandardDeviations()[0];
    double sd3 = r3->getUriStandardDeviations()[0];
    std::vector<double> sd4 = r4->getUriStandardDeviations();
    double sdErrUri1 = 2.5 - (2.5 * 0.90); 
    double sdErrUri2 = 7.5 - (7.5 * 0.90); 
    double sdErrUri3 = 5.0 - (5.0 * 0.90); 

    if( !(sd1 > 2.5 - sdErrUri1 && sd1 < 2.5 + sdErrUri1) ){
        std::cout << "small error in standard deviation Uri1, r1. \n";
    }
    if( !(sd2 > 7.5 - sdErrUri2 && sd2 < 7.5 + sdErrUri2) ){
        std::cout << "small error in standard deviation Uri2, r2. \n";
    }
    if( !(sd3 > 5.0 - sdErrUri3 && sd3 < 5.0 + sdErrUri3) ){
        std::cout << "small error in standard deviation URI, r3. \n";
    }
    if( !(sd4[1] > 2.5 - sdErrUri1 && sd4[1] < 2.5 + sdErrUri1) ){
        std::cout << "small error in standard deviation Uri1, r4. \n";
    }
    if( !(sd4[2] > 7.5 - sdErrUri2 && sd4[2] < 7.5 + sdErrUri2) ){
        std::cout << "small error in standard deviation Uri2, r4. \n";
    }
    if( !(sd4[0] > 5.0 - sdErrUri3 && sd4[0] < 5.0 + sdErrUri3) ){
        std::cout << "small error in standard deviation URI, r4. \n";
    }
    

    // -- unit test getUriNormalizedhistogram()
    std::vector<std::vector<double>> h1 = r1->getUriNormalizedHistograms();
    std::vector<std::vector<double>> h2 = r2->getUriNormalizedHistograms();
    std::vector<std::vector<double>> h3 = r3->getUriNormalizedHistograms();
    std::vector<std::vector<double>> h4 = r4->getUriNormalizedHistograms();


    // -- Printing Request object statistics.
    std::cout << std::endl;
    std::cout << "Mean of r1: " << m1 << std::endl;
    std::cout << "Standard deviation of r1: " << sd1 << std::endl;
    std::cout << "Normalized Histogram: " << std::endl;
    printHistograms(h1);
    std::cout << "\n\n";


    std::cout << "Mean of r2: " << m2 << std::endl;
    std::cout << "Standard deviation of r2: " << sd2 << std::endl;
    std::cout << "Normalized Histogram: " << std::endl;
    printHistograms(h2); // -- This one is big
    std::cout << "\n\n";


    std::cout << "Mean of r3: " << m3 << std::endl;
    std::cout << "Standatd deviation of r3: " << sd3 << std::endl;
    std::cout << "Normalized Histogram: " << std::endl;
    printHistograms(h3);
    std::cout << "\n\n";


    std::cout << "Mean(s) of r4: ";
    printVector(m4);
    std::cout << "Standard deviation(s) of r4: ";
    printVector(sd4);
    std::cout << "Normalized Histogram(s): " << std::endl;
    printHistograms(h4);
    std::cout << "\n\n";


// ~~~~~~~~~~~~~~~~~ TESTING Histogram.cpp ~~~~~~~~~~~~~~~~~~~
    Histogram* histogram1 = new Histogram(4);
    std::vector<double> data1 = { 1.0, 1.0, 2.0, 2.0, 4.0, 6.0, 7.0, 8.0 };
    histogram1->updateHistogram(data1);

    std::vector<int> expected1 = { 4, 1, 1, 2};
    std::vector<double> expected2 = { 0.5, 0.125, 0.125, 0.25};
    std::vector<int> result1 = histogram1->getHistogram();
    std::vector<double> result2 = histogram1->getNormalizedHistogram();

    for(unsigned int i = 0; i < 4; i++){
        if(result1[i] != expected1[i]){
            std::cout << "Error in updateHistogram()" << std::endl;
        }
        if(result2[i] != expected2[i]){
            std::cout << "Error in getNormalizedHistogram()" << std::endl;
        }
    }

}



/** Helper funcitons */
void printHistograms(std::vector<std::vector<double>> histograms){
    for(std::vector<double> h : histograms){
        for(unsigned int i = 0; i < h.size(); i++){
            std::cout << h[i] << "   ";
        }
        std::cout << std::endl;
    }
}

void printVector(std::vector<double> vec){
    for(double m : vec){
        std::cout << m << "  ";
    }
    std::cout << std::endl;
}






