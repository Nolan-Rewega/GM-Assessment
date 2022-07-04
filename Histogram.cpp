#include "Histogram.hpp"

Histogram::Histogram(int bins)
{
    m_bins = bins;
    m_histogramData.resize(m_bins, 0);
    m_numDataPoints = 0.0;
    m_smallest = std::numeric_limits<double>::max();
    m_largest  = std::numeric_limits<double>::lowest();
}


void Histogram::updateHistogram(std::vector<double> data)
{  
    if(data.size() == 0){ return; }
    
    m_histogramData.clear();

    // -- There must be atleast 1 bin per data item.
    int usableBins = (data.size() < m_bins) ? data.size() : m_bins;

    for(double value : data){
        if(value >  m_largest) { m_largest  = value; }
        if(value < m_smallest) { m_smallest = value; }
    }

    double range = m_largest - m_smallest;
    m_numDataPoints = data.size();

    // -- Count the number of data items per bin.
    for(double value : data){
        int binIndex = (value - m_smallest) * (usableBins / range); 
        // -- if value == m_largest, binIndex == usableBins
        // -- which gives a index out of range error.
        binIndex -= (binIndex == usableBins) ? 1 : 0;
        m_histogramData[binIndex]++;
    }
}


std::vector<int> Histogram::getHistogram()
{
    return m_histogramData;
}


std::vector<double> Histogram::getNormalizedHistogram()
{
    std::vector<double> normalizedHistogram;
    normalizedHistogram.resize(m_bins, 0.0);
    for(unsigned int i = 0; i < m_histogramData.size(); i++){
        normalizedHistogram[i] = m_histogramData[i] / m_numDataPoints;
    }
    return normalizedHistogram;
}

