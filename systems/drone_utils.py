import csv
import asyncio

from mavsdk import System
from mavsdk.mission import MissionItem, MissionPlan

# asynchronous function to connect to drone
# ! need to add error handling: i.e connection lost, ststaus updates, etc.

async def connect_system(drone):
    await drone.connect()

    print("Waiting for drone to connect...")

    async for state in drone.core.connection_state():
        if state.is_connected:
            print("Connected to drone!")
            break
        else:
            print("Lost drone connection.")


# Parse through csv to upload waypoints
def upload_mission_items(waypoints_as_csv):
    mission_items = []

    with open(waypoints_as_csv, 'r') as csvfile:
        dict_reader = csv.DictReader(csvfile)
        for row in dict_reader:
            mission_items.append(
                MissionItem(
                    row['latitude_deg'],
                    row['longitude_deg'],
                    row['relative_altitude_m'],
                    3,
                    True,
                    float("nan"),
                    float("nan"),
                    MissionItem.CameraAction.NONE,
                    float("nan"),
                    float("nan"),
                    float("nan"),
                    float("nan"),
                    float("nan"),
                    MissionItem.VehicleAction.NONE,
                )
            )
    return mission_items


# Upload mission
async def upload_mission_plan(drone, mission_items):
    mission_plan = MissionPlan(mission_items)

    await drone.mission.set_return_to_launch_after_mission(True) #set to return to launch for testing purposes

    print("Uploading mission plan...")
    await drone.mission.upload_mission(mission_plan)
    print("Upload successful!") 


# Arms the drone and starts the mission
async def arm_and_start_mission(drone):

    print("Waiting for drone to have global position estimate...")
    async for health in drone.telemetry.health():
        if health.is_global_position_ok and health.is_home_position_ok:
            print("Global position estimate OK")
            break

    print("Arming...")
    await drone.action.arm()

    print("Start mission...")
    await drone.mission.start_mission()

#Print mission progress
async def print_mission_progress(drone):
        async for mission_progress in drone.mission.mission_progress():
            print(f"Mission progress: {mission_progress.current}/{mission_progress.total}")

# Checks if drone is in the air. Stops all asynchronous routines once it is not
async def check_is_in_air(drone, running_tasks):
    was_in_air = False
    
    async for is_in_air in drone.telemetry.in_air():
        if is_in_air:
            was_in_air = is_in_air

        if was_in_air and not is_in_air:
            for task in running_tasks:
                task.cancel()
                try:
                    await task
                except asyncio.CancelledError:
                    pass
                await asyncio.get_event_loop().shutdown_asyncgens()

                return
                