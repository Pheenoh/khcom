.syntax unified
	.text
	.align 2, 0
	.global clear_modM
	.thumb
	.thumb_func
	.type clear_modM, %function
clear_modM:
	.incbin "roms/B8CP.gba", 0x11e810, 0x1c
.syntax divided
