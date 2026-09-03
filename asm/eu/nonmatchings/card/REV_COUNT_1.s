.syntax unified
	.text
	.align 2, 0
	.global REV_COUNT_1
	.thumb
	.thumb_func
	.type REV_COUNT_1, %function
REV_COUNT_1:
	.incbin "roms/B8CP.gba", 0x9912c, 0x1a8
.syntax divided
