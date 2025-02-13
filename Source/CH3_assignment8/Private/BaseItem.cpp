#include "BaseItem.h"
#include "SpartaGameState.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Collision->SetupAttachment(Scene);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Collision);

	Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::OnItemOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ABaseItem::OnItemEndOverlap);

	if (GetWorld()) {
		// 웨이브가 끝날 시 아이템 정리용으로 작성 하였습니다.
		ASpartaGameState* SpartaGameState = GetWorld()->GetGameState<ASpartaGameState>();
		if (SpartaGameState) {
			SetLifeSpan(SpartaGameState->WaveDuration);
		}
	}
}

void ABaseItem::OnItemOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult) {
	if (OtherActor && OtherActor->ActorHasTag("Player")) {
		ActivateItem(OtherActor);
	}
}
void ABaseItem::OnItemEndOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex) {

}
void ABaseItem::ActivateItem(AActor* Activator) {

	UParticleSystemComponent* Particle = nullptr;

	if (PickupParticle) {
		Particle = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PickupParticle, GetActorLocation(), GetActorRotation(), true);
	}

	if (PickupSound) {
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSound, GetActorLocation());
	}

	if (Particle)
	{
		FTimerHandle DestroyParticleTimerHandle;
		TWeakObjectPtr<UParticleSystemComponent> WeakParticle = Particle;

		GetWorld()->GetTimerManager().SetTimer(
			DestroyParticleTimerHandle,
			[WeakParticle]()
			{
				if (WeakParticle.IsValid())
				{
					WeakParticle->DestroyComponent();
				}
			},
			2.0f,
			false
		);
	}
}
FName ABaseItem::GetItemType() const {
	return ItemType;
}

void ABaseItem::DestroyItem() {
	Destroy();
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();

}

void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

