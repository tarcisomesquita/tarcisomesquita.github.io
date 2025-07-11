#!/bin/bash
# sudo showkey -s

VBoxManage controlvm "LU" keyboardputscancode 1d 14 94 9d   # ctrl+t

VBoxManage controlvm "LU" keyboardputscancode 1c 9c         # enter

VBoxManage controlvm "LU" keyboardputscancode 1d 1e 9e 9d   # ctrl+a

VBoxManage controlvm "LU" keyboardputscancode 1d 2e ae 9d   # ctrl+c

VBoxManage controlvm "LU" keyboardputscancode 38 0f 8f b8   # alt+tab

VBoxManage controlvm "LU" keyboardputscancode 1d 2a 2f af aa 9d  # ctrl+shift+v

VBoxManage controlvm "LU" keyboardputscancode 1d 11 91 9d   # ctrl+w

