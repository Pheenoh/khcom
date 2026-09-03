.syntax unified
	.text
	.align 2, 0
	.global task_btl_sora_0
	.thumb
	.thumb_func
	.type task_btl_sora_0, %function
task_btl_sora_0:
	.incbin "roms/B8CP.gba", 0x21f7c, 0x44c
.syntax divided
