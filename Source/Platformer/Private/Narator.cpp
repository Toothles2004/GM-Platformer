// Fill out your copyright notice in the Description page of Project Settings.

#include "Narator.h"

// Sets default values
ANarator::ANarator()
	: m_CurrentText("")
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANarator::PrintText(const FString& text)
{
	m_CurrentText = text;
}

// Called when the game starts or when spawned
void ANarator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANarator::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	if(!m_TextQueue.empty())
	{
		if(m_TextQueue.front()->Update(deltaTime))
		{
			m_TextQueue.pop_front();
			m_CurrentText = "";
			return;
		}
		PrintText(m_TextQueue.front()->GetText());
	}
}

void ANarator::SetText(const FString& text, bool shouldInterrupt)
{
	if(shouldInterrupt)
	{
		m_TextQueue.clear();
	}

	auto temp = std::make_unique<NarrationText>(text);
	m_TextQueue.push_back(std::move(temp));
}

