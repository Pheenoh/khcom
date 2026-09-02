.syntax unified
	.align 2, 0
	.global ply_prio
	.thumb
	.thumb_func
	.type ply_prio, %function
ply_prio:
	.incbin "roms/B8CJ.gba", 0x11f724, 0xc
.syntax divided
