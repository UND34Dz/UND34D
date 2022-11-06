# UND34D

**TODO**
​​​​​​​​​​
---------------
https://github.com/orgs/UND34Dz/projects/1
---------------
​​​​​​​​​​


![](https://img.shields.io/badge/dynamic/json?color=ffab00&label=Online%20Version&query=%24.game.online&url=https%3A%2F%2Fraw.githubusercontent.com%2FUND34Dz%2FUND34D%2Fmaster%2Fmetadata.json&style=flat-square&labelColor=000000) ![](https://img.shields.io/badge/dynamic/json?color=ffab00&label=Game%20Build&query=%24.game.build&url=https%3A%2F%2Fraw.githubusercontent.com%2FUND34Dz%2FUND34D%2Fmaster%2Fmetadata.json&style=flat-square&labelColor=000000)

## Table of contents

 * [How to build](#how-to-build)
 * [Staying Up To Date](#staying-up-to-date)
 * [Project Structure](#project-structure)
 * [Features](#features)
 * [Contributing](#contributing)

## How to build

```bash
git clone https://github.com/UND34Dz/UND34D.git --recursive
```

Go into the directory you just cloned:
```bash
cd UND34D
```

Run the magical script:
```bash
script.bat
```

Now you have `UND34D.sln` you can open it in "Visual Studio" or run "msbuild.exe" in your GS Dev Cmd.

## Staying Up To Date
Run the script:
```bash
script.bat
```
Or just run commands manualy.


## Project Structure
- `native_hooks/` hooks to natives
- `backend/` all features that should be ran in a loop are in here sorted by category
- `gui/` includes everything related to UI elements
- `hooks/` function hooks
- `native_hooks/` hooks to natives
- `services/` service files to interact and maintain stuff
- `util/` general utility functions to keep code as compact and as much in one place as possible
- `views/` all gui windows are, except handling windows for some reason

## Features

Below is an incomplete list of feature that I believe are notable to this "base" or menu.

 - Return Native spoofing
 - Custom [settings](UND34D/src/core/globals.hpp) with deep compare if changes were made include auto saving
 - Clear and well structured source code
 - Includes a thread pool to queue tasks that shouldn't block the game thread, very similar to fiber pool
 - Updated natives.hpp from https://nativedb.spyral.dev/natives
 - Includes basic code samples to interact with an api
 - ReClass.NET structures implemented, accessible from a global called g_local_player defined in `common.hpp`
