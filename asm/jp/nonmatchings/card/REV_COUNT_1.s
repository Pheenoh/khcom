.syntax unified
	.align 2, 0
	.global REV_COUNT_1
	.thumb
	.thumb_func
	.type REV_COUNT_1, %function
REV_COUNT_1:
	.incbin "roms/B8CJ.gba", 0x98fc0, 0x1a8
.syntax divided
