.syntax unified
	.text
	.align 2, 0
	.global task_btl_sora_2
	.thumb
	.thumb_func
	.type task_btl_sora_2, %function
task_btl_sora_2:
	.incbin "roms/B8CP.gba", 0x2b0f4, 0x260
.syntax divided
