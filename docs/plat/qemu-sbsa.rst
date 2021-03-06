QEMU SBSA Target
================

Trusted Firmware-A (TF-A) implements the EL3 firmware layer for QEMU SBSA
Armv8-A. While running Qemu from command line, we need to supply two Flash
images. First Secure BootRom is supplied by -pflash argument. This Flash image
is made by EDK2 build system by composing BL1 and FIP. Second parameter for Qemu
is responsible for Non-secure rom which also given with -pflash argument and
contains of UEFI and EFI variables (also made by EDK2 build system). Semihosting
is not used

When QEMU starts all CPUs are released simultaneously, BL1 selects a
primary CPU to handle the boot and the secondaries are placed in a polling
loop to be released by normal world via PSCI.

BL2 edits the FDT, generated by QEMU at run-time to add a node describing PSCI
and also enable methods for the CPUs.

Current limitations:

-  Only cold boot is supported

To build TF-A:

::

    git clone https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git tfa
    cd tfa
    export CROSS_COMPILE=aarch64-none-elf-
    make PLAT=qemu_sbsa all fip

To build TF-A with BL32 and SPM enabled(StandaloneMM as a Secure Payload):

::

    git clone https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git tfa
    cd tfa
    export CROSS_COMPILE=aarch64-none-elf-
    make PLAT=qemu_sbsa BL32=../STANDALONE_MM.fd SPM_MM=1 EL3_EXCEPTION_HANDLING=1 all fip

Images will be placed at build/qemu_sbsa/release (bl1.bin and fip.bin).
Need to copy them into top directory for EDK2 compilation.

::

    cp build/qemu_sbsa/release/bl1.bin ../
    cp build/qemu_sbsa/release/fip.bin ../

Those images cannot be used by itself (no semihosing support). Flash images are built by
EDK2 build system, refer to edk2-platform repo for full build instructions.

::

    git clone https://github.com/tianocore/edk2-platforms.git
    Platform/Qemu/SbsaQemu/Readme.md

