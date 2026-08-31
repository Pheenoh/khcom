.syntax unified
	.align 2, 0
	.global task_bos_boogie_dice_1
	.thumb
	.thumb_func
	.type task_bos_boogie_dice_1, %function
task_bos_boogie_dice_1:
	.incbin "roms/B8CJ.gba", 0xd9d40, 0x5cc
.syntax divided
