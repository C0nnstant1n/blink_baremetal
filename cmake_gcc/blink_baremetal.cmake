####################################################################
# Automatically-generated file. Do not edit!                       #
####################################################################

set(SDK_PATH "C:/Users/conns/.silabs/slt/installs/conan/p/simpl418dd9bdfa44b/p")
set(COPIED_SDK_PATH "simplicity_sdk_2024.12.1")
set(PKG_PATH "C:/Users/conns/.silabs/slt/installs")

add_library(slc OBJECT
    "${SDK_PATH}/platform/common/src/sl_assert.c"
    "${SDK_PATH}/platform/common/src/sl_core_cortexm.c"
    "${SDK_PATH}/platform/common/src/sl_syscalls.c"
    "${SDK_PATH}/platform/Device/SiliconLabs/EFR32MG21/Source/startup_efr32mg21.c"
    "${SDK_PATH}/platform/Device/SiliconLabs/EFR32MG21/Source/system_efr32mg21.c"
    "${SDK_PATH}/platform/driver/button/src/sl_button.c"
    "${SDK_PATH}/platform/driver/button/src/sl_simple_button.c"
    "${SDK_PATH}/platform/driver/gpio/src/sl_gpio.c"
    "${SDK_PATH}/platform/driver/leddrv/src/sl_led.c"
    "${SDK_PATH}/platform/driver/leddrv/src/sl_simple_led.c"
    "${SDK_PATH}/platform/emlib/src/em_burtc.c"
    "${SDK_PATH}/platform/emlib/src/em_cmu.c"
    "${SDK_PATH}/platform/emlib/src/em_core.c"
    "${SDK_PATH}/platform/emlib/src/em_emu.c"
    "${SDK_PATH}/platform/emlib/src/em_gpio.c"
    "${SDK_PATH}/platform/emlib/src/em_msc.c"
    "${SDK_PATH}/platform/emlib/src/em_rtcc.c"
    "${SDK_PATH}/platform/emlib/src/em_system.c"
    "${SDK_PATH}/platform/emlib/src/em_timer.c"
    "${SDK_PATH}/platform/peripheral/src/sl_hal_gpio.c"
    "${SDK_PATH}/platform/service/clock_manager/src/sl_clock_manager.c"
    "${SDK_PATH}/platform/service/clock_manager/src/sl_clock_manager_hal_s2.c"
    "${SDK_PATH}/platform/service/clock_manager/src/sl_clock_manager_init.c"
    "${SDK_PATH}/platform/service/clock_manager/src/sl_clock_manager_init_hal_s2.c"
    "${SDK_PATH}/platform/service/device_init/src/sl_device_init_emu_s2.c"
    "${SDK_PATH}/platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg21.c"
    "${SDK_PATH}/platform/service/device_manager/src/sl_device_clock.c"
    "${SDK_PATH}/platform/service/device_manager/src/sl_device_gpio.c"
    "${SDK_PATH}/platform/service/device_manager/src/sl_device_peripheral.c"
    "${SDK_PATH}/platform/service/interrupt_manager/src/sl_interrupt_manager_cortexm.c"
    "${SDK_PATH}/platform/service/memory_manager/src/sl_memory_manager_region.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer_hal_prortc.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtcc.c"
    "${SDK_PATH}/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.c"
    "${SDK_PATH}/platform/service/system/src/sl_system_init.c"
    "${SDK_PATH}/platform/service/system/src/sl_system_process_action.c"
    "../app.c"
    "../autogen/sl_event_handler.c"
    "../autogen/sl_simple_button_instances.c"
    "../autogen/sl_simple_led_instances.c"
    "../blink.c"
    "../main.c"
)

target_include_directories(slc PUBLIC
   "../config"
   "../autogen"
   "../."
    "${SDK_PATH}/platform/Device/SiliconLabs/EFR32MG21/Include"
    "${SDK_PATH}/platform/common/inc"
    "${SDK_PATH}/platform/driver/button/inc"
    "${SDK_PATH}/platform/service/clock_manager/inc"
    "${SDK_PATH}/platform/service/clock_manager/src"
    "${SDK_PATH}/platform/CMSIS/Core/Include"
    "${SDK_PATH}/platform/service/device_manager/inc"
    "${SDK_PATH}/platform/service/device_init/inc"
    "${SDK_PATH}/platform/emlib/inc"
    "${SDK_PATH}/platform/driver/gpio/inc"
    "${SDK_PATH}/platform/peripheral/inc"
    "${SDK_PATH}/platform/service/interrupt_manager/inc"
    "${SDK_PATH}/platform/service/interrupt_manager/inc/arm"
    "${SDK_PATH}/platform/driver/leddrv/inc"
    "${SDK_PATH}/platform/service/memory_manager/inc"
    "${SDK_PATH}/platform/common/toolchain/inc"
    "${SDK_PATH}/platform/service/system/inc"
    "${SDK_PATH}/platform/service/sleeptimer/inc"
)

