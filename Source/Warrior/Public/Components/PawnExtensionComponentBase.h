// Hyunseop's Portfolio

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	// 명시한 타입에 맞게 형변환 하여 단순 반환해주는 함수
	template<class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, 
			"'T' Template Parameter to GetPawn must be derived from APawn");
		return CastChecked<T>(GetOwner());
	}

	// 형변환 없이 그대로 APawn형태로 받아오는 함수
	FORCEINLINE APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	// Pawn의 컨트롤러를 형변환하여 반환하는 함수
	template<class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value,
			"'T' Template Parameter to GetController must be derived from AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
		
};
