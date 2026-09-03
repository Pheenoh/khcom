.syntax unified
	.text
	.align 2, 0
	.global ply_prio
	.thumb
	.thumb_func
	.type ply_prio, %function
ply_prio:
	.incbin "roms/B8CP.gba", 0x11e1c8, 0xc
.syntax divided
