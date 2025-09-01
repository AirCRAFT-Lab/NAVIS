# NAVIS 

**NAVIS** is a VR-based UAS operations platform designed to make drone piloting more accessible to non-professional users. By simulating real-world flight dynamics in a simulation environment, NAVIS provides an immersive training experience that enhances user proficiency without the need for costly equipment or formal training.


## Features
- **Virtual Flight Testing Cage** – A replica of SLU’s flight testing cage built in Unreal Engine 5 for realistic simulation.
  ![Cage VRE Sample](https://github.com/user-attachments/assets/fed0da7d-bb9c-4fb9-8f20-cce9aacc8bff)
- **Simulated Flight Dynamics** – In development: Incorporates flight physics and control logic to create an accurate UAV piloting experience.
- **Drone Operations Interface** – In development: Integrating a flight control system to mirror real-world UAS behavior.
- **Future Integration with Live Hardware** – Bridging virtual training with physical drone operations for real-time control.

## Tech Stack
- **Unreal Engine 5** – Simulation design and simulation.
- **Blueprints & C++** – Game logic and physics implementation.
- **VR Integration** – In progress: testing on Meta Quest 3, with deployment planned for PC, VR headsets (OpenXR-supported devices), and additional platforms as applicable.

## Research Affiliation
This project is part of ongoing research at the [AirCRAFT Lab](https://sites.google.com/a/slu.edu/aircraft-lab/aircraft-computational-resource-aware-fault-tolerance-aircraft-lab) at Saint Louis University (SLU).

**Usage Restriction**: This research is currently proprietary and should not be copied, distributed, or used outside of the lab.

## Installation & Setup
To set up and explore NAVIS’s Virtual Flight Testing Cage in Unreal Engine 5:

### Requirements
- Git LFS installed ([Git LFS Installation Guide](https://docs.github.com/en/repositories/working-with-files/managing-large-files/installing-git-large-file-storage))
- Unreal Engine 5.5 installed ([Unreal Engine 5 Download](https://www.unrealengine.com/en-US/download))
- Nvidia App installed ([Nvidia App Download](https://www.nvidia.com/en-us/software/nvidia-app/))
- Meta Link App installed ([Meta Link App Download](https://www.meta.com/help/quest/1517439565442928/?srsltid=AfmBOoo5HDX9Xwzl0RUPHDrSAxrTUrCMRuUgJxGMM2FmbLKsoUtUX3ZB))
- Steam installed ([Steam Download](https://store.steampowered.com/about/download))
- SteamVR installed ([SteamVR Download](https://www.google.com/search?client=safari&rls=en&q=steamvr&ie=UTF-8&oe=UTF-8))
### Setup Steps
1. Clone the Repository (Make sure Git LFS is installed)
   
   `git clone https://github.com/aidabah/NAVIS.git`

2. Open the Project in Unreal Engine 5
    - Launch Unreal Engine 5
    - Open the .uproject file inside the cloned repository

3. Turn on deveoper mode on Meta Quest headset and connect Meta Quest headset via usb to PC

4. Download MetaXR plugin if using Meta Quest headset ([Meta XR Plugin Installation](https://developers.meta.com/horizon/documentation/unreal/unreal-quick-start-install-metaxr-plugin/)) 

5. Open Unreal Engine, enable MetaXR plugin and OpenXR plugin, then restart Unreal Engine

6. Launch SteamVR and re-open the project

7. Enable 'VR preview' mode
   
9. Green play button should now have VR Preview icon

    
You can now explore the simulation in VR and modify the NAVIS simulation in Unreal Engine 5.

## Contact
For inquiries regarding this research, please reach out to:
- Aida Bah (Project Lead) – aidasulayb@gmail.com
- Kaysar Adde (Systems Developer) - kaysar.adde@slu.edu
- Dr. Srikanth Gururajan (Lab Director) – srikanth.gururajan@slu.edu

## License
This project is licensed under the **AirCRAFT Lab Research License (ALRL) v1.0**. It is for internal research use at the **AirCRAFT Lab, Saint Louis University (SLU)**. External distribution, commercial use, and public disclosure are prohibited without prior approval.

For full details, see the file `LICENSE.md`.

