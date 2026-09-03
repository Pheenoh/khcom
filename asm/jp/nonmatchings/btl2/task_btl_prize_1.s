.syntax unified
	.text
	.align 2, 0
	.global task_btl_prize_1
	.thumb
	.thumb_func
	.type task_btl_prize_1, %function
task_btl_prize_1:
	.incbin "roms/B8CJ.gba", 0x30dac, 0x544
.syntax divided
