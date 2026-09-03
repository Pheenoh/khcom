.syntax unified
	.text
	.align 2, 0
	.global task_btl_sora_2
	.thumb
	.thumb_func
	.type task_btl_sora_2, %function
task_btl_sora_2:
	.incbin "roms/B8CJ.gba", 0x2714c, 0x26c
.syntax divided
