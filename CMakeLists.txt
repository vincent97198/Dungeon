cmake_minimum_required(VERSION 3.19)
project(NEW)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(NEW
        DungeonCPP/Dungeon.cpp
        Dungeon.h
        GameCharacter/GameCharacter.cpp
        GameCharacter/GameCharacter.h
        Item.cpp
        Item.h
        main.cpp
        GameCharacter/Monster.cpp
        GameCharacter/Monster.h
        GameCharacter/NPC.cpp
        GameCharacter/NPC.h
        Object.cpp
        Object.h
        GameCharacter/Player/Player.cpp
        GameCharacter/Player/Player.h
        Record.cpp
        Record.h
        Room/Room.cpp
        Room/Room.h Others/consoleColor.h Others/programming_Tools.h Others/programming_Tools.cpp Others/consoleColor.cpp DungeonCPP/demoMap.cpp DungeonCPP/Action/Action_Movement.cpp DungeonCPP/Check_Logic.cpp DungeonCPP/Action/Action_Action.cpp DungeonCPP/Create_Player.cpp DungeonCPP/Show_Status.cpp DungeonCPP/Action/Pick_Item.cpp Others/check_type.cpp Others/check_type.h Equipment/Equipment.cpp Equipment/Equipment.h Equipment/Weapon.cpp Equipment/Weapon.h "DungeonCPP/Action/Fight system.cpp" Others/Ask.cpp Others/Ask.h DungeonCPP/Action/Talk_to_NPC.cpp DungeonCPP/Menu.cpp DungeonCPP/Menu.h Others/consoleScreen.cpp Others/consoleScreen.h Equipment/Armor.cpp Equipment/Armor.h GameCharacter/Player/Player_Record.cpp GameCharacter/Player/Player_get_and_set.cpp "GameCharacter/Player/Player skill.cpp" "GameCharacter/Player/Player Equip.cpp" Room/Room_get_and_set.cpp Room/Room_record.cpp DungeonCPP/Options.cpp DungeonCPP/Options.h)
