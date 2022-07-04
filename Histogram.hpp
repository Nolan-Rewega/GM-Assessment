#include <string>
#include <vector>
#include <limits>

/**
 * Histogram data class.
 *
 * Instantiations of this class  will represent given  data in a histogram
 * with bins on the X-axis, and number of items in each bin on the Y-axis.
 * To use, instantiate an  object and call updateHistogram() with a vector
 * of doubles.
 */
class Histogram{
private:
    /** The maximum number of bins */   
    unsigned int m_bins;
    
    /** A count of the number of data items in the histogram*/
    double m_numDataPoints;
    
    /** The values of the smallest and largest data items */
    double m_smallest, m_largest;
    
    /** The histograms Y-axis data */
    std::vector<int> m_histogramData;


public:
    /**
    * Constuctor method
    * 
    * @params [in] bins The number of bins desired in this histogram.
    */
    Histogram(int bins);
    
    /**
    * Update the current histogram with new data
    *
    * @param [in] data The data to be used to compute the Y-axis values
    */
    void updateHistogram(std::vector<double> data);
    
    /**
    * Gets the normalized histograms Y-axis values.
    *
    * @return a vector<double> of values between 0.0 and 1.0.
    */
    std::vector<double> getNormalizedHistogram();   
    
    /**
    * Gets the histograms Y-axis values.
    *
    * @return a vector<int> of values from 0 to +infinity 
    */
    std::vector<int> getHistogram(); 

};
