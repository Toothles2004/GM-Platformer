// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PLATFORMER_API NarrationText
{
public:
	NarrationText(FString text);
	~NarrationText();

	bool Update(float deltaTime);

	FString GetText() const { return m_CurrentText; }

private:
	FString m_Text;
	FString m_CurrentText;

	float m_CharactersPerSec;
	float m_TotalTimeElapsed;
	float m_DelayTimer;
	float m_DelayMaxTime;

	int m_CurrentIndex;
};
