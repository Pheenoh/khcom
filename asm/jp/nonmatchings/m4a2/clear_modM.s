.syntax unified
	.text
	.align 2, 0
	.global clear_modM
	.thumb
	.thumb_func
	.type clear_modM, %function
clear_modM:
	.incbin "roms/B8CJ.gba", 0x11fd6c, 0x1c
.syntax divided
