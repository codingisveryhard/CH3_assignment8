#include "MineItem.h"
#include "Components/SphereComponent.h"
#include "SpartaGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

AMineItem::AMineItem() {

	ExplosionDelay = 2.0f;
	ExplosionRadius = 300.0f;
	ExplosionDamage = 30;
	ItemType = "Mine";

	ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	ExplosionCollision->InitSphereRadius(ExplosionRadius);
	ExplosionCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ExplosionCollision->SetupAttachment(Scene);

	ExplosionParticle = nullptr;
	ExplosionSound = nullptr;
	bIsExplode = false;
}

void AMineItem::Explode() {

	UParticleSystemComponent* Particle = nullptr;

	if (ExplosionParticle) {
		Particle = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, GetActorLocation(), GetActorRotation(), false);
	}

	if (ExplosionSound) {
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());
	}

	TArray<AActor*> OverlappingActors;
	ExplosionCollision->GetOverlappingActors(OverlappingActors);

	// 지뢰 작동시 트리거 작동
	ASpartaGameState* SpartaGameState = GetWorld()->GetGameState<ASpartaGameState>();
	if (SpartaGameState) {
		SpartaGameState->OnTriggered.Broadcast();	// 외부에서 바인딩된 함수 실행
	}

	for (AActor* Actor : OverlappingActors) {
		if (Actor && Actor->ActorHasTag("Player")) {
			UGameplayStatics::ApplyDamage(Actor, ExplosionDamage, nullptr, this, UDamageType::StaticClass());
		}
	}

	DestroyItem();

	if (Particle) {
		FTimerHandle DestroyParticleTimerHandle;
		TWeakObjectPtr<UParticleSystemComponent> WeakParticle = Particle;

		GetWorld()->GetTimerManager().SetTimer(DestroyParticleTimerHandle,
			[WeakParticle]() {
				if (WeakParticle.IsValid()) {
					WeakParticle->DestroyComponent();
				}
			},
			5.0f,
			false
		);
	}
}

void AMineItem::ActivateItem(AActor* Activator) {

	if (bIsExplode) return;

	Super::ActivateItem(Activator);

	GetWorld()->GetTimerManager().SetTimer(
		ExplosionTimerHandle,
		this,
		&AMineItem::Explode,
		ExplosionDelay,
		false
	);

	bIsExplode = true;
}
