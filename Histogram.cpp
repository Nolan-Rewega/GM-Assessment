#include "Histogram.hpp"
#include <iostream>

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
    
    // -- There cannot be more bins than data items.
    int usableBins = (data.size() < m_bins) ? data.size() : m_bins;
    
    m_histogramData.clear();
    m_histogramData.resize(usableBins, 0);
    
    for(double value : data){
        if(value >  m_largest) { m_largest  = value; }
        if(value < m_smallest) { m_smallest = value; }
    }
    
    double range = m_largest - m_smallest;
    m_numDataPoints = data.size();
    
    // -- Count the number of data items per bin.
    for(double value : data){
        // -- (range == 0) causes Divide by Zero.
        int binIdx =
            (range == 0) ? 0 : (value - m_smallest) * (usableBins / range);
        // -- (binIdx == usableBins) causes IndexOutofBounds.
        binIdx -= (binIdx == usableBins) ? 1 : 0;
        m_histogramData[binIdx]++;
    }
}


std::vector<int> Histogram::getHistogram()
{
    return m_histogramData;
}


std::vector<double> Histogram::getNormalizedHistogram()
{
    std::vector<double> normalizedHistogram;
    normalizedHistogram.resize(m_histogramData.size(), 0.0);
    for(unsigned int i = 0; i < m_histogramData.size(); i++){
        normalizedHistogram[i] = m_histogramData[i] / m_numDataPoints;
    }
    return normalizedHistogram;
}

