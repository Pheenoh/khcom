.syntax unified
	.align 2, 0
	.global task_bos_boogie_dice_3
	.thumb
	.thumb_func
	.type task_bos_boogie_dice_3, %function
task_bos_boogie_dice_3:
	.incbin "roms/B8CJ.gba", 0xda3e4, 0x118
.syntax divided
