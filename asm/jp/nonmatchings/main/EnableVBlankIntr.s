.syntax unified
	.align 2, 0
	.global EnableVBlankIntr
	.thumb
	.thumb_func
	.type EnableVBlankIntr, %function
EnableVBlankIntr:
	.incbin "roms/B8CJ.gba", 0x260, 0x34
.syntax divided
