// Fill out your copyright notice in the Description page of Project Settings.

#include "CsvWriter.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/FileManager.h"


bool UCsvWriter::WriteWaypointsToCsv(
	const TArray<FWaypoint>& Waypoints,
	FString& OutFullPath,
	bool bIncludeHeader) {

	//Declaring path to waypoints csv
	const FString ProjectSaveDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Missions"));

	//Checking if file already exists at path.
	if (!IFileManager::Get().MakeDirectory(*ProjectSaveDir, /*Tree=*/true)) {

		UE_LOG(LogTemp, Error, TEXT("Failed to create directory: %s"), *ProjectSaveDir);
		return false;
	}

		//Declare csv file
		OutFullPath = FPaths::Combine(ProjectSaveDir, TEXT("waypoints.csv"));
		FString Csv;

		//Write header
		if (bIncludeHeader) {
			Csv += TEXT("index,latitude_deg,longitude_deg,relative_altitude_m\r\n");
		}

		//Tentative default altitude
		const int32 DefaultAltM = 30;

		//Append waypoints to rows
		for (const FWaypoint& Waypoint : Waypoints) {
			Csv += FString::Printf(
				TEXT("%d, %.10f, %.10f, %d\r\n"),
				Waypoint.Index, 
				Waypoint.LatitudeDeg, 
				Waypoint.LongitudeDeg, 
				DefaultAltM
			);
		}

		//Write or overwrite
		const bool bOK = FFileHelper::SaveStringToFile(
			Csv,
			*OutFullPath,
			FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
			
		if (!bOK) {
			UE_LOG(LogTemp, Error, TEXT("Failed to write to CSV: %s"), *OutFullPath);
		}
		else {
			UE_LOG(LogTemp, Display, TEXT("Wrote %d waypoints to %s"), Waypoints.Num(), *OutFullPath);
		}
		
		return bOK;
}
