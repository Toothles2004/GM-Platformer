#pragma once
#include "NarrationText.h"
#include <memory>
#include <deque>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narator.generated.h"
UCLASS()
class PLATFORMER_API ANarator : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ANarator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetText(const FString& text, bool shouldInterrupt);

	UFUNCTION(BlueprintCallable)
	FString GetCurrentText() const { return m_CurrentText; }

private:
	virtual void PrintText(const FString& text);

	std::deque<std::unique_ptr<NarrationText>> m_TextQueue;
	FString m_CurrentText;
};
