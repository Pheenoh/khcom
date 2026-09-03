.syntax unified
	.text
	.align 2, 0
	.global mode_StaffRoll_1
	.thumb
	.thumb_func
	.type mode_StaffRoll_1, %function
mode_StaffRoll_1:
	.incbin "roms/B8CP.gba", 0x112b9c, 0x3ec
.syntax divided
