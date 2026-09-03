.syntax unified
	.text
	.align 2, 0
	.global event_seq_3
	.thumb
	.thumb_func
	.type event_seq_3, %function
event_seq_3:
	.incbin "roms/B8CP.gba", 0x6cd78, 0x4c
.syntax divided
