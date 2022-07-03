#include <iostream>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <string>
#include <vector>
#include <map>

#include "Request.hpp"

/**
 * Resource request processing class with statistic telemetrics.
 *
 * Instantiations of this class do state based processing of resource requests
 * with  the added  beneifit of statistical  analysis.  To use, instantiate an
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
    };
    /** chrono start and end time_points */
    std::chrono::high_resolution_clock::time_point m_requestStart;
    std::chrono::high_resolution_clock::time_point m_requestEnd;
    
    /** The string of the current processing URI */
    std::string m_currentRequestUri;
    
    /** A map to store URI data for later lookup */
    std::map<std::string, UriData> m_uriRequestData;
    
    /**
     * Calculates the mean value of all request to the given URI
     *
     * @params [in] uri The URI of the request endpoint.
     */
    void calculateUriMean(const std::string& uri);

    /**
     * Calculates the standard deviation of all request on the given URI
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
    StatisticalRequest();
    
    /**
     * Retrieves all mean response times from each seperate URI
     * stored inside an array.
     *
     * @params None
     * @returns a vector<double> containing URI mean values
     */
    std::vector<double> getUriMeans();

    /**
     * Retrieves all mean response times from each seperate URI
     * stored inside an array.
     *
     * @params None
     * @returns a vector<double> containing URI mean values
     */
    std::vector<double> getUriStandardDeviations();
    
    /** Prints m_uriRequestData to console. */
    void printUriData();

};

