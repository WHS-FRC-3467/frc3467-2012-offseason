#include "UpdateLCD.h"

	UpdateLCD::UpdateLCD()
	{
		Requires(dslcd);
		m_interval = 0.1;
		m_lastUpdate = GetTime();
	}
	
	void UpdateLCD::Initialize()
	{
	}

	void UpdateLCD::Execute()
	{
		double current_time = GetTime();
		if (current_time - m_lastUpdate > m_interval)
		{
			m_lastUpdate = current_time;
			dslcd->LCDUpdate();
		}
	}

	bool UpdateLCD::IsFinished()
	{
		return false;
	}
	
	void UpdateLCD::End()
	{
	}
	
	void UpdateLCD::Interrupted()
	{
	}
