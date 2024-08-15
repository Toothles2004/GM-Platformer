// Fill out your copyright notice in the Description page of Project Settings.


#include "NarrationText.h"

NarrationText::NarrationText(FString text)
	: m_Text{text},
	m_CharactersPerSec{0.04},
	m_TotalTimeElapsed{},
	m_CurrentText{""},
	m_DelayTimer{},
	m_DelayMaxTime{1.f},
	m_CurrentIndex{}
{

}

NarrationText::~NarrationText()
{
}

bool NarrationText::Update(float deltaTime)
{
	// over time print out the text
	m_TotalTimeElapsed += deltaTime;
	
	if(m_TotalTimeElapsed > m_CharactersPerSec)
	{
		if((m_CurrentIndex) < m_Text.Len())
		{
			m_TotalTimeElapsed = 0;
			m_CurrentText += m_Text[m_CurrentIndex];
			m_CurrentIndex++;
		}
		else
		{
			m_DelayTimer += deltaTime;
			if(m_DelayTimer > m_DelayMaxTime)
			{
				return true;
			}
		}
	}

	return false;
}
