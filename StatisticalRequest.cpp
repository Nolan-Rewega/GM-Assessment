#include "StatisticalRequest.hpp"


StatisticalRequest::StatisticalRequest()
{
    m_currentRequestUri = "";
}


std::vector<double> StatisticalRequest::getUriMeans()
{
    std::vector<double> means;
    for(auto it = m_uriRequestData.cbegin(); it != m_uriRequestData.end(); it++){
        means.push_back(it->second.mean);
    }
    return means;
}


std::vector<double> StatisticalRequest::getUriStandardDeviations()
{
    std::vector<double> standardDeviations;
    for(auto it = m_uriRequestData.cbegin(); it != m_uriRequestData.end(); it++){
        standardDeviations.push_back(it->second.standardDeviation);
    }
    return standardDeviations;
}


void StatisticalRequest::start(const std::string& uri)
{
    m_currentRequestUri = uri;

    // -- add Uri into request map if its not already in the map
    const auto it = m_uriRequestData.find(uri);
    if(it == m_uriRequestData.end()) {
        UriData data;
        data.numberOfRequests = 0.0;
        data.mean = 0.0;
        data.standardDeviation = 0.0;
        m_uriRequestData.insert( {uri, data} );
    }
    
    // -- start timing request here
    m_requestStart = std::chrono::high_resolution_clock::now();
}


void StatisticalRequest::finish()
{
    // -- stop timing here.
    m_requestEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timeMs = (m_requestEnd - m_requestStart);

    const auto it = m_uriRequestData.find(m_currentRequestUri);
    if(it != m_uriRequestData.end()){
        it->second.requests.push_back(timeMs.count());
        it->second.numberOfRequests += 1;
        calculateUriMean(m_currentRequestUri);
        calculateUriStandardDeviation(m_currentRequestUri);
    }
    
    m_currentRequestUri = "";
}


void StatisticalRequest::calculateUriMean(const std::string& uri)
{
    const auto it = m_uriRequestData.find(uri);
    if(it != m_uriRequestData.end()){
        double sum = 0.0;
        for(double value : it->second.requests){
            sum += value;
        }
        it->second.mean = sum / it->second.numberOfRequests;
    }
}


void StatisticalRequest::calculateUriStandardDeviation(const std::string& uri)
{
    const auto it = m_uriRequestData.find(uri);
    if(it != m_uriRequestData.end()){
        double sum = 0.0;
        for(double value : it->second.requests){
            sum += (value - it->second.mean) * (value - it->second.mean);
        }
        it->second.standardDeviation = sqrt(sum / it->second.numberOfRequests);
    }
}


void StatisticalRequest::printUriData(){
    for(auto it = m_uriRequestData.cbegin(); it != m_uriRequestData.end(); it++){
        for(unsigned int i = 0; i < it->second.requests.size(); i++){
            std::cout << "Request " << i << ": "
                    << it->second.requests[i] << std::endl;
        }
        std::cout << "# of Reqs: " << it->second.numberOfRequests << std::endl;
        std::cout << "Mean: " << it->second.mean << std::endl;
        std::cout << "SD: " << it->second.standardDeviation << std::endl;
    }

}










