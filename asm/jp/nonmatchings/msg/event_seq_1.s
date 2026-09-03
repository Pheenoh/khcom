.syntax unified
	.text
	.align 2, 0
	.global event_seq_1
	.thumb
	.thumb_func
	.type event_seq_1, %function
event_seq_1:
	.incbin "roms/B8CJ.gba", 0x6d2c8, 0x3fc
.syntax divided
