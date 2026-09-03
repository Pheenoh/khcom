.syntax unified
	.text
	.align 2, 0
	.global REV_COUNT_2
	.thumb
	.thumb_func
	.type REV_COUNT_2, %function
REV_COUNT_2:
	.incbin "roms/B8CP.gba", 0x99478, 0x34
.syntax divided
