.syntax unified
	.align 2, 0
	.global MPlayJumpTableCopy
	.thumb
	.thumb_func
	.type MPlayJumpTableCopy, %function
MPlayJumpTableCopy:
	.incbin "roms/B8CJ.gba", 0x11f664, 0x1a
.syntax divided
