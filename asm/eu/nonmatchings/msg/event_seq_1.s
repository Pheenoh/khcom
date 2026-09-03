.syntax unified
	.text
	.align 2, 0
	.global event_seq_1
	.thumb
	.thumb_func
	.type event_seq_1, %function
event_seq_1:
	.incbin "roms/B8CP.gba", 0x6c620, 0x548
.syntax divided
