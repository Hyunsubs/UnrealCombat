// Hyunseop's Portfolio


#include "Components/Combat/EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "WarriorGameplayTags.h"

#include "WarriorDebugHelper.h"

void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	OverlappedActors.AddUnique(HitActor);


	// TODO: ��� üũ �����ϱ�
	// ���� �ְų� ����Ұ����� ���� �ɼ��� üũ�ؾ���
	bool bIsValidBlock = false;

	const bool bIsPlayerBlocking = false;
	const bool bIsMyAttackUnblockable = false;

	if (bIsPlayerBlocking && !bIsMyAttackUnblockable)
	{
		// ��� �������� bool�� ����
	}

	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;

	if (bIsValidBlock)
	{
		// ����ϵ��� ����
	}
	else
	{
		// �µ��� ����
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			GetOwningPawn(),
			WarriorGameplayTags::Shared_Event_MeleeHit,
			EventData
		);
	}
}