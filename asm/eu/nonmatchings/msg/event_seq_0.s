.syntax unified
	.text
	.align 2, 0
	.global event_seq_0
	.thumb
	.thumb_func
	.type event_seq_0, %function
event_seq_0:
	.incbin "roms/B8CP.gba", 0x6c504, 0x11c
.syntax divided
