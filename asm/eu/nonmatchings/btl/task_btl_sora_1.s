.syntax unified
	.text
	.align 2, 0
	.global task_btl_sora_1
	.thumb
	.thumb_func
	.type task_btl_sora_1, %function
task_btl_sora_1:
	.incbin "roms/B8CP.gba", 0x22738, 0x89bc
.syntax divided
