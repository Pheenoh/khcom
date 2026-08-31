.syntax unified
	.align 2, 0
	.global task_btl_sora_1
	.thumb
	.thumb_func
	.type task_btl_sora_1, %function
task_btl_sora_1:
	.incbin "roms/B8CJ.gba", 0x1e854, 0x88f8
.syntax divided
