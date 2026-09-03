.syntax unified
	.text
	.align 2, 0
	.global task_btl_sora_0
	.thumb
	.thumb_func
	.type task_btl_sora_0, %function
task_btl_sora_0:
	.incbin "roms/B8CJ.gba", 0x1e098, 0x44c
.syntax divided
