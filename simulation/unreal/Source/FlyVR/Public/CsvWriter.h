// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Waypoint.h"     // Waypoint struct
#include "CsvWriter.generated.h"

/**
 * 
 */
UCLASS()
class FLYVR_API UCsvWriter : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	* Function to write an array of waypoints to a CSV file.
	*/

	UFUNCTION(BlueprintCallable, Category = "NAVIS|CSV")
	static bool WriteWaypointsToCsv(
		const TArray<FWaypoint>& Waypoints,
		FString& OutFullPath,
		bool bIncludeHeader = true);
};
