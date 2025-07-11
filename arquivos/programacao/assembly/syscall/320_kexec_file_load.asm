# kexec allows "live" booting of a new kernel "over" the currently running kernel. Essentially, kexec skips the bootloader stage (hardware initialization phase by the system firmware, BIOS or UEFI) and directly loads the new kernel into memory, where it starts executing immediately. This avoids the long times associated with a full reboot, and can help systems to meet high-availability requirements by minimizing downtime.

# root user can load arbitrary code via kexec and execute it.

