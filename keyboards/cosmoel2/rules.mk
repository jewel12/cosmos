# Add VIK configuration here (e.g. VIK_PMW3360_RIGHT=yes to use a trackball)

VIK_ENABLE = yes
VIK_AZOTEQ_RIGHT = yes

# Required: VIK rules check SPLIT_KEYBOARD but keyboard.json sets it after rules.mk
SPLIT_KEYBOARD = yes

include $(KEYBOARD_PATH_1)/vik/rules.mk
