#pragma once

#include "CoreMinimal.h"
#include "Waypoint.generated.h"

USTRUCT(BlueprintType)
struct FWaypoint
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Index;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double LatitudeDeg;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double LongitudeDeg;

};