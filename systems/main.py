from drone_utils import *
import asyncio
import logging

from mavsdk import System
from mavsdk.mission import MissionItem, MissionPlan

# Enable INFO level logging
#logging.basicConfig(level=logging.INFO)

async def main():
    print("starting function..")
    waypoints = '../simulation/unreal/Saved/Missions/waypoints.csv'
    system_address = "udp://0.0.0.0:14540"
    drone = System()
    await connect_system(drone)

    mission_items = upload_mission_items(waypoints)
    await upload_mission_plan(drone, mission_items)

    await arm_and_start_mission(drone)

    mission_progress_task = asyncio.create_task(print_mission_progress(drone))
    running_tasks = [mission_progress_task]

    termination_task = asyncio.create_task(check_is_in_air(drone, running_tasks))

    await termination_task

if __name__ == "__main__":
    asyncio.run(main())