target_compile_definitions(slc PUBLIC
    "DEBUG_EFM=1"
    "EFR32MG21A020F768IM32=1"
    "SL_CODE_COMPONENT_SYSTEM=system"
    "SL_CODE_COMPONENT_CLOCK_MANAGER=clock_manager"
    "SL_COMPONENT_CATALOG_PRESENT=1"
    "SL_CODE_COMPONENT_DEVICE_PERIPHERAL=device_peripheral"
    "SL_CODE_COMPONENT_HAL_COMMON=hal_common"
    "SL_CODE_COMPONENT_HAL_GPIO=hal_gpio"
    "CMSIS_NVIC_VIRTUAL=1"
    "CMSIS_NVIC_VIRTUAL_HEADER_FILE=\"cmsis_nvic_virtual.h\""
    "SL_CODE_COMPONENT_CORE=core"
    "SL_CODE_COMPONENT_SLEEPTIMER=sleeptimer"
)

target_link_libraries(slc PUBLIC
    "-Wl,--start-group"
    "gcc"
    "c"
    "m"
    "nosys"
    "-Wl,--end-group"
)
target_compile_options(slc PUBLIC
    $<$<COMPILE_LANGUAGE:C>:-mcpu=cortex-m33>
    $<$<COMPILE_LANGUAGE:C>:-mthumb>
    $<$<COMPILE_LANGUAGE:C>:-mfpu=fpv5-sp-d16>
    $<$<COMPILE_LANGUAGE:C>:-mfloat-abi=hard>
    $<$<COMPILE_LANGUAGE:C>:-mcmse>
    $<$<COMPILE_LANGUAGE:C>:-Wall>
    $<$<COMPILE_LANGUAGE:C>:-Wextra>
    $<$<COMPILE_LANGUAGE:C>:-Os>
    $<$<COMPILE_LANGUAGE:C>:-fdata-sections>
    $<$<COMPILE_LANGUAGE:C>:-ffunction-sections>
    $<$<COMPILE_LANGUAGE:C>:-fomit-frame-pointer>
    $<$<COMPILE_LANGUAGE:C>:-g>
    "$<$<COMPILE_LANGUAGE:C>:SHELL:-imacros sl_gcc_preinclude.h>"
    $<$<COMPILE_LANGUAGE:C>:-fno-lto>
    $<$<COMPILE_LANGUAGE:C>:--specs=nano.specs>
    $<$<COMPILE_LANGUAGE:CXX>:-mcpu=cortex-m33>
    $<$<COMPILE_LANGUAGE:CXX>:-mthumb>
    $<$<COMPILE_LANGUAGE:CXX>:-mfpu=fpv5-sp-d16>
    $<$<COMPILE_LANGUAGE:CXX>:-mfloat-abi=hard>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-mcmse>
    $<$<COMPILE_LANGUAGE:CXX>:-Wall>
    $<$<COMPILE_LANGUAGE:CXX>:-Wextra>
    $<$<COMPILE_LANGUAGE:CXX>:-Os>
    $<$<COMPILE_LANGUAGE:CXX>:-fdata-sections>
    $<$<COMPILE_LANGUAGE:CXX>:-ffunction-sections>
    $<$<COMPILE_LANGUAGE:CXX>:-fomit-frame-pointer>
    $<$<COMPILE_LANGUAGE:CXX>:-g>
    "$<$<COMPILE_LANGUAGE:CXX>:SHELL:-imacros sl_gcc_preinclude.h>"
    $<$<COMPILE_LANGUAGE:CXX>:-fno-lto>
    $<$<COMPILE_LANGUAGE:CXX>:--specs=nano.specs>
    $<$<COMPILE_LANGUAGE:ASM>:-mcpu=cortex-m33>
    $<$<COMPILE_LANGUAGE:ASM>:-mthumb>
    $<$<COMPILE_LANGUAGE:ASM>:-mfpu=fpv5-sp-d16>
    $<$<COMPILE_LANGUAGE:ASM>:-mfloat-abi=hard>
    "$<$<COMPILE_LANGUAGE:ASM>:SHELL:-imacros sl_gcc_preinclude.h>"
    "$<$<COMPILE_LANGUAGE:ASM>:SHELL:-x assembler-with-cpp>"
)

set(post_build_command )
set_property(TARGET slc PROPERTY C_STANDARD 17)
set_property(TARGET slc PROPERTY CXX_STANDARD 17)
set_property(TARGET slc PROPERTY CXX_EXTENSIONS OFF)

target_link_options(slc INTERFACE
    -mcpu=cortex-m33
    -mthumb
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
    -T${CMAKE_CURRENT_LIST_DIR}/../autogen/linkerfile.ld
    --specs=nano.specs
    "SHELL:-Xlinker -Map=$<TARGET_FILE_DIR:blink_baremetal>/blink_baremetal.map"
    -fno-lto
    -Wl,--gc-sections
    -Wl,--no-warn-rwx-segments
)

# BEGIN_SIMPLICITY_STUDIO_METADATA=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=END_SIMPLICITY_STUDIO_METADATA