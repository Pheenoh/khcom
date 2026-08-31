.syntax unified
	.align 2, 0
	.global mode_mapinspect_2
	.thumb
	.thumb_func
	.type mode_mapinspect_2, %function
mode_mapinspect_2:
	.incbin "roms/B8CJ.gba", 0x1093f4, 0x1a4
.syntax divided
