// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Waypoint.h"     // Waypoint struct
#include "CsvWriter.generated.h"

/**
 * @file CsvWriter.h
 *
 * @brief This file contains the class for a waypoint to CSV writer. 
 * 
 * @author Aida Bah
 * Contact: aidasulayb@gmail.com
 *
 */

UCLASS()
class FLYVR_API UCsvWriter : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * @brief This function writes an array of waypoints to a CSV file.
	 * 
	 * @param Waypoints: an array of Waypoint strcut.
	 * @return bOK: boolean for successful write to target csv file.
	 */
	

	UFUNCTION(BlueprintCallable, Category = "NAVIS|CSV")
	static bool WriteWaypointsToCsv(
		const TArray<FWaypoint>& Waypoints,
		FString& OutFullPath,
		bool bIncludeHeader = true);
};
