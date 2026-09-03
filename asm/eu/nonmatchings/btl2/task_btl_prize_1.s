.syntax unified
	.text
	.align 2, 0
	.global task_btl_prize_1
	.thumb
	.thumb_func
	.type task_btl_prize_1, %function
task_btl_prize_1:
	.incbin "roms/B8CP.gba", 0x351a4, 0x544
.syntax divided
