.syntax unified
	.align 2, 0
	.global task_btl_shadow_1
	.thumb
	.thumb_func
	.type task_btl_shadow_1, %function
task_btl_shadow_1:
	.incbin "roms/B8CJ.gba", 0x2f578, 0x4
.syntax divided
