.syntax unified
	.align 2, 0
	.global mode_vsbattle_2
	.thumb
	.thumb_func
	.type mode_vsbattle_2, %function
mode_vsbattle_2:
	.incbin "roms/B8CJ.gba", 0xc678, 0x100
.syntax divided
