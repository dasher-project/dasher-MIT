#include "DasherGameMode.h"
#include "GameScorer.h"
#include "GameStatistics.h"
#include <sstream>

using Dasher::CDasherGameMode;

void CDasherGameMode::Scorer::NewFrame(unsigned long time, myint iMouseX, myint iMouseY, myint iTargetY)
{
  if(m_bInPlay && !m_bPaused)
  {
    TargetData.push_back(iTargetY);
  }
  
}

void CDasherGameMode::Scorer::Reset()
{
  TargetData.clear();
  m_Statsbreakdown.str("");
  m_bInPlay=false;
}

void CDasherGameMode::Scorer::Start(unsigned long time)
{
  if(!m_bInPlay)
    {
      m_bInPlay=true;
      m_iStartTime = time;
    }
  m_bPaused=false; 
}

void CDasherGameMode::Scorer::Stop(unsigned long time)
{
  m_bPaused=true;
}

void CDasherGameMode::Scorer::SentenceFinished(unsigned long time)
{
  m_bInPlay = false;
  m_iStopTime = time;
  CalculateStats();
}

int CDasherGameMode::Scorer::GetScore()
{
  return (2000 - m_stats.dev)/20.0;
}

void CDasherGameMode::Scorer::CalculateStats()
{
  const std::vector<myint>& v = TargetData;
  m_Statsbreakdown.str("");
  
  size_t cnt = std::distance(v.begin(), v.end());
  if(cnt==0) return;
  m_stats.sum = std::accumulate(v.begin(), v.end(), double());
  m_stats.m1 = m_stats.sum/cnt;
  m_stats.m2 = nthMoment<double,2>(v.begin(), v.end(), m_stats.m1);
  m_stats.m3 = nthMoment<double,3>(v.begin(), v.end(), m_stats.m1);
  m_stats.m4 = nthMoment<double,4>(v.begin(), v.end(), m_stats.m1);
  m_stats.dev = sqrt(m_stats.m2); // Standard Deviation
  m_stats.skew = m_stats.m3/(m_stats.m2*m_stats.dev); // Skewness
  m_stats.kurt = m_stats.m4 / (m_stats.m2*m_stats.m2) - 3; // Excess Kurtosis

  m_Statsbreakdown << "Score: " << GetScore() << "\n";
    //<< "Samples: " << cnt << "\n"
    // << "Mean: " << m_stats.m1 << "\n"
    //	   << "StdDev: " << m_stats.dev << "\n"
    //	   << "Skew: " << m_stats.skew << "\n"
    //	   << "Kurt: " << m_stats.kurt << "\n"
	
}

std::string CDasherGameMode::Scorer::GetBreakdown()
{
  CalculateStats();
 return m_Statsbreakdown.str();
}