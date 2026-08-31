.syntax unified
	.align 2, 0
	.global mode_vsbattle_1
	.thumb
	.thumb_func
	.type mode_vsbattle_1, %function
mode_vsbattle_1:
	.incbin "roms/B8CJ.gba", 0xc5f8, 0x80
.syntax divided
