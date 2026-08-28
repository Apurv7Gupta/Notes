> [!NOTE]
> **For installing on custom drive:** https://github.com/Apurv7Gupta/Self-Service-Programs/blob/main/Docker_on_custom_drive.md

# Docker Desktop Installation

## 1. Download Docker Desktop

Go to https://www.docker.com/products/docker-desktop/ click "Download Docker Desktop"

## 2. Install Docker Desktop

Run the downloaded `Docker Desktop Installer.exe`. Leave the default configuration options checked (specifically "Use WSL 2 instead of Hyper-V") and click **OK**.

## 3. Restart Your Computer

Restart your computer once the installation completes.

## 4. Launch Docker Desktop

Launch **Docker Desktop** from the Windows Start Menu. Accept the Docker Subscription Service Agreement and skip any onboarding surveys or sign-in prompts.

## 5. Wait for Docker to Initialize

Wait for the Docker engine to fully initialize. The status indicator in the bottom-left corner of the UI must turn solid green.

## 6. Verify the Installation

Open a **new** PowerShell window (to ensure Docker's environment variables are loaded into your PATH) and verify the installation by running:

```powershell
docker run hello-world
```

## 7. Remove the `hello-world` Test Footprint

To completely remove the `hello-world` test footprint, delete both the stopped container instance and the cached image from your disk by running:

```powershell
docker container rm $(docker ps -aq --filter ancestor=hello-world)
docker image rm hello-world
```

## 8. Quit Docker Desktop

To completely shut down Docker, right-click the Docker whale icon in the Windows system tray (bottom-right of the taskbar) and click **Quit Docker Desktop**.

## 9. Shut Down WSL

To forcefully terminate the underlying WSL virtual machines and guarantee absolute zero background resource consumption, execute this in PowerShell:

```powershell
wsl --shutdown
```
