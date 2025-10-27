#pragma once

#include "CoreMinimal.h"
#include "Waypoint.generated.h"

/**
 * @file Waypoint.h
 *
 * @brief This file contains the Waypoint struct.
 *
 *
 * @author Aida Bah
 * Contact: aidasulayb@gmail.com
 *
 */

USTRUCT(BlueprintType)
/**
* @struct Waypoint
* @brief Represents a waypoint for mission planning.
*
* This struct stores the index, longitude, and latitude of a spline endpoint.
* This data is used as a waypoint for autonomous UAV missions.
*
*/
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