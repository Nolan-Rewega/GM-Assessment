#include <iostream>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <string>
#include <vector>
#include <map>

#include "Request.hpp"
#include "Histogram.hpp"

/**
 * Resource request processing class with statistic metrics.
 *
 * Instantiations of this  class do state based processing of resource requests
 * with the additional beneifit of statistical analysis. To use, instantiate an
 * object and call process() on a URI to get the response data.
 */
class StatisticalRequest : public Request{
private:
    /** struct that holds all statistical URI data */
    struct UriData
    {
        std::vector<double> requests;
        int numberOfRequests;
        double mean;
        double standardDeviation;
        Histogram* histogram;
    };

    int m_histogramBinQuantity;
    
    /** chrono start and end time_points */
    std::chrono::high_resolution_clock::time_point m_requestStart;
    std::chrono::high_resolution_clock::time_point m_requestEnd;
    
    /** The string of the currently processing URI */
    std::string m_currentRequestUri;
    
    /** A map to store URI data for later lookup */
    std::map<std::string, UriData> m_uriRequestData;
   
    /**
     * Calculates the mean value for the given URI
     *
     * @params [in] uri The URI of the request endpoint.
     */
    void calculateUriMean(const std::string& uri);

    /**
     * Calculates the standard deviation for the given URI
     *
     * @params [in] uri The URI of the request endpoint.
     */
    void calculateUriStandardDeviation(const std::string& uri);

protected:
    /**
     * Start processing the request
     *
     * @params [in] uri The URI of the request endpoint.
     */
    void start(const std::string& uri);
    
    /** Finish processing the request */
    void finish();

public:
    /** Constructor for StatisticalRequest */
    StatisticalRequest(int binQuantity);
    
    /**
     * Retrieves each processed URI's mean.
     *
     * @params None
     * @returns a vector<double> containing URI mean values
     */
    std::vector<double> getUriMeans();

    /**
     * Retrieves each processed URI's standard deviation value.
     *
     * @params None
     * @returns a vector<double> containing URI standard deviation values
     */
    std::vector<double> getUriStandardDeviations();
    
    /**
     * Retrieves each processed URI's normalized histogram.
     *
     * @params None
     * @returns a vector<vector<double>> containing histogram y-axis data.
     */
    std::vector<std::vector<double>> getUriNormalizedHistograms();
    
    /** Prints m_uriRequestData to console. */
    void printUriData();

};

